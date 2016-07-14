/*************************************************************************
	> File Name: CHEFARC.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Sat 09 Jul 2016 11:02:02 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 105;
bool mp[N][N];
int dp[2][N][N], n, m;

void bfs(int x, int y, int idx, int step) {
  dp[idx][x][y] = 0;
  queue<int> q;
  q.push(x), q.push(y);
  while (q.size()) {
    int x = q.front(); q.pop();
    int y = q.front(); q.pop();
    for (int i = x - step; i <= x + step; i++) {
      for (int j = y - step; j <= y + step; j++) {
        if (i < 1 || i > n || j < 1 || j > m || mp[i][j] || abs(i - x) + abs(j - y) > step) {
          continue;
        }
        if (dp[idx][i][j] < 0) {
          dp[idx][i][j] = dp[idx][x][y] + 1;
          q.push(i), q.push(j);
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int k1, k2;
    cin >> n >> m;
    cin >> k1 >> k2;
    REPP(i, 1, n) {
      REPP(j, 1, m) {
        cin >> mp[i][j];
      }
    }
    memset(dp, -1, sizeof(dp));
    bfs(1, 1, 0, k1);
    bfs(1, m, 1, k2);
    int ans = INT_MAX;
    REPP(i, 1, n) {
      REPP(j, 1, m) {
        if (dp[0][i][j] < 0 || dp[1][i][j] < 0) continue;
        ans = min(ans, max(dp[0][i][j], dp[1][i][j]));
      }
    }
    if (ans == INT_MAX) ans = -1;
    cout << ans << endl;
  }

  return 0;
}


