;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname flags) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))

(require 2htdp/image)
(require 2htdp/universe)


(define WIDTH 100)
(define HEIGHT (/ WIDTH (/ 3 2)))
;vietnam

(overlay (star (/ HEIGHT 4) "solid" "gold")
 (rectangle WIDTH HEIGHT "solid" "crimson"))

;chile
(overlay/xy
  (overlay/xy
    (overlay
       (star (/ HEIGHT 6) "solid" "white")
       (rectangle (/ WIDTH 3) (/ HEIGHT 2) "solid" "mediumblue")
    )
    (/ WIDTH 3) 0
    (rectangle WIDTH (/ HEIGHT 2) "solid" "white")
  )
  0 0
  (rectangle WIDTH HEIGHT "solid" "crimson")
)

;suriname
(overlay
 (star (/ WIDTH 6) "solid" "gold")
 (rectangle WIDTH (/ HEIGHT 2) "solid" "crimson")
 (rectangle WIDTH (/ HEIGHT (/ 3 2)) "solid" "white")
 (rectangle WIDTH HEIGHT "solid" "forestgreen")
)

;saint lucia
(underlay/offset
 (rectangle WIDTH HEIGHT "solid" "deepskyblue")
 0 0
 (underlay/offset
  (overlay/xy
   (isosceles-triangle (/ HEIGHT (/ 9 5)) 30 "solid" "black")
   (/ WIDTH -36) (/ HEIGHT -8)
   (isosceles-triangle (/ HEIGHT (/ 7 5)) 30 "solid" "white")
  )
  0 (/ HEIGHT 5)
  (isosceles-triangle (/ HEIGHT (/ 12 5)) 60 "solid" "gold")
 )
)

;turkey
(underlay/offset
 (underlay/offset
  (rectangle WIDTH HEIGHT "solid" "orangered")
  (/ WIDTH -7) 0
  (underlay/offset
   (ellipse (/ WIDTH 2.8) (/ WIDTH 2.8) "solid" "white")
   (/ WIDTH 20) 0
   (ellipse (/ WIDTH 3.5) (/ WIDTH 3.5) "solid" "orangered")
   )
  )
 (/ WIDTH 15) 0
 (rotate 90 (star (/ WIDTH 8) "solid" "white"))
)