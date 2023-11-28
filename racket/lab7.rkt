#lang htdp/isl+
(define-struct leaf [val])
(define-struct node [left right])
 
(define (BinTree X) (signature (mixed [LeafOf X] [NodeOf [BinTree X] [BinTree X]])))
; represents a (full) binary tree with values (of type X) at the leaves of the tree

(define (binTree-temp bt)
  (... (cond
         [(leaf? bt) ...]
         [(node? bt) ...
          (binTree-temp (node-left bt)) ...
          (binTree-temp (node-right bt)) ...]) ...))

(define bt1 (make-node (make-leaf 1) (make-leaf 2)))
(define bt2 (make-node (make-leaf 3) (make-leaf 4)))
(define bt3 (make-node bt1 bt2))

(define bt4 (make-node (make-leaf "a") (make-leaf "b")))
(define bt5 (make-node (make-leaf "c") (make-leaf "d")))
(define bt6 (make-node bt4 bt5))

(define (list-extend l1 l2)
  (cond
    [(empty? l1) l2]
    [(cons? l1) (cons (first l1) (list-extend (rest l1) l2))]))

(check-expect (list-extend (list 1 2 3) (list 4 5 6)) (list 1 2 3 4 5 6))

(define (tree-flatten bt)
  (cond
    [(leaf? bt) (list (leaf-val bt))]
    [(node? bt) (list-extend
                 (tree-flatten (node-left bt))
                 (tree-flatten (node-right bt)))]))

(check-expect (tree-flatten bt3) (list 1 2 3 4))
(check-expect (tree-flatten bt6) (list "a" "b" "c" "d"))

(: height ([BinTree %X] -> Natural))
; Determines the height of the given tree
; This is the length of the longest path from the root to a leaf
(define (height bt)
  (cond [(leaf? bt) 0]
        [(node? bt) (add1 (max (height (node-left bt))
                               (height (node-right bt))))]))

(define (tree-reverse bt)
  (cond
    [(leaf? bt) bt]
    [(node? bt) (make-node
                 (tree-reverse (node-right bt))
                 (tree-reverse (node-left bt)))]))

(check-expect (tree-reverse bt3)
              (make-node
               (make-node
                (make-leaf 4)
                (make-leaf 3))
               (make-node
                (make-leaf 2)
                (make-leaf 1))))


(define (tree-map bt f)
  (cond
    [(leaf? bt) (make-leaf (f (leaf-val bt)))]
    [(node? bt)
     (make-node 
      (tree-map (node-left bt) f)
      (tree-map (node-right bt) f))]))

(check-expect (tree-map bt1 add1) (make-node (make-leaf 2) (make-leaf 3)))

(define (tree-andmap bt pred)
  (cond
    [(leaf? bt) (pred (leaf-val bt))]
    [(node? bt)
     (and 
      (tree-andmap (node-left bt) pred)
      (tree-andmap (node-right bt) pred))]))

