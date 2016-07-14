/*************************************************************************
	> File Name: B.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Thu 30 Jun 2016 01:07:00 AM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (auto i = (a); i <= (b); i++)
using namespace std;

const int N = 20;
const int K = 9;
const int M = 2520;
LL dp[N][1 << K][M];
int bit[N];
bool vis[N][1 << K][M];

int bitNum[1 << K], valid[1 << K][M][10];

LL Dfs(int pos, int k, int now, int mod, int flag) {
  if (pos < 0) {
    if (bitNum[now] < k) return 0;
    return valid[now][mod][k];
  }
  else if (flag && vis[pos][now][mod]) return dp[pos][now][mod];
  else {
    if (flag) {
      vis[pos][now][mod] = 1;
      LL &ans = dp[pos][now][mod];
      REP(i, 10) {
        if (i == 0) ans += Dfs(pos - 1, k, now, mod * 10 % M, 1);
        else ans += Dfs(pos - 1, k, now | (1 << (i - 1)), (mod * 10 + i) % M, 1);
      }
      return ans;
    }
    else {
      LL ans = 0;
      REP(i, bit[pos] + 1) {
        if (i == 0) ans += Dfs(pos - 1, k, now, mod * 10 % M, bit[pos]);
        else ans += Dfs(pos - 1, k, now | (1 << (i - 1)), (mod * 10 + i) % M, bit[pos] != i);
      }
      return ans;
    }
  }
}

LL Solve(LL x, int k) {
  if (x == 0) return 0;
  int length = 0;
  while (x) {
    bit[length++] = x % 10;
    x /= 10;
  }
  return Dfs(length - 1, k, 0, 0, 0);
}

int main() {
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
  ios::sync_with_stdio(0);
  clock_t st = clock();
  int t;
  REP(i, 1 << K) bitNum[i] = __builtin_popcount(i);
  REP(i, 1 << K) {
    REP(j, M) {
      REP(k, 10) {
        int cnt = 0;
        REP(bit, K) if ((i & (1 << bit)) && j % (bit + 1) == 0) cnt++;
        valid[i][j][k] = cnt >= k;
      }
    }
  }
  cerr << 1.0 * (clock() - st) / CLOCKS_PER_SEC << endl;
  cin >> t;
  while (t--) {
    memset(dp, 0, sizeof(dp));
    memset(vis, 0, sizeof(vis));
    LL a, b;
    int k;
    cin >> a >> b >> k;
    cout << Solve(b, k) - Solve(a - 1, k) << endl;
  }
  return 0;
}

