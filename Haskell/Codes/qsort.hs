swap :: (Num a) => (a, b) -> (b, a)
swap (x, y) = (y, x)

power :: (Num a) => a -> Int -> a
power _ 0 = 1
power x y = if odd y 
            then power (x * x) (y `div` 2) * x
            else power (x * x) (y `div` 2)

qsort :: Ord a => [a] -> [a]
qsort [] = []
qsort (x:xs) = qsort [y | y <- xs, y <= x] ++ [x] ++ qsort [y | y <- xs, y > x]
