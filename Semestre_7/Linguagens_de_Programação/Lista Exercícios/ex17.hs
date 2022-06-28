multList :: [Float] -> [Float] -> [Float]
multList (x:[]) (y:[]) = [y*x]
multList (x:xs) (y:[]) = [y*x]
multList (x:[]) (y:ys) = [y*x]
multList (x:xs) (y:ys) = [y*x] ++ (multList xs ys)