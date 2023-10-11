;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname program2) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
(require 2htdp/image)

(define (score-by-length list)
  (cond
    [(empty? list) 0]
    [else (+
           (string-length (first list))
           (score-by-length (rest list)))]
  )
)

(define (overlay-all list)
  (cond
   [(empty? list) (rectangle 10 10 "solid" "white")]
   [else (overlay
          (first list)
          (overlay-all (rest list))
         )
   ]
  )
 )

(define (bar-graph list)
  (cond
    [(empty? list) (rectangle 1 1 "solid" "white")]
    [else (beside/align
           "bottom"
           (rectangle 10 (first list) "solid" "black")
           (bar-graph (rest list))
          )
    ]
  )
)

(define (is-in? value list)
  (cond
    [(empty? list) #false]
    [(equal? value (first list)) #true]
    [else (is-in? value (rest list))]
  )
)

(define (len list)
  (cond
    [(empty? list) 0]
    [else (+ (len (rest list)) 1)]
  )
)

(define (words-to-sentence list)
  (cond
    [(empty? list) ""]
    [(equal? (len list) 1) (first list)]
    [else (string-append
            (string-append
             (first list)
              " "
            )
            (words-to-sentence (rest list))
          )
    ]
  )
)

;(define a (cons "a" (cons "b" (cons "c" '()))))

;(words-to-sentence a)