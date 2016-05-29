/*************************************************************************
	> File Name: D.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sun 29 May 2016 05:48:09 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 1 << 13;
int vis[3][N], dp[3][N];
int a[3][N], n;

int dfs(int person, int st) {
  if (vis[person][st]) return dp[person][st];
  if (((st - 1) & st) == 0) {
    return dp[person][st] = __builtin_ctz(st);
  }
  else {
    vis[person][st] = 1;
    int mx = n;
    for (int i = 0; i < n; i++) {
      if (st & (1 << i)) {
        int answer = dfs((person + 1) % 3, st ^ (1 << i));
        if (mx == n || a[person][answer] < a[person][mx]) {
          mx = answer;
        }
      }
    }
    return dp[person][st] = mx;
  }
}

int main() {
  ios::sync_with_stdio(0);
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
  int t, ca = 1;
  cin >> t;
  while (t--) {
    memset(vis, 0, sizeof(vis));
    cin >> n;
    REP(i, 3) {
      REP(j, n) {
        int x;
        cin >> x;
        x--;
        a[i][x] = j;
      }
    }
    int answer = dfs(0, (1 << n) - 1);
    cout << answer + 1 << endl;
  }
  return 0;
}



