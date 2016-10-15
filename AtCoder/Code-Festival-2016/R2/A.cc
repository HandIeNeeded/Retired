/*************************************************************************
  >         File: A.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Mon 10 Oct 2016 11:58:18 AM CST
*************************************************************************/
#include <bits/stdc++.h>

int a[111111];

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  int now = 1;
  using LL = long long;
  LL ans = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == now) {
      now++;
      continue;
    }
    int k = (a[i] - 1) / now;
    ans += k;
    a[i] = 1;
    if (a[i] == now) now++;
    //std::cerr << "# i << ' ' << now << ' ' << ans # is " << i << ' ' << now << ' ' << ans << std::endl;
  }
  std::cout << ans << std::endl;

  return 0;
}
