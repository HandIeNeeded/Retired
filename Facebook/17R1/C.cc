/*************************************************************************
  >         File: C.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sun 15 Jan 2017 03:55:42 PM JST
*************************************************************************/
#include <bits/stdc++.h>

template<class T> 
void toMin(T &a, T b) {
  if (a > b) a = b;
}

int main() {
  std::ios::sync_with_stdio(0);
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
  int t, cas = 0;
  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    int n, m, d;
    std::cin >> n >> m >> d;
    const int N = 111;
    const int M = 5555;
    static int A[M], B[M];
    using LL = long long;
    LL dp[M][2];
    static LL visit[N][N];
    LL inf = 1LL << 40;
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) visit[i][j] = inf;
    for (int i = 0; i < N; ++i) for (int j = 0; j < 2; ++j) dp[i][j] = inf;
    for (int i = 1; i <= n; ++i) visit[i][i] = 0;
    for (int i = 0; i < m; ++i) {
      int x, y, z;
      std::cin >> x >> y >> z;
      visit[x][y] = visit[y][x] = std::min(visit[x][y], 1LL * z);
    }
    for (int k = 1; k <= n; ++k) {
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
          toMin(visit[i][j], visit[i][k] + visit[k][j]);
          assert(visit[i][j] >= 0);
        }
      }
    }
    for (int i = 1; i <= d; ++i) {
      std::cin >> A[i] >> B[i];
    }
    dp[0][0] = 0;
    A[0] = B[0] = 1;
    for (int i = 1; i <= d - 1; ++i) {
      //not get ith delivery
      int now = B[i - 1];
      int target = A[i];
      toMin(dp[i][0], dp[i - 1][0] + visit[now][target] + visit[target][B[i]]);
      toMin(dp[i][1], dp[i - 1][0] + visit[now][target] + visit[target][A[i + 1]] + visit[A[i + 1]][B[i]]);
      assert(dp[i][0] >= 0);

      //get ith delivery
      now = B[i - 1];
      target = B[i];
      toMin(dp[i][0], dp[i - 1][1] + visit[now][target]);
      toMin(dp[i][1], dp[i - 1][1] + visit[now][A[i + 1]] + visit[A[i + 1]][target]);
      assert(dp[i][1] >= 0);
    }
    LL ans = dp[d - 1][0] + visit[B[d - 1]][A[d]] + visit[A[d]][B[d]];
    toMin(ans, dp[d - 1][1] + visit[B[d - 1]][B[d]]);
    if (ans >= inf) ans = -1;
    std::cout << "Case #" << ++cas << ":";
    std::cout << " " << ans << std::endl;
  }
  return 0;
}
