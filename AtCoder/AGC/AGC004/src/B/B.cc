/*************************************************************************
  >         File: B.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sun 04 Sep 2016 08:18:12 PM CST
*************************************************************************/
#include <bits/stdc++.h>
using LL = long long;
int a[2222];
LL b[2222];

int main() {
  std::ios::sync_with_stdio(0);
  int n, x;
  std::cin >> n >> x;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    b[i] = a[i];
  }
  LL answer = 1LL << 60;
  for (int itr = 0; itr < n; itr++) {
    for (int i = 0; i < n; i++) b[(i + itr) % n] = std::min(b[(i + itr) % n], 1LL * a[i]);
    LL sum = std::accumulate(b, b + n, 0LL);
    answer = std::min(answer, sum + 1LL * itr * x);
  }
  std::cout << answer << std::endl;

  return 0;
}
