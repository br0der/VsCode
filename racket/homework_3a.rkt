#lang htdp/bsl
(require 2htdp/image)
(require 2htdp/universe)
; A PS (Photo Shoot) is one of:
; - (make-launch Number Interval)
(define-struct launch [photographer goal])


; - (make-flight Number Interval Posn)
(define-struct flight [photographer goal drone])

; Where:
;   - photographer represents a photographer's x-coordinate on the ground
;   - goal represents the range of the desired image to to be captured at the ground-level (interval)
;   - drone (if any) represents the drone's x/y position (with 0, 0 at the bottom left)
; All numbers are measured in pixels.
 
; An Interval is a (make-interval Number Number)
(define-struct interval [left right])
; and represents the leftmost and rightmost range of an interval in pixel coordinates (inclusive)
;----------------------------------------------------------------------------------------------------------------






;TEMPLATE
(define (photoshoot-temp PS)
  (cond
    [(flight? PS )...]
    [(launch? PS )...]
   )
  )

(define (launch-temp l)
  (...
   (launch-photographer l)
   (interval-temp(launch-goal l))
   ...)

  )


(define  (flight-temp f)
  (...(flight-photographer f)
     (interval-temp (flight-goal f))
     (posn-temp(flight-drone f))...)
  )


(define (posn-temp p)
  (...(posn-x p)
      (posn-y p)
   ...))


(define (interval-temp i)
  (...(interval-left i)
      (interval-right i)
   ...)
  )


;EXAMPLES

(define INTERVAL (make-interval 30 70))

(define PHOTOGRAPHER1 4)
(define PHOTOGRAPHER2 9)
(define PHOTOGRAPHER3 12)

(define GOAL INTERVAL)

(define DRONE1 (make-posn 14 24))
(define DRONE2 (make-posn 14 22))
(define DRONE3 (make-posn 12 26))
(define DRONE4 (make-posn 16 26))


;EXERCISE 2
;PS -> PS
;Purpose: this function, given a PS, moves the drone (if any) down by 1 pixel.

(define (falling-drone PS)
  (cond
    [(flight? PS) 
     (make-flight (flight-photographer PS) (flight-goal PS) (make-posn (posn-x (flight-drone PS)) (-(posn-y (flight-drone PS))1))   ) ]
    [(launch? PS) PS]
    )
  )

(check-expect
 (falling-drone (make-flight PHOTOGRAPHER1 GOAL DRONE1) )
 (make-flight PHOTOGRAPHER1 GOAL (make-posn 14 23)))
(check-expect
 (falling-drone (make-launch PHOTOGRAPHER2 GOAL  ) )
 (make-launch PHOTOGRAPHER2 GOAL ))




;EXERCISE 3

;PS->PS
;Purpose: this function, given a PS without a drone in flight, puts the drone
;in flight at 20 pixels in the air and 15 pixels to the right of the photographer.

(define (launch-drone PS)
  (cond
    [(launch? PS)
     (make-flight
      (launch-photographer PS)
      (launch-goal PS)
      (make-posn (+ 15 (launch-photographer PS)) 20))]
    [(flight? PS) PS]))

(check-expect
 (launch-drone (make-launch PHOTOGRAPHER3 GOAL))
 (make-flight PHOTOGRAPHER3 GOAL (make-posn (+ PHOTOGRAPHER3 15) 20)))

;EXERCISE 4

;PS->boolean
;Purpose: this function determines if the shoot is over. The shoot is over if the
;drone has crashed (height = 0), or if the drone has captured the goal.

(define (shoot-over? PS)
  (cond
    [(flight? PS)
     (cond
       [(<= (posn-y (flight-drone PS)) 0) #true]
       [(and (<=
              (- (posn-x (flight-drone PS)) (/ (posn-y (flight-drone PS)) 2))
              (interval-left (flight-goal PS)))
             (>=
              (+ (posn-x (flight-drone PS)) (/ (posn-y (flight-drone PS)) 2))
              (interval-right (flight-goal PS)))) #true]
       [else #false])]
    [else #false]
   )
  )

(check-expect (shoot-over? (make-flight PHOTOGRAPHER2 GOAL DRONE1) ) true)
(check-expect (shoot-over? (make-flight PHOTOGRAPHER2 GOAL DRONE2) ) false)
(check-expect (shoot-over? (make-flight PHOTOGRAPHER2 GOAL DRONE3) ) false )
(check-expect (shoot-over? (make-flight PHOTOGRAPHER2 GOAL DRONE4) ) false )


;EXERCISE 5

(define WIDTH 100)
(define HEIGHT 100)
(define WIDTH-P 8)
(define HEIGHT-P 15)
(define WIDTH-D 20)
(define HEIGHT-D 5)

(define (draw-drone ps)
  (cond
     [(flight? ps) (rectangle WIDTH-D HEIGHT-D "solid" "black")]
     [(launch? ps) (rectangle 0 0 "solid" "white")]))
(define (drone-offset-x ps)
  (cond
     [(flight? ps) (* -1 (posn-x (flight-drone ps)))]
     [(launch? ps) 0]))
(define (drone-offset-y ps)
  (cond
     [(flight? ps) (- (posn-y (flight-drone ps)) HEIGHT)]
     [(launch? ps) 0]))


(define (draw-ps ps)
  (overlay/xy
   (draw-drone ps)
   (drone-offset-x ps)
   (drone-offset-y ps)
   (overlay/xy
    (rectangle WIDTH-P HEIGHT-P "solid" "blue")
    (cond
      [(flight? ps) (* -1 (flight-photographer ps))]
      [(launch? ps) (* -1 (launch-photographer ps))])
    (+ (* -1 HEIGHT) HEIGHT-P)
    (empty-scene WIDTH HEIGHT))))

