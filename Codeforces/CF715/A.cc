/*************************************************************************
  >         File: A.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 17 Sep 2016 10:44:05 PM CST
*************************************************************************/
#include <bits/stdc++.h>
using LL = long long;

LL Sqr(int x) {
  return 1LL * x * x;
}

LL Get(int x) {
  return Sqr(x * (x + 1));
}

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::cin >> n;
  if (n == 1) {
    std::cout << 2 << std::endl;
    return 0;
  }
  std::cout << 2 << std::endl;
  for (int i = 2; i <= n; ++i) {
    std::cout << 1LL * i * (i + 1) * (i + 1) - (i - 1) << std::endl;
  }
  return 0;
}
