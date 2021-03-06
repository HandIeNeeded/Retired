/*************************************************************************
  >         File: A.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 15 Oct 2016 09:38:33 PM CST
*************************************************************************/
#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::cin >> n;
  using LL = long long;
  LL a = 0, b = 0;
  std::cin >> a >> b;
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    std::cin >> x >> y;
    LL k = std::max((a + x - 1) / x, (b + y - 1) / y);
    a = k * x, b = k * y;
  }
  std::cout << a + b << std::endl;

  return 0;
}
