/*************************************************************************
  >         File: B.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 26 Nov 2016 11:50:36 PM JST
*************************************************************************/
#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::cin >> n;
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    sum += i;
    if (sum >= n) {
      for (int j = i; j >= 1; --j) {
        if (n >= j) {
          std::cout << j << std::endl;
          n -= j;
        }
      }
      break;
    }
  }

  return 0;
}
