-- List: [("Alan Turing", 5550044), ("Lionel Messi", 323245434), ("Menino Ney", 34442234)]

filterByName :: String -> (String, Int)  -> Bool
filterByName (b:_) ((a:[]), _)  =  a == b 
filterByName (b:[]) ((a:_), _)  =  a == b
filterByName (b:bs) ((a:as), _)  =  a == b && (filterByName bs (as, 0) )

tupleFilter :: [(String, Int)] -> String -> [(String, Int)]
tupleFilter list str = filter (filterByName str) list 