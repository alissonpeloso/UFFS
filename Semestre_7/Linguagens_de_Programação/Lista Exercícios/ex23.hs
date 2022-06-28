countList :: [a] -> Int
countList list = foldl (+) 0 newList
 where
  newList = map (\_ -> 1) list 