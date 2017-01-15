/*************************************************************************
  >         File: A.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 26 Nov 2016 11:47:30 PM JST
*************************************************************************/
#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(0);
  int n, m;
  std::cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::string s;
      std::cin >> s;
      if (s == "snuke") {
        std::cout << char('A' + j);
        std::cout << 1 + i << std::endl;
      }
    }
  }
  return 0;
}
