/*************************************************************************
  >         File: B.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sun 23 Oct 2016 09:47:50 PM CST
*************************************************************************/
#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(0);
  int sum, n;
  std::cin >> sum >> n;
  int a[111];
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  int mx = *std::max_element(a, a + n);
  if (2 * mx > sum) {
    std::cout << sum - (sum - mx) * 2 - 1 << std::endl;
  }
  else {
    std::cout << 0 << std::endl;
  }
  return 0;
}
