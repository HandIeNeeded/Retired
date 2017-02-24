/*************************************************************************
  >         File: A.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sun 15 Jan 2017 03:36:20 PM JST
*************************************************************************/
#include <bits/stdc++.h>

int main() {
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
  std::ios::sync_with_stdio(0);
  int t, cas = 0;
  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    int n, m;
    std::cin >> n >> m;
    using LL = long long;
    const int N = 300 + 5;
    static LL dp[N][N];
    memset(dp[0], 0x3f, sizeof(dp[0]));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
      std::vector<int> weights;
      for (int j = 0; j < m; ++j) {
        int x;
        std::cin >> x;
        weights.push_back(x);
      }
      std::sort(weights.begin(), weights.end());
      int sum = 0;
      memset(dp[i + 1], 0x3f, sizeof(dp[i + 1]));
      auto toMin = [] (LL &a, int b) {
        if (a > b) a = b;
      };
      memcpy(dp[i + 1], dp[i], sizeof(dp[i + 1]));
      for (int j = 0; j < m; ++j) {
        sum += weights[j];
        for (int k = i; k < N; ++k) {
          if (j + 1 + k < N) toMin(dp[i + 1][j + 1 + k], dp[i][k] + sum + (j + 1) * (j + 1));
        }
      }
    }
    std::cout << "Case #" << ++cas << ":";
    std::cout << " " << dp[n][n] << std::endl;
  }
  return 0;
}
