#lang htdp/isl+

(require 2htdp/image)
(require 2htdp/universe)
; A KMCA (K-Means Clustering Assignment) is a
; (make-assignment [List-of Centroid] [List-of Nat] Boolean)
(define-struct assignment (centroids labels no-reassignment?))
; - where centroids is the current list of centroids (ordered from 0...k-1)
; - labels are the labels assigned to each datapoint
;   labels are indices into the centroids list
;   (the first datapoint is labeled with the first element in labels,
;    second point the second label, etc.)
; - and no-reassignment? keeps track of whether or not re-assignment has occurred
 
; A Centroid is a (make-centroid Number Number)
(define-struct centroid [x y])
; - where x is the x-coordinate of the centroid
; - and y is the y-coordinate of the centroid
 
; A Datapoint is a (make-datapoint Number Number)
(define-struct datapoint [x y])
; - where x is the x-coordinate of the data point
; - and y is the y-coordinate of the data point



(define (firstN num lis)
  (cond
    [(= num 0) '()]
    [(empty? lis) '()]
    [else (cons (first lis) (firstN (sub1 num) (rest lis)))]))

(check-expect (firstN 3 (list 1 2 3 4 5)) (list 1 2 3))
(check-expect (firstN 3 (list 1 2)) (list 1 2))

(define (dist dp ct)
  (sqrt (+ (* (- (datapoint-x dp) (centroid-x ct))  (- (datapoint-x dp) (centroid-x ct)))
           (* (- (datapoint-y dp) (centroid-y ct))  (- (datapoint-y dp) (centroid-y ct))))))

(check-expect (dist (make-datapoint 3 4) (make-centroid 6 8)) 5)

(define (mean lodp)
  (let ([sumX (foldr (lambda (elem acc) (+ acc (datapoint-x elem))) 0 lodp)]
        [sumY (foldr (lambda (elem acc) (+ acc (datapoint-y elem))) 0 lodp)])
    (make-datapoint (/ sumX (length lodp)) (/ sumY (length lodp)))))
 
#;(check-expect (mean (list
                       (make-datapoint 1 2)
                       (make-datapoint 3 4)
                       (make-datapoint 10 2)))
                (make-datapoint 4.6 2.6))

(define (mean-c lolodp)
  (foldr (lambda (elem acc) (let ([point (mean elem)]) (cons (make-centroid (datapoint-x point) (datapoint-y point)) acc)))
         '()
         lolodp))

; cluster : [List-of Nat] Nat [List-of X] -> [List-of [List-of X]]
; Given a list of labels and the number of clusters, cluster lox
; (length labels) = (length lox)
(check-expect (cluster (list 0 1 3 0 1 3)
                       4
                       (list "a" "b" "c" "d" "e" "f"))
              (list (list "a" "d")
                    (list "b" "e")
                    '()
                    (list "c" "f")))

