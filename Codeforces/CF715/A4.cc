/*************************************************************************
  >         File: A4.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 17 Sep 2016 11:22:43 PM CST
*************************************************************************/
#include <bits/stdc++.h>
using LL = long long;

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::cin >> n;
  LL y = 2;
  for (LL k = 1; k <= n; ++k) {
    LL a = 1LL * (k + 1) * (k + 1), z = 1;
    LL tmp = k, j, x;
    for (j = 2; j * j <= k; j++) {
      if (tmp % j) continue;
      int cnt = 0;
      while (tmp % j == 0) {
        tmp /= j;
        cnt++;
      }
      cnt = (cnt + 1) / 2;
      while (cnt--) z *= j;
    }
    z *= tmp;
    x = z * z / k * a - y / k;
    y = (k + 1) * z;
    std::cout << x << std::endl;
  }
  return 0;
}
