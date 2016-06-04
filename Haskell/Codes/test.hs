#!/usr/bin/env runhaskell

bimTell :: (RealFloat a) => a -> a -> String

bimTell weight height 
  | bim <= skinny = "Shin!!!"
  | bim <= normal = "Normal!!!"
  | bim <= fat = "Fat!!!"
  | otherwise = "Whale!!!"
  where (bim, skinny, normal, fat) = (weight / height ^ 2, 18.5, 25.0, 30.0)
