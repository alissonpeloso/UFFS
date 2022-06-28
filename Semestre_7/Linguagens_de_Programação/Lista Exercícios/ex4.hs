precoRetrato :: Integer -> String -> Double
precoRetrato n day | n == 1 = x * 100
                   | n == 2 = x * 130
                   | n == 3 = x * 150
                   | n == 4 = x * 165
                   | n == 5 = x * 175
                   | n == 6 = x * 180
                   | n >= 7 = x * 185
				   where
					x | day == "domingo" = 1.2
					  | day == "sábado" = 1.2
					  | day == "segunda" = 1
					  | day == "terça" = 1
					  | day == "quarta" = 1
					  | day == "quinta" = 1
					  | day == "sexta" = 1





