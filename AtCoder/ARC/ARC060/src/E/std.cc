/*************************************************************************
  >         File: E.cc
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sun 28 Aug 2016 08:42:27 PM CST
*************************************************************************/
#include <bits/stdc++.h>
const int N = 1e5 + 5;
int a[N];

int main() {
  std::ios::sync_with_stdio(0);
  int n, L;
  std::cin >> n;
  for (int i = 0; i < n; i++) std::cin >> a[i];
  std::cin >> L;
  int q;
  std::cin >> q;
  while (q--) {
    int a, b;
    std::cin >> a >> b;
    a--, b--;
    if (a > b) std::swap(a, b);
    int step = 0;
    while (a < b) {
      auto pos = std::upper_bound(::a + a, ::a + n, ::a[a] + L) - ::a;
      a = pos - 1;
      step++;
    }
    std::cout << step << std::endl;
  }
  return 0;
}
