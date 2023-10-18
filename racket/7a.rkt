#lang htdp/isl+

(define (rep->nat r)
  ((r add1) 0))

(define (rep-add1 r)
  (lambda (f) (lambda (x) (f ((r f) x)))))

(define (nat->rep n)
  (if (zero? n)
      (lambda (f) identity)
      (rep-add1 (nat->rep (sub1 n)))))

(define (rep+ r1 r2)
  (lambda (func) (lambda (x) ((r1 func) ((r2 func) x)))))

(define (rep* r1 r2)
  (lambda (func) (r1 (r2 func))))

(define (rep^ r1 r2)
  (r2 r1))
(rep->nat (rep^ (nat->rep 3) (nat->rep 2)))
(r1 (r1 (r1 x)))