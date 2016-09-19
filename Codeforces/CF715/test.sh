#!/bin/bash

while true; do
  ./gen > data.in
  ./A4 < data.in > my.out
  ./check

  if [[ "$?" == -1 ]]; then
    break 
  fi
done
