#lang htdp/isl+
(define-struct graph [nodes neighbors])
(define AGraph (signature [GraphOf [ListOf Symbol] (Symbol -> [ListOf Symbol])]))
; and represents the nodes and edges in a graph.
; All symbols that represent nodes are assumed to be unique
; All symbols returned by (graph-neighbors _) will also be unique
; All symbols returned by (graph-neighbors _) are assumed to be in nodes

(define G1
  (make-graph '(a b c d e)
              (lambda (x)
                (cond
                  [(symbol=? x 'a) '(b c)]
                  [(symbol=? x 'b) '(a d)]
                  [(symbol=? x 'c) '(a d)]
                  [(symbol=? x 'd) '(b c)]
                  [(symbol=? x 'e) '()]))))

(define G2
  (make-graph '(a b c d e)
              (lambda (x)
                (cond
                  [(symbol=? x 'a) '(b c)]
                  [(symbol=? x 'b) '(a d e)]
                  [(symbol=? x 'c) '(a d)]
                  [(symbol=? x 'd) '(b c)]
                  [(symbol=? x 'e) '(b)]))))

(define G5
  (make-graph '(a b c d e)
              (lambda (x)
                (cond
                  [(symbol=? x 'a) '(b c d e)]
                  [(symbol=? x 'b) '()]
                  [(symbol=? x 'c) '()]
                  [(symbol=? x 'd) '()]
                  [(symbol=? x 'e) '()]))))

(define G6
  (make-graph '(a b c d e)
              (lambda (x)
                (cond
                  [(symbol=? x 'a) '()]
                  [(symbol=? x 'b) '(a)]
                  [(symbol=? x 'c) '(a)]
                  [(symbol=? x 'd) '(a)]
                  [(symbol=? x 'e) '(a)]))))

(define (neighbor-of? g s1 s2)
  (member? s2 ((graph-neighbors g) s1)))

(check-expect (neighbor-of? G1 'a 'b) #true)
(check-expect (neighbor-of? G1 'a 'c) #true)
(check-expect (neighbor-of? G1 'b 'c) #false)
(check-expect (neighbor-of? G1 'e 'b) #false)
(check-expect (neighbor-of? G5 'a 'b) #true)
(check-expect (neighbor-of? G5 'b 'a) #false)

(define (list=? l1 l2)
  (and (= (length l1) (length l2)) (andmap (lambda (x) (member? x l2)) l1)))

(check-expect (list=? '(a b c) '(c a b)) true)
(check-expect (list=? '(a b c) '(c a b d)) false)
(check-expect (list=? '(a b d) '(a b c)) false)

(define (both-neighbors s1 s2 g)
  (append (filter (lambda (x) (not (member? x ((graph-neighbors g) s2))))
                  ((graph-neighbors g) s1))
          ((graph-neighbors g) s2)))

(check-expect (list=? (both-neighbors 'a 'b G1) '(b c a d)) #true)
(check-expect (list=? (both-neighbors 'a 'e G1) '(b c)) #true)
(check-expect (list=? (both-neighbors 'c 'b G1) '(d a)) #true)
(check-expect (list=? (both-neighbors 'b 'a G1) '(b c a d)) #true)

(define G10
  (make-graph '(e b c d a)
              (lambda (x)
                (cond
                  [(symbol=? x 'd) '()]
                  [(symbol=? x 'a) '()]
                  [(symbol=? x 'c) '()]
                  [(symbol=? x 'e) '()]
                  [(symbol=? x 'b) '()]))))

(define G11
  (make-graph '()
              (lambda (x)
                (cond
                  [(symbol=? x 'd) '()]))))

(define (graph=? g1 g2)
  (if (list=? (graph-nodes g1) (graph-nodes g2))
      (andmap (lambda (x) (list=?
                           ((graph-neighbors g1) x)
                           ((graph-neighbors g2) x)))
              (graph-nodes g1))
      #false))

(check-expect (graph=? G1 G2) #false)
(check-expect (graph=? G1 G1) #true)
(check-expect (graph=? G2 G2) #true)
(check-expect (graph=? G6 G5) #false)
(check-expect (graph=? G1 G3) #false)
(check-expect (graph=? G10 G10) #true)
(check-expect (graph=? G11 G11) #true)
(check-expect (graph=? G1 G11) #false)
(check-expect (graph=? G1 G10) #false)

(: graph=?/curried (Graph -> (Graph -> Boolean)))
; Curried graph=?
(define graph=?/curried (λ (g1) (λ (g2) (graph=? g1 g2))))
 
;(: f (Graph -> Graph))
; Do something to g
;(define (f g ...) ...)
 
#;(check-satisfied (f some-input-graph ...)
                   (graph=?/curried
                    some-expected-graph))

(define G3
  (make-graph '(f c d e)
              (lambda (x)
                (cond
                  [(symbol=? x 'f) '(f c d)]
                  [(symbol=? x 'c) '(f d)]
                  [(symbol=? x 'd) '(f c)]
                  [(symbol=? x 'e) '()]))))

(define G4
  (make-graph '(a b c g)
              (lambda (x)
                (cond
                  [(symbol=? x 'a) '(b c)]
                  [(symbol=? x 'b) '(a g)]
                  [(symbol=? x 'c) '(a g)]
                  [(symbol=? x 'g) '(b c)]))))

(define (collapse s1 s2 s3 g)
  (make-graph
   (cons s3
         (filter (lambda (x) (not (or (symbol=? s1 x) (symbol=? s2 x))))
                 (graph-nodes g)))
   (lambda (x) (if (symbol=? x s3)
                   (if (or (member? s1 (both-neighbors s1 s2 g)) (member? s2 (both-neighbors s1 s2 g)))
                       (cons s3
                             (filter (lambda (x) (not (or (symbol=? s1 x) (symbol=? s2 x))))
                                     (both-neighbors s1 s2 g)))
                       (both-neighbors s1 s2 g))
                   (let ([old ((graph-neighbors g) x)])
                     (if (or
                          (member? s1 old)
                          (member? s2 old))
                         (cons s3
                               (filter (lambda (x) (not (or (symbol=? s1 x) (symbol=? s2 x))))
                                       old))
                         old))))))

(check-satisfied (collapse 'a 'b 'f G1)
                 (graph=?/curried
                  G3))
(check-satisfied (collapse 'd 'e 'g G2)
                 (graph=?/curried
                  G4))

(define (reverse-edges g)
  (make-graph
   (graph-nodes g)
   (lambda (b)
     (filter
      (lambda (a)
        (member? b ((graph-neighbors g) a)))
      (graph-nodes g)))))

(check-satisfied (reverse-edges G1)
                 (graph=?/curried
                  G1))
(check-satisfied (reverse-edges G2)
                 (graph=?/curried
                  G2))
(check-satisfied (reverse-edges G5)
                 (graph=?/curried
                  G6))

(define G7
  (make-graph '(aa bb cc dd ee)
              (lambda (x)
                (cond
                  [(symbol=? x 'aa) '(bb cc)]
                  [(symbol=? x 'bb) '(aa dd)]
                  [(symbol=? x 'cc) '(aa dd)]
                  [(symbol=? x 'dd) '(bb cc)]
                  [(symbol=? x 'ee) '()]))))

(define G8
  (make-graph '(e d c b a)
              (lambda (x)
                (cond
                  [(symbol=? x 'e) '(b c d a)]
                  [(symbol=? x 'd) '()]
                  [(symbol=? x 'c) '()]
                  [(symbol=? x 'b) '()]
                  [(symbol=? x 'a) '()]))))

(define G9
  (make-graph '(e d c b a)
              (lambda (x)
                (cond
                  [(symbol=? x 'e) '()]
                  [(symbol=? x 'd) '(e)]
                  [(symbol=? x 'c) '(e)]
                  [(symbol=? x 'b) '(e)]
                  [(symbol=? x 'a) '(e)]))))

(define (zip l1 l2)
  (cond
    [(or (empty? l1) (empty? l2)) '()]
    [else (cons (list (first l1) (first l2)) (zip (rest l1) (rest l2)))]))

(define (rename g los)
  (foldl (lambda (elem acc)
           (collapse (first elem) (first elem) (second elem) acc))
         g
         (zip (graph-nodes g) los)))

(check-satisfied (rename G1 '(aa bb cc dd ee))
                 (graph=?/curried
                  G7))