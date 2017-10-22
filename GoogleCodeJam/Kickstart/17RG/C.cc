/*************************************************************************
  >         File: C.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sun 22 Oct 2017 03:06:17 PM JST
*************************************************************************/
#include <bits/stdc++.h>

const int N = 44;
int mp[N][N];
int a[N];

int solve(int x, int y) {
  if (x == y - 1) return 0;
  else {
    int add = *std::min_element(a + x, a + y);
    int ans = -1;
    for (int mid = x + 1; mid < y; ++mid) {
      ans = std::max(ans, solve(x, mid) + solve(mid, y));
    }
    return add + ans;
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  int t, cas = 1;
  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        std::cin >> mp[i][j];
      }
    }
    for (int i = 0; i < m; ++i) a[i] = mp[0][i];
    //int min = *std::min_element(a, a + m);
    //std::cout << "Case #" << cas++ << ": " << min * (m - 1) << std::endl;
    std::cout << "Case #" << cas++ << ": " << solve(0, m) << std::endl;
  }

  return 0;
}
