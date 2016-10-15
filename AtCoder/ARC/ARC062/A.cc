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
  LL a = 0, b = 0;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cint >> x >> y;
    if (a == 0) a = x, y = b;
    else {

    }
  }
  std::cout << a + b << std::endl;

  return 0;
}
