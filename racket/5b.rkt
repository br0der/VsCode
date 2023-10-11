#lang htdp/isl
(require 2htdp/image)
(require 2htdp/universe)


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
(define (wire-temp cell)
  (... (wiredat-name) ... (wiredate-isInput) ...))

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
(define (gate-temp cell)
  (cond
    [(string=? (gatedat-logic cell) NOT) ... ]
    [(string=? (gatedat-logic cell) OR) ... ]
    [(string=? (gatedat-logic cell) AND) ... ]))

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
(define NOT-DOWN-DAT (make-gatedat NOT DOWN))
(define OR-LEFT-DAT (make-gatedat OR LEFT))
(define AND-LEFT-DAT (make-gatedat AND LEFT))

; - For a "plate", the Data will be null.
(define PLATE-DAT null)

; - For an "empty", the Data will be null.
(define EMPTY-DAT null)

(define-struct cell [type data])

; A Cell is a (make-cell type data)
(define CellSig (signature [CellOf String Any]))
; represents the type of Cell, and the data associated with that type of Cell

(define (cell-temp c)
  (cond
    [(string=? (cell-type c) TYP-WIRE) ...]
    [(string=? (cell-type c) TYP-GATE) ...]
    [(string=? (cell-type c) TYP-PLATE) ...]
    [(string=? (cell-type c) TYP-EMPTY) ...]))

; Examples
(define X-CELL (make-cell TYP-WIRE X-WIRE-DAT))
(define Y-CELL (make-cell TYP-WIRE Y-WIRE-DAT))
(define Z-CELL (make-cell TYP-WIRE Z-WIRE-DAT))
(define NOT-DOWN-GATE (make-cell TYP-GATE NOT-DOWN-DAT))
(define AND-LEFT-GATE (make-cell TYP-GATE AND-LEFT-DAT))
(define PLATE (make-cell TYP-PLATE PLATE-DAT))
(define EMPTY (make-cell TYP-EMPTY EMPTY-DAT))

(define CELL-SIZE 50)

; cell->image : Cell -> Image
; Purpose: Displays a cell based on its relevant data
(define (cell->image currCell)
 (cond
   [(string=? (cell-type currCell) TYP-WIRE)
    (overlay
     (rectangle CELL-SIZE CELL-SIZE "outline" "black")
     (overlay
      (text (wiredat-name (cell-data currCell)) (/ CELL-SIZE 2) (if (wiredat-isInput (cell-data currCell)) "white" "black"))
      (rectangle CELL-SIZE CELL-SIZE "solid" "gray")))]
   [(string=? (cell-type currCell) TYP-GATE)
    (overlay
     (rectangle CELL-SIZE CELL-SIZE "outline" "black")
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
     (rectangle CELL-SIZE CELL-SIZE "solid" "blue")))]
   [(string=? (cell-type currCell) TYP-PLATE)
    (overlay
     (rectangle CELL-SIZE CELL-SIZE "outline" "black")
     (rectangle CELL-SIZE CELL-SIZE "solid" "yellow"))]
   [(string=? (cell-type currCell) TYP-EMPTY)
    (rectangle CELL-SIZE CELL-SIZE "outline" "black")]))



(check-expect (cell->image X-CELL)
              (overlay
               (rectangle CELL-SIZE CELL-SIZE "outline" "black")
               (overlay
                (text (wiredat-name (cell-data X-CELL)) (/ CELL-SIZE 2) "white")
                (rectangle CELL-SIZE CELL-SIZE "solid" "gray"))))
(check-expect (cell->image NOT-DOWN-GATE)
              (overlay
               (rectangle CELL-SIZE CELL-SIZE "outline" "black")
               (overlay
                (text (string-append
                       "NOT"
                       (string-append
                        "\n   ↓"))
                      (round (/ CELL-SIZE 2.5))
                      "WHITE")
                (rectangle CELL-SIZE CELL-SIZE "solid" "blue"))))
(check-expect (cell->image PLATE)
              (overlay
               (rectangle CELL-SIZE CELL-SIZE "outline" "black")
               (rectangle CELL-SIZE CELL-SIZE "solid" "yellow")))
(check-expect (cell->image EMPTY)
              (rectangle CELL-SIZE CELL-SIZE "outline" "black"))


(define L1 (list X-CELL Y-CELL Z-CELL EMPTY PLATE NOT-DOWN-GATE))
(define L2 (list EMPTY PLATE NOT-DOWN-GATE Z-CELL Y-CELL X-CELL))
(define L3 (list EMPTY))

(: containedIn? ([ListOf CellSig] [ListOf CellSig] -> Boolean))
; Purpose: Checks if one list of Cells is contained in another list of cells
(define (containedIn? lis1 lis2)
  (cond
    [(empty? lis1) true]
    [(cons? lis1) (and (member? (first lis1) lis2) (containedIn? (rest lis1) lis2))]))
(check-expect (containedIn? L1 L2) true)
(check-expect (containedIn? L1 L3) false)
(check-expect (containedIn? L3 L2) true)

