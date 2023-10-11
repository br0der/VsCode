#lang htdp/bsl

; A Building is one of:
; - "ground"
; - (make-story Number PosInt String Building)
(define-struct story [height rooms color below])
; and represents either the ground story,
; or a story with a height, number of rooms, color, and
;   the rest of the building beneath it

(define BLD1 "ground")
(define BLD2 (make-story 10 15 "red" BLD1))
(define BLD3 (make-story 8 10 "blue" BLD2))
(define BLD4 (make-story 3 50 "yellow" BLD3))
(define BLD5 (make-story 3 40 "yellow" BLD4))
;Exercise 1 Design a function "num-rooms" which counts the total number of rooms in a Building.

; num-rooms : Building -> Number
; computes the total number of rooms in a given building
(define (num-rooms floor)
  (cond
    [(string? floor) 0]
    [else (+ (num-rooms (story-below floor)) (story-rooms floor))]))

(check-expect (num-rooms BLD1) 0)
(check-expect (num-rooms BLD2) 15)
(check-expect (num-rooms BLD3) 25)
(check-expect (num-rooms BLD4) 75)

;Exercise 2 Design a function "max-rooms" which returns the maximum number of rooms in a Building.

; max-rooms : Building -> Number
; computes the maximum number of rooms in a given building
(define (max-rooms floor)
  (cond
    [(string? floor) 0]
    [else (max (max-rooms (story-below floor)) (story-rooms floor))]))

(check-expect (max-rooms BLD1) 0)
(check-expect (max-rooms BLD2) 15)
(check-expect (max-rooms BLD3) 15)
(check-expect (max-rooms BLD4) 50)

;Exercise 3 Design a function "first-floor" that returns either the first floor above "ground" or "#f" if no such floor exists.

; first-floor : Building -> Building or False
; returns the floor above the ground floor
(define (first-floor floor)
  (cond
    [(string? floor) #f]
    [(string? (story-below floor)) floor]
    [else (first-floor (story-below floor))]))

(check-expect (first-floor BLD1) #f)
(check-expect (first-floor BLD2) BLD2)
(check-expect (first-floor BLD3) BLD2)
(check-expect (first-floor BLD4) BLD2)

;Exercise 4 Design a function "unbalanced?" which returns a "#t" if there is a higher story that has more rooms than a lower story, and "#f" otherwise.

; unbalanced? : Building -> Boolean
; returns true is there is a floor that has more rooms than a floor below it, else false
(define (unbalanced? floor)
  (cond
    [(string? floor) false]
    [(string? (story-below floor)) false]
    [else (or
      (unbalanced? (story-below floor))
      (>
       (story-rooms floor)
       (story-rooms (story-below floor))))]))

(check-expect (unbalanced? BLD1) #f)
(check-expect (unbalanced? BLD2) #f)
(check-expect (unbalanced? BLD3) #f)
(check-expect (unbalanced? BLD4) #t)
(check-expect (unbalanced? BLD5) #t)

(define BLD6 "ground")
(define BLD7 (make-story 10 0 "red" BLD6))
(define BLD8 (make-story 8 1 "blue" BLD7))

(check-expect (unbalanced? BLD6) #f)
(check-expect (unbalanced? BLD7) #f)
(check-expect (unbalanced? BLD8) #t)

(define BLD15 (make-story 8 2 "blue" "ground"))
(define BLD16 (make-story 8 3 "blue" BLD15))
(define BLD17 (make-story 1000 1 "blue" BLD16))
(define BLD19 (make-story 1000 1 "blue" BLD17))

;(check-expect (unbalanced? BLD11) #t)
;(check-expect (unbalanced? BLD14) #f)
(check-expect (unbalanced? BLD19) #t)
;(check-expect (unbalanced? BLD18) #f)