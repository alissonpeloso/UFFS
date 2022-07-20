canLoan :: Float -> Float -> Bool
canLoan salary installment = if salary * 0.3 >= installment then True else False