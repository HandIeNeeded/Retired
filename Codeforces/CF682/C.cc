/*************************************************************************
	> File Name: C.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Sat 18 Jun 2016 01:22:48 AM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 1e5 + 5;
vector<int> edge[N], val[N];
int son[N], a[N], bad[N];

void dfs1(int x, int p, int now = 0) {
  if (now > a[x]) bad[x] = 1;
  REP(i, edge[x].size()) {
    int y = edge[x][i];
    int z = val[x][i];
    if (y == p) continue;
    dfs1(y, x, max(now + z, 0));
    son[x] += son[y];
  }
  son[x]++;
}

int dfs2(int x, int p) {
  if (bad[x]) return son[x];
  int ans = 0;
  for (auto &y: edge[x]) if (y != p) {
    ans += dfs2(y, x);
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  REPP(i, 1, n) cin >> a[i];
  REPP(i, 2, n) {
    int x, y;
    cin >> x >> y;
    edge[i].push_back(x), val[i].push_back(y);
    edge[x].push_back(i), val[x].push_back(y);
  }
  dfs1(1, 0);
  //REPP(i, 1, n) cout << i << ' ' << son[i] << ' ' << bad[i] << endl;
  cout << dfs2(1, 0) << endl;
  return 0;
}


