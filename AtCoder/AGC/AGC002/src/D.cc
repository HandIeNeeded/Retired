/*************************************************************************
  >         File: D.cc
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sun 31 Jul 2016 08:47:32 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

const int N = 1e5 + 5;
set<int> numbers[N];
int ans[N], f[N];
int a[N], b[N];
int x[N], y[N], z[N];
int sqt = 234;

struct Q{
  int x, y, z, idx;

  bool operator < (const Q& rhs) const {
    return x < rhs.x || (x == rhs.x && y < rhs.y) || 
      (x == rhs.x && y == rhs.y && z < rhs.z) || 
      (x == rhs.x && y == rhs.y && z == rhs.z && idx < rhs.idx);
  }
};

map<Q, int> mp;
vector<int> qs[N];

int find(int x) {
  return f[x] == x ? x : f[x] = find(f[x]);
}

void merge(int a, int b, int idx) {
  if (numbers[a].size() > numbers[b].size()) swap(a, b);
  if (numbers[a].size() <= sqt) {
    int tot = numbers[a].size() + numbers[b].size();
    for (auto &x: numbers[a]) {
      
    }
  }
  else {

  }
  f[a] = b;
  numbers[b].insert(numbers[a].begin(), numbers[a].end());
}

int main() {
  ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) f[i] = i, numbers[i].insert(i);
  for (int i = 1; i <= m; i++) cin >> a[i] >> b[i];
  int q; cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> x[i] >> y[i] >> z[i];
    qs[x[i]].push_back(i);
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    x = a[i], y = b[i];
    int tx = find(x), ty = find(y);
    if (tx == ty) continue;
    else {
      merge(tx, ty, i);
    }
  }
  for (int i = 1; i <= q; i++) {
    cout << ans[i] << endl;
  }

  return 0;
}