(check-expect (tree-andmap bt1 positive?) #true)
(check-expect (tree-andmap bt1 (lambda (x) (not (equal? x 2)))) #false)

(define (tree-ormap bt pred)
  (cond
    [(leaf? bt) (pred (leaf-val bt))]
    [(node? bt)
     (or 
      (tree-ormap (node-left bt) pred)
      (tree-ormap (node-right bt) pred))]))

(check-expect (tree-ormap bt1 negative?) #false)
(check-expect (tree-ormap bt1 (lambda (x) (not (equal? x 2)))) #true)

(define (tree-filter bt pred base)
  (cond
    [(leaf? bt) (if (pred (leaf-val bt))
                    bt
                    (make-leaf base))]
    [(node? bt)
     (make-node 
      (tree-filter (node-left bt) pred base)
      (tree-filter (node-right bt) pred base))]))

(check-expect (tree-filter bt3 (lambda (x) (< x 3)) -1)
              (make-node
               (make-node
                (make-leaf 1)
                (make-leaf 2))
               (make-node
                (make-leaf -1)
                (make-leaf -1))))

(define (tree-foldr bt lfunc cfunc)
  (cond
    [(leaf? bt) (lfunc (leaf-val bt))]
    [(node? bt)
     (cfunc 
      (tree-foldr (node-left bt) lfunc cfunc)
      (tree-foldr (node-right bt) lfunc cfunc))]))

(check-expect (tree-foldr bt3 add1 *)
              120)

(define (even-length-total bt)
  (foldr (lambda (elem acc) (+ acc
                               (if (even? (string-length elem))
                                   (string-length elem)
                                   0)))
         0
         (tree-flatten bt)))

(define bt7 (make-node (make-leaf "abcd") (make-leaf "baa")))
(define bt8 (make-node (make-leaf "caaaaaa") (make-leaf "dgsdgs")))
(define bt9 (make-node bt7 bt8))

(check-expect (even-length-total bt9) 10)

(define (height2 bt)
  (tree-foldr bt (lambda (x) 0) (lambda (x y) (add1 (max x y)))))

(check-expect (height2 bt3) 2)

(define (tree-reverse2 bt)
  (tree-foldr bt (lambda (x) (make-leaf x)) (lambda (x y) (make-node y x))))

(check-expect (tree-reverse2 bt3)
              (make-node
               (make-node
                (make-leaf 4)
                (make-leaf 3))
               (make-node
                (make-leaf 2)
                (make-leaf 1))))


(define (tree-map-fold bt f)
  (tree-foldr bt (lambda (x) (make-leaf (f x))) make-node))

(check-expect (tree-map-fold bt1 add1) (make-node (make-leaf 2) (make-leaf 3)))

(define (tree-andmap-fold bt pred)
  (tree-foldr bt pred (lambda (x y) (and x y))))


(check-expect (tree-andmap-fold bt1 positive?) #true)
(check-expect (tree-andmap-fold bt1 (lambda (x) (not (equal? x 2)))) #false)

(define (tree-ormap-fold bt pred)
  (tree-foldr bt pred (lambda (x y) (or x y))))

(check-expect (tree-ormap-fold bt1 negative?) #false)
(check-expect (tree-ormap-fold bt1 (lambda (x) (not (equal? x 2)))) #true)

(define (tree-filter-fold bt pred base)
  (tree-foldr bt (lambda (x) (if (pred x)
                                 (make-leaf x)
                                 (make-leaf base))) make-node))

(check-expect (tree-filter-fold bt3 (lambda (x) (< x 3)) -1)
              (make-node
               (make-node
                (make-leaf 1)
                (make-leaf 2))
               (make-node
                (make-leaf -1)
                (make-leaf -1))))

(define (balanced? bt)
  (cond
    [(leaf? bt) true]
    [(node? bt)
     (and
      (and (balanced? (node-left bt)) (balanced? (node-right bt)))
      (<= (abs (- (height (node-left bt)) (height (node-right bt)))) 1))]))

(define (balanced?2 bt)
  (<= (abs (-
            (tree-foldr (node-left bt)
                        (lambda (x) 0)
                        (lambda (x y) (if (<= (abs (- x y)) 1)
                                          (add1 (max x y))
                                          -2)))
            (tree-foldr (node-right bt)
                        (lambda (x) 0)
                        (lambda (x y) (if (<= (abs (- x y)) 1)
                                          (add1 (max x y))
                                          -2)))))
      1))

(check-expect (balanced?2
               (make-node
                (make-node
                 (make-leaf 1)
                 (make-leaf 2))
                (make-node
                 (make-leaf 3)
                 (make-leaf 4)))) true)

(check-expect (balanced?2
               (make-node
                (make-leaf 1)
                (make-node
                 (make-leaf 3)
                 (make-leaf 4)))) true)

(check-expect (balanced?2
               (make-node
                (make-leaf 1)
                (make-node
                 (make-leaf 3)
                 (make-node
                  (make-leaf 4)
                  (make-leaf 5))))) false)