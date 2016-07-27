/*************************************************************************
  > File Name: B.cc
  > Author: Riho.Yoshioka
  > Mail:   riho.yoshioka@yandex.com
  > Created Time: Tue 19 Jul 2016 09:22:21 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

const int N = 2e5 + 5;
int vis[N], now;
vector<int> inv[N];
vector<int> keys;
int p[N], pre[N], edge[N], has;

void spread(int x) {
  vis[x] = 2 * now;
  for (auto &y: inv[x]) if (vis[y] != 2 * now) {
    spread(y);
  }
}

void dfs(int x) {
  if (vis[x]) {
    int node = pre[x], cnt = 0;
    while (node != x) {
      spread(node);
      node = pre[node];
      cnt++;
    }
    vis[node] = now, cnt++;
    spread(node);
    keys.push_back(node);
    if (cnt == 1) has = node;
    return ;
  }
  vis[x] = now;
  pre[edge[x]] = x;
  dfs(edge[x]);
}

int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    edge[i] = x;
    p[i] = x;
    inv[x].push_back(i);
  }
  int cnt = 0;
  has = 0;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      now = i;
      dfs(i);
      cnt++;
    }
  }
  int ans = cnt;
  if (has) ans--;
  else has = keys[0];
  for (auto &x: keys) p[x] = has;
  cout << ans << endl;
  for (int i = 1; i <= n; i++) {
    cout << p[i] << ' ';
  }
  cout << endl;
  return 0;
}
