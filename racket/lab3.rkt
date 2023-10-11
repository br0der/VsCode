#lang htdp/isl
(define-struct next [prev])
(define Nat (signature (mixed (enum 0) [NextOf Nat])))
 
 (define N0 0)
 (define N1 (make-next N0))
 (define N2 (make-next N1))
 (define N3 (make-next N2))
 (: nat-temp (Nat -> Any))
 (define (nat-temp nat)
   (cond
     [(and (number? nat) (zero? nat)) ...]
     [(next? nat) (... (nat-temp (next-prev nat)) ...)]))

(: zero?/nat (Nat -> Boolean))
; outputs whether a nat is zero
(define (zero?/nat nat)
    (and (number? nat) (zero? nat)))

(check-expect (zero?/nat N0) #true)
(check-expect (zero?/nat N1) #false)
(check-expect (zero?/nat N2) #false)
 
(: double (Nat -> Nat))
; Double the Nat
(define (double nat)
  (cond
    [(zero?/nat nat) 0]
    [(next? nat) (make-next (make-next (double (next-prev nat))))]))
 
(check-expect (double N0) 0)
(check-expect (double N1) (make-next (make-next 0)))
(check-expect (double N2) (make-next (make-next (make-next (make-next 0)))))


(: nat->number (Nat -> Number))
; Converts from a Nat to a number
(define (nat->number nat)
  (cond
    [(zero?/nat nat) 0]
    [(next? nat) (+ (nat->number (next-prev nat)) 1)]))

(check-expect (nat->number (double N0)) 0)
(check-expect (nat->number (double N1)) 2)
(check-expect (nat->number (double N2)) 4)

(: even?/nat (Nat -> Boolean))
(define (even?/nat nat)
  (cond
    [(zero?/nat nat) true]
    [(next? nat) (not (even?/nat (next-prev nat)))]))

(check-expect (even?/nat N0) true)
(check-expect (even?/nat N1) false)
(check-expect (even?/nat N2) true)
(check-expect (even?/nat N3) false)

(: +/nat (Nat Nat -> Nat))
; Adds two nats
(define (+/nat nat1 nat2)
  (cond
    [(zero?/nat nat1) nat2]
    [(zero?/nat nat2) nat1]
    [(and (next? nat1) (next? nat2))
     (make-next (make-next
                 (+/nat (next-prev nat1) (next-prev nat2))))]))

(check-expect (+/nat N0 N0) N0)
(check-expect (+/nat N0 N1) N1)
(check-expect (+/nat N1 N1) N2)
(check-expect (+/nat N2 N1) N3)

;Exercise 7

(define (/nat nat1 nat2)
  (cond [(or (zero?/nat nat1) (zero?/nat nat2)) 0]
        [(and (next? nat1) (next? nat2))
         (+/nat nat1 (/nat nat1 (next-prev nat2)))]))

(check-expect (/nat N2 N2) (double N2))



(define (factorial/nat nat1)
  (cond [(zero?/nat nat1) N1]
        [(next? nat1) (/nat nat1 (factorial/nat (next-prev nat1)))]))

(check-expect (factorial/nat N2) N2)
(check-expect (factorial/nat N3) (double N3))

(define-struct pair [element value])
(define Entry (signature [PairOf String Number]))
; represents an element with a count
 
(define (pair-temp p)
  (... (pair-element p) ... (pair-value p) ...))
 
(define Counter (signature [ListOf Entry]))
; and represents a multiset (a set of elements where
; an element can appear more than once)
 
(define (counter-temp counter)
  (cond [(empty? counter) ...]
        [(cons? counter) (... (pair-temp (first counter))
                              ... (counter-temp (rest counter))
                              ...)]))
 
(define marble-bag (list (make-pair "green" 2) (make-pair "red" 5)))
; marble-bag represents a bag with 2 "green" marbles and 5 "red" ones
 
(: get (Counter String -> Number))
; Get the count of the given element
(define (get counter element)
  (cond [(empty? counter) (error "not found")]
        [else (if (counts-element? (first counter) element)
                  (pair-value (first counter))
                  (get (rest counter) element))]))
 
(check-error (get (list (make-pair "cats" 3)) "dogs") "not found")
(check-expect (get (list (make-pair "cats" 3) (make-pair "dogs" 4)) "dogs") 4)
 
(: counts-element? (Entry String -> Boolean))
; Does the pair hold a count for the element?
(define (counts-element? pair element)
  (string=? element (pair-element pair)))
 
(check-expect (counts-element? (make-pair "green" 2) "green") #true)
(check-expect (counts-element? (make-pair "red" 5) "blue") #false)

(: add-to-counter (Counter String -> Counter))
; Add one to the count associated with element or set it to 1
; if it hasn't been seen before
(define (add-to-counter counter element)
  (cond
    [(empty? counter) (list (make-pair element 1))]
    [(cons? counter) (if (counts-element? (first counter) element)
                         (cons (increment-value (first counter))
                               (rest counter))
                         (cons (first counter)
                               (add-to-counter (rest counter) element)))]))
 
(check-expect (add-to-counter '() "blue") (list (make-pair "blue" 1)))
(check-expect (add-to-counter marble-bag "red")
              (list (make-pair "green" 2) (make-pair "red" 6)))
(check-expect (add-to-counter marble-bag "green")
              (list (make-pair "green" 3) (make-pair "red" 5)))
 
(: increment-value (Entry -> Entry))
; Increment the value in pair
(define (increment-value pair)
  (make-pair (pair-element pair) (add1 (pair-value pair))))
 
(check-expect (increment-value (make-pair "green" 2)) (make-pair "green" 3))
(check-expect (increment-value (make-pair "red" 5)) (make-pair "red" 6))

(define (total-size counter)
  (cond
    [(empty? counter) 0]
    [(cons? counter) (+ (pair-value (first counter)) (total-size (rest counter)))]))

(check-expect (total-size (list (make-pair "green" 2) (make-pair "red" 6))) 8)
(check-expect (total-size (list (make-pair "green" 2) (make-pair "red" 2))) 4)

(define (initiate-counter str)
  (list (make-pair str 1)))

(check-expect (initiate-counter "red") (list (make-pair "red" 1)))
(check-expect (initiate-counter "blue") (list (make-pair "blue" 1)))

(define (all-elements counter)
  (cond
    [(empty? counter) '()]
    [(> (pair-value (first counter)) 0)
     (cons
      (pair-element (first counter))
      (all-elements
       (cons
        (make-pair (pair-element (first counter)) (- (pair-value (first counter)) 1))
        (rest counter))))]
    [(= (pair-value (first counter)) 0) (all-elements (rest counter))]))

(check-expect (all-elements (list (make-pair "green" 2) (make-pair "red" 2))) (list "green" "green" "red" "red"))
(check-expect (all-elements (list (make-pair "blue" 1) (make-pair "green" 2) (make-pair "red" 2))) (list "blue" "green" "green" "red" "red"))

;Exercise 12

(define (highest-count counter)
  (cond [(empty? counter) 0]
        [(cons? counter) (cond [(>= (pair-value (first counter)) (highest-count (rest counter))) (pair-value (first counter))]
                               [(< (pair-value (first counter)) (highest-count (rest counter))) (highest-count (rest counter))])]))

(define marble-bag2 (list (make-pair "green" 2) (make-pair "red" 5) (make-pair "blue" 1) (make-pair "green" 234) (make-pair "yellow" -1)))

(check-expect (highest-count marble-bag2) 234)

(define (counter- counter1 counter2)
  [(empty? counter1) '()]
  [(cons? counter1) (cond
                      [(< (pair-value (first counter1)) (get counter2 (pair-element (first counter1)))) (counter- (rest counter1) counter2)]
                      [(>= (first counter1))
                       (if (get counter2 (pair-element (first counter1)))] (cons (make-pair (