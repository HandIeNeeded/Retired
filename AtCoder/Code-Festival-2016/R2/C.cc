/*************************************************************************
  >         File: C.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Mon 10 Oct 2016 01:18:53 PM CST
*************************************************************************/
#include <bits/stdc++.h>

using LL = long long;
const int N = 111111;
int a[N], b[N]; 
LL prefix[N];

int main() {
  std::ios::sync_with_stdio(0);
  int n, m;
  std::cin >> n >> m;
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  for (int i = 0; i < m; ++i) std::cin >> b[i];
  LL ans = 0;
  ans += std::accumulate(a, a + n, 0LL);
  ans += std::accumulate(b, b + m, 0LL);
  std::sort(a, a + n);
  std::sort(b, b + m);
  for (int i = 0; i < m; ++i) prefix[i + 1] = prefix[i] + b[i];
  for (int i = 0; i < n; ++i) {
    auto pos = std::upper_bound(b, b + m, a[i]) - b;
    ans += 1LL * a[i] * (m - pos) + prefix[pos];
  }
  std::cout << ans << std::endl;


  return 0;
}
