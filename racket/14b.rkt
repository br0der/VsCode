#lang htdp/isl+

(: op? (Any -> Boolean))
; determines whether argument is the symbol of an arithmetic operator
(define (op? s)
  (member s '(+ - * /)))
(define Op (signature (predicate op?)))

(: op-convert (Symbol -> (Number Number -> Number)))
; Easily converts operations for ease of access in a future
; eval function. Only works on +, -, *, /
(define (op-convert o)
  (cond
    [(symbol=? o '+) +]
    [(symbol=? o '-) -]
    [(symbol=? o '*) *]
    [(symbol=? o '/) /]))
(check-expect ((op-convert '+) 3 4) 7)
(check-expect ((op-convert '*) 3 4) 12)
(check-expect ((op-convert '/) 3 4) 3/4)
(check-expect ((op-convert '-) 3 4) -1)

(define-struct e-num [num])

(define-struct e-var [sym])

; An operation, like (+ 1 2)
; stores the operator, and the left and right expressions
(define-struct e-op [op left right])
(define E-Op (signature (EOpOf Op Exp Exp)))
(define OP-1 (make-e-op '+ 1 (make-e-op '* 2 4)))
(define OP-2 (make-e-op '- 10 (make-e-op '/ 8 3)))

; A lambda function, like (lambda (x) (+ x 1))
; stores the argument's symbol, and the body expression
(define-struct e-lam [param body])
(define Lambda (signature (ELamOf Symbol Exp)))
(define LA-1 (make-e-lam 'x (make-e-op '+ 'x 1)))
(define LA-2 (make-e-lam 'x 'x))

; Function application, like ((lambda (x) (+ x 1)) 10)
; stores the function being called, and the argument value
; the function can be a regular lambda, an application that
; may return a lambda, or a symbol representing a function
; that may be passed in
(define-struct e-app [fun arg])
(define Application (signature (EAppOf Exp Exp)))
(define APP-1 (make-e-app LA-1 10))
(define APP-2 (make-e-app LA-2 8))
(define APP-3 (make-e-app (make-e-lam 'z (make-e-op '/ 'z 3)) 9))

(define Val (signature (mixed Number Lambda)))

; Any expression representable in StateLang, either a symbol,
; Value, operation, or application of a function
(define Exp (signature (mixed Symbol ; for lambda argument values used later
                              E-Op
                              Val
                              Application)))
; examples for Exp after parse, for ease of writing

; any S-Expression
(define SExp (signature (mixed Number
                               String
                               Boolean
                               Symbol
                               [ListOf SExp])))

(: parse (SExp -> Exp))
; parses a given S-expression into a struct representation for use in StateLang
(define (parse s)
  (cond [(number? s) s]
        [(symbol? s) (if (not (op? s))
                         s
                         (error "use of numerical operator where identifier expected " s))]
        [(cons? s) (cond [(op? (first s)) (parse-op s)]
                         [(memq? (first s) '(lambda λ)) (parse-lamb s)]
                         [else (parse-app s)])] ; must be an application, or invalid
        [else (error "invalid s-expression " s)]))

(check-expect (parse '(+ 1 2)) (make-e-op '+ 1 2))
(check-expect (parse '(* (- 1 2) (/ 3 4)))
              (make-e-op '* (make-e-op '- 1 2) (make-e-op '/ 3 4)))
(check-expect (parse '(lambda (x) (+ x 1)))
              (make-e-lam 'x (make-e-op '+ 'x 1)))
(check-expect (parse '((lambda (x) x) 10))
              (make-e-app (make-e-lam 'x 'x) 10))
(check-expect (parse '((lambda (x) (x 2)) (lambda (y) (+ y 1))))
              (make-e-app (make-e-lam 'x (make-e-app 'x 2)) (make-e-lam 'y (make-e-op '+ 'y 1))))

(: parse-op (SExp -> E-Op))
; parse a given S-expression into an Operation
(define (parse-op s)
  (if (and (list? s)
           (= (length s) 3)
           (op? (first s)))
      (make-e-op (first s) (parse (second s)) (parse (third s)))
      (error "invalid s-expression for operation " s)))

(check-expect (parse-op '(+ 1 1)) (make-e-op '+ 1 1))
(check-expect (parse-op '(* x 3)) (make-e-op '* 'x 3))
(check-expect (parse-op '(- (+ 1 1) (/ 10 8)))
              (make-e-op '-
                       (make-e-op '+ 1 1)
                       (make-e-op '/ 10 8)))

(: parse-lamb (SExp -> Lambda))
; parse a given S-expression into a Lambda
(define (parse-lamb s)
  (if (and (list? s)
           (= (length s) 3)
           (memq? (first s) '(lambda λ))
           ; conditions for argument
           (list? (second s))
           (= (length (second s)) 1)
           (symbol? (first (second s))))
      (make-e-lam (first (second s)) (parse (third s)))
      (error "invalid s-expression for lambda " s)))

(check-expect (parse-lamb '(lambda (x) x))
              (make-e-lam 'x 'x))
(check-expect (parse-lamb '(λ (x) (+ x 1)))
              (make-e-lam 'x (make-e-op '+ 'x 1)))
(check-expect (parse-lamb '(lambda (x) (lambda (y) (+ x y))))
              (make-e-lam 'x (make-e-lam 'y (make-e-op '+ 'x 'y))))

(: parse-app (SExp -> Application))
; parse a given S-expression into a function application
(define (parse-app s)
  (if (and (list? s)
           (= (length s) 2)
           (list? (first s)))
      (make-e-app (parse (first s)) (parse (second s)))
      (if (and (list? s)
               (= (length s) 2)
               (symbol? (first s)))
          (make-e-app (first s) (parse (second s)))
          (error "invalid s-expression for function application " s))))

(check-expect (parse-app '((λ (x) x) 1))
              (make-e-app (make-e-lam 'x 'x) 1))
(check-expect (parse-app '((λ (x) (+ x 1)) 10))
              (make-e-app (make-e-lam 'x (make-e-op '+ 'x 1)) 10))
(check-expect (parse-app '(x 10))
              (make-e-app 'x 10))

; Exp examples
(define EX-1 (parse '(+ 1 2)))
(define EX-2 (parse '(* (- 1 2) (/ 3 4))))
(define EX-3 (parse '(lambda (x) (+ x 1))))
(define EX-4 (parse '((lambda (x) x) 10)))

(: subst (Exp Symbol Val -> Exp))
; Given an expression, replaces all occurances of var with the value val
(define (subst expr var val)
  (cond
    [(symbol? expr) (if (symbol=? expr var)
                        val
                        expr)]
    [(e-op? expr) (make-e-op (e-op-op expr)
                         (subst (e-op-left expr) var val)
                         (subst (e-op-right expr) var val))]
    [(number? expr) expr]
    [(e-lam? expr) (if (symbol=? (e-lam-param expr) var)
                      expr
                      (make-e-lam (e-lam-param expr)
                                 (subst (e-lam-body expr) var val)))]
    [(e-app? expr) (make-e-app (subst (e-app-fun expr) var val)
                           (subst (e-app-arg expr) var val))]))


(check-expect (subst (parse 1) 'x 2) 1)
(check-expect (subst (parse 'x) 'x 2) 2)
(check-expect (subst (parse '(lambda (x) x)) 'x 2) (parse '(lambda (x) x)))
(check-expect (subst (parse '(lambda (y) x)) 'x 2) (parse '(lambda (y) 2)))
(check-expect (subst (parse '(+ ((lambda (x) y) y) y)) 'y 2) (parse '(+ ((lambda (x) 2) 2) 2)))
(check-expect (subst (parse '(+ ((lambda (p) ((lambda (r) (+ (* r p) x)) x)) y) x)) 'x 10)
              (parse '(+ ((lambda (p) ((lambda (r) (+ (* r p) 10)) 10)) y) 10)))

(: eval (Exp -> Val))
; Evaluates an expression just like ISL, but does not verify that
; all variables inside it are bound.
(define (eval expr)
  (cond
    [(symbol? expr) (error "Tried to evaluate, but ran into a symbol")]
    [(e-op? expr) ((op-convert (e-op-op expr)) (eval (e-op-left expr)) (eval (e-op-right expr)))]
    [(number? expr) expr]
    [(e-lam? expr) expr]
    [(and (e-app? expr)
          (e-lam? (e-app-fun expr)))
     (eval (subst (e-lam-body (e-app-fun expr))
                  (e-lam-param (e-app-fun expr))
                  (eval (e-app-arg expr))))]
    [(and (e-app? expr)
          (e-app? (e-app-fun expr)))
     (eval (make-e-app (eval (e-app-fun expr))
                     (e-app-arg expr)))]
    [(and (e-app? expr)
          (symbol? (e-app-fun expr)))
     (eval (make-e-app (eval (e-app-fun expr))
                     (e-app-arg expr)))]))

(check-expect (eval (parse '(+ 1 2))) 3)
(check-expect (eval (parse '((lambda (y)
                               (+ ((lambda (x) (+ x y))
                                   4)
                                  2))
                             -9)))
              -3)
(check-error (eval (parse '((lambda (x) (+ x y)) 2))))
(check-expect (eval (parse '(lambda (x) (+ x 2503791))))
              (parse '(lambda (x) (+ x 2503791))))
(check-expect (eval (parse '(((lambda (x) (lambda (x) (* x 10))) 2) 3)))
              30)
(check-expect (eval (parse '((lambda (x) (x 5)) (lambda (y) (+ y 2))))) 7)
(check-expect (eval (parse '(((lambda (x) (lambda (x) (* x 10))) 2) 3))) 30)



(: wf (Exp -> Exp))
; Finds all unbound variables, where a variable is used before it is
; defined. Either returns the error with the variables, or the same
; expression that was passed in
(define (wf exp)
  (local [(define (wf/acc exp acc)
            (cond
              [(symbol? exp) (if (member? exp acc)
                                  '()
                                  (list exp))]
              [(e-op? exp) (append (wf/acc (e-op-left exp))
                                  (wf/acc (e-op-right exp)))]
              [(number? exp) '()]
              [(e-lam? exp) (wf/acc (e-lam-body exp) (cons (e-lam-param exp) acc))]
              [(e-app? exp)
               (append
                (wf/acc (e-app-fun exp) acc)
                (wf/acc (e-app-arg exp) acc))]))]
    (let ([errors (wf/acc exp '())])
      (if (empty? errors)
          exp
          (error "Unbound variables found: " errors)))))

(check-error (wf (parse '(lambda (x) y))) "Unbound variables found: (list 'y)")
(check-expect (wf (parse '(lambda (x) x))) (parse '(lambda (x) x)))
(check-error (wf (parse '((lambda (x) x) y))) "Unbound variables found: (list 'y)")