#lang htdp/asl
(require deinprogramm/signature/signature)
 
(define (BoxOf T)
  (signature (predicate (lambda (v) (and (box? v) (not (false? (apply-signature T (unbox v)))))))))

; Exercise 1

(: make-incrementer-1 (-> (Number -> Number)))
(define make-incrementer-1
  (let ([mem (box 0)])
    (lambda ()
      (lambda (inc)
        (begin
          (set-box! mem (+ inc (unbox mem)))
          (unbox mem))))))
 
(: make-incrementer-2 (-> (Number -> Number)))
(define make-incrementer-2
  (lambda ()
    (let ([mem (box 0)])
      (lambda (inc)
        (begin
          (set-box! mem (+ inc (unbox mem)))
          (unbox mem))))))

(: incrementer-distinguish ((-> (Number -> Number)) -> Number))
(define (incrementer-distinguish f)
  (begin
    ((f) 5)
    ((f) 5)))

(check-expect (not (equal? (incrementer-distinguish make-incrementer-1)
                           (incrementer-distinguish make-incrementer-2)))
              #t)

; Exercise 2

(: box-magic ([BoxOf Number] [BoxOf Number] -> [ListOf Number]))
; increments each input by 1, producing a list of their unboxed outputs
(define (box-magic b1 b2)
  (let ([newb1 (add1 (unbox b1))])
  (begin (set-box! b2 (add1 (unbox b2)))
         (set-box! b1 newb1)
         (list (unbox b1) (unbox b2)))))


(define box1 (box 1))
(define box2 (box 2))
(check-expect (box-magic box1 box1)
              (list (add1 (unbox box1)) (add1 (unbox box1))))


(define (check B1 B2)
  (equal? (list (add1 (unbox B1)) (add1 (unbox B2)))
          (box-magic B1 B2)))

; Exercise 3

(: muter-1 ([BoxOf Number] -> Number))
(define (muter-1 v)
  (local [(define the-v v)]
    (begin (set-box! the-v (add1 (unbox the-v)))
           (unbox the-v))))
(: muter-2 ([BoxOf Number] -> Number))
(define (muter-2 v)
  (local [(define the-v v)]
    (begin (set! the-v (box (add1 (unbox the-v))))
           (unbox the-v))))

(define (muter-distinguish m)
  (let ([bx (box 5)])
  (begin (m bx)
         (m bx)
         (unbox bx))))

(check-expect (not (equal? (muter-distinguish muter-1) (muter-distinguish muter-2))) #t)

; Exercise 4

(: fn-caller-1 ((Number -> Number) (Number -> Number) -> Number))
(define (fn-caller-1 f1 f2)
  (+ (f1 1) (f2 1)))
(: fn-caller-2 ((Number -> Number) (Number -> Number) -> Number))
(define (fn-caller-2 f1 f2)
  (+ (f2 1) (f1 1)))

(define (caller-distinguish func)
  (let ([bx (box 1)])
    (func (lambda (x) (+ x (unbox bx)))
          (lambda (x) (begin
                        (set-box! bx (+ x (unbox bx)))
                        (unbox bx))))))

(check-expect (not (equal? (caller-distinguish fn-caller-1)
                           (caller-distinguish fn-caller-2)))
              #t)

; Exercise 5

(: fn-caller-alt-1 ((Number -> Number) -> Number))
(define (fn-caller-alt-1 f)
  (+ (f 1) (f 1)))
(: fn-caller-alt-2 ((Number -> Number) -> Number))
(define (fn-caller-alt-2 f)
  (let [(x (f 1))]
    (+ x x)))

(define (caller-alt-distinguish func)
  (let ([bx (box 1)])
    (func (lambda (x) (begin
                        (set-box! bx (+ x (unbox bx)))
                        (unbox bx))))))

(check-expect (not (equal? (caller-alt-distinguish fn-caller-alt-1)
                           (caller-alt-distinguish fn-caller-alt-2)))
              #t)

; Exercise 6

(: multi-update ([BoxOf Number] [BoxOf Number] (Number -> Number) [ListOf [BoxOf Number]] -> (predicate void?)))
; given two indices, transform the values of the corresponding cells in the list using the given function
; assumes indices are within bounds, and it will error if they are the same.
; i.e., if the two indices were i & j, and the list were ... vi ... vj ... (all values boxed) then the
; resulting list should be ... (f vi) ... (f vj) ... (note, of course, the i does not have to be less than j).
(define (multi-update-buggy i1 i2 f l)
  (if (= (unbox i1) (unbox i2))
      (error "Must pass different indices")
      (begin (set-box! (list-ref l (unbox i1)) (f (unbox (list-ref l (unbox i1)))))
                (set-box! (list-ref l (unbox i2)) (f (unbox (list-ref l (unbox i2))))))))

(define (multi-update i1 i2 f l)
  (if (= (unbox i1) (unbox i2))
      (error "Must pass different indices")
      (let ([new1 (f (unbox (list-ref l (unbox i1))))])
        (begin (set-box! (list-ref l (unbox i2)) (f (unbox (list-ref l (unbox i2)))))
               (set-box! (list-ref l (unbox i1)) new1)))))
(define b1 (box 1))
(define l1 (list (box 1) b1 b1))
(define (output func)
  (let* ([b1 (box 1)]
         [l1 (list (box 1) b1 b1)])
    (begin (func (box 1) (box 2) add1 l1)
           (equal? (list 1 2 2)
                   (map unbox l1)))))
;(check-expect (output multi-update-buggy) false)
(check-expect (output multi-update) true)