(: cell-set-equal? ([ListOf CellSig] [ListOf CellSig] -> Boolean))
; Purpose: Uses containedIn? to check if one lis is contained in another, and makes sure their lengths are the same.
;          If either of these are false, it returns false.
(define (cell-set-equal? lis1 lis2)
  (and (= (length lis1) (length lis2)) (containedIn? lis1 lis2)))

(check-expect (cell-set-equal? L1 L2) true)
(check-expect (cell-set-equal? L1 L3) false)
(check-expect (cell-set-equal? L3 L2) false)

(define Column (signature [ListOf CellSig]))
; Interpretation: A column is a list of Cells, which will be displayed vertically
; Examples:
(define COL1 (list X-CELL Y-CELL EMPTY EMPTY))
(define COL2 (list PLATE Z-CELL NOT-DOWN-GATE EMPTY))
(define COL3 (list EMPTY EMPTY AND-LEFT-GATE EMPTY))

(define (column-temp col)
  (... (cond
    [(empty? col) ...]
    [(cons? col) (... (first col) ... (column-temp (rest col)) ...)]) ...))

(define Grid (signature [ListOf Column]))
; Interpretation: A grid is a list of Columns, each which contain cells. Each cell can be accessed through a
;                 function using a Posn, but the each cell does not know its own location.
; Examples:
(define GRID1 (list COL1 COL2 COL3))
(define GRID2 (list COL3 COL2 COL1))

(define (grid-temp gr)
  (... (cond
    [(empty? gr) ...]
    [(cons? gr) (... (column-temp (first gr)) ... (grid-temp (rest gr)) ...)]) ...))

(define Image (signature (predicate image?)))

(: grid->image (Grid -> Image))
;; Purpose: takes a list of colums and returns an image
(define (grid->image gr)
  (cond
    [(empty? gr) (rectangle 0 0 "solid" "white")]
    [(cons? gr) (overlay/xy
                 (column->image (first gr)) CELL-SIZE 0
                 (grid->image (rest gr)))]
))

(check-expect (grid->image GRID1) (overlay/xy (column->image COL1)  CELL-SIZE 0
                                              (overlay/xy (column->image COL2) CELL-SIZE 0
                                              (column->image COL3) )))

(check-expect (grid->image GRID2) (overlay/xy (column->image COL3)  CELL-SIZE 0
                                              (overlay/xy (column->image COL2) CELL-SIZE 0
                                              (column->image COL1) )))

(: column->image (Column -> Image))
;; Purpose: takes a list of cells (column) and returns an image 
(define (column->image col)
  (cond
    [(empty? col) (rectangle 0 0 "solid" "white")]
    [(cons? col) (overlay/xy
                 (cell->image (first col)) 0 CELL-SIZE
                 (column->image (rest col)))]
))

(grid->image GRID1)

(check-expect(column->image COL1) (overlay/xy (cell->image X-CELL) 0 CELL-SIZE
                                              (overlay/xy (cell->image Y-CELL) 0 CELL-SIZE
                                              (overlay/xy (cell->image EMPTY) 0 CELL-SIZE (cell->image EMPTY)  ))))

(check-expect(column->image COL2) (overlay/xy (cell->image PLATE) 0 CELL-SIZE
                                              (overlay/xy (cell->image Z-CELL) 0 CELL-SIZE
                                              (overlay/xy (cell->image NOT-DOWN-GATE) 0 CELL-SIZE (cell->image EMPTY)  ))))

(define Posn (signature (predicate posn?)))

(: get-index ([ListOf Any] Number -> (mixed Column CellSig Boolean)))
; Purpose: Given a list of either columns or Cells and the index you want to get,
;          gets the element at that index, of false if it is out of bounds
(define (get-index lis idx)
  (cond
    [(< idx 0) false]
    [(empty? lis) false]
    [(zero? idx) (first lis)]
    [(cons? lis) (get-index (rest lis) (- idx 1))]))

(check-expect (get-index (list X-CELL Y-CELL EMPTY PLATE) -1) false)
(check-expect (get-index (list X-CELL Y-CELL EMPTY PLATE) 0) X-CELL)
(check-expect (get-index (list X-CELL Y-CELL EMPTY PLATE) 1) Y-CELL)
(check-expect (get-index (list X-CELL Y-CELL EMPTY PLATE) 2) EMPTY)
(check-expect (get-index (list X-CELL Y-CELL EMPTY PLATE) 3) PLATE)
(check-expect (get-index (list X-CELL Y-CELL EMPTY PLATE) 4) false)


(: get-cell (Grid Posn -> (mixed CellSig Boolean)))
; Purpose: Given a Grid and a posn which stores the x and y, it returns the cell at
;          that index, or false if it is out of bounds
(define (get-cell gr pos)
  (cond
    [(< (posn-x pos) 0) false]
    [(boolean? (get-index gr (posn-x pos))) false]
    [(boolean? (get-index (get-index gr (posn-x pos)) (posn-y pos))) false]
    [else (get-index (get-index gr (posn-x pos)) (posn-y pos))]))

