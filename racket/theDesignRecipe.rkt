#lang htdp/bsl
(require 2htdp/image)
(require 2htdp/universe)
(require racket/bool)

(define CIRCLE "circle")
(define SQUARE "square")
(define TRIANGLE "triangle")

; draw: Shape -> Image
; Draw the shape
(define (draw shape)
  (cond [(string=? shape "circle")   (circle 10 "solid" "red")]
        [(string=? shape "square")   (square 5 "solid" "blue")]
        [(string=? shape "triangle") (triangle 7 "solid" "orange")]))
 
(check-expect (draw CIRCLE)   (circle 10 "solid" "red"))
(check-expect (draw SQUARE)   (square 5 "solid" "blue"))
(check-expect (draw TRIANGLE) (triangle 7 "solid" "orange"))

(define (draw/scene shape)
  (overlay shape (empty-scene 100 100)))

(define (next-shape shape)
  (cond
    [(string=? shape "circle") "square"]
    [(string=? shape "square") "triangle"]
    [(string=? shape "triangle") "circle"]))

(draw/scene (draw (next-shape CIRCLE)))