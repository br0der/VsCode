#lang htdp/asl
(require 2htdp/image)
(require 2htdp/universe)

(define Image (signature (predicate image?)))
(define Color (signature (predicate image-color?)))

(define CONSOLE-WIDTH 1000)
(define USERS-WIDTH 300)
(define CONSOLE-HEIGHT 500)
(define FONT-SIZE 18)
(define RATE-RESET 5)

; A message in chat, with the sender's name and messge content
(define-struct msg [name content])
(define Message (signature (MsgOf String String)))

(define-struct usr [name blocked? rate])
(define User (signature (UsrOf String Boolean Integer)))

; State of the world, containing the current typed message draft,
; list of people's names who are blocked logged in users, and previous message history.
(define-struct world-state [message users logs])
(define State (signature (WorldStateOf String [ListOf User] [ListOf Message])))

(: state->image (State -> Image))
(define (state->image st)
  (overlay/align
   "left" "bottom"
   (beside/align
    "top"
    (crop/align
     "left" "bottom" (- CONSOLE-WIDTH USERS-WIDTH) CONSOLE-HEIGHT
     (overlay/align
      "left" "bottom"
      (above/align
       "left"
       (foldr (lambda (elem acc) (above/align "left" elem acc)) (empty-scene 0 0) (map msg->image (reverse (world-state-logs st))))
       (chatbox (world-state-message st)))
      (empty-scene (- CONSOLE-WIDTH USERS-WIDTH) CONSOLE-HEIGHT)))
    (users->image st))
   (empty-scene CONSOLE-WIDTH CONSOLE-HEIGHT)))

(: show-text (String Color -> Image))
(define (show-text str color)
  (text/font str FONT-SIZE color "monospace" "default" 'normal 'normal #f))

(: msg->image (Message -> Image))
(define (msg->image m)
  (show-text (string-append (msg-name m)
                            ": "
                            (msg-content m)) "black"))

(: users->image (State -> Image))
(define (users->image ws)
  (let ([users (world-state-users ws)])
    (foldr (lambda (elem acc) (above/align "left" elem acc)) (empty-scene 0 0)
           (map (lambda (user)
                  (show-text (string-append
                              (number->string (usr-rate user))
                              (usr-name user))
                             (if (usr-blocked? user) "red" "black")))
                users))))

(: chatbox (String -> Image))
(define (chatbox s)
  (frame (show-text s "black")))

(define (get-rate name lou)
  (cond
    [(empty? lou) RATE-RESET]
    [(cons? lou) (if (string=? (usr-name (first lou)) name)
                     (usr-rate (first lou))
                     (get-rate name (rest lou)))]))

(define (limit-messages logs)
  (let ([num 5])
    (cond
      [(<= (length logs) num) logs]
      [(> (length logs) num) (limit-messages (reverse (rest (reverse logs))))])))

(: rec (State [ListOf (mixed (enum 'send 'users) String [ListOf String])]
              -> State))
(define (rec ws msg)
  (cond [(symbol=? (first msg) 'send)
         (let* ([sender (first (filter
                                (lambda (u) (string=? (usr-name u) (second msg)))
                                (world-state-users ws)))]
                [sent? (not (or (usr-blocked? sender) (zero? (usr-rate sender))))])
           (make-world-state (world-state-message ws)
                             (if sent?
                                 (map (lambda (u)
                                        (if (string=? (usr-name u) (usr-name sender))
                                            (make-usr (usr-name u)
                                                      (usr-blocked? u)
                                                      (sub1 (usr-rate u)))
                                            u)) (world-state-users ws))
                                 (world-state-users ws))
                             (if sent?
                                 (limit-messages
                                  (cons (make-msg (second msg)
                                                  (third msg))
                                        (world-state-logs ws)))
                                 (world-state-logs ws))))]
        [(symbol=? (first msg) 'users)
         (make-world-state (world-state-message ws)
                           (map (lambda (name) (make-usr
                                                name
                                                false
                                                (get-rate name (world-state-users ws))))
                                (second msg))
                           (world-state-logs ws))]))

(define (change-message ws new-message)
  (make-world-state
   new-message
   (world-state-users ws)
   (world-state-logs ws)))

(define (key-handler ws key)
  (cond
    [(string=? "\r" key) (make-package
                          (change-message ws "")
                          (world-state-message ws))]
    [(string=? "\b" key)
     (if (not (string=? "" (world-state-message ws)))
         (make-world-state
          (implode (reverse (rest (reverse (explode (world-state-message ws))))))
          (world-state-users ws)
          (world-state-logs ws))
         ws)]
    [(= 1 (string-length key)) (change-message
                                ws
                                (string-append
                                 (world-state-message ws)
                                 key))]
    [(string=? "left" key) (change-message
                            ws
                            (string-append
                             (world-state-message ws)
                             "🍲"))]
    [(string=? "right" key) (change-message
                             ws
                             (string-append
                              (world-state-message ws)
                              "🤓☝️"))]
    [else ws]))

(define (mouse-handler ws x y event)
  (if (and (string=? "button-down" event) (<= (- CONSOLE-WIDTH USERS-WIDTH) x))
      (let ([idx (floor (/ y FONT-SIZE))])
        (if (< idx (length (world-state-users ws)))
            (let ([user (list-ref (world-state-users ws) idx)])
              (make-world-state
               (world-state-message ws)
               (map (lambda (u) (if (string=? (usr-name u) (usr-name user))
                                    (make-usr (usr-name u)
                                              (not (usr-blocked? u))
                                              (usr-rate u))
                                    u))
                    (world-state-users ws))
               (world-state-logs ws)))
            ws))
      ws))


    

(: tick-handler (State -> State))
(define (tick-handler ws)
  (make-world-state
   (world-state-message ws)
   (map (lambda (u)
          (make-usr
           (usr-name u)
           (usr-blocked? u)
           RATE-RESET))
        (world-state-users ws))
   (world-state-logs ws)))

; main : String -> ...
(define (main code)
  (big-bang (make-world-state "" '() '())
    (name code)
    (register "lambda-chat.dbp.io")
    (port 20000)
    (to-draw state->image)
    (on-key key-handler)
    (on-mouse mouse-handler)
    (on-tick tick-handler 1)
    (on-receive rec)))