(check-expect (get-cell GRID1 (make-posn -1 0)) false)
(check-expect (get-cell GRID1 (make-posn 0 0)) X-CELL)
(check-expect (get-cell GRID1 (make-posn 2 2)) AND-LEFT-GATE)
(check-expect (get-cell GRID1 (make-posn 3 2)) false)
(check-expect (get-cell GRID1 (make-posn 0 4)) false)
(check-expect (get-cell GRID1 (make-posn 2 3)) EMPTY)

(: set-in-col (Column Number CellSig -> (mixed Column Boolean)))
; Purpose: Given a Grid and a posn which stores the x and y, it returns the cell at
;          that index, or false if it is out of bounds
(define (set-in-col col y cll)
  (cond
    [(< y 0) false]
    [(empty? col) false]
    [(zero? y) (cons cll (rest col))]
    [(boolean? (set-in-col (rest col) (- y 1) cll)) false]
    [else (cons
           (first col)
           (set-in-col (rest col) (- y 1) cll))]))

(check-expect (set-in-col (list X-CELL Y-CELL EMPTY PLATE) -1 PLATE) false)
(check-expect (set-in-col (list X-CELL Y-CELL EMPTY PLATE) 2 PLATE) (list X-CELL Y-CELL PLATE PLATE))
(check-expect (set-in-col (list X-CELL Y-CELL EMPTY PLATE) 1 EMPTY) (list X-CELL EMPTY EMPTY PLATE))
(check-expect (set-in-col (list X-CELL Y-CELL EMPTY PLATE) 2 EMPTY) (list X-CELL Y-CELL EMPTY PLATE))
(check-expect (set-in-col (list X-CELL Y-CELL EMPTY PLATE) 4 X-CELL) false)

(: set-cell (Grid Posn CellSig -> (mixed Grid Boolean)))
; Purpose: Given a Grid and a posn which stores the x and y, it returns the cell at
;          that index, or false if it is out of bounds
(define (set-cell gr pos cll)
  (cond
    [(< (posn-x pos) 0) false]
    [(empty? gr) false]
    [(zero? (posn-x pos)) (if (boolean? (set-in-col (first gr) (posn-y pos) cll))
                          false
                          (cons (set-in-col (first gr) (posn-y pos) cll) (rest gr)))]
    [(boolean? (set-cell (rest gr) (make-posn (- (posn-x pos) 1) (posn-y pos)) cll)) false]
    [else (cons
           (first gr)
           (set-cell (rest gr) (make-posn (- (posn-x pos) 1) (posn-y pos)) cll))]))

;(grid->image (set-cell GRID1 (make-posn 1 2) X-CELL))
(check-expect (set-cell GRID1 (make-posn 1 2) X-CELL)
              (list
               (list X-CELL Y-CELL EMPTY EMPTY)
               (list PLATE Z-CELL X-CELL EMPTY)
               (list EMPTY EMPTY AND-LEFT-GATE EMPTY)))
(check-expect (set-cell GRID1 (make-posn 0 0) EMPTY)
              (list
               (list EMPTY Y-CELL EMPTY EMPTY)
               (list PLATE Z-CELL NOT-DOWN-GATE EMPTY)
               (list EMPTY EMPTY AND-LEFT-GATE EMPTY)))
(check-expect (set-cell GRID1 (make-posn 2 3) PLATE)
              (list
               (list X-CELL Y-CELL EMPTY EMPTY)
               (list PLATE Z-CELL NOT-DOWN-GATE EMPTY)
               (list EMPTY EMPTY AND-LEFT-GATE PLATE)))
(check-expect (set-cell GRID1 (make-posn 3 3) PLATE) false)
(check-expect (set-cell GRID1 (make-posn 2 4) PLATE) false)
(check-expect (set-cell GRID1 (make-posn -1 3) PLATE) false)
(check-expect (set-cell GRID1 (make-posn 2 -1) PLATE) false)

(: get-neighbors (Grid Posn -> (mixed [ListOf CellSig] Boolean)))
; Purpose: Given a grid and a posn, returns a list of its neighbors in the order top, right, bottom, left
(define (get-neighbors gr pos)
  (if (boolean? (get-cell gr pos))
      false
      (filter
       cell?
       (list
        (get-cell gr (make-posn (posn-x pos) (- (posn-y pos) 1)))
        (get-cell gr (make-posn (+ (posn-x pos) 1) (posn-y pos)))
        (get-cell gr (make-posn (posn-x pos) (+ (posn-y pos) 1)))
        (get-cell gr (make-posn (- (posn-x pos) 1) (posn-y pos)))))))

(check-expect (get-neighbors GRID1 (make-posn 0 0)) (list PLATE Y-CELL))
(check-expect (get-neighbors GRID1 (make-posn 2 3)) (list AND-LEFT-GATE EMPTY))
(check-expect (get-neighbors GRID1 (make-posn 1 1)) (list PLATE EMPTY NOT-DOWN-GATE Y-CELL))