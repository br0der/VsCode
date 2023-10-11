#lang htdp/bsl
(require 2htdp/image)
(require 2htdp/universe)
(require racket/bool)

(define (scene t)
  (place-image
   (circle 50 "solid" "yellow")
   200
   (- 250 t)
   (rectangle 400 200 "solid" "blue")
  )
)

(animate scene)