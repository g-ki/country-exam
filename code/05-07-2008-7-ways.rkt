(define (neighbours v g)
  (cdr (assoc v g)))

(define (ways g u v)
  (define (helper c)
    (cond
      ((null? c) 0)
      ((eqv? c v) 1)
      (else (apply + (map helper (neighbours c g))))
      ))
  (helper u))

(define G `((a b c) (b c e) (c d) (d e) (e)))