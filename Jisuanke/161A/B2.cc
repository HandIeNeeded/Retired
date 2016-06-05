/*************************************************************************
	> File Name: B2.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Sun 05 Jun 2016 10:31:51 AM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 10005;
const int M = 505;

int dp[N][M], cnt[N][M];
int graph[M][M];
int a[N], ans[N];
vector<int> edge[N];

void dfs1(int x, int p = 0) {
  for (auto &y: edge[x]) if (y != p) {
    dfs1(y, x);
    REP(i, M) dp[x][i] = dp[y][i];
    REP(i, M) dp[x][i] += cnt[y][i], cnt[x][i] += cnt[y][i];
  }
  cnt[x][a[x]]++;
}

void dfs2(int x, int p = 0) {
  REP(i, M) ans[x] += dp[x][i] * (graph[a[x]][i] == 1);
  for (auto &y: edge[x]) if (y != p) {
    vector<int> dis(M, 0), num(M, 0);
    REP(i, M) dis[i] = dp[x][i], num[i] = cnt[x][i];
    REP(i, M) num[i] -= cnt[y][i];
    REP(i, M) dis[i] -= dp[y][i] + cnt[y][i];
    REP(i, M) cnt[y][i] += num[i];
    REP(i, M) dp[y][i] += num[i] + dis[i];
    dfs2(y, x);
  }
}

int main() {
  ios::sync_with_stdio(0);
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
  int n;
  cin >> n;
  REP(i, M) REP(j, M) graph[i][j] = __gcd(i, j);
  REPP(i, 1, n) cin >> a[i];
  REP(i, n - 1) {
    int x, y;
    cin >> x >> y;
    edge[x].push_back(y);
    edge[y].push_back(x);
  }
  dfs1(1);
  //REPP(i, 1, n) {
  //  cout << "dp: " << endl;
  //  REPP(j, 1, n) {
  //    cout << dp[i][j] << ' ';
  //  }
  //  cout << endl;
  //  cout << "cnt: " << endl;
  //  REPP(j, 1, n) {
  //    cout << cnt[i][j] << ' ';
  //  }
  //  cout << endl;
  //}
  dfs2(1);
  //REPP(i, 1, n) {
  //  cout << "dp: " << endl;
  //  REPP(j, 1, n) {
  //    cout << dp[i][j] << ' ';
  //  }
  //  cout << endl;
  //  cout << "cnt: " << endl;
  //  REPP(j, 1, n) {
  //    cout << cnt[i][j] << ' ';
  //  }
  //  cout << endl;
  //}
  //REPP(i, 1, n) cout << ans[i] << endl;
  int ans = 0;
  REPP(i, 1, n) ans += ::ans[i];
  cout << ans / 2 << endl;
  return 0;
}


