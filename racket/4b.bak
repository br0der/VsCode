#lang htdp/isl

;Exercise 1
(define (interleave l1 l2)
  (cond
    [(empty? l1) l2]
    [(cons? l1) (cons (first l1) (interleave l2 (rest l1)))]))

(check-expect (interleave (list 1 3 5 7 9 11 13 16) (list 2 4 6 8 10 12 14 15))
              (list 1 2 3 4 5 6 7 8 9 10 11 12 13 14 16 15))
(check-expect (interleave (list 1 3 5) (list 2 4 6 8))
              (list 1 2 3 4 5 6 8))
(check-expect (interleave (list 1 3 5 7) (list 2 4 6))
              (list 1 2 3 4 5 6 7))
(check-expect (interleave '() (list 2 4 6))
              (list 2 4 6))
(check-expect (interleave (list 2 4 6) '())
              (list 2 4 6))

(define (prime-factors x)
  (cond [(= x 1) empty]
        [(prime? x) (list x)]
        [else (local [(define lpf (lowest-factor/acc x 2))]
                (cons lpf (prime-factors (/ x lpf))))]))

(define (lowest-factor/acc x f)
  (if (and (prime? f) (= 0 (modulo x f)))
      f
      (lowest-factor/acc x (add1 f))))

(define (prime? x)
  (cond [(= x 1) #false]
        [else (prime?/acc x (floor (sqrt x)))]))

(define (prime?/acc x d)
  (cond [(= d 1) #true]
        [else (and (not (= 0 (modulo x d))) (prime?/acc x (sub1 d)))]))

(check-expect (prime-factors 50717259)
              (list 3 3 3 3 3 3 29 2399))
(check-expect (prime-factors 2)
              (list 2))
(check-expect (prime-factors 7)
              (list 7))
(check-expect (prime-factors 10)
              (list 2 5))

(define (num-in-list lis n)
  (cond
    [(empty? lis) false]
    [(= (first lis) n) true]
    [else (num-in-list (rest lis) n)]))

(define (num-in-all-list lis n)
  (cond
    [(empty? lis) true]
    [(not (num-in-list (first lis) n)) false]
    [else (num-in-all-list (rest lis) n)]))

(define (intersection lis)
  (cond
    [(empty? (first lis)) '()]
    [(num-in-all-list (rest lis) (first (first lis)))
     (cons (first (first lis))
           (intersection (cons (rest (first lis)) (rest lis))))]
    [else (intersection (cons (rest (first lis)) (rest lis)))]))

(check-expect (intersection (list (list 0 1 2 3) (list 1 2 3 4) (list 0 2 3 4) (list 2 3)))
              (list 2 3))

(check-expect (intersection (list (list 0 1 2 3) (list 1 2 3 4) (list 0 2 3 4) (list 2 3) (list 5)))
              '())

(check-expect (intersection (list (list 0 1 2 3) (list 0 1 2 3)))
              (list 0 1 2 3))

(check-expect (intersection (list (list 0 1 2 3)))
              (list 0 1 2 3))

(check-expect (intersection (list (list 0 1 2 3) (list 5 6 7 8)))
              '())

(define (lis=? lis1 lis2)
  (cond
    [(and (empty? lis1) (empty? lis2)) true]
    [(or (empty? lis1) (empty? lis2)) false]
    [(not (= (first lis1) (first lis2))) false]
    [else (lis=? (rest lis1) (rest lis2))]))

(define (lis-in? lis1 lis2)
  (cond
    [(empty? lis2) false]
    [(lis=? lis1 (first lis2)) true]
    [else (lis-in? lis1 (rest lis2))]))

(define (all-contained-in? lis1 lis2)
  (cond
    [(empty? lis1) true]
    [(not (lis-in? (first lis1) lis2)) false]
    [else (all-contained-in? (rest lis1) lis2)]))

(check-expect (all-contained-in? (list
                                  (list 0 1 2)
                                  (list 1 2 3)
                                  (list 2 3 4))
                                 (list
                                  (list 2 3 4)
                                  (list 1 2 3)
                                  (list 0 1 2)))
              true)

(check-expect (all-contained-in? (list
                                  (list 1 2 3)
                                  (list 1 2 3)
                                  (list 2 3 4))
                                 (list
                                  (list 2 3 4)
                                  (list 1 2 3)
                                  (list 0 1 2)))
              true)

(check-expect (all-contained-in? (list
                                  (list 0 1 2)
                                  (list 1 2 3)
                                  (list 2 3 4))
                                 (list
                                  (list 3 4 5)
                                  (list 2 3 4)
                                  (list 1 2 3)
                                  (list 0 1 2)))
              true)

(check-expect (all-contained-in? (list
                                  (list 0 1 2)
                                  (list 1 2 3)
                                  (list 2 3 4))
                                 (list
                                  (list 0 1 2)
                                  (list 0 1 2)
                                  (list 0 1 2)))
              false)

(check-expect (all-contained-in? (list
                                  (list 0 1 2))
                                 (list
                                  (list 0 1)
                                  (list 1 2)
                                  (list 0 2)
                                  (list 0)
                                  (list 1)
                                  (list 2)))
              false)

(check-expect (all-contained-in? '()
                                 (list
                                  (list 0 1)
                                  (list 1 2)
                                  (list 0 2)
                                  (list 0)
                                  (list 1)
                                  (list 2)))
              true)
(check-expect (all-contained-in? (list
                                  (list 0 1)
                                  (list 1 2)
                                  (list 0 2)
                                  (list 0)
                                  (list 1)
                                  (list 2))
                                 (list '()))
              false)


(define (combine num lis)
  (cond
    [(empty? lis) '()]
    [else (cons (cons num (first lis)) (combine num (rest lis)))]))

(define (extend lis1 lis2)
  (cond
    [(empty? lis2) lis1]
    [else (cons (first lis2) (append lis1 (rest lis2)))]))

(define (powerlist lis)
  (cond
    [(empty? lis) (list '())]
    [else (cons
           (list (first lis))
           (extend
            (combine (first lis) (powerlist (rest lis)))
            (powerlist (rest lis))))]))

(define (equivalent lis1 lis2)
  (and (all-contained-in? lis1 lis2) (all-contained-in? lis2 lis1)))

(check-expect (equivalent
               (powerlist (list 1 2 3))
               (list
                '()
                (list 1)
                (list 2)
                (list 1 2)
                (list 1 3)
                (list 1 2 3)
                (list 3)
                (list 2 3)))
              true)

(check-expect (equivalent 
               (list
                '()
                (list 1))
              (powerlist (list 1)))
              true)

(check-expect (equivalent 
               (list
                '())
              (powerlist '()))
              true)

(check-expect (equivalent
               (powerlist (list 1 2 3 4 5 6))
               (list '() (list 1) (list 2) (list 1 2) (list 1 3) (list 1 2 3) (list 1 2 4) (list 1 2 3 4) (list 1 2 3 5) (list 1 2 3 4 5) (list 1 2 3 4 6) (list 1 2 3 4 5 6) (list 1 2 3 6) (list 1 2 3 5 6) (list 1 2 5) (list 1 2 4 5) (list 1 2 4 6) (list 1 2 4 5 6) (list 1 2 6) (list 1 2 5 6) (list 1 4) (list 1 3 4) (list 1 3 5) (list 1 3 4 5) (list 1 3 4 6) (list 1 3 4 5 6) (list 1 3 6) (list 1 3 5 6) (list 1 5) (list 1 4 5) (list 1 4 6) (list 1 4 5 6) (list 1 6) (list 1 5 6) (list 3) (list 2 3) (list 2 4) (list 2 3 4) (list 2 3 5) (list 2 3 4 5) (list 2 3 4 6) (list 2 3 4 5 6) (list 2 3 6) (list 2 3 5 6) (list 2 5) (list 2 4 5) (list 2 4 6) (list 2 4 5 6) (list 2 6) (list 2 5 6) (list 4) (list 3 4) (list 3 5) (list 3 4 5) (list 3 4 6) (list 3 4 5 6) (list 3 6) (list 3 5 6) (list 5) (list 4 5) (list 4 6) (list 4 5 6) (list 6) (list 5 6)))
              true)
