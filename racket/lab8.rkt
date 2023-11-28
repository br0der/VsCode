#lang htdp/isl+

(require htdp/dir)

 

;(define-struct file [name size date content])
;(define AFile (signature [FileOf String Number ADate String]))

; - where name is the name of the file (including extension)

; - size is the size of the file in bytes

; - date is the last modified date of the file

; - and content is the contents of the file

 

;(define-struct date [year month day hours minutes seconds])

;(define ADate (signature [DateOf Number Number Number Number Number Number]))

; - where year is the year the file was modified

; - month is the month the file was modified

; - day is the day the file was modified

; - hours is the hour the file was modified

; - minutes is the minute the file was modified

; - and seconds is the second the file was modified

 

;(define-struct dir [name dirs files])

;(define ADirectory (signature [DirOf Symbol [ListOf ADirectory] [ListOf AFile]]))

; - where name is the directory path

; - dirs is the list of sub-directories in this directory

; - and files is the list of files in this directory

;   (not including the ones in sub-directories)

 

;(: EMPTY-DIR ADirectory)

(define EMPTY-DIR (make-dir 'hopes&dreams '() '()))

 

;(: CAREER ADirectory)

(define CAREER

  (make-dir

   'Career

   (list (make-dir 'CareerApplications

                   '()

                   (list (make-file "CoverLetter.doc" 31744

                                    (make-date 2015 9 20 11 36 25) "")

                         (make-file "EmploymentApplication.pdf" 231010

                                    (make-date 2015 10 13 13 10 0) "")))

         (make-dir 'CareerMyJob

                   '()

                   (list (make-file "BackgroundCheck.pdf" 1040138

                                    (make-date 2016 8 23 10 27 10) "")

                         (make-file "I9.pdf" 963654

                                    (make-date 2015 11 20 15 49 45) "")

                         (make-file "JobOffer.pdf" 507887

                                    (make-date 2015 11 20 15 49 0) ""))))

   (list (make-file "References.docx" 11634

                    (make-date 2016 8 6 9 55 15) "")

         (make-file "Resume.doc" 34816

                    (make-date 2016 10 12 13 18 12) "")

         (make-file "Transcript.doc" 140288

                    (make-date 2015 9 11 9 3 0) ""))))

 

;(: file-temp (AFile -> Any))

(define (file-temp f)

  (... (file-name f) (file-size f) (date-temp (file-date f)) (file-content f)))

 

;(: date-temp (ADate -> Any))

(define (date-temp d)

  (... (date-year d) (date-month d) (date-hours d) (date-minutes d) (date-seconds d)))

 

;(: directory-temp (ADirectory -> Any))

(define (directory-temp d)

  (... (dir-name d) (lod-temp (dir-dirs d)) (lof-temp (dir-files d))))

 

;(: lod-temp ([ListOf ADirectory] -> Any))

(define (lod-temp lod)

  (cond [(empty? lod) ...]

        [(cons? lod) (... (directory-temp (first lod)) (lod-temp (rest lod)))]))

 

;(: lof-temp ([ListOf AFile] -> Any))

(define (lof-temp lof)

  (cond [(empty? lof) ...]

        [(cons? lof) (... (file-temp (first lof)) (lof-temp (rest lof)))]))



;(: count-files (ADirectory -> Number))

; Count the number of files in d and its sub-directories recursively

(define (count-files d)

  (foldr (λ (sub-dir count)

           (+ (count-files sub-dir) count))

         (length (dir-files d))

         (dir-dirs d)))

(check-expect (count-files EMPTY-DIR) 0)

(check-expect (count-files CAREER) 8)



(define EX1 (make-dir

             'Racket

             (list (make-dir

                    'subdr

                    '()

                    (list (make-file "despair.txt" 20 (make-date 1776 7 4 20 30 00) "We the people"))))

             (list (make-file "1b.rkt" 1037

                              (make-date 2023 10 12 11 30 00) "")

                   (make-file "2a.rkt" 1522

                              (make-date 2023 10 13 11 30 00) "")

                   (make-file "2b.rkt" 2350

                              (make-date 2023 10 14 11 30 00) "")

                   (make-file "3a.rkt" 1053

                              (make-date 2023 10 15 11 30 00) ""))))



(define (findFile dir name)

  (or

   (ormap (lambda (x) (findFile x name)) (dir-dirs dir))

   (ormap (lambda (x) (equal? name (file-name x))) (dir-files dir))))



(check-expect (findFile EX1 "despair.txt") true)

(check-expect (findFile CAREER "I9.pdf") true)

(check-expect (findFile CAREER "I8.pdf") false)



(define (totalSize dir)

  (+

   (foldr

    (lambda (elem acc) (+ acc (totalSize elem))) 0 (dir-dirs dir))

   (foldr

    (lambda (elem acc) (+ acc (file-size elem))) 0 (dir-files dir))))



(check-expect (totalSize EX1) 5982)

(check-expect (totalSize CAREER) 2961171)


(define (rename d src target)
  (cond [(empty? (dir-dirs d))
         (make-dir
          (dir-name d)
          '()
          (map (lambda (f) (if (equal? (file-name f) src)
                               (make-file target (file-size f) (file-date f) (file-content f))
                               f)) (dir-files d)))]
        [(cons? (dir-dirs d))
         (make-dir
          (dir-name d)
          (map (lambda (directory) (rename directory src target)) (dir-dirs d))
          (map (lambda (f) (if (equal? (file-name f) src) (make-file target (file-size f) (file-date f) (file-content f)) f)) (dir-files d)))]))

(check-expect (rename EX1 "despair.txt" "hope.txt")
              (make-dir

               'Racket

               (list (make-dir

                      'subdr

                      '()

                      (list (make-file "hope.txt" 20 (make-date 1776 7 4 20 30 00) "We the people"))))

               (list (make-file "1b.rkt" 1037

                                (make-date 2023 10 12 11 30 00) "")

                     (make-file "2a.rkt" 1522

                                (make-date 2023 10 13 11 30 00) "")

                     (make-file "2b.rkt" 2350

                                (make-date 2023 10 14 11 30 00) "")

                     (make-file "3a.rkt" 1053

                                (make-date 2023 10 15 11 30 00) ""))))

(check-expect (rename CAREER "JobOffer.pdf" "jkurfiredlol.pdf")

              (make-dir

               'Career

               (list (make-dir 'CareerApplications

                               '()

                               (list (make-file "CoverLetter.doc" 31744

                                                (make-date 2015 9 20 11 36 25) "")

                                     (make-file "EmploymentApplication.pdf" 231010

                                                (make-date 2015 10 13 13 10 0) "")))

                     (make-dir 'CareerMyJob

                               '()

                               (list (make-file "BackgroundCheck.pdf" 1040138

                                                (make-date 2016 8 23 10 27 10) "")

                                     (make-file "I9.pdf" 963654

                                                (make-date 2015 11 20 15 49 45) "")

                                     (make-file "jkurfiredlol.pdf" 507887

                                                (make-date 2015 11 20 15 49 0) ""))))

               (list (make-file "References.docx" 11634

                                (make-date 2016 8 6 9 55 15) "")

                     (make-file "Resume.doc" 34816

                                (make-date 2016 10 12 13 18 12) "")

                     (make-file "Transcript.doc" 140288

                                (make-date 2015 9 11 9 3 0) ""))))

; exericse 5

(define (size-matters d size)
  (cond [(empty? (dir-dirs d))
         (make-dir
          (dir-name d)
          '()
          (filter (lambda (f) (>= (file-size f) size)) (dir-files d)))]
        [(cons? (dir-dirs d))
         (make-dir
          (dir-name d)
          (map (lambda (directory) (size-matters directory size)) (dir-dirs d))
          (filter (lambda (f) (>= (file-size f) size)) (dir-files d)))]))

(check-expect (size-matters EX1 1500)
              (make-dir

               'Racket

               (list (make-dir

                      'subdr

                      '()

                      '()))

               (list 

                (make-file "2a.rkt" 1522

                           (make-date 2023 10 13 11 30 00) "")

                (make-file "2b.rkt" 2350

                           (make-date 2023 10 14 11 30 00) ""))))

; A FSC (FileSystemCompotent) is one of:
; - File
; - Dir
 
; A Dir is a (make-dir2 Symbol [List-of FSC])
(define-struct dir2 [name contents])


(define (num-files/dir d)
  (foldr (lambda (elem acc)
           (+ acc (cond
                    [(file? elem) 1]
                    [(dir2? elem) (num-files/dir elem)])))
         0
         (dir2-contents d)))

(define EX2
  (make-dir2
   'mcxample
   (list
    (make-file "2a.rkt" 1522

               (make-date 2023 10 13 11 30 00) "")

    (make-file "2b.rkt" 2350

               (make-date 2023 10 14 11 30 00) "")
    (make-file "References.docx" 11634

               (make-date 2016 8 6 9 55 15) "")

    (make-file "Resume.doc" 34816

               (make-date 2016 10 12 13 18 12) "")

    (make-file "Transcript.doc" 140288

               (make-date 2015 9 11 9 3 0) "")
    (make-dir2
     'steal
     (list
      (make-file "1b.rkt" 1037

                 (make-date 2023 10 12 11 30 00) "")

      (make-file "2a.rkt" 1522

                 (make-date 2023 10 13 11 30 00) "")

      (make-file "2b.rkt" 2350

                 (make-date 2023 10 14 11 30 00) "")

      (make-file "3a.rkt" 1053

                 (make-date 2023 10 15 11 30 00) ""))))))

(check-expect (num-files/dir EX2) 9)

(define (dir->directory d)
  (foldr (lambda (elem acc)
           (cond
             [(file? elem)
              (make-dir (dir-name acc) (dir-dirs acc) (cons elem (dir-files acc)))]
             [(dir2? elem)
              (make-dir (dir-name acc) (cons (dir->directory elem) (dir-dirs acc)) (dir-files acc))]))
         (make-dir (dir2-name d) '() '()) (dir2-contents d)))

(check-expect
 (dir->directory EX2)
 (make-dir
  'mcxample
  (list
   (make-dir
    'steal
    '()
    (list
     (make-file "1b.rkt" 1037 (make-date 2023 10 12 11 30 0) "")
     (make-file "2a.rkt" 1522 (make-date 2023 10 13 11 30 0) "")
     (make-file "2b.rkt" 2350 (make-date 2023 10 14 11 30 0) "")
     (make-file "3a.rkt" 1053 (make-date 2023 10 15 11 30 0) ""))))
  (list
   (make-file "2a.rkt" 1522 (make-date 2023 10 13 11 30 0) "")
   (make-file "2b.rkt" 2350 (make-date 2023 10 14 11 30 0) "")
   (make-file "References.docx" 11634 (make-date 2016 8 6 9 55 15) "")
   (make-file "Resume.doc" 34816 (make-date 2016 10 12 13 18 12) "")
   (make-file "Transcript.doc" 140288 (make-date 2015 9 11 9 3 0) ""))))