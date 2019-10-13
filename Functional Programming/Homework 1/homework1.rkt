#lang racket

;;Задача 1.

;;Функция за намиране на двоен факториел
(define (doubleFact n)
  (cond
    [(equal? n 2) 2]
    [(equal? n 1) 1]
    [(equal? n 0) 1]
    [(< n 0) 1]
    [else (* n (doubleFact (- n 2)))]
   )
)

;;Функция за намиране на аритметичния израз след знака са сума
(define (func z n)
  (/(* (doubleFact (-(* 2 n) 1)) (expt z (+(* 2 n) 1))) (* (doubleFact (* 2 n)) (+(* 2 n) 1))))

(define (closeEnough y x)
  (<(abs (- y x)) 0.000001))

;;Функция за намиране на сумата - arcsin(z)
(define (arcsin z)
  (define (helpFunc z expected sum n)
    (cond
      [(> (abs z) 1) #f]
      [(closeEnough sum expected)  sum]
      [else (helpFunc z expected (+ sum (func z n)) (+ 1 n))]         
      )
    )
  (helpFunc z (asin z) 0 0)
)

;;Задача 2.

(define (automorphic? n)
  (define (automorphic?help n n2)
    (cond
      [(and (>= n 1) (<= n 9))
       (if(equal? (modulo n2 10) n)
          #t
          #f
          )]
      [else (if(equal? (modulo n2 10) (modulo n 10))
               (automorphic?help (quotient n 10) (quotient n 10))
               #f
               )]
      )
    )
  (automorphic?help n (* n n))
  )
  


;;Задача 3.

;;Помощна функция 
(define (isPrime?HelpFunc x p)
  (if (equal? x p) #t
  (if (equal? (remainder x p) 0) #f
      (isPrime?HelpFunc x (+ p 1)))))

;;Функция , установяваща дали едно число е просто
(define ( isPrime? x )
    (cond
      [( equal? x 1 ) #f]
      [( equal? x 2 ) #t]
      [( equal? x 3 ) #t]
      [ else (isPrime?HelpFunc x 2 ) ]))

;;Функция (sum-of-greater-primes n k)
(define (sum-of-greater-primes n k)
  ( define(helpFunc btk counter sum)
     (cond
       [(equal? counter n) sum]
       [(isPrime? btk) (helpFunc (+ btk 1) (+ counter 1) (+ sum btk)) ]
       [else (helpFunc (+ btk 1) counter sum)]
     )
  )
  (helpFunc (+ k 1) 0 0)
 )