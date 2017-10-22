/*************************************************************************
  >         File: B.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sun 22 Oct 2017 03:31:37 PM JST
*************************************************************************/
#include <bits/stdc++.h>

const int N = 111;
std::pair<int, int> p[N];

using LL = long long;
LL solve(int n, std::vector<std::pair<int, int>> candidates) {
  if (n == 1) return 0;
  LL ans = 1e18;
  for (int i = 0; i < n; ++i) {
    for  (int j = i + 1; j < n; ++j) {
      std::vector<std::pair<int, int>> next;
      for (int k = 0; k < n; ++k) {
        if (k == i || k == j) continue;
        next.push_back(candidates[k]);
      }
      next.push_back(candidates[i]);
      ans = std::min(ans, solve(n - 1, next) + std::min(candidates[i].first ^ candidates[j].second, candidates[i].second ^ candidates[j].first));
      next.pop_back();
      next.push_back(candidates[j]);
      ans = std::min(ans, solve(n - 1, next) + std::min(candidates[i].first ^ candidates[j].second, candidates[i].second ^ candidates[j].first));
    }
  }
  return ans;
}

int main() {
  #ifdef HOME
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  #endif
  std::ios::sync_with_stdio(0);
  int t, cas = 1;
  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
      std::cin >> p[i].first;
    }
    for (int i = 0; i < n; ++i) {
      std::cin >> p[i].second;
    }
    std::vector<std::pair<int, int>> candidates(p, p + n);
    std::cout << "Case #" << cas++ << ": " << solve(n, candidates) << std::endl;
  }

  return 0;
}
