/*************************************************************************
  >         File: K.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 10 Sep 2016 01:46:05 PM CST
*************************************************************************/
#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::cin >> n;
  (n & 1) ? puts("Alice") : puts("Bob");
  return 0;
}
