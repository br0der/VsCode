#lang htdp/bsl
(require 2htdp/image)
(require 2htdp/universe)
(require racket/bool)

; A CSG (CoinShuffleGame) is a (make-csg CoinOrFalse CoinOrFalse CoinOrFalse)
(define-struct csg [left middle right])
; and represents the three cups in a coin shuffle game, and what is under them

; A CoinOrFalse is one of:
; - #false
; - Number
; and represents either no coin or the coin's monetary value

(define CoinOrFalse1 #false)
(define CoinOrFalse2 1)
(define CoinOrFalse3 5)

; A Guess is one of:
; - "left"
; - "middle"
; - "right



(define Guess1 "left")
(define Guess2 "middle")
(define Guess3 "right")

;;function that takes in 3 values 
(define (CoinShuffleGame CoF1 CoF2 CoF3)
  (make-csg CoF1 CoF2 CoF3))

;; game is an instance of Coinshuffle, left cup has 1, mid 5, right false




(define (shuffle-right csg1)
  ;;order is important
  (make-csg (csg-right csg1) (csg-left csg1) (csg-middle csg1)))

(check-expect (shuffle-right (CoinShuffleGame 1 5 false)) (CoinShuffleGame false 1 5))
(check-expect (shuffle-right (CoinShuffleGame false 1 5)) (CoinShuffleGame 5 false 1))
(check-expect (shuffle-right (CoinShuffleGame 5 false 1)) (CoinShuffleGame 1 5 false))
;;to call function (suffle-right game) because game is an instance so we are passing an instance


(define(csg-value csgg guess1)
  (cond
    [(string=? guess1 "left")
     (cond
       [(number? (csg-left csgg)) (csg-left csgg)]
       [else 0])]
    [(string=? guess1 "middle")
     (cond
       [(number? (csg-middle csgg)) (csg-middle csgg)]
       [else 0])]
    [(string=? guess1 "right")
     (cond
       [(number? (csg-right csgg)) (csg-right csgg)]
       [else 0])]))
(check-expect (csg-value (CoinShuffleGame 1 5 false) "left") 1)
(check-expect (csg-value (CoinShuffleGame 1 5 false) "middle") 5)
(check-expect (csg-value (CoinShuffleGame 1 5 false) "right") 0)

(define (inflation csgg2 number)
  (make-csg (helper (csg-left csgg2) number) (helper(csg-middle csgg2) number) (helper(csg-right csgg2)number)))

(define (helper currentValue add)
   (cond
    [(number? currentValue)(+ currentValue add)]
    [else false]
    ))

;(define game (CoinShuffleGame 1 5 false))

(check-expect (inflation (CoinShuffleGame 1 5 false) 3) (CoinShuffleGame 4 8 false))
(check-expect (inflation (CoinShuffleGame false false false) 3) (CoinShuffleGame false false false))
(check-expect (inflation (CoinShuffleGame 1 2 3) 103) (CoinShuffleGame 104 105 106))

; Data
; - Definition
; - Interpretation
; - Examples
; - Template

; A type is one of:
; - "wire"
; - "gate"
; - "plate"
; - "empty"
; Interp - The string which identifies
;          what type of cell the current cell is

(define TYP-WIRE "wire")
(define TYP-GATE "gate")
(define TYP-PLATE "plate")
(define TYP-EMPTY "empty")

(define (type-temp type)
  (cond
    [(string=? type TYP-WIRE) ...]
    [(string=? type TYP-GATE) ...]
    [(string=? type TYP-EMPTY) ...]
    [(string=? type TYP-PLATE) ...]))

(define-struct wiredat [name isInput])
(define-struct gatedat [logic dir])

; Data is a structure, which can differ between types.
; - For a "wire", the Data will be (make-wireDat name isInput)
; - - name is a string which represents the short name which is displayed on the cell
; - - isInput is a boolean which is true if it is an input, and false otherwise
(define X-WIRE-DAT (make-wiredat "X" true))
(define Y-WIRE-DAT (make-wiredat "Y" true))
(define Z-WIRE-DAT (make-wiredat "Z" false))

; - For a "gate", the Data will be (make-gateDat logic dir)
; - - logic is a string which represents which logic gate the gate represents.
; - - Is one of:
; - - - "NOT"
; - - - "OR"
; - - - "AND"
(define NOT "NOT")
(define OR "OR")
(define AND "AND")
; - - dir is a string which represents which direction the current
; - - logic gate will send its output to
; - - Is one of:
; - - - "left"
; - - - "right"
; - - - "up"
; - - - "down"
(define LEFT "left")
(define RIGHT "right")
(define UP "up")
(define DOWN "down")
(define NOT-DOWN-DAT (make-gatedat NOT UP))
(define OR-LEFT-DAT (make-gatedat OR LEFT))
(define AND-LEFT-DAT (make-gatedat AND UP))

; - For a "plate", the Data will be null.
(define PLATE-DAT null)

; - For an "empty", the Data will be null.
(define EMPTY-DAT null)

(define-struct cell [type data])

; A Cell is a (make-cell type data)
; represents the type of Cell, and the data associated with that type of Cell

; Examples
(define X-CELL (make-cell TYP-WIRE X-WIRE-DAT))
(define Y-CELL (make-cell TYP-WIRE Y-WIRE-DAT))
(define Z-CELL (make-cell TYP-WIRE Z-WIRE-DAT))
(define NOT-DOWN-GATE (make-cell TYP-GATE NOT-DOWN-DAT))
(define PLATE (make-cell TYP-PLATE PLATE-DAT))
(define EMPTY (make-cell TYP-EMPTY EMPTY-DAT))

(define CELL-SIZE 50)

(define (cell->image currCell)
 (cond
   [(string=? (cell-type currCell) TYP-WIRE)
    (overlay
     (text (wiredat-name (cell-data currCell)) (/ CELL-SIZE 2) "black")
     (rectangle CELL-SIZE CELL-SIZE "solid" "gray"))]
   [(string=? (cell-type currCell) TYP-GATE)
    (overlay
     (text (string-append
            (gatedat-logic (cell-data currCell))
            (string-append
             "\n  "
             (cond
              [(string=? (gatedat-dir (cell-data currCell)) LEFT) "←"]
              [(string=? (gatedat-dir (cell-data currCell)) RIGHT) "→"]
              [(string=? (gatedat-dir (cell-data currCell)) UP) " ↑"]
              [(string=? (gatedat-dir (cell-data currCell)) DOWN) " ↓"])))
           (round (/ CELL-SIZE 2.5))
           "WHITE")
     (rectangle CELL-SIZE CELL-SIZE "solid" "blue"))]
   [(string=? (cell-type currCell) TYP-PLATE)
    (rectangle CELL-SIZE CELL-SIZE "solid" "yellow")]
   [(string=? (cell-type currCell) TYP-EMPTY)
    (rectangle CELL-SIZE CELL-SIZE "outline" "black")]))

;(cell->image X-CELL)
;(cell->image Y-CELL)
;(cell->image Z-CELL)
;(cell->image NOT-DOWN-GATE)
;(cell->image PLATE)
;(cell->image EMPTY)