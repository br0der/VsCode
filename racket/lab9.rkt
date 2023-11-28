#lang htdp/isl+

(require 2htdp/image)
(require 2htdp/universe)

(define GameOfLife (signature [ListOf [ListOf Boolean]]))
; where the length of the outer list is the same as all of the inner lists
; and represents alive (#t) and dead (#f) cells
(: TINY-GAME GameOfLife)
(define TINY-GAME
  '((#f #f #f #f)
    (#f #t #t #f)
    (#f #t #f #f)
    (#f #f #f #f)))
(: TINY-GAME+1 GameOfLife)
(define TINY-GAME+1
  '((#f #f #f #f)
    (#f #t #t #f)
    (#f #t #t #f)
    (#f #f #f #f)))
(: neighbors (Number Number GameOfLife -> [ListOf Boolean]))
; The neighbors of i, j in gol (i = row, j = column)
(define (neighbors i j gol)
  (list (get-cell (sub1 i) (sub1 j) gol)
        (get-cell (sub1 i) j        gol)
        (get-cell (sub1 i) (add1 j) gol)
        (get-cell i        (sub1 j) gol)
        (get-cell i        (add1 j) gol)
        (get-cell (add1 i) (sub1 j) gol)
        (get-cell (add1 i) j        gol)
        (get-cell (add1 i) (add1 j) gol)))
(check-expect (neighbors 1 1 TINY-GAME)
              (list #f #f #f
                    #f    #t
                    #f #t #f))
(check-expect (neighbors 3 1 TINY-GAME)
              (list #f #t #f
                    #f    #f
                    #f #f #f))
 
(: get-cell (Number Number GameOfLife -> Boolean))
; The value of the cell at y, x (looping around the ends of the list if necessary)
(define (get-cell y x gol)
  (local [(define n     (length gol))
          (define y-mod (modulo y n))
          (define x-mod (modulo x n))]
    (list-ref (list-ref gol y-mod) x-mod)))
(check-expect (get-cell 0 0 TINY-GAME) #f)
(check-expect (get-cell 4 4 TINY-GAME) #f)
(check-expect (get-cell 1 2 TINY-GAME) #t)
(check-expect (get-cell 5 6 TINY-GAME) #t)

(define CellUpdate (signature (Boolean [ListOf Boolean] -> Boolean)))
; It represents the rules by which a cell's new value is determined
(: range? (Number -> Boolean))
(define (range? n)
  (and (>= n 0)
       (<= n 8)))
 
; Represents a number in the range 0-8, inclusive
(define Num0-8 (signature (predicate range?)))
 
(: cell-update ([ListOf Num0-8] [ListOf Num0-8] -> CellUpdate))
; Output a cell update function with "birth" numbers and "survival" numbers

(define (cell-update birth survival)
  (lambda (curr lob)
    (let ([count (true-count lob)])
      (if curr
          (if (member? count survival)
              #t
              #f)
          (if (member? count birth)
              #t
              #f)))))

(define (true-count lob)
  (foldr (lambda (elem acc) (if elem (add1 acc) acc)) 0 lob))
(check-expect (true-count (first TINY-GAME)) 0)
(check-expect (true-count (second TINY-GAME)) 2)

(define (new-value/conway curr lob)
  ((cell-update (list 3) (list 2 3)) curr lob))

(check-expect (new-value/conway false (neighbors 3 3 TINY-GAME)) #f)
(check-expect (new-value/conway false (neighbors 2 2 TINY-GAME)) #t)
(check-expect (new-value/conway true (neighbors 1 1 TINY-GAME)) #t)

(define (next-grid gol)
  (build-list (length gol)
              (lambda (r)
                (build-list
                 (length (first gol))
                 (lambda (c) (new-value/conway (get-cell r c gol) (neighbors r c gol)))))))
(check-expect (next-grid TINY-GAME) TINY-GAME+1)

(define CELL-SIZE 5)
(define LIVE-CELL (color-frame "cadetblue" (square CELL-SIZE "solid" "seashell")))
(define DEAD-CELL (square CELL-SIZE "solid" "white"))

(define Image (signature (predicate image?)))
(: draw-grid (GameOfLife -> Image))
; Draw the game of life
(define (draw-grid gol)
  (cond
    [(empty? gol) (empty-scene 0 0)]
    [(cons? gol) (above (draw-row (first gol))
                        (draw-grid (rest gol)))]))
    
(check-expect (draw-grid TINY-GAME)
              (above (beside DEAD-CELL DEAD-CELL DEAD-CELL DEAD-CELL)
                     (beside DEAD-CELL LIVE-CELL LIVE-CELL DEAD-CELL)
                     (beside DEAD-CELL LIVE-CELL DEAD-CELL DEAD-CELL)
                     (beside DEAD-CELL DEAD-CELL DEAD-CELL DEAD-CELL)))

(define (draw-row lob)
  (cond
    [(empty? lob) (empty-scene 0 0)]
    [(cons? lob) (if (first lob)
                     (beside
                      LIVE-CELL
                      (draw-row (rest lob)))
                     (beside
                      DEAD-CELL
                      (draw-row (rest lob))))]))

(: main (GameOfLife -> GameOfLife))
; Run conway's game of life
(define (main gol)
  (big-bang gol
    [on-tick next-grid 1/2]
    [to-draw draw-grid]))

(define EX1 (list (list #f #f #f #f #f #f #f)
         (list #f #f #f #f #f #f #f)
         (list #f #f #f #f #f #f #f)
         (list #f #f #f #f #f #f #f)
         (list #f #f #f #f #t #t #t)
         (list #f #f #f #f #t #f #f)
         (list #f #f #f #f #f #t #f)))

#;(main
   (list (list #f #f #f #f #f #f #f)
         (list #f #f #f #f #f #f #f)
         (list #f #f #f #f #f #f #f)
         (list #f #f #f #f #f #f #f)
         (list #f #f #f #f #t #t #t)
         (list #f #f #f #f #t #f #f)
         (list #f #f #f #f #f #t #f)))

(define Coord
  (signature (predicate (λ (l)
                          (and (list? l)
                               (= (length l) 2)
                               (number? (first l))
                               (number? (second l)))))))
(define FirstState (signature [ListOf Coord]))

(: initial-grid (Number FirstState -> GameOfLife))
; A game of life with size grid-size with points in fs alive
; assume grid-size is larger than any number in fs
(define (initial-grid grid-size fs)
  (build-list grid-size (λ (x)
                          (build-list grid-size (λ (y)
                                                  (member? (list x y) fs))))))
(check-expect (initial-grid 4 (list (list 1 1)
                                    (list 1 2)
                                    (list 2 1))) TINY-GAME)

#;(main
   (initial-grid 50
                 (list (list 20 20)
                       (list 20 21)
                       (list 21 20)
                       (list 22 20)
                       (list 20 24)
                       (list 21 24)
                       (list 22 24)
                       (list 22 23))))

(define (helper tortise hare update)
  (if (equal? tortise hare)
      0
      (add1 (helper (next-grid tortise update) (next-grid (next-grid hare update) update) update))))

(define (make-repeater f n)
  (if (zero? n)
      (lambda (x) x)
      (f (make-repeater f (sub1 n)))))

(define (cycle-size init update)
  (let ([n (helper init (next-grid init update) update)])
    (let ([rep (make-repeater (lambda (x) (next-grid x update)) n)])
      (helper (rep init) (next-grid (rep init)) update))))
    
(cycle-size EX1 new-value/conway)