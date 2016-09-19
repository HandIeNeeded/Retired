/*************************************************************************
  >         File: A2.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 17 Sep 2016 11:13:03 PM CST
*************************************************************************/
#include <bits/stdc++.h>
using LL = long long;
int main() {
  std::ios::sync_with_stdio(0);
  LL n;
  std::cin >> n;
  LL q = 2;
  for (int i = 1; i <= n; ++i) {
    LL s = 1LL * (i + 1) * (i + 1);
    LL d = q / s;
    LL a = sqrt(double(d));
    ++a;
    std::cout << a * a * i * s - q << std::endl;
    q = a * i;
  }
  return 0;
}
