/*************************************************************************
  >         File: B.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 24 Sep 2016 08:03:18 PM CST
*************************************************************************/
#include <bits/stdc++.h>
int a[111111];

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    a[i]--;
  }
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    int x = i;
    if (a[a[x]] == x) cnt++;
  }
  assert(cnt % 2 == 0);
  std::cout << cnt / 2 << std::endl;


  return 0;
}
