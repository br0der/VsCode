#lang htdp/isl+

(define (topsy-turvy sexp)
  (cond
    [(symbol? sexp) sexp]
    [(cons? sexp) (map topsy-turvy (reverse sexp))]))

(define EX1 '(X Y (Z A M N) B))
(define EX2 '(X Y Z X))
(define EX3 '(X (Y (Z (A (B))))))
(check-expect (topsy-turvy EX1) '(B (N M A Z) Y X))
(check-expect (topsy-turvy EX2) '(X Z Y X))
(check-expect (topsy-turvy EX3) '(((((B) A) Z) Y) X))
  
(define (find-path sexp val)
  (cond
    [(symbol? sexp) (if (symbol=? sexp val)
                        '()
                        #false)]
    [(cons? sexp) (if (list? (find-path (first sexp) val))
                      (cons 0 (find-path (first sexp) val))
                      (if (and (not (empty? (rest sexp))) (list? (find-path (rest sexp) val)))
                          (cons (add1 (first (find-path (rest sexp) val))) (rest (find-path (rest sexp) val)))
                          #false))]))
(check-expect (find-path EX1 'X) (list 0))
(check-expect (find-path EX1 'Z) (list 2 0))
(check-expect (find-path EX1 'N) (list 2 3))
(check-expect (find-path EX1 'B) (list 3))
(check-expect (find-path EX3 'B) (list 1 1 1 1 0))
(check-expect (find-path 'B 'B) '())

(: unfold ((%a -> Boolean) (%a -> %b) (%a -> %a) %a -> (ListOf %b)))
(define (unfold pred? f g val)
  (if (pred? val)
      '()
      (cons (f val) (unfold pred? f g (g val)))))

(define (make-list-unfold n v)
  (unfold zero? (lambda (x) v) sub1 n))

(check-expect (make-list-unfold 5 5) (list 5 5 5 5 5))
(check-expect (make-list-unfold 10 0) (list 0 0 0 0 0 0 0 0 0 0))
(check-expect (make-list-unfold 0 10) (list))

(define (map-unfold f lis)
  (unfold empty? (lambda (x) (f (first x))) rest lis))

(check-expect (map-unfold add1 (list 1 2 3)) (list 2 3 4))
(check-expect (map-unfold list (list -1 0 1)) (list (list -1) (list 0) (list 1)))