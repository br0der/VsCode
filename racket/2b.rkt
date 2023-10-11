
#lang htdp/bsl


; Exercise 1
;(define-struct Position (x y))

(define (dist pos)
  (cond
    [(string? pos) 0]
    [(number? pos) pos]
    [(posn? pos)
     (sqrt(+ (* (posn-x pos) (posn-x pos)) (* (posn-y pos) (posn-y pos))))]))

(check-expect (dist (make-posn 3 4)) 5)
(check-expect (dist (make-posn 6 8)) 10)
(check-expect (dist ("origin")) 0)

; Exercise 2
(define (manhattan-distance pos)
  (+ (abs(posn-x pos)) (abs(posn-y pos))))

(check-expect (manhattan-distance (make-posn 5 10)) 15)
(check-expect (manhattan-distance (make-posn 0 10)) 10)
(check-expect (manhattan-distance (make-posn 5 0)) 5)
(check-expect (manhattan-distance (make-posn 0 -10)) 10)
(check-expect (manhattan-distance (make-posn -5 0)) 5)
(check-expect (manhattan-distance (make-posn -5 -10)) 15)

; Exercise 3
(define (gbp->eur gbp)
  (cond
    [(<= gbp 5) 0]
    [else (/ (* (- gbp 5) 4) 5)]))

(check-expect (gbp->eur 5) 0)
(check-expect (gbp->eur 6) 0.8)
(check-expect (gbp->eur 10) 4)
(check-expect (gbp->eur 15) 8)
(check-expect (gbp->eur 0) 0)
(check-expect (gbp->eur 100) 76)

; Exercise 4
(define (leap-year? year)
  (cond
    [(= (remainder year 400) 0) true]
    [(= (remainder year 100) 0) false]
    [(= (remainder year 4) 0) true]
    [else false]))

(check-expect (leap-year? 2000) true)
(check-expect (leap-year? 1900) false)
(check-expect (leap-year? 2001) false)
(check-expect (leap-year? 2004) true)

