/*************************************************************************
  >         File: P1005.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 17 Sep 2016 12:32:16 PM CST
*************************************************************************/
#include <bits/stdc++.h>

int main() {
  int t;
  std::cerr << "test";
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    n & 1  ? puts("Balanced") : puts("Bad");
  }
  return 0;
}
