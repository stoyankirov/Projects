#lang racket

;;Задача 1. Да се дефинира функцията (cartesian-product xs ys), която връща
;като резултат списък от двойки, представящ декартовото произведение на
;множествата xs и ys, представени чрез списъци.
;Пример: (cartesian-product '(1 2) '(3 4)) → '((1 . 3) (1 . 4) (2 . 3) (2 . 4))

(define (combinations x lst)
  (define (iter reducedlst result)
    (if(null? reducedlst)
       result
       (iter (cdr reducedlst) (append result (list (cons x (car reducedlst)))))
       )
    )
  (iter lst '())
  )

(define (cartesian-product xs ys)
  (define (iter lst-xs result)
     (if(null? lst-xs)
        result
        (iter (cdr lst-xs) (append result (combinations (car lst-xs) ys)))
        )
    )
  (iter xs '())
  )

;Задача 2. Да се дефинира функцията (latin-square? xss), която проверява
;дали матрицата xss е латински квадрат (определение на понятието можете да
;намерите например на https://en.wikipedia.org/wiki/Latin_square). Можете да
;приемете, че за символи ще използваме числата от 1 до n, където n е
;големината (броят на редовете/стълбовете) на матрицата. 

(define (get-column-elements lst)
  (define (iter lst result)
    (if(null? lst)
       result
       (iter (cdr lst) (append result (list(car(car lst)))))
       )
    )
  (iter lst '())
)

(define (check-numbers lst)
  (define (iter lst x)
    (cond [(null? lst) #t]
          [(equal? x (car lst)) #f]
          [else (iter (cdr lst) x)]
          )
    )
  (cond [(null? lst) #t]
        [(iter (cdr lst) (car lst)) (check-numbers (cdr lst))]
        [else #f]
        )
  )

(define (check-all-columns matrix)
  (cond [(null? matrix) #t]
        [(check-numbers (get-column-elements matrix)) (check-all-columns (cdr matrix))]
        [else #f]
        )
  )

(define (check-all-rows matrix)
  (cond [(null? matrix) #t]
        [(check-numbers (car matrix)) (check-all-rows (cdr matrix))]
        [else #f]
        )
  )

(define (latin-square? xss)
  (if(and (check-all-rows xss) (check-all-columns xss))
     #t
     #f
     )
  )
    
;Задача 3. Да се дефинира функция (pair-compose fs), която получава списък
;(f1 f2 f3 ... fn) от едноаргументни числови функции и връща нова едноаргументна
;числова функция g - такава, че оценката на (g x) е равна на сумата (f1 . f2) (x) +
;(f3 . f4) (x) + ... + (fn-1 . fn) (x), където “.” означава композиция на функции. Ако
;оригиналният списък с функции има нечетен брой елементи, то последната
;функция от списъка се композира с функцията идентитет, която получава един
;аргумент и го връща без промяна.

(define (1+ x) (+ 1 x))
(define (2* x) (* 2 x))
(define operands (list 1+ 2* 2*))

(define (simple-compose f g)
  (lambda(x) (f(g x))))

(define (pair-compose fs)
  (define (iter fs lst)
    (cond [(null? fs) lst] 
          [(null? (cdr fs)) (iter (cdr fs) (append (list (simple-compose (car fs) identity)) lst))] 
          [else (iter (cddr fs) (append (list (simple-compose (car fs) (car ( cdr fs)))) lst))]
    )
  )
  (lambda(x) (apply + (map (lambda(y) (y x)) (iter fs '()))))
)











