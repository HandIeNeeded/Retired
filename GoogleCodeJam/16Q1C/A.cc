/*************************************************************************
	> File Name: A.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sun 08 May 2016 05:03:07 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;
const int N = 30;
int a[N], n;
pair<int, int> p[N];

bool check() {
  REP(i, n) if (p[i].first > 1) return 1;
  return 0;
}

int main() {
#ifdef HOME
    std::string file(__FILE__);
    freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
    freopen((file.substr(0, file.find('.')) + ".out").c_str(), "w", stdout);
#endif

  int t, ca = 1;
  cin >> t;
  while (t--) {
    cin >> n;
    REP(i, n) cin >> a[i];
    REP(i, n) p[i] = {a[i], i};
    cout << "Case #" << ca++ << ":";
    while (check()) {
      sort(p, p + n);
      string ans;
      ans += char(p[n - 1].second + 'A');
      p[n - 1].first--;
      if (p[n - 2].first > 1) ans += char(p[n - 2].second + 'A'), p[n - 2].first--;
      cout << ' ' << ans;
    }
    sort(p, p + n);
    if (n & 1) {
      cout << ' ' << char('A' + p[n - 1].second);
    }
    REP(i, n / 2) {
      string ans;
      ans += p[2 * i].second + 'A';
      ans += p[2 * i + 1].second + 'A';
      cout << ' ' << ans;
    }
    cout << endl;
  }
  return 0;
}



