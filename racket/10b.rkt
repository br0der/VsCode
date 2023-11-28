#lang htdp/isl+

(: op? (Any -> Boolean))
; determines whether argument is the symbol of an arithmetic operator
(define (op? s)
  (member s '(+ - * /)))
(define Op (signature (predicate op?)))

(define identity-mem
  (lambda (x mem) x))

; an (EM+Of Exp)
; represents a program that computes its argument and adds it to the value in memory
(define-struct e-m+ [arg])
; an EMr represents a program that recalls a value from memory
(define-struct e-mr [])
; an EMc represents a program that clears the value in memory (sets it to zero)
(define-struct e-mc [])

(define-struct e-op [op left right])
(define-struct e-in [])
; an Exp is a
(define Exp (signature (mixed Number
                              (EOpOf Op Exp Exp)
                              (EM+Of Exp)
                              EMr
                              EMc
                              EIn)))
; representing a calculator program that can prompt for input and manipulate state

(define E0 3)
(define E1 (make-e-op '+ (make-e-op '- 1 (make-e-op '+ 2 2))
                      (make-e-op '* 3 (make-e-op '/ 3 4))))
(define E2 (make-e-op '+ 1 (make-e-op '- 2 3)))
(define E3 (make-e-op '+ (make-e-in) 2))
(define E4 (make-e-op '* (make-e-in) (make-e-op '+ 3 (make-e-op '- 7 5))))
(define E5 (make-e-op '* (make-e-m+ (make-e-op '+ 3 2))
                      (make-e-op '- 4 (make-e-mr))))



(define S-Exp (signature (mixed Number String Boolean Symbol (ListOf S-Exp))))

(define S0 3)
(define S1 '(+ (- 1 (+ 2 2)) (* 3 (/ 3 4))))
(define S2 '(+ 1 (- 2 3)))
(define S3 '(+ (input) 2))
(define S4 '(* (input) (+ 3 (- 7 5))))
(define S5 '(* (m+ (+ 3 2)) (- 4 (mr))))

(define-struct input [resume])
; AInput is a
(define AInput (signature [InputOf (Number -> Result)]))
; representing a suspended calculator computation awaiting user input
 
; a Result is a
(define Result (signature (mixed Number AInput)))
; where a Number is a final answer and a AInput is awaiting user input

; A Cont is a
(define Cont (signature (Number Number -> Result)))
; where the Number is the answer of the previous computation

(: op->fn (Op -> (Number Number -> Number)))
; returns the mathematical function associated with the provided Op
(define (op->fn o)
  (cond [(symbol=? o '+) +]
        [(symbol=? o '-) -]
        [(symbol=? o '*) *]
        [(symbol=? o '/) /]))

(check-expect ((op->fn '+) 3 4) 7)
(check-expect ((op->fn '-) 3 4) -1)
(check-expect ((op->fn '*) 3 4) 12)
(check-expect ((op->fn '/) 3 4) 3/4)

(: op->id (Op -> Number))
; returns the identity of the operation,
; i.e., the number that will leave the other operand unaffected
(define (op->id o)
  (cond [(member? o '(+ -)) 0]
        [(member? o '(* /)) 1]))

(check-expect (+ 2 (op->id '+)) 2)
(check-expect (- 2 (op->id '-)) 2)
(check-expect (* 2 (op->id '*)) 2)
(check-expect (/ 2 (op->id '/)) 2)

(: parse (S-Exp -> Exp))
; parses the given S-Expression into an Exp,
; throwing an error if it was unsuccesssful.
(define (parse s)
  (cond [(number? s) s]
        [(and (cons? s)
              (and (>= (length s) 1)
                   (<= (length s) 3)))
         (cond [(op? (first s)) (make-e-op (first s)
                                           (parse (second s))
                                           (parse (third s)))]
               [(and (symbol? (first s))
                     (symbol=? (first s) 'm+)) (make-e-m+ (parse (second s)))]
               [(and (symbol? (first s))
                     (= (length s) 1))
                (cond [(symbol=? (first s) 'input) (make-e-in)]
                      [(symbol=? (first s) 'mr) (make-e-mr)]
                      [(symbol=? (first s) 'mc) (make-e-mc)]
                      [else (error "recieved invalid symbol " (first s))])])]
        [else (error "recieved invalid expression " s)]))

(check-expect (parse S5) E5)
(check-expect (parse S0) E0)
(check-expect (parse S1) E1)
(check-expect (parse S2) E2)
(check-expect (parse S3) E3)
(check-expect (parse S4) E4)

(check-error (parse #t))
(check-error (parse '(+ 1 hello)))
(check-error (parse '(/ a (input))))
(check-error (parse '(^ "a" ())))
(check-error (parse '(* 1 2 3 4 5)))
(check-error (parse '(- (input 2 3) 4)))

(define E10 (parse '(+ (- 1 (* 2 (m+ 2))) (+ (m+ (- (mr) 1)) (mr)))))
(define E11 (parse '(+ (mr) (mr))))
(define E12 (parse '(+ (m+ 5) (+ (mc) (mr)))))
(define E13 (parse '(+ (+ (mr) (m+ 5)) (mr))))
(define E14 (parse '(+ (+ (mr) (m+ 2)) (mr))))
(define E15 (parse '(+ (+ (+ (mc) (mr)) (m+ 2)) (mr))))

(: eval (Exp -> Result))
; evaluate the given expression, using the given number as input
(define (eval exp)
  ((eval/aux exp 0) identity-mem))

(check-expect (eval E0) 3)
(check-expect (eval E1) -0.75)
(check-expect (eval E2) 0)
(check-expect (eval E5) 0)
(check-expect (eval E10) 4)
(check-expect (eval E11) 0)
(check-expect (eval E12) 0)
(check-expect (eval E13) 5)
(check-expect (eval E14) 2)
(check-expect (eval E15) 2)

;(check-expect (eval E13) 7)
;(check-expect (eval E3) 2)
; input tests:
; (check-expect (eval 5 E3) 7)
; (check-expect (eval -2 E3) 0)

(: simplify (Exp -> Exp))
; simplifies the cases of adding/subtracting 0 and multpliying/dividing 1.
(define (simplify exp)
  (cond [(number? exp) exp]
        [(e-in? exp) exp]
        [(e-op? exp) (cond [(member? (e-op-op exp) '(+ *)) (simplify+* exp)]
                           [(member? (e-op-op exp) '(- /)) (simplify-/ exp)])]))

(check-expect (simplify E0) E0)
(check-expect (simplify E3) E3)
(check-expect (simplify (parse '(+ 0 (/ 1 1)))) 1)
(check-expect (simplify (parse '(+ 2 (+ 4 (* 1 3))))) (parse '(+ 2 (+ 4 3))))
(check-expect (simplify (parse '(+ (* 1 2) (* 1 0)))) 2)

(: simplify+* (Exp -> Exp))
; simplify + or * by removing identity operations
(define (simplify+* exp)
  (local [(define id (op->id (e-op-op exp)))]
    ; (+ 0 x) | (* 1 x) -> (simplify x)
    (cond [(equal? (simplify (e-op-left exp)) id) (simplify (e-op-right exp))]
          ; (+ x 0) | (* x 1) -> (simplify x)
          [(equal? (simplify (e-op-right exp)) id) (simplify (e-op-left exp))]
          ; (+ | * x y) -> (+ | * (simplify x) (simplify y))
          [else (make-e-op (e-op-op exp)
                           (simplify (e-op-left exp))
                           (simplify (e-op-right exp)))])))

(check-expect (simplify+* (parse '(+ 0 1))) 1)
(check-expect (simplify+* (parse '(+ 0 0))) 0)
(check-expect (simplify+* (parse '(+ 2 3))) (parse '(+ 2 3)))

(check-expect (simplify+* (parse '(* 1 0))) 0)
(check-expect (simplify+* (parse '(* 10 1))) 10)

(: simplify-/ (Exp -> Exp))
; simplify - or / by removing identity operations
(define (simplify-/ exp)
  (local [(define id (op->id (e-op-op exp)))]
    (if (equal? (simplify (e-op-right exp)) id)
        ; (- x 0) | (/ x 1) -> (simplify x)
        (simplify (e-op-left exp))
        ; (- | / x y) -> (- | / (simplify x) (simplify y)
        (make-e-op (e-op-op exp)
                   (simplify (e-op-left exp))
                   (simplify (e-op-right exp))))))

(check-expect (simplify-/ (parse '(- 2 0))) 2)
(check-expect (simplify-/ (parse '(- 0 2))) (parse '(- 0 2)))

(check-expect (simplify-/ (parse '(/ 2 1))) 2)
(check-expect (simplify-/ (parse '(/ 2 2))) (parse '(/ 2 2)))

(: compact (Exp -> Exp))
; compact the expression by simplifying operations independent of the input
(define (compact exp)
  (cond [(number? exp) exp]
        [(e-in? exp) exp]
        [(e-op? exp)
         (cond [(and (number? (e-op-left exp))
                     (number? (e-op-right exp)))
                (compact ((op->fn (e-op-op exp)) (e-op-left exp)
                                                 (e-op-right exp)))]
               [(e-in? (e-op-left exp))
                (make-e-op (e-op-op exp)
                           (e-op-left exp)
                           (compact (e-op-right exp)))]
               [(e-in? (e-op-right exp))
                (make-e-op (e-op-op exp)
                           (compact (e-op-left exp))
                           (e-op-right exp))]
               [else (compact (make-e-op (e-op-op exp)
                                         (compact (e-op-left exp))
                                         (compact (e-op-right exp))))])]))

(check-expect (compact E0) E0)
(check-expect (compact E1) -3/4)
(check-expect (compact E2) 0)
(check-expect (compact E3) E3)
(check-expect (compact (parse '(+ 3 (- 5 (/ 4 2))))) 6)
(check-expect (compact (parse '(* 3 (+ 5 7)))) 36)
(check-expect (compact (parse S4)) (parse '(* (input) 5)))

(: run (S-Exp -> Result))
; evaluate from the given S-Expression and the number as the input
(define (run s)
  (eval ((compose simplify compact parse) s)))

; optimizations should not change behavior; expressions should evaluate
; as if nothing was changed
(check-expect (run S0) (eval E0))

; input tests:
;(check-expect (run S3) (eval E3))
#;(check-expect (run 8 S4)
                (eval 8 E4))

(: resume (AInput Number -> Result))
; continue the computation with the given input
(define (resume in n)
  ((input-resume in) n))

(check-expect (resume (make-input add1) 1) 2)
(check-expect (resume (make-input (λ (x) (* x 2))) 4) 8)
(check-expect (resume (resume (make-input (λ (x)
                                            (make-input (λ (y) (+ x y))))) 10)
                      5) 15)

#|
Exercise 2:

Example expression '(* (+ 1 (input)) (input))
Evaluating expressions left->right vs. right->left takes inputs
in a different order.

Passing in 1 and 3 for the inputs in either order will produce a different
result:
'(* (+ 1 1) 3) = 6
'(* (+ 1 3) 1) = 4
|#

(: eval/aux (Exp Number -> (Cont -> Result)))
; evaluates the expression left->right
(define (eval/aux exp mem)
  (cond [(number? exp) (λ (cont) (cont exp mem))]
        [(e-mr? exp) (λ (cont) (cont mem mem))]
        [(e-mc? exp) (λ (cont) (cont 0 0))]
        [(e-m+? exp) (λ (cont) ((eval/aux (e-m+-arg exp) mem) (lambda (x y) (cont 0 (+ x y)))))]
        [(e-in? exp) (λ (cont) (make-input (λ (x) (cont x mem))))]
        [(e-op? exp) (λ (cont)
                       ((eval/aux (e-op-left exp) mem)
                        (λ (x mem1)
                          ((eval/aux (e-op-right exp) mem1)
                           (λ (y mem2)
                             (cont ((op->fn (e-op-op exp)) x y) mem2))))))]))

(check-expect (resume (resume ((eval/aux (make-e-op '- (make-e-in)
                                                    (make-e-in)) 0) identity-mem) 3) 2)
              1)
(check-expect (resume (resume ((eval/aux (make-e-op '+ (make-e-in)
                                                    (make-e-in)) 0) identity-mem) 10) 30)
              40)
(check-expect ((eval/aux (parse '(+ (m+ 1) (mr))) 0) identity-mem) 1)
(check-expect (resume (eval (parse '(- (m+ (input)) (+ (mr) 2)))) 10) -12)
(check-expect (resume ((eval/aux (parse '(+ (m+ (input)) (mr))) 0) identity-mem) 2) 2)