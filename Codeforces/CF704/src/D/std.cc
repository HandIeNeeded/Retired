#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

const int N = 100;
pair<int, int> p[N];
int has[2][N];
int t[N], x[N], y[N];

int main() {
  ios::sync_with_stdio(0);
  int n, m, r, b;
  cin >> n >> m >> r >> b;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    p[i] = {x, y};
    has[0][x]++, has[1][y]++;
  }
  for (int i = 0; i < m; i++) {
    cin >> t[i] >> x[i] >> y[i];
  }
  int ans = INT_MAX;
  string best = string(n, 'b');
  for (int i = 0; i < (1 << n); i++) {
    string res = string(n, 'b');
    int cnt[2][N] = {{0}, {0}};
    int rcnt = 0;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        res[j] = 'r';
        cnt[0][p[j].first]++;
        cnt[1][p[j].second]++;
        rcnt++;
      }
    }
    bool bad = 0;
    for (int j = 0; j < m; j++) {
      if (t[j] == 1) {
        int diff = abs(has[0][x[j]] - cnt[0][x[j]] - cnt[0][x[j]]);
        if (diff > y[j]) {
          bad = 1;
          break;
        }
      }
      else {
        int diff = abs(has[1][x[j]] - cnt[1][x[j]] - cnt[1][x[j]]);
        if (diff > y[j]) {
          bad = 1;
          break;
        }
      }
    }
    if (!bad) {
      int result = r * rcnt + b * (n - rcnt);
      if (ans > result) {
        ans = result;
        best = res;
      }
    }
  }
  if (ans == INT_MAX) {
    cout << -1 << endl;
  }
  else {
    cout << ans << endl;
    cerr << best << endl;
  }

  return 0;
}
