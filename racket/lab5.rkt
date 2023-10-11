#lang htdp/isl+

(define Positive (signature (predicate (lambda (x) (and (number? x) (positive? x))))))
(define-struct fias [min max step])
(define AFIAS (signature [FiasOf Number Number Positive]))
; where (make-fias min max step) represents all numbers
; of the form min + (k * step), where k is a natural number,
; such that min + (k * step) < max.
 
(define FIAS-EMPTY (make-fias 1 1 0.25)) ; empty sequence, as min >= max
(define FIAS-1 (make-fias 0 1 0.25)) ; sequence with the elements (0, .25, .5, .75)
 
; fias-temp : AFIAS -> ?
(define (fias-temp fias)
  (... (fias-min fias) ... (fias-max fias) ... (fias-step fias) ...))

(: empty-fias? (AFIAS -> Boolean))
; determines if the given FIAS is empty
(define (empty-fias? fias)
  (>= (fias-min fias) (fias-max fias)))

(: next-sequence (AFIAS -> AFIAS))
; returns a new FIAS where the min is the original FIAS's min plus its step
(define (next-sequence fias)
  (make-fias
    (+ (fias-min fias) (fias-step fias))
    (fias-max fias)
    (fias-step fias)))

(define (sum-elem FIAS)
  (marvelous-func + 0 FIAS))

(define FIAS1 (make-fias 2 10 2))
(define FIAS2 (make-fias 0 0 2))
(define FIAS3 (make-fias .5 5 .5))

(check-expect (sum-elem FIAS1) 20)
(check-expect (sum-elem FIAS2) 0)
(check-expect (sum-elem FIAS3) 22.5)

(define (mult-elem FIAS)
  (marvelous-func * 1 FIAS))

(check-expect (mult-elem FIAS1) 384)
(check-expect (mult-elem FIAS2) 1)
(check-expect (mult-elem FIAS3) 708.75)

(define (list-elem FIAS)
  (marvelous-func cons '() FIAS))

(check-expect (list-elem FIAS1) (range 2 10 2))
(check-expect (list-elem FIAS2) (range 0 0 2))
(check-expect (list-elem FIAS3) (range .5 5 .5))

(define (marvelous-func operator start FIAS)
  (cond
    [(empty-fias? FIAS) start]
    [else (operator (fias-min FIAS) (marvelous-func operator start (next-sequence FIAS)))]))

(define (squares? FIAS)
  (m-func (lambda (x) (integer? (sqrt x))) FIAS))

(check-expect (squares? FIAS1) true)
(check-expect (squares? FIAS2) false)
(check-expect (squares? FIAS3) true)

(define (evens? FIAS)
  (m-func (lambda (x) (and (integer? x) (even? x))) FIAS))

(check-expect (evens? FIAS1) true)
(check-expect (evens? FIAS2) false)
(check-expect (evens? FIAS3) true)

(define (m-func condition FIAS)
  (cond
    [(empty-fias? FIAS) false]
    [else (or (condition (fias-min FIAS)) (m-func condition (next-sequence FIAS)))]))