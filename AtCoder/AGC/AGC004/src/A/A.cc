/*************************************************************************
  >         File: A.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sun 04 Sep 2016 07:58:58 PM CST
*************************************************************************/
#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(0);
  int a, b, c;
  std::cin >> a >> b >> c;
  if (a % 2 == 0 || b % 2 == 0 || c % 2 == 0) {
    std::cout << 0 << std::endl;
    return 0;
  }
  if (a > b) std::swap(a, b);
  if (a > c) std::swap(a, c);
  if (b > c) std::swap(b, c);
  std::cout << 1LL * a * b << std::endl;

  return 0;
}
