/*************************************************************************
  >         File: A3.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 17 Sep 2016 11:17:54 PM CST
*************************************************************************/
#include <bits/stdc++.h>
using LL = long long;

int main() {
  std::ios::sync_with_stdio(0);
  
  LL N;
  std::cin >> N;
  LL x = 2;
  for (int i = 1; i <= N; ++i) {
    LL up = 1LL * (i + 1) * (i + 1);
    LL dw = i;
    LL g = std::__gcd(up, dw);
    up /= g;
    x /= i;
    LL to = up * dw;
    LL lo = 1, hi = 1000000000LL / to, res = 1;
    while (lo <= hi) {
      LL mid = lo + (hi - lo) / 2;
      if (to * mid * mid >= x) {
        res = mid;
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }
    to *= res * res;
    std::cout << to - x << std::endl;
    x = res * (i + 1) * dw;
  }
  return 0;
}
