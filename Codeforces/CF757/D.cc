/*************************************************************************
  >         File: D.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Fri 13 Jan 2017 02:00:49 AM JST
*************************************************************************/
#include <bits/stdc++.h>

const int N = 20;
const int MO = 1e9 + 7;
int dp[77][1 << N];

void Add(int &x, int y) {
  x += y;
  if (x >= MO) x -= MO;
}

int get(const std::string& s) {
  int ans = 0;
  for (int i = 0; i < s.size(); ++i) {
    ans <<= 1;
    ans += s[i] - '0';
    if (ans > N) return N + 1;
  }
  return ans;
}

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::string s;
  n = 75;
  srand(time(0) % clock());
  s.resize(n);
  for (int i = 0; i < n; ++i) {
    s[i] = (rand() & 1) + '0';
  }
  std::cin >> n;
  std::cin >> s;
  for (int i = 0; i < n; ++i) dp[i][0] = 1;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      if (j > i) break;
      int x = get(s.substr(i - j, j));
      if (x == 0) continue;
      if (x > N) break;
      --x;
      for (int k = 0; k < (1 << N); ++k) if (dp[i - j][k]) {
        Add(dp[i][k | (1 << x)], dp[i - j][k]);
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= N; ++j) {
      if (dp[i][(1 << j) - 1]) {
        Add(ans, dp[i][(1 << j) - 1]);
      }
    }
  }
  std::cout << ans << std::endl;
  std::cerr << "---------------------------" << std::endl;
  std::cerr << "Time used: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec." << std::endl;
  return 0;
}
