#lang htdp/isl+

;; -------------- Starter Code --------------

(define S-Exp (signature (mixed Number String Boolean Symbol [ListOf S-Exp])))

(: op? (Any -> Boolean))
; determines whether argument is the symbol of an arithmetic operator
(define (op? s)
  (member s '(+ - * /)))
(define Op (signature (predicate op?)))
 
(define-struct e-op [op left right])
(define-struct e-in [])
(define Exp (signature (mixed Number
                              [EOpOf Op Exp Exp]
                              EIn)))
 
(define E0 3)
(define E1 (make-e-op '+ (make-e-op '- 1 (make-e-op '+ 2 2))
                      (make-e-op '* 3 (make-e-op '/ 3 4))))
(define E2 (make-e-op '+ 1 (make-e-op '- 2 3)))
(define E3 (make-e-op '+ (make-e-in) 2))

(define S0 3)
(define S1 '(+ (- 1 (+ 2 2)) (* 3 (/ 3 4))))
(define S2 '(+ 1 (- 2 3)))
(define S3 '(+ (input) 2))
(define S4 '(+ (- (* 3 (* (input) (input))) (* 4 (input))) 7))

;; -------------- Assignment --------------

(: parse (S-Exp -> Exp))
; Parses an s-expression representing numbers, inputs, and binary arithmetic operations on them
; into an equivalent struct-based representation so they can be processed by other functions
(define (parse s)
  (cond [(number? s) s]
        [(and (list? s) (symbol? (first s)) (symbol=? (first s) 'input))  (make-e-in)]
        [(and (list? s) (= (length s) 3) (op? (first s)))
         (make-e-op (first s) (parse (second s)) (parse (third s)))]
        [else (error "invalid s-exp")]))

(check-error (parse #t))
(check-error (parse '(+ 1 hello)))
(check-error (parse '(* (/ 3 2) (+ -5 (* #f 2)))))
(check-expect (parse S0) E0)
(check-expect (parse S1) E1)
(check-expect (parse S2) E2)
(check-expect (parse S3) E3)

(define E4 (parse S4))

(: eval (Number Exp -> Number))
; Replaces all instances of (make-e-in) in an expression with the input number,
; then evaluates the entire expression to a single number and returns it
(define (eval n s)
  (cond [(number? s) s]
        [(e-in? s) n]
        [(e-op? s) ((cond [(symbol=? (e-op-op s) '+) +]
                          [(symbol=? (e-op-op s) '-) -]
                          [(symbol=? (e-op-op s) '*) *]
                          [(symbol=? (e-op-op s) '/) /])
                    (eval n (e-op-left s))
                    (eval n (e-op-right s)))]))

(check-expect (eval 5 E4) 62)
(check-expect (eval -9 E4) 286)
(check-expect (eval 1204312047 E0) 3)
(check-expect (eval -124912734 E1) -0.75)
(check-expect (eval -3 E3) -1)

(: simplify (Exp -> Exp))
; Purpose: Simplifies and expression by removing operations that don't do anything,
; ex (+ ... 0) or (* ... 1) then returns the final expression
(define (simplify s)
  (cond
    [(or (number? s) (e-in? s)) s]
    [(e-op? s) (let* ([left (simplify (e-op-left s))]
                     [right (simplify (e-op-right s))]
                     [is-num (lambda (x n) (and (number? x) (= n x)))]
                     [result (make-e-op (e-op-op s) left right)])
                 (cond
                   [(symbol=? (e-op-op s) '+)
                    (cond
                      [(is-num left 0) right]
                      [(is-num right 0) left]
                      [else result])]
                   [(symbol=? (e-op-op s) '-)
                    (cond
                      [(is-num right 0) left]
                      [else result])]
                   [(symbol=? (e-op-op s) '*)
                    (cond
                      [(is-num right 1) left]
                      [(is-num left 1) right]
                      [else result])]
                   [(symbol=? (e-op-op s) '/)
                    (cond
                      [(is-num right 1) left]
                      [else result])]))]))

(check-expect (simplify (parse '(+ (- (* (/ (input) 1) 1) 0) 0))) (parse '(input)))
(check-expect (simplify (parse '(+ (+ (- (* (/ (input) 1) 1) 0) 0) (+ (- (* (/ (input) 1) 1) 0) 0)))) (parse '(+ (input) (input))))
(check-expect (simplify (parse '(+ (* 1 (- (/ (+ 0 (* 2 (+ (input) 7))) 1) 0)) 9)))
              (parse '(+ (* 2 (+ (input) 7)) 9)))
(check-expect (simplify (parse '(+ (* 1 (/ 2 7)) (/ (+ 0 (- 0 0)) 1))))
              (parse '(/ 2 7)))

(: compact (Exp -> Exp))
; Purpose: Compacts an expression by evaluating things that do not depend on input,
; for example (+ 1 1), then returns the final expression
(define (compact s)
  (cond
    [(or (number? s) (e-in? s)) s]
    [(e-op? s) (let ([left (compact (e-op-left s))]
                     [right (compact (e-op-right s))])
                 (if (and (number? left) (number? right))
                     ((cond [(symbol=? (e-op-op s) '+) +]
                          [(symbol=? (e-op-op s) '-) -]
                          [(symbol=? (e-op-op s) '*) *]
                          [(symbol=? (e-op-op s) '/) /])
                      left
                      right)
                     (make-e-op (e-op-op s) left right)))]))
                     
(check-expect (compact E0) (eval 1204312047 E0))
(check-expect (compact E1) (eval -124912734 E1))
(check-expect (compact (parse '(+ (* 1 (input)) (/ (- 17 1) (+ -1 2))))) (parse '(+ (* 1 (input)) 16)))
(check-expect (compact (parse '(+ (/ 12 (+ 1 (+ (* 2 2) 1))) (+ (input) (* (- (+ 5 0) 3) (input))))))
              (parse '(+ 2 (+ (input) (* 2 (input))))))

(: run (Number S-Exp -> Number))
; Purpose: combines simplify, compact, parse, and eval into one function to evaluate an
; expression efficiently
(define (run n s)
  (eval n (simplify (compact (simplify (parse s))))))

(check-expect (run 3 '(+ (/ 12 (+ 1 (+ (* 2 2) 1))) (+ (input) (* (- (+ 5 0) 3) (input))))) 11)
(check-expect (run 0 '(+ (* 1 (input)) (/ (- 17 1) (+ -1 2)))) 16)
(check-expect (run 0 '(+ (* 1 (input)) (/ (- 17 1) (+ -1 2)))) 16)
(check-expect (run 5 S4) 62)
(check-expect (run -9 S4) 286)
(check-expect (run 5 2) 2)
(check-expect (run 5 '(input)) 5)

(lambda (x) (cont x))
