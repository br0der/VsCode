#lang htdp/isl+

(require "lib.rkt")

(: op? (Any -> Boolean))
; determines whether argument is the symbol of an arithmetic operator
(define (op? s)
  (memq? s '(+ - * /)))
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
(define Num (signature (ENumOf Number)))

(define-struct e-var [sym])
(define Var (signature (EVarOf Symbol)))

; An operation, like (+ 1 2)
; stores the operator, and the left and right expressions
(define-struct e-op [op left right])
(define Operation (signature (EOpOf Op ExprV3 ExprV3)))
(define OP-1 (make-e-op '+ (make-e-num 1) (make-e-op '* (make-e-num 2) (make-e-num 4))))
(define OP-2 (make-e-op '- (make-e-num 10) (make-e-op '/ (make-e-num 8) (make-e-num 3))))

; A lambda function, like (lambda (x) (+ x 1))
; stores the argument's symbol, and the body expression
(define-struct e-lam [param body])
(define Lambda (signature (ELamOf Symbol ExprV3)))
(define LA-1 (make-e-lam 'x (make-e-op '+ (make-e-var 'x) (make-e-num 1))))
(define LA-2 (make-e-lam 'x (make-e-var 'x)))

; Function application, like ((lambda (x) (+ x 1)) 10)
; stores the function being called, and the argument value
; the function can be a regular lambda, an application that
; may return a lambda, or a symbol representing a function
; that may be passed in
(define-struct e-app [fun arg])
(define Application (signature (EAppOf ExprV3 ExprV3)))
(define APP-1 (make-e-app LA-1 (make-e-num 10)))
(define APP-2 (make-e-app LA-2 (make-e-num 10)))
(define APP-3 (make-e-app (make-e-lam (make-e-var 'z) (make-e-op '/ (make-e-var 'z) (make-e-num 3))) (make-e-num 9)))

(define ValV1 (signature (mixed Num Lambda)))
; Lambda cannot be converted into a Num, so these two cases are distinct. They
; are the base types that we have.

; Any expression representable in StateLang, either a symbol,
; Value, operation, or application of a function
(define ExprV1 (signature (mixed Num
                                 Var
                                 Operation
                                 Lambda
                                 Application)))


(define-struct e-set! [id arg])
(define Set (signature (ESet!Of (mixed Var Loc BoxLoc) ExprV3)))

(define-struct e-loc [sym])
(define Loc (signature (ELocOf Symbol)))

; An expression in StateLang V2 - allowing set!
(define ExprV2 (signature (mixed ExprV1
                                 Set
                                 Loc)))

(define-struct e-box [val])
(define Box (signature (EBoxOf ExprV3)))

(define-struct e-unbox [sym])
(define Unbox (signature (EUnboxOf (mixed Box BoxLoc Var Unbox))))

(define-struct e-set-box [id arg])
(define SetBox (signature (ESetBoxOf (mixed Var Loc BoxLoc) ExprV3)))

(define-struct e-box-loc [sym])
(define BoxLoc (signature (EBoxLocOf Symbol)))

(define ExprV3 (signature (mixed ExprV2
                                 Box
                                 Unbox
                                 BoxLoc
                                 SetBox)))


(define ValV3 (signature (mixed ValV1
                                BoxLoc)))

; examples for Exp after parse, for ease of writing
(define Store (HashMapOf Symbol ValV3))
(define-struct res [store val])
(define Result (signature (ResOf Store ValV3)))

; any S-Expression
(define SExp (signature (mixed Number
                               String
                               Boolean
                               Symbol
                               [ListOf SExp])))

;;;;;;;;;;;
; V1 CODE ;
;;;;;;;;;;;

(: parse-v1 (SExp -> ExprV1))
; parses a given S-expression into a struct representation for use in StateLang
(define (parse-v1 s)
  (cond [(number? s) (make-e-num s)]
        [(symbol? s) (if (not (op? s))
                         (make-e-var s)
                         (error "use of numerical operator where identifier expected " s))]
        [(cons? s) (cond [(op? (first s)) (parse-op-v1 s)]
                         [(memq? (first s) '(lambda λ)) (parse-lamb-v1 s)]
                         [else (parse-app-v1 s)])] ; must be an application, or invalid
        [else (error "invalid s-expression " s)]))

(check-expect (parse-v1 '(+ 1 2)) (make-e-op '+ (make-e-num 1) (make-e-num 2)))
(check-expect (parse-v1 '(* (- 1 2) (/ 3 4)))
              (make-e-op '* (make-e-op '- (make-e-num 1) (make-e-num 2)) (make-e-op '/ (make-e-num 3) (make-e-num 4))))
(check-expect (parse-v1 '(lambda (x) (+ x 1)))
              (make-e-lam 'x (make-e-op '+ (make-e-var 'x) (make-e-num 1))))
(check-expect (parse-v1 '((lambda (x) x) 10))
              (make-e-app (make-e-lam 'x (make-e-var 'x)) (make-e-num 10)))
(check-expect (parse-v1 '((lambda (x) (x 2)) (lambda (y) (+ y 1))))
              (make-e-app (make-e-lam 'x (make-e-app (make-e-var 'x) (make-e-num 2))) (make-e-lam 'y (make-e-op '+ (make-e-var 'y) (make-e-num 1)))))

(: parse-op-v1 (SExp -> Operation))
; parse a given S-expression into an Operation
(define (parse-op-v1 s)
  (if (and (list? s)
           (= (length s) 3)
           (op? (first s)))
      (make-e-op (first s) (parse-v1 (second s)) (parse-v1 (third s)))
      (error "invalid s-expression for operation " s)))

(check-expect (parse-op-v1 '(+ 1 1)) (make-e-op '+ (make-e-num 1) (make-e-num 1)))
(check-expect (parse-op-v1 '(* x 3)) (make-e-op '*  (make-e-var 'x) (make-e-num 3)))
(check-expect (parse-op-v1 '(- (+ 1 1) (/ 10 8)))
              (make-e-op '-
                         (make-e-op '+ (make-e-num 1) (make-e-num 1))
                         (make-e-op '/ (make-e-num 10) (make-e-num 8))))

(: parse-lamb-v1 (SExp -> Lambda))
; parse a given S-expression into a Lambda
(define (parse-lamb-v1 s)
  (if (and (list? s)
           (= (length s) 3)
           (memq? (first s) '(lambda λ))
           ; conditions for argument
           (list? (second s))
           (= (length (second s)) 1)
           (symbol? (first (second s))))
      (make-e-lam (first (second s)) (parse-v1 (third s)))
      (error "invalid s-expression for lambda " s)))

(check-expect (parse-lamb-v1 '(lambda (x) x))
              (make-e-lam 'x (make-e-var 'x)))
(check-expect (parse-lamb-v1 '(λ (x) (+ x 1)))
              (make-e-lam 'x (make-e-op '+ (make-e-var 'x) (make-e-num 1))))
(check-expect (parse-lamb-v1 '(lambda (x) (lambda (y) (+ x y))))
              (make-e-lam 'x (make-e-lam 'y (make-e-op '+ (make-e-var 'x) (make-e-var 'y)))))

(: parse-app-v1 (SExp -> Application))
; parse a given S-expression into a function application
(define (parse-app-v1 s)
  (if (and (list? s)
           (= (length s) 2)
           (list? (first s)))
      (make-e-app (parse-v1 (first s)) (parse-v1 (second s)))
      (if (and (list? s)
               (= (length s) 2)
               (symbol? (first s)))
          (make-e-app (parse-v1 (first s)) (parse-v1 (second s)))
          (error "invalid s-expression for function application " s))))

(check-expect (parse-app-v1 '((λ (x) x) 1))
              (make-e-app (make-e-lam 'x
                                      (make-e-var 'x))
                          (make-e-num 1)))
(check-expect (parse-app-v1 '((λ (x) (+ x 1)) 10))
              (make-e-app (make-e-lam 'x
                                      (make-e-op '+ (make-e-var 'x) (make-e-num 1)))
                          (make-e-num 10)))
(check-expect (parse-app-v1 '(x 10))
              (make-e-app (make-e-var 'x) (make-e-num 10)))

; Exp examples
(define EX-1 (parse-v1 '(+ 1 2)))
(define EX-2 (parse-v1 '(* (- 1 2) (/ 3 4))))
(define EX-3 (parse-v1 '(lambda (x) (+ x 1))))
(define EX-4 (parse-v1 '((lambda (x) x) 10)))

(: subst-v1 (ExprV1 ExprV1 Var -> ExprV1))
; Given an expression, replaces all occurances of var with the value val
(define (subst-v1 expr val var)
  ; replace the Var with the Symbol that it contains
  ; and keep the previous function as-is inside
  (let ([v (e-var-sym var)])
    (cond
      [(e-var? expr) (if (symbol=? (e-var-sym expr) v)
                         val
                         expr)]
      [(e-op? expr) (make-e-op (e-op-op expr)
                               (subst-v1 (e-op-left expr) val var)
                               (subst-v1 (e-op-right expr) val var))]
      [(e-num? expr) expr]
      [(e-lam? expr) (if (symbol=? (e-lam-param expr) v)
                         expr
                         (make-e-lam (e-lam-param expr)
                                     (subst-v1 (e-lam-body expr) val var)))]
      [(e-app? expr) (make-e-app (subst-v1 (e-app-fun expr) val var)
                                 (subst-v1 (e-app-arg expr) val var))])))

(check-expect (subst-v1 (parse-v1 1) (parse-v1 2) (parse-v1 'x)) (parse-v1 1))
(check-expect (subst-v1 (parse-v1 'x) (parse-v1 2) (parse-v1 'x)) (parse-v1 2))
(check-expect (subst-v1 (parse-v1 '(lambda (x) x)) (parse-v1 2) (parse-v1 'x)) (parse-v1 '(lambda (x) x)))
(check-expect (subst-v1 (parse-v1 '(lambda (y) x)) (parse-v1 2) (parse-v1 'x)) (parse-v1 '(lambda (y) 2)))
(check-expect (subst-v1 (parse-v1 '(+ ((lambda (x) y) y) y)) (parse-v1 2) (parse-v1 'y)) (parse-v1 '(+ ((lambda (x) 2) 2) 2)))
(check-expect (subst-v1 (parse-v1 '(+ ((lambda (p) ((lambda (r) (+ (* r p) x)) x)) y) x)) (parse-v1 10) (parse-v1 'x))
              (parse-v1 '(+ ((lambda (p) ((lambda (r) (+ (* r p) 10)) 10)) y) 10)))

(: eval-v1 (ExprV1 -> ValV1))
; Evaluates an expression just like ISL, but does not verify that
; all variables inside it are bound.
(define (eval-v1 expr)
  (cond
    [(e-var? expr) (error "Tried to evaluate, but ran into a variable")]
    [(e-op? expr) (make-e-num ((op-convert (e-op-op expr))
                               (e-num-num (eval-v1 (e-op-left expr)))
                               (e-num-num (eval-v1 (e-op-right expr)))))]
    [(e-num? expr) expr]
    [(e-lam? expr) expr]
    [(and (e-app? expr)
          (e-lam? (e-app-fun expr)))
     (eval-v1 (subst-v1 (e-lam-body (e-app-fun expr))
                        (eval-v1 (e-app-arg expr))
                        (make-e-var (e-lam-param (e-app-fun expr)))))]
    [(and (e-app? expr)
          (e-app? (e-app-fun expr)))
     (eval-v1 (make-e-app (eval-v1 (e-app-fun expr))
                          (e-app-arg expr)))]))

(check-expect (eval-v1 (parse-v1 '(+ 1 2))) (parse-v1 3))
(check-expect (eval-v1 (parse-v1 '((lambda (y)
                                     (+ ((lambda (x) (+ x y))
                                         4)
                                        2))
                                   -9)))
              (parse-v1 -3))
(check-error (eval-v1 (parse-v1 '((lambda (x) (+ x y)) 2))))
(check-expect (eval-v1 (parse-v1 '(lambda (x) (+ x 2503791))))
              (parse-v1 '(lambda (x) (+ x 2503791))))
(check-expect (eval-v1 (parse-v1 '(((lambda (x) (lambda (x) (* x 10))) 2) 3)))
              (parse-v1 30))
(check-expect (eval-v1 (parse-v1 '((lambda (x) (x 5)) (lambda (y) (+ y 2))))) (parse-v1 7))
(check-expect (eval-v1 (parse-v1 '(((lambda (x) (lambda (x) (* x 10))) 2) 3))) (parse-v1 30))

(: wf-v1 (ExprV1 -> ExprV1))
; Finds all unbound variables, where a variable is used before it is
; defined. Either returns the error with the variables, or the same
; expression that was passed in
(define (wf-v1 exp)
  (local [(define (wf-v1/acc exp acc)
            (cond
              [(e-var? exp) (if (member? (e-var-sym exp) acc)
                                '()
                                (list (e-var-sym exp)))]
              [(e-op? exp) (append (wf-v1/acc (e-op-left exp) acc)
                                   (wf-v1/acc (e-op-right exp) acc))]
              [(e-num? exp) '()]
              [(e-lam? exp) (wf-v1/acc (e-lam-body exp) (cons (e-lam-param exp) acc))]
              [(e-app? exp)
               (append
                (wf-v1/acc (e-app-fun exp) acc)
                (wf-v1/acc (e-app-arg exp) acc))]))]
    (let ([errors (wf-v1/acc exp '())])
      (if (empty? errors)
          exp
          (error "Unbound variables found: " errors)))))

(check-error (wf-v1 (parse-v1 '(lambda (x) y))))
(check-expect (wf-v1 (parse-v1 '(lambda (x) x))) (parse-v1 '(lambda (x) x)))
(check-error (wf-v1 (parse-v1 '((lambda (x) x) y))))


;;;;;;;;;;;
; V2 CODE ;
;;;;;;;;;;;

(: parse-v2 (SExp -> ExprV2))
(define (parse-v2 s)
  (cond [(number? s) (make-e-num s)]
        [(symbol? s) (if (not (op? s))
                         (make-e-var s)
                         (error "use of numerical operator where identifier expected " s))]
        [(cons? s) (cond [(op? (first s)) (parse-op-v2 s)]
                         [(memq? (first s) '(lambda λ)) (parse-lamb-v2 s)]
                         [(eq? (first s) 'set!) (parse-set-v2 s)]
                         [(eq? (first s) 'loc) (parse-loc-v2 s)]
                         [else (parse-app-v2 s)])] ; must be an application, or invalid
        [else (error "invalid s-expression " s)]))

(check-expect (parse-v2 '(+ 1 2)) (make-e-op '+ (make-e-num 1) (make-e-num 2)))
(check-expect (parse-v2 '(* (- 1 2) (/ 3 4)))
              (make-e-op '* (make-e-op '- (make-e-num 1) (make-e-num 2)) (make-e-op '/ (make-e-num 3) (make-e-num 4))))
(check-expect (parse-v2 '(lambda (x) (+ x 1)))
              (make-e-lam 'x (make-e-op '+ (make-e-var 'x) (make-e-num 1))))
(check-expect (parse-v2 '((lambda (x) x) 10))
              (make-e-app (make-e-lam 'x (make-e-var 'x)) (make-e-num 10)))
(check-expect (parse-v2 '((lambda (x) (x 2)) (lambda (y) (+ y 1))))
              (make-e-app (make-e-lam 'x (make-e-app (make-e-var 'x) (make-e-num 2)))
                          (make-e-lam 'y (make-e-op '+ (make-e-var 'y) (make-e-num 1)))))

(: parse-op-v2 (SExp -> Operation))
; parse a given S-expression into an Operation
(define (parse-op-v2 s)
  (if (and (list? s)
           (= (length s) 3)
           (op? (first s)))
      (make-e-op (first s) (parse-v2 (second s)) (parse-v2 (third s)))
      (error "invalid s-expression for operation " s)))

(check-expect (parse-op-v2 '(+ 1 1)) (make-e-op '+ (make-e-num 1) (make-e-num 1)))
(check-expect (parse-op-v2 '(* x 3)) (make-e-op '*  (make-e-var 'x) (make-e-num 3)))
(check-expect (parse-op-v2 '(- (+ 1 1) (/ 10 8)))
              (make-e-op '-
                         (make-e-op '+ (make-e-num 1) (make-e-num 1))
                         (make-e-op '/ (make-e-num 10) (make-e-num 8))))

(: parse-lamb-v2 (SExp -> Lambda))
; parse a given S-expression into a Lambda
(define (parse-lamb-v2 s)
  (if (and (list? s)
           (= (length s) 3)
           (memq? (first s) '(λ lambda))
           ; conditions for argument
           (list? (second s))
           (= (length (second s)) 1)
           (symbol? (first (second s))))
      (make-e-lam (first (second s)) (parse-v2 (third s)))
      (error "invalid s-expression for lambda " s)))

(check-expect (parse-lamb-v1 '(lambda (x) x))
              (make-e-lam 'x (make-e-var 'x)))
(check-expect (parse-lamb-v1 '(λ (x) (+ x 1)))
              (make-e-lam 'x (make-e-op '+ (make-e-var 'x) (make-e-num 1))))
(check-expect (parse-lamb-v1 '(lambda (x) (lambda (y) (+ x y))))
              (make-e-lam 'x (make-e-lam 'y (make-e-op '+ (make-e-var 'x) (make-e-var 'y)))))

(: parse-app-v2 (SExp -> Application))
; parse a given S-expression into a function application
(define (parse-app-v2 s)
  (if (and (list? s)
           (= (length s) 2))
      (make-e-app (parse-v2 (first s)) (parse-v2 (second s)))
      (error "invalid s-expression for function application " s)))

(check-expect (parse-app-v2 '((λ (x) x) 1))
              (make-e-app (make-e-lam 'x
                                      (make-e-var 'x))
                          (make-e-num 1)))
(check-expect (parse-app-v2 '((λ (x) (+ x 1)) 10))
              (make-e-app (make-e-lam 'x
                                      (make-e-op '+ (make-e-var 'x) (make-e-num 1)))
                          (make-e-num 10)))
(check-expect (parse-app-v2 '(x 10))
              (make-e-app (make-e-var 'x) (make-e-num 10)))

(: parse-set-v2 (SExp -> Set))
; parse a given S-expression into a set!
(define (parse-set-v2 s)
  (if (and (list? s)
           (= (length s) 3)
           (symbol=? (first s) 'set!))
      (make-e-set! (parse-v2 (second s)) (parse-v2 (third s)))
      (error "invalid s-expression for set! " s)))

(check-expect (parse-set-v2 '(set! x 5))
              (make-e-set! (make-e-var 'x) (make-e-num 5)))
(check-expect (parse-set-v2 '(set! y (+ 4 1)))
              (make-e-set! (make-e-var 'y) (make-e-op '+ (make-e-num 4) (make-e-num 1))))

(: parse-loc-v2 (SExp -> Loc))
; parse a given S-expression into a Loc
(define (parse-loc-v2 s)
  (if (and (list? s)
           (= (length s) 2)
           (eq? (first s) 'loc)
           (symbol? (second s))
           (string=? (substring (symbol->string (second s)) 0 3) "loc"))
      (make-e-loc (second s))
      (error "invalid s-expression for loc " s)))

; TODO: tests

(: subst-v2 (ExprV2 Loc Var -> ExprV2))
; Given an expression, replaces all occurances of var with the value val
(define (subst-v2 expr val var)
  ; replace the Var with the Symbol that it contains
  ; and keep the previous function as-is inside
  (let ([v (e-var-sym var)])
    (cond
      [(e-var? expr) (if (symbol=? (e-var-sym expr) v)
                         val
                         expr)]
      [(e-loc? expr) expr]
      [(e-op? expr) (make-e-op (e-op-op expr)
                               (subst-v2 (e-op-left expr) val var)
                               (subst-v2 (e-op-right expr) val var))]
      [(e-num? expr) expr]
      [(e-lam? expr) (if (symbol=? (e-lam-param expr) v)
                         expr
                         (make-e-lam (e-lam-param expr)
                                     (subst-v2 (e-lam-body expr) val var)))]
      [(e-app? expr) (make-e-app (subst-v2 (e-app-fun expr) val var)
                                 (subst-v2 (e-app-arg expr) val var))]
      [(e-set!? expr) (make-e-set! (subst-v2 (e-set!-id expr) val var) (subst-v2 (e-set!-arg expr) val var))])))

(check-expect (subst-v2 (parse-v2 '(+ (set! x x) x)) (make-e-loc 'loc15) (parse-v2 'x))
              (parse-v2 '(+ (set! (loc loc15) (loc loc15)) (loc loc15))))
(check-expect (subst-v2 (parse-v2 '(lambda (x) (+ x 5))) (make-e-loc 'loc150152) (parse-v2 'x))
              (parse-v2 '(lambda (x) (+ x 5))))
(check-expect (subst-v2 (parse-v2 '((lambda (x) (+ x 5)) x)) (make-e-loc 'loc150152) (parse-v2 'x))
              (parse-v2 '((lambda (x) (+ x 5)) (loc loc150152))))
(check-expect (subst-v2 (parse-v2 '((lambda (x) (+ x 5)) (loc loc25))) (make-e-loc 'loc150152) (parse-v2 'x))
              (parse-v2 '((lambda (x) (+ x 5)) (loc loc25))))

(: wf-v2 (ExprV2 -> ExprV2))
; Finds all unbound variables, where a variable is used before it is
; defined. Either returns the error with the variables, or the same
; expression that was passed in
(define (wf-v2 exp)
  (local [(define (wf-v2/acc exp acc)
            (cond
              [(e-var? exp) (if (member? (e-var-sym exp) acc)
                                '()
                                (list (e-var-sym exp)))]
              [(e-op? exp) (append (wf-v2/acc (e-op-left exp) acc)
                                   (wf-v2/acc (e-op-right exp) acc))]
              [(e-num? exp) '()]
              [(e-lam? exp) (wf-v2/acc (e-lam-body exp) (cons (e-lam-param exp) acc))]
              [(e-app? exp)
               (append
                (wf-v2/acc (e-app-fun exp) acc)
                (wf-v2/acc (e-app-arg exp) acc))]
              [(e-set!? exp) (append
                              (if (member? (e-var-sym (e-set!-id exp)) acc)
                                  '()
                                  (list (e-set!-id exp)))
                              (wf-v2/acc (e-set!-arg exp) acc))]))]
    (let ([errors (wf-v2/acc exp '())])
      (if (empty? errors)
          exp
          (error "Unbound variables found: " errors)))))

(check-error (wf-v2 (parse-v2 '(lambda (x) y))))
(check-expect (wf-v2 (parse-v2 '(lambda (x) x))) (parse-v2 '(lambda (x) x)))
(check-error (wf-v2 (parse-v2 '((lambda (x) x) y))))
(check-expect (wf-v2 (parse-v2 '(lambda (x) (+ (set! x 1) 1))))
              (parse-v2 '(lambda (x) (+ (set! x 1) 1))))
(check-error (wf-v2 (parse-v2 '(+ (set! x 1) 1))))
(check-error (wf-v2 (parse-v2 '(lambda (x) (+ (set! x y) 1)))))

(: eval-v2 (ExprV2 Store -> Result))
; Evaluates an expression just like ISL, but does not verify that
; all variables inside it are bound.

(define (eval-v2 expr store)
  (cond
    [(e-var? expr) (error "Tried to evaluate, but ran into a variable")]
    [(e-loc? expr) (make-res store (hash-ref store (e-loc-sym expr)))]
    [(e-op? expr) (let* ([frst (eval-v2 (e-op-left expr) store)]
                         [scnd (eval-v2 (e-op-right expr) (res-store frst))])
                    (make-res
                     (res-store scnd)
                     (make-e-num ((op-convert (e-op-op expr))
                                  (e-num-num (res-val frst))
                                  (e-num-num (res-val scnd))))))]
    [(e-num? expr) (make-res store expr)]
    [(e-lam? expr) (make-res store expr)]
    [(and (e-app? expr)
          (e-lam? (e-app-fun expr)))
     (let ([h (gensym "loc")])
       (eval-v2
        (subst-v2 (e-lam-body (e-app-fun expr))
                  (make-e-loc h)
                  (make-e-var (e-lam-param (e-app-fun expr))))
        (hash-set
         store
         h
         (res-val (eval-v2 (e-app-arg expr) store)))))]
    [(e-app? expr)
     (eval-v2 (make-e-app (res-val (eval-v2 (e-app-fun expr) store))
                          (e-app-arg expr))
              store)]
    [(e-set!? expr)
     (make-res (hash-set
                store
                (e-loc-sym (e-set!-id expr))
                (if (e-loc? (e-set!-arg expr))
                    (hash-ref store (e-loc-sym (e-set!-arg expr)))
                    (e-set!-arg expr)))
                (make-e-num 0))]))


(check-expect (res-val (eval-v2 (parse-v2 '(+ 1 2)) (hash))) (parse-v2 3))
(check-expect (res-val (eval-v2 (parse-v2 '((lambda (x) x) 2)) (hash))) (parse-v2 2))
(check-expect (res-val (eval-v2 (parse-v2 '((lambda (y)
                                              (+ ((lambda (x) (+ x y))
                                                  4)
                                                 2))
                                            -9)) (hash)))
              (parse-v2 -3))
(check-error (eval-v2 (parse-v2 '((lambda (x) (+ x y)) 2)) (hash)))
(check-expect (res-val (eval-v2 (parse-v2 '(lambda (x) (+ x 2503791))) (hash)))
              (parse-v2 '(lambda (x) (+ x 2503791))))
(check-expect (res-val (eval-v2 (parse-v2 '(((lambda (x) (lambda (x) (* x 10))) 2) 3)) (hash)))
              (parse-v2 30))
(check-expect (res-val (eval-v2 (parse-v2 '((lambda (x) (x 5)) (lambda (y) (+ y 2)))) (hash))) (parse-v2 7))
(check-expect (res-val (eval-v2 (parse-v2 '(((lambda (x) (lambda (x) (* x 10))) 2) 3)) (hash))) (parse-v2 30))
(check-expect (res-val (eval-v2 (parse-v2 '((lambda (x) (+ (set! x 1) x)) 2)) (hash))) (parse-v2 1))
(check-expect (res-val (eval-v2 (parse-v2 '(((λ (x) (λ (y) (+ (+ (set! x 2) (set! y x)) (* x y)))) 2) 3))
                                (hash)))
                       (parse-v2 4))

;;;;;;;;;;;
; V3 CODE ;
;;;;;;;;;;;

(: parse-v3 (SExp -> ExprV3))
(define (parse-v3 s)
  (cond [(number? s) (make-e-num s)]
        [(symbol? s) (if (not (op? s))
                         (make-e-var s)
                         (error "use of numerical operator where identifier expected " s))]
        [(cons? s) (cond [(op? (first s)) (parse-op-v3 s)]
                         [(memq? (first s) '(lambda λ)) (parse-lamb-v3 s)]
                         [(eq? (first s) 'set!) (parse-set-v3 s)]
                         [(eq? (first s) 'box) (parse-box-v3 s)]
                         [(eq? (first s) 'set-box!) (parse-set-box-v3 s)]
                         [(eq? (first s) 'unbox) (parse-unbox-v3 s)]
                         [(eq? (first s) 'loc) (parse-loc-v3 s)]
                         [(eq? (first s) 'bloc) (parse-box-loc-v3 s)]
                         [else (parse-app-v3 s)])] ; must be an application, or invalid
        [else (error "invalid s-expression " s)]))

(check-expect (parse-v3 '(+ 1 2)) (make-e-op '+ (make-e-num 1) (make-e-num 2)))
(check-expect (parse-v3 '(* (- 1 2) (/ 3 4)))
              (make-e-op '* (make-e-op '- (make-e-num 1) (make-e-num 2)) (make-e-op '/ (make-e-num 3) (make-e-num 4))))
(check-expect (parse-v3 '(lambda (x) (+ x 1)))
              (make-e-lam 'x (make-e-op '+ (make-e-var 'x) (make-e-num 1))))
(check-expect (parse-v3 '((lambda (x) x) 10))
              (make-e-app (make-e-lam 'x (make-e-var 'x)) (make-e-num 10)))
(check-expect (parse-v3 '((lambda (x) (x 2)) (lambda (y) (+ y 1))))
              (make-e-app (make-e-lam 'x (make-e-app (make-e-var 'x) (make-e-num 2)))
                          (make-e-lam 'y (make-e-op '+ (make-e-var 'y) (make-e-num 1)))))

(: parse-op-v3 (SExp -> Operation))
; parse a given S-expression into an Operation
(define (parse-op-v3 s)
  (if (and (list? s)
           (= (length s) 3)
           (op? (first s)))
      (make-e-op (first s) (parse-v3 (second s)) (parse-v3 (third s)))
      (error "invalid s-expression for operation " s)))

(check-expect (parse-op-v3 '(+ 1 1)) (make-e-op '+ (make-e-num 1) (make-e-num 1)))
(check-expect (parse-op-v3 '(* x 3)) (make-e-op '*  (make-e-var 'x) (make-e-num 3)))
(check-expect (parse-op-v3 '(- (+ 1 1) (/ 10 8)))
              (make-e-op '-
                         (make-e-op '+ (make-e-num 1) (make-e-num 1))
                         (make-e-op '/ (make-e-num 10) (make-e-num 8))))

(: parse-lamb-v3 (SExp -> Lambda))
; parse a given S-expression into a Lambda
(define (parse-lamb-v3 s)
  (if (and (list? s)
           (= (length s) 3)
           (memq? (first s) '(λ lambda))
           ; conditions for argument
           (list? (second s))
           (= (length (second s)) 1)
           (symbol? (first (second s))))
      (make-e-lam (first (second s)) (parse-v3 (third s)))
      (error "invalid s-expression for lambda " s)))

(check-expect (parse-lamb-v1 '(lambda (x) x))
              (make-e-lam 'x (make-e-var 'x)))
(check-expect (parse-lamb-v1 '(λ (x) (+ x 1)))
              (make-e-lam 'x (make-e-op '+ (make-e-var 'x) (make-e-num 1))))
(check-expect (parse-lamb-v1 '(lambda (x) (lambda (y) (+ x y))))
              (make-e-lam 'x (make-e-lam 'y (make-e-op '+ (make-e-var 'x) (make-e-var 'y)))))

(: parse-app-v3 (SExp -> Application))
; parse a given S-expression into a function application
(define (parse-app-v3 s)
  (if (and (list? s)
           (= (length s) 2))
      (make-e-app (parse-v3 (first s)) (parse-v3 (second s)))
      (error "invalid s-expression for function application " s)))

(check-expect (parse-app-v3 '((λ (x) x) 1))
              (make-e-app (make-e-lam 'x
                                      (make-e-var 'x))
                          (make-e-num 1)))
(check-expect (parse-app-v3 '((λ (x) (+ x 1)) 10))
              (make-e-app (make-e-lam 'x
                                      (make-e-op '+ (make-e-var 'x) (make-e-num 1)))
                          (make-e-num 10)))
(check-expect (parse-app-v3 '(x 10))
              (make-e-app (make-e-var 'x) (make-e-num 10)))

(: parse-set-v3 (SExp -> Set))
; parse a given S-expression into a set!
(define (parse-set-v3 s)
  (if (and (list? s)
           (= (length s) 3)
           (symbol=? (first s) 'set!))
      (make-e-set! (parse-v3 (second s)) (parse-v3 (third s)))
      (error "invalid s-expression for set! " s)))

(check-expect (parse-set-v3 '(set! x 5))
              (make-e-set! (make-e-var 'x) (make-e-num 5)))
(check-expect (parse-set-v3 '(set! y (+ 4 1)))
              (make-e-set! (make-e-var 'y) (make-e-op '+ (make-e-num 4) (make-e-num 1))))

(: parse-loc-v3 (SExp -> Loc))
; parse a given S-expression into a Loc
(define (parse-loc-v3 s)
  (if (and (list? s)
           (= (length s) 2)
           (eq? (first s) 'loc)
           (symbol? (second s))
           (string=? (substring (symbol->string (second s)) 0 3) "loc"))
      (make-e-loc (second s))
      (error "invalid s-expression for loc " s)))

(: parse-box-loc-v3 (SExp -> BoxLoc))
; parsea given S-expression into a BoxLoc
(define (parse-box-loc-v3 s)
  (if (and (list? s)
           (= (length s) 2)
           (eq? (first s) 'bloc)
           (symbol? (second s))
           (string=? (substring (symbol->string (second s)) 0 4) "bloc"))
      (make-e-box-loc (second s))
      (error "invalid s-expression for boxloc " s)))

; TODO: tests

(: parse-box-v3 (SExp -> Box))
; parse a given S-expression into a Box
(define (parse-box-v3 s)
  (if (and (list? s)
           (= (length s) 2)
           (eq? (first s) 'box))
      (make-e-box (parse-v3 (second s)))
      (error "invalid s-expression for box " s)))

(: parse-set-box-v3 (SExp -> SetBox))
; parse a given S-expression into a SetBox
(define (parse-set-box-v3 s)
  (if (and (list? s)
           (= (length s) 3)
           (eq? (first s) 'set-box!))
      (make-e-set-box (parse-v3 (second s)) (parse-v3 (third s)))
      (error "invalid s-expression for set-box! " s)))

(: parse-unbox-v3 (SExp -> Unbox))
; parse a given S-expression into an Unbox
(define (parse-unbox-v3 s)
  (if (and (list? s)
           (= (length s) 2)
           (eq? (first s) 'unbox))
      (make-e-unbox (parse-v3 (second s)))
      (error "invalid s-expression for unbox " s)))

(: subst-v3 (ExprV3 (mixed Loc BoxLoc) Var -> ExprV3))
; Given an expression, replaces all occurances of var with the value val
(define (subst-v3 expr val var)
  ; replace the Var with the Symbol that it contains
  ; and keep the previous function as-is inside
  (let ([v (e-var-sym var)])
    (cond
      [(e-var? expr) (if (symbol=? (e-var-sym expr) v)
                         val
                         expr)]
      [(e-loc? expr) expr]
      [(e-op? expr) (make-e-op (e-op-op expr)
                               (subst-v3 (e-op-left expr) val var)
                               (subst-v3 (e-op-right expr) val var))]
      [(e-num? expr) expr]
      [(e-lam? expr) (if (symbol=? (e-lam-param expr) v)
                         expr
                         (make-e-lam (e-lam-param expr)
                                     (subst-v3 (e-lam-body expr) val var)))]
      [(e-app? expr) (make-e-app (subst-v3 (e-app-fun expr) val var)
                                 (subst-v3 (e-app-arg expr) val var))]
      [(e-set!? expr) (make-e-set! (subst-v3 (e-set!-id expr) val var)
                                   (subst-v3 (e-set!-arg expr) val var))]
      [(e-set-box? expr) (make-e-set-box (subst-v3 (e-set-box-id expr) val var)
                                         (subst-v3 (e-set-box-arg expr) val var))]
      [(e-unbox? expr) (make-e-unbox (subst-v3 (e-unbox-sym expr) val var))]
      [(e-box? expr) (make-e-box (subst-v3 (e-box-val expr) val var))]
      [(e-box-loc? expr) expr])))

(check-expect (subst-v3 (parse-v3 '(+ (set! x x) x)) (make-e-loc 'loc15) (parse-v3 'x))
              (parse-v3 '(+ (set! (loc loc15) (loc loc15)) (loc loc15))))
(check-expect (subst-v3 (parse-v3 '(lambda (x) (+ x 5))) (make-e-loc 'loc150152) (parse-v3 'x))
              (parse-v3 '(lambda (x) (+ x 5))))
(check-expect (subst-v3 (parse-v3 '((lambda (x) (+ x 5)) x)) (make-e-loc 'loc150152) (parse-v3 'x))
              (parse-v3 '((lambda (x) (+ x 5)) (loc loc150152))))
(check-expect (subst-v3 (parse-v3 '((lambda (x) (+ x 5)) (loc loc25))) (make-e-loc 'loc150152) (parse-v3 'x))
              (parse-v3 '((lambda (x) (+ x 5)) (loc loc25))))

(: wf-v3 (ExprV3 -> ExprV3))
; Finds all unbound variables, where a variable is used before it is
; defined. Either returns the error with the variables, or the same
; expression that was passed in
(define (wf-v3 exp)
  (local [(define (wf-v3/acc exp acc)
            (cond
              [(e-var? exp) (if (member? (e-var-sym exp) acc)
                                '()
                                (list (e-var-sym exp)))]
              [(e-op? exp) (append (wf-v3/acc (e-op-left exp) acc)
                                   (wf-v3/acc (e-op-right exp) acc))]
              [(e-num? exp) '()]
              [(e-lam? exp) (wf-v3/acc (e-lam-body exp) (cons (e-lam-param exp) acc))]
              [(e-app? exp)
               (append
                (wf-v3/acc (e-app-fun exp) acc)
                (wf-v3/acc (e-app-arg exp) acc))]
              [(e-set!? exp) (append
                              (if (member? (e-var-sym (e-set!-id exp)) acc)
                                  '()
                                  (list (e-set!-id exp)))
                              (wf-v3/acc (e-set!-arg exp) acc))]
              [(e-set-box? exp) (append
                                 (if (member? (e-var-sym (e-set-box-id exp)) acc)
                                     '()
                                     (list (e-set-box-id exp)))
                                 (wf-v3/acc (e-set-box-arg exp) acc))]))]
    (let ([errors (wf-v3/acc exp '())])
      (if (empty? errors)
          exp
          (error "Unbound variables found: " errors)))))

(check-error (wf-v3 (parse-v3 '(lambda (x) y))))
(check-expect (wf-v3 (parse-v3 '(lambda (x) x))) (parse-v3 '(lambda (x) x)))
(check-error (wf-v3 (parse-v3 '((lambda (x) x) y))))
(check-expect (wf-v3 (parse-v3 '(lambda (x) (+ (set! x 1) 1))))
              (parse-v3 '(lambda (x) (+ (set! x 1) 1))))
(check-error (wf-v3 (parse-v3 '(+ (set! x 1) 1))))
(check-error (wf-v3 (parse-v3 '(lambda (x) (+ (set! x y) 1)))))

(: eval-v3 (ExprV3 Store -> Result))
; Evaluates an expression just like ISL, but does not verify that
; all variables inside it are bound.
(define (eval-v3 expr store)
  (cond
    [(e-var? expr) (error "Tried to evaluate, but ran into a variable")]
    [(e-loc? expr) (make-res store (hash-ref store (e-loc-sym expr)))]
    [(e-box-loc? expr) (make-res store expr)]
    [(e-op? expr) (let* ([frst (eval-v3 (e-op-left expr) store)]
                         [scnd (eval-v3 (e-op-right expr) (res-store frst))])
                    (make-res
                     (res-store scnd)
                     (make-e-num ((op-convert (e-op-op expr))
                                  (e-num-num (res-val frst))
                                  (e-num-num (res-val scnd))))))]
    [(e-num? expr) (make-res store expr)]
    [(e-lam? expr) (make-res store expr)]
    [(and (e-app? expr)
          (e-lam? (e-app-fun expr)))
     (let* ([ar (eval-v3 (e-app-arg expr) store)]
            [h (if (e-box-loc? (res-val ar))
                   (e-box-loc-sym (res-val ar))
                   (gensym "loc"))])
       (eval-v3
        (subst-v3 (e-lam-body (e-app-fun expr))
                  ((if (e-box? (e-app-arg expr))
                       make-e-box-loc
                       make-e-loc)
                   h)
                  (make-e-var (e-lam-param (e-app-fun expr))))
        
        (if (e-box? (e-app-arg expr))
            (res-store ar)
            (hash-set
             store
             h
             (res-val ar)))))]
    [(e-app? expr)
     (eval-v3 (make-e-app (res-val (eval-v3 (e-app-fun expr) store))
                          (e-app-arg expr))
              store)]
    [(e-set!? expr)
     (make-res (hash-set
                store
                ((if (e-loc? (e-set!-id expr))
                     e-loc-sym
                     e-box-loc-sym)
                 (e-set!-id expr))
                (cond
                  [(e-loc? (e-set!-arg expr)) (hash-ref store (e-loc-sym (e-set!-arg expr)))]
                  [(e-box-loc? (e-set!-arg expr)) (hash-ref store (e-box-loc-sym (e-set!-arg expr)))]
                  [else (e-set!-arg expr)]))
               (make-e-num 0))]
    [(e-set-box? expr) (make-res (hash-set
                                  store
                                  (e-box-loc-sym (e-set-box-id expr))
                                  (if (e-loc? (e-set-box-arg expr))
                                      (hash-ref store (e-loc-sym (e-set-box-arg expr)))
                                      (e-set-box-arg expr)))
                                 (make-e-num 0))]
    [(e-unbox? expr)
     (let ([e (eval-v3 (e-unbox-sym expr) store)])
       (make-res
        (res-store e)
        (hash-ref (res-store e) (e-box-loc-sym (res-val e)))))]
    [(e-box? expr) (let ([h (gensym "bloc")]
                         [v (eval-v3 (e-box-val expr) store)])
                     (make-res (hash-set (res-store v)
                                        h
                                        (res-val v))
                               (make-e-box-loc h)))]))

;v2 tested all non-box features
(check-expect (res-val (eval-v3 (parse-v3 '(unbox (box 1))) (hash))) (make-e-num 1))
(check-expect (res-val (eval-v3 (parse-v3 '((lambda (x) (unbox x)) (box 1))) (hash))) (make-e-num 1))
(check-expect (res-val (eval-v3 (parse-v3 '((lambda (x) (+ (+ (unbox x) (set-box! x 2)) (unbox x))) (box 1))) (hash))) (make-e-num 3))
;(check-expect (res-val (eval-v3 (parse-v3 '()) (hash))) )
(check-expect (res-val (eval-v3 (parse-v3 '((lambda (x) (unbox x)) (box 2))) (hash)))
              (make-e-num 2))
(check-expect (res-val (eval-v3 (parse-v3 '((lambda (x) (+ (set-box! x 4) (unbox x))) (box 2))) (hash)))
              (make-e-num 4))
(check-error (res-val (eval-v3 (parse-v3 '((lambda (x) (+ (set-box! x 5) x)) (box 1))) (hash))))
(check-expect (res-val (eval-v3 (parse-v3 '((lambda (x) (unbox (box x))) 1)) (hash)))
              (make-e-num 1))
(check-expect (res-val (eval-v3 (parse-v3 '(unbox (unbox (box (box 1))))) (hash))) (make-e-num 1))
(check-expect (res-val (eval-v3 (parse-v3 '((lambda (y) (+ (unbox (box ((lambda (z) (+ (set-box! y 9)
                                                                                       z))
                                                                        9)))
                                                           (unbox y)))
                                            (box 1)))
                                (hash)))
              (make-e-num 18))
(check-expect (res-val (eval-v3 (parse-v3 '((lambda (x) ((lambda (y) (+ (set-box! x 2)
                                                                        (+ (unbox (unbox y))
                                                                           (+ (set-box! y 3)
                                                                              (+ (unbox y)
                                                                                 (unbox x))))))
                                                         (box x)))
                                            (box 1)))
                                (hash)))
              (make-e-num 7))
(check-expect (res-val (eval-v3 (parse-v3 '((lambda (x) (+ (set-box! x 5)
                                                           ((lambda (y) (+ (set! y x)
                                                                           (unbox y)))
                                                            (box 2))))
                                            (box 9)))
                                (hash)))
              (make-e-num 5))
(check-expect (res-val (eval-v3 (parse-v3 '((lambda (x) (+ (set-box! x 5)
                                                           ((lambda (y) (+ (set-box! y x)
                                                                           (unbox (unbox y))))
                                                            (box 2))))
                                            (box 9)))
                                (hash)))
              (make-e-num 5))
(check-expect (res-val (eval-v3 (parse-v3 '((lambda (x) ((lambda (y) (+ (set-box! y x)
                                                                        (unbox y)))
                                                         (box 1)))
                                            2))
                                (hash)))
              (make-e-num 2))
(check-expect (res-val (eval-v3 (parse-v3 '((lambda (x) (+ (set-box! x 5)
                                                           ((lambda (y) (+ (set! y x)
                                                                           (+ (set-box! y 7)
                                                                              (unbox x))))
                                                            (box 2))))
                                            (box 9)))
                                (hash)))
              (make-e-num 7))
(check-expect (res-val (eval-v3 (parse-v3 '((lambda (x) (+ (set-box! x 5)
                                                           ((lambda (y) (+ (set! y x)
                                                                           (+ (set-box! x 7)
                                                                              (unbox y))))
                                                            (box 2))))
                                            (box 9)))
                                (hash)))
              (make-e-num 7))
(check-expect (res-val (eval-v3 (parse-v3 'balls (hash)))) 'balls)