/*************************************************************************
  > File Name: C.cc
  > Author: Riho.Yoshioka
  > Mail:   riho.yoshioka@yandex.com
  > Created Time: Sat 16 Jul 2016 08:39:04 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

const int N = 2005;
int n, k, mx, cnt, vis[N], now;
vector<int> edge[N];

void dfs(int x, int p, int dep = 1) {
  if (dep * 2 > k) {
    cnt++;
    return ;
  }
  vis[x] = now;
  int cnt = 0;
  for (auto y: edge[x]) if (y != p) {
    dfs(y, x, dep + 1);
    cnt++;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    edge[x].push_back(y);
    edge[y].push_back(x);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    mx = 0;
    now = vis[i] = i;
    for (auto &y: edge[i]) {
      cnt = 0;
      dfs(y, i), mx = max(mx, cnt);
    }
    int res = 0;
    for (int j = 1; j <= n; j++) if (vis[j] == i) res++;
    if (k % 2 == 0) mx = 0;
    ans = max(ans, res + mx);
  }
  cout << n - ans << endl;

  return 0;
}
