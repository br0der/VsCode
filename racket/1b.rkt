#lang htdp/bsl
(require 2htdp/image)
(require 2htdp/universe)
(require racket/bool)

(define (dist x y)
  (sqrt(+ (* x x) (* y y)))
)

(check-expect (dist 3 4) 5)
(check-expect (dist 6 8) 10)

(define (iff happy outside)
  (not (xor happy outside))
)

(check-expect (iff true true) true)
(check-expect (iff true false) false)
(check-expect (iff false true) false)
(check-expect (iff false false) true)

(define (image-classify img)
  (cond
    [(> (image-width img) (image-height img)) "wide"]
    [(< (image-width img) (image-height img)) "tall"]
    [else "square"]
  )
)

(check-expect (image-classify (rectangle 10 20 "solid" "white")) "tall")
(check-expect (image-classify (rectangle 30 20 "solid" "white")) "wide")
(check-expect (image-classify (rectangle 20 20 "solid" "white")) "square")

(define (image-area img)
  (* (image-width img) (image-height img))
)

(check-expect (image-area (rectangle 10 20 "solid" "white")) 200)
(check-expect (image-area (rectangle 300 1 "solid" "white")) 300)