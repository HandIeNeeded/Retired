#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 505 + 5;
int a[N];
vector<int> edge[N];
int vis[N];

int get(int a, int b) {
  queue<int> q;
  memset(vis, 0, sizeof(vis));
  q.push(a), q.push(0), vis[a] = 1;
  while (q.size()) {
    int x = q.front(); q.pop();
    int dis = q.front(); q.pop();
    for (auto &y: edge[x]) {
      if (y == b) return dis + 1;
      if (!vis[y]) {
        q.push(y);
        q.push(dis + 1);
        vis[y] = 1;
      }
    }
  }
  return -1;
}

int main() {
  int n;
  cin >> n;
  REPP(i, 1, n) cin >> a[i];
  REP(i, n - 1) {
    int x, y;
    cin >> x >> y;
    edge[x].push_back(y);
    edge[y].push_back(x);
  }
  int ans = 0;
  REPP(i, 1, n) REPP(j, i + 1, n) {
    if (__gcd(a[i], a[j]) == 1) {
      //assert(get(i, j) > 0);
      ans += get(i, j);
    }
  }
  cout << ans << endl;
  return 0;
}


