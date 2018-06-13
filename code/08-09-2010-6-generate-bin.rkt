#lang racket

(define (bin x)
  (define (helper i result)
    (cond
      ((= i 0) (cons 0 result))
      ((= i 1) (cons 1 result))
      (else (helper (quotient i 2) (cons (modulo i 2) result)))
     )
    )
  (helper x `()))

(define (generate-bin x)
  (stream-cons (bin x) (generate-bin (+ 1 x)))
  )

(define (stream-take stream n)
  (if (= n 0)
      empty-stream
      (stream-cons (stream-first stream) (stream-take (stream-rest stream) (- n 1))))
  )