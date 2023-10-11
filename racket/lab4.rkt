#lang htdp/isl
(require 2htdp/web-io)
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

;Exercise 4

(define (highest-count counter)
  (cond [(empty? counter) 0]
        [(cons? counter) (cond [(>= (pair-value (first counter)) (highest-count (rest counter))) (pair-value (first counter))]
                               [(< (pair-value (first counter)) (highest-count (rest counter))) (highest-count (rest counter))])]))

(define marble-bag2 (list (make-pair "green" 2) (make-pair "red" 5) (make-pair "blue" 1) (make-pair "green" 234) (make-pair "yellow" -1)))

(check-expect (highest-count marble-bag2) 234)

(define SExp (signature Any))
(: my-first-web-page (String String -> SExp))
; produces a web page with given author and title
(define (my-first-web-page author title)
  `(html
     (head
       (title ,title)
       (meta ((http-equiv "content-type")
              (content "text-html"))))
     (body
       (h1 ,title)
       (p "I, " ,author ", made this page."))))

;(show-in-browser (my-first-web-page "Brady" "Hello World"))

'(table ((border "1"))
     (tr (td "1")   (td "2")    (td "3")   (td "4"))
     (tr (td "2.8") (td "-1.1") (td "3.4") (td "1.3")))

(define (to-row lis)
  (cons 'tr (to-row-helper lis)))

(define (to-row-helper lis)
  (cond
    [(empty? lis) '()]
    [(cons? lis) (cons
                  `(td ,(number->string (first lis)))
                  (to-row-helper (rest lis)))]))

(to-row (list 1 2 3))

(define (table-maker lis1 lis2)
  `(table ((border "1"))
          ,(to-row lis1)
          ,(to-row lis2)))

(show-in-browser (table-maker (list 1 2 3) (list 4 5 6 7)))