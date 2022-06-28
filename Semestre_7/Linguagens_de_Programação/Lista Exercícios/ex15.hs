primeiros :: [a] -> [a]
primeiros (x:[]) = []
primeiros (x:xs) = [x] ++ primeiros(xs)