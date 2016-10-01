/*************************************************************************
  >         File: C.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 01 Oct 2016 08:21:20 PM CST
*************************************************************************/
#include <bits/stdc++.h>
int a[111], has[111];

int main() {
  std::ios::sync_with_stdio(0);
  bool bad = false;
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; ++i) std::cin >> a[i], has[a[i]] = 1;
  int minValue = *std::min_element(a + 1, a + n + 1);
  int maxValue = *std::max_element(a + 1, a + n + 1);
  if (maxValue & 1) {
    bad = std::count(a + 1, a + n + 1, minValue) != 2;
  } else {
    bad = std::count(a + 1, a + n + 1, minValue) != 1;
  }
  for (int i = minValue; i <= maxValue; ++i) if (!has[i]) bad = true;
  for (int i = 1; i <= n; ++i) if (a[i] > n - 1) bad = true;
  for (int i = 1; i <= n; ++i) if (a[i] < 1) bad = true;
  bad ? puts("Impossible") : puts("Possible");
  return 0;
}
