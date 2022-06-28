takeGrade :: Float -> Float -> Float -> Char
takeGrade tb as ef | 8 <= x && x <= 10 = 'A'
                   | 7 <= x && x < 8 = 'B'
                   | 6 <= x && x < 7 = 'C'
                   | 5 <= x && x < 6 = 'D'
                   | 0 <= x && x < 5 = 'E'
    where
        x = (tb * 0.2) + (as * 0.3) + (ef * 0.5)