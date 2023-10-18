#lang htdp/isl+
(define (Comparison X) (signature (X X -> Number)))
; with a negative output indicating the first parameter comes first,
;      a positive output indicating the first parameter comes second,
;      and 0 indicating they are equal
 
(define-struct leaf [])
(define-struct node [key info smaller bigger])
 
(define (BST X Y) (signature (mixed Leaf [NodeOf X Y [BST X Y] [BST X Y]])))
; and represents either an empty BST or
; a node with key, info, and two subtrees with smaller/larger keys, respectively
 
(define-struct treemap [comp bst])
(define (ATreemap X Y) (signature [TreemapOf [Comparison X] [BST X Y]]))
; and represents a treemap with a searchable bst with comp comparing over type x

;Exercise 1
(define (insert k i tm)
  (let ([curr (treemap-bst tm)])
    (cond
      [(leaf? curr) (make-treemap (treemap-comp tm) (make-node k i (make-leaf) (make-leaf)))]
      [else (let ([c ((treemap-comp tm) (node-key curr) k)])
              (cond
                [(= c 0) (make-treemap
                          (treemap-comp tm)
                          (make-node
                           k
                           i
                           (node-smaller curr)
                           (node-bigger curr)))]
                [(> c 0) (make-treemap
                          (treemap-comp tm)
                          (make-node
                           (node-key curr)
                           (node-info curr)
                           (treemap-bst (insert
                                         k
                                         i
                                         (make-treemap (treemap-comp tm) (node-smaller curr))))
                           (node-bigger curr)))]
                [(< c 0) (make-treemap
                          (treemap-comp tm)
                          (make-node
                           (node-key curr)
                           (node-info curr)
                           (node-smaller curr)
                           (treemap-bst (insert
                                         k
                                         i
                                         (make-treemap (treemap-comp tm) (node-bigger curr))))))]))])))

(define ex1 (make-treemap (lambda (x y) (- x y)) (make-leaf)))

(check-expect (treemap-bst (insert 1 "d" (insert 2.5 "c" (insert 3 "b" (insert 2 "a" ex1)))))
              (make-node 2 "a"
                         (make-node 1 "d" (make-leaf) (make-leaf))
                         (make-node 3 "b"
                                    (make-node 2.5 "c" (make-leaf) (make-leaf))
                                    (make-leaf))))

(define n1
  (make-node 5 "e"
             (make-node 4 "b"
                        (make-node 3 "c"
                                   (make-node 1 "d"
                                              (make-leaf)
                                              (make-leaf))
                                   (make-leaf))
                        (make-leaf))
             (make-leaf)))

(check-expect (treemap-bst (insert 5 "e" (insert 1 "d" (insert 3 "c" (insert 4 "b" (insert 5 "a" ex1))))))
              n1)

(define n3
  (make-node 4 "b"
             (make-leaf)
             (make-node 5 "e"
                        (make-leaf)
                        (make-leaf))))
(define n2
  (make-node 3 "c"
             (make-node 1 "d"
                        (make-leaf)
                        (make-leaf))
             n3))

(check-expect (treemap-bst (insert 5 "e" (insert 5 "a" (insert 4 "b" (insert 1 "d" (insert 3 "c" ex1))))))
              n2)

(define (find tm k)
  (let ([curr (treemap-bst tm)])
    (cond
      [(leaf? curr) (error "Item not found")]
      [else (let ([c ((treemap-comp tm) (node-key curr) k)])
              (cond
                [(= c 0) (node-info curr)]
                [(> c 0) (find (make-treemap (treemap-comp tm) (node-smaller curr))
                               k)]
                [(< c 0) (find (make-treemap (treemap-comp tm) (node-bigger curr))
                               k)]))])))

(check-expect (find (make-treemap (lambda (x y) (- x y)) n2) 3)
              "c")
(check-expect (find (make-treemap (lambda (x y) (- x y)) n2) 4)
              "b")
(check-expect (find (make-treemap (lambda (x y) (- x y)) n2) 1)
              "d")
(check-expect (find (make-treemap (lambda (x y) (- x y)) n2) 5)
              "e")
(check-error (find (make-treemap (lambda (x y) (- x y)) n2) 6))
(check-expect (find (make-treemap (lambda (x y) (- x y)) n1) 1)
              "d")
(check-error (find (make-treemap (lambda (x y) (- x y)) n1) 0))

(define (absmin n)
  (cond
    [(leaf? (node-smaller n)) (node-key n)]
    [else (absmin (node-smaller n))]))
(define (absmax n)
  (cond
    [(leaf? (node-bigger n)) (node-key n)]
    [else (absmax (node-bigger n))]))

(define (submap tm lo hi)
  (let ([curr (treemap-bst tm)])
    (cond
      [(leaf? curr) (make-treemap
                     (treemap-comp tm)
                     (make-leaf))]
      [(or (< ((treemap-comp tm) (node-key curr) lo) 0) (> ((treemap-comp tm) (node-key curr) hi) 0))
       (make-treemap
        (treemap-comp tm)
        (make-leaf))]
      #;[(> ((treemap-comp tm) (absmax curr) hi) 0) (submap
                                                     (make-treemap (treemap-comp tm) (node-smaller curr))
                                                     lo hi)]
      [else (make-treemap
             (treemap-comp tm)
             (make-node
              (node-key curr)
              (node-info curr)
              (treemap-bst
               (submap
                (make-treemap (treemap-comp tm) (node-smaller curr)) lo hi))
              (treemap-bst
               (submap
                (make-treemap (treemap-comp tm) (node-bigger curr)) lo hi))))])))

(define n
  (make-node 4 "b"
             (make-node 3 "b"
                        (make-leaf)
                        (make-leaf))
             (make-node 5 "e"
                        (make-leaf)
                        (make-leaf))))
(check-expect (treemap-bst (submap (make-treemap - n2) 0 6)) n2)
(check-expect (treemap-bst (submap (make-treemap - n2) 1 5)) n2)
(check-expect (treemap-bst (submap (make-treemap - n2) 2 5))
              (make-node
               3
               "c"
               (make-leaf)
               (make-node
                4
                "b"
                (make-leaf)
                (make-node
                 5
                 "e"
                 (make-leaf)
                 (make-leaf)))))
(define n5
  (make-node 3 "c"
             (make-node 1 "d"
                        (make-leaf)
                        (make-node 2 "c"
                                   (make-leaf)
                                   (make-leaf)))
             (make-leaf)))
(check-expect (treemap-bst (submap (make-treemap (lambda (x y) (- x y)) n5) 2 3))
              (make-node 3 "c" (make-leaf) (make-leaf)))
;(check-expect (treemap-bst (submap (make-treemap (lambda (x y) (- x y)) n2) 2 4)) (make-leaf))
;(check-expect (treemap-bst (submap (make-treemap (lambda (x y) (- x y)) n1) 1 2)) (make-node 1 "d" (make-leaf) (make-leaf)))
;(check-expect (treemap-bst (submap (make-treemap (lambda (x y) (- x y)) n1) 2 1)) (make-leaf))

