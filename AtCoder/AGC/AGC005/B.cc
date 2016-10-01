/*************************************************************************
  >         File: B.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 01 Oct 2016 08:04:50 PM CST
*************************************************************************/
#include <bits/stdc++.h>
constexpr int N = 2e5 + 5;
int a[N], L[N], R[N];

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::cin >> n;
  std::iota(L + 1, L + n + 1, 0);
  for (int i = 1; i <= n; ++i) R[i] = i + 1;
  for (int i = 0; i < n; ++i) std::cin >> a[i + 1];
  for (int i = 1; i <= n; ++i) {
    int j = L[i];
    while (j && a[j] > a[i]) j = L[j];
    L[i] = j;
  }
  for (int i = n; i >= 1; --i) {
    int j = R[i];
    while (j <= n && a[j] > a[i]) j = R[j];
    R[i] = j;
  }
  using LL = long long;
  LL answer = 0;
  for (int i = 1; i <= n; ++i) {
    answer += 1LL * a[i] * (R[i] - i) * (i - L[i]);
  }
  std::cout << answer << std::endl;

  return 0;
}
