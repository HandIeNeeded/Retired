#!/usr/bin/env runhaskell

power :: Num a => a -> Int -> a
power _ 0 = 1
power x y = power (x * x) (y `div` 2) * if odd y then x else 1
