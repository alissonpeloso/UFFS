aumento :: Int -> Float
aumento 0 = 0
aumento 1 = 0.015
aumento n = 2 * (aumento (n-1))

salaryValue :: Float -> Int -> Int -> Float
salaryValue salary hiringYear currentYear = salary * (1 + (aumento (currentYear-hiringYear)))