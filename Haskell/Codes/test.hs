swap :: (Num a) => (a, b) -> (b, a)
swap (x, y) = (y, x)

power :: (Num a) => a -> Int -> a
power _ 0 = 1
power x y = if odd y 
            then power (x * x) (y `div` 2) * x
            else power (x * x) (y `div` 2)

qsort :: Ord a => [a] -> [a]
qsort [] = []
qsort xs = qsort [x | x <- tail xs, x < head xs] ++ [head xs] ++ qsort [x | x <- tail xs, x >= head xs]
