/*************************************************************************
	> File Name: CHEFELEC.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Sat 09 Jul 2016 08:30:29 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 1e5 + 5;
int a[N];

int main() {
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
  ios::sync_with_stdio(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    string mark;
    cin >> mark;
    REPP(i, 1, n) cin >> a[i];
    a[0] = -1e9;
    a[n + 1] = 2e9;
    int ans = 0;
    REPP(i, 1, n) {
      if (mark[i - 1] == '1') continue;
      int j = i;
      int mx = 0;
      while (j <= n && mark[j - 1] == '0') mx = max(mx, a[j] - a[j - 1]), j++;
      mx = max(mx, a[j] - a[j - 1]);
      ans += a[j] - a[i - 1] - mx;
      i = j;
    }
    cout << ans << endl;
  }

  return 0;
}


