/*************************************************************************
  >         File: A.cc
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 20 Aug 2016 09:35:54 PM CST
*************************************************************************/
#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(0);
  int n, m;
  std::cin >> n >> m;
  bool has = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char ch;
      std::cin >> ch;
      if (ch == 'C' || ch == 'M' || ch == 'Y') has = 1;
    }
  }
  has ? puts("#Color") : puts("#Black&White");

  return 0;
}
