#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 500;
int a[N], b[N], n, k;
int sum[N], prefix[N], vis[N];

bool check(int x) {
  REP(i, n) vis[i] = b[i];
  REP(i, n) if (x & (1 << i)) vis[i] = 1;
  prefix[0] = vis[0];
  REPP(i, 1, n - 1) prefix[i] = prefix[i - 1] + vis[i];
  REP(i, n) {
    int pos = sum[i] - k;
    int index = upper_bound(sum, sum + n, pos) - sum;
    int cnt = 0;
    if (index == 0) cnt = prefix[i];
    else {
      cnt = prefix[i] - prefix[index - 1];
    }
    //cout << "hehe" << ' ' << i << ' ' << index << endl;
    if (cnt == 0) return 0;
  }
  return 1;
}

int main() {
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
  int t, ca = 1;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    REP(i, n) cin >> a[i];
    REP(i, n) cin >> b[i];
    sum[0] = a[0];
    for (int i = 1; i < n; i++) {
      sum[i] = sum[i - 1] + a[i];
    }
    int res = n + 1;
    REP(i, 1 << n) {
      int ans = 0;
      REP(j, n) if (i & (1 << j)) {
        if (!b[j]) ans++;
      }
      if (check(i)) {
        res = min(res, ans);
      }
    }
    cout << res << endl;
  }
  return 0;
}