(define (cluster labels k lox)
  (cond
    [(= k 0) '()]
    [else (append (cluster labels (sub1 k) lox)
                  (list (foldr (lambda (x y z)
                                 (if (eq? x (- k 1))
                                     (append (list y) z)
                                     z))
                               '()
                               labels
                               lox)))]))

; assign-new-labels : [List-of Centroid] Nat [List-of Datapoint]  -> [List-of Nat]
; Given the current centroids and the list of data points, output the new labels
(check-expect (assign-new-labels (list (make-centroid -5 -5) (make-centroid 5 5))
                                 2
                                 (list (make-datapoint -20 -20)
                                       (make-datapoint -3 1)
                                       (make-datapoint 20 20)))
              (list 0 0 1))

(define (assign-new-labels centroids k lodp)
  (cond
    [(empty? lodp) '()]
    [(cons? lodp) (append
                   (list (local
                           [(define c (argmin (lambda (x) (dist (first lodp) x)) centroids))]
                           (foldr (lambda (x y z) (if (and (eq? (centroid-x x) (centroid-x c))
                                                           (eq? (centroid-y x) (centroid-y c)))
                                                      y
                                                      z))
                                  -1
                                  centroids
                                  (build-list (length centroids) (lambda (x) x)))))
                   (assign-new-labels centroids k (rest lodp)))]))

(define (initial-assignment k lodp)
  (let
      ([centroids (map (lambda (x) (make-centroid (datapoint-x x) (datapoint-y x))) (firstN k lodp))])
    (make-assignment centroids (assign-new-labels centroids k lodp) false)))

(define as1 (initial-assignment 3 (list
                                   (make-datapoint 1 2)
                                   (make-datapoint 4 1)
                                   (make-datapoint 2 0)
                                   (make-datapoint 8 5)
                                   (make-datapoint 3 3))))

(define dp (list
            (make-datapoint 1 2)
            (make-datapoint 4 1)
            (make-datapoint 2 0)
            (make-datapoint 8 5)
            (make-datapoint 3 3)))

(define (next-assignment kmca k lodp)
  (let
      ([centroids (mean-c (build-list k
                                      (lambda (x)
                                        (foldr
                                         (lambda (elem1 elem2 acc) (if (= x elem1) (cons elem2 acc) acc))
                                         '()
                                         (assignment-labels kmca)
                                         lodp))))])
    (make-assignment centroids (assign-new-labels centroids k lodp) (equal? (assign-new-labels centroids k lodp) (assignment-labels kmca)))))

(next-assignment as1 3 dp)

(define SIZE 200)

(define BG (empty-scene SIZE SIZE))
(define COLORS (list "red" "purple" "blue" "green" "yellow" "orange" "pink" "grey"))
 
; draw-centroid : Centroid Color Image -> Image
; Draw a centroid on the given image
(check-expect
 (draw-centroid (make-centroid 0 0) "red" (circle 10 "solid" "black"))
 (place-image (text "X" 20 "red") 0 0 (circle 10 "solid" "black")))
(define (draw-centroid ctr color bg)
  (place-image (text "X" 20 color) (centroid-x ctr) (centroid-y ctr) bg))
 
; draw-point : Datapoint Color Image -> Image
; Draw a datapoint onto the given image
(check-expect
 (draw-point (make-datapoint 10 2) "red" (circle 10 "solid" "black"))
 (place-image (circle 3 "outline" "red") 10 2 (circle 10 "solid" "black")))
(define (draw-point dp color bg)
  (place-image (circle 3 "outline" color) (datapoint-x dp) (datapoint-y dp) bg))

; draw-shapes : [List-of X] [List-of Nat] [X Color Image -> Image] Image -> Image
; Draw shapes on bg at xs using colors from labels
(check-expect (draw-shapes (list (make-centroid 0 0) (make-centroid 1 1))
                           (list 0 3)
                           draw-centroid
                           BG)
              (draw-centroid (make-centroid 0 0) (first COLORS)
                             (draw-centroid (make-centroid 1 1) (fourth COLORS)
                                            BG)))
(define (draw-shapes xs labels x->image bg)
  (foldr (lambda (x y z) (draw-centroid x (list-ref COLORS y) z))
         bg
         xs
         labels))

(define (draw-points lodp labels image)
  (foldr (lambda (x y z) (draw-point x (list-ref COLORS y) z))
         image
         lodp
         labels))

(define (draw-centroids loc k image)
  (foldr (lambda (x y z) (draw-centroid x (list-ref COLORS y) z))
         image
         loc
         (build-list k identity)))

(define (draw kmca k lodp)
  (draw-centroids (assignment-centroids kmca) k
                  (draw-points lodp (assignment-labels kmca) BG)))

; main : PosInt [List-of Datapoint] -> [List-of [List-of Datapoint]]
; run k-means clustering and output the datapoints binned into their respective clusters
(define (main k lop)
  (local
    [; next-assignment/main : KMCA -> KMCA
     ; Advance to the next assignment
     (define (next-assignment/main assignment)
       (next-assignment assignment k lop))
     ; draw/main : KMCA -> KMCA
     ; Draw the current clusters and points
     (define (draw/main assignment)
       (draw assignment k lop))]
    (cluster
     (assignment-labels
      (big-bang (initial-assignment k lop)
        [on-tick next-assignment/main 1]
        [to-draw draw/main]
        [stop-when assignment-no-reassignment?]))
     k lop)))

; random-datapoint : ? -> Datapoint
; Make a random datapoint
(define (random-datapoint _)
  (make-datapoint (random SIZE) (random SIZE)))
(define DATAPOINTS (build-list 10000 random-datapoint))
(main 7 DATAPOINTS)