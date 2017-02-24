/*************************************************************************
  >         File: B.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Fri 13 Jan 2017 12:36:57 AM JST
*************************************************************************/
#include <bits/stdc++.h>

const int N = 1e5 + 5;
int a[N], cnt[N];

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) std::cin >> a[i], cnt[a[i]]++;
  int ans = 1;
  for (int i = 2; i < N; ++i) {
    for (int j = i + i; j < N; j += i) {
      cnt[i] += cnt[j];
    }
    ans = std::max(ans, cnt[i]);
  }
  std::cout << ans << std::endl;
  return 0;
}
