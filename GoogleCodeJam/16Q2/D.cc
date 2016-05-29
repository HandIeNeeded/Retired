/*************************************************************************
	> File Name: D.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sat 28 May 2016 11:30:05 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 10;
char mp[N][N], g[N][N];
int n, a[N << 1], tot;
int tmp[N] = {0};
bool vis[N];

bool dfs(int dep) {
  if (dep == n) return true;
  else {
    int find = 0;
    REP(j, n) if (!vis[j] && g[tmp[dep]][j] == '1') {
      find = 1;
      break;
    }
    if (find == 0) return 0;
    REP(j, n) if (!vis[j] && g[tmp[dep]][j] == '1') {
      vis[j] = 1;
      if (!dfs(dep + 1)) return false;
      vis[j] = 0;
    }
    return 1;
  }
}

bool check(int x) {
  REP(i, n) tmp[i] = i;
  do {
    REP(i, n) vis[i] = 0;
    if (!dfs(0)) return 0;
  }while (next_permutation(tmp, tmp + n));
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
  freopen((file.substr(0, file.find('.')) + ".out").c_str(), "w", stdout);
#endif
  int t, ca = 1;
  cin >> t;
  while (t--) {
    cin >> n;
    REP(i, n) cin >> mp[i];
    tot = n * n;
    int answer = n * n;
    REP(i, 1 << tot) {
      REP(a, n) REP(b, n) g[a][b] = mp[a][b];
      int extra = 0;
      REP(j, tot) if (i & (1 << j)) {
        if (mp[j / n][j % n] == '0') {
          g[j / n][j % n] = '1';
          extra++;
        }
      }
      if (extra >= answer) continue;
      if (check(i)) {
        answer = min(answer, extra);
      }
    }
    cout << "Case #" << ca++ << ": " << answer << endl;
  }
  return 0;
}

