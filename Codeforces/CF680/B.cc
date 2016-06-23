/*************************************************************************
	> File Name: B.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Thu 09 Jun 2016 12:53:47 AM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 105;
int a[N];

int main() {
  int n, m;
  cin >> n >> m;
  REPP(i, 1, n) cin >> a[i];
  int l = m, r = m;
  int ans = 0;
  REPP(i, 0, n - 1) {
    if (i == 0) {
      if (a[m]) ans++;
    }
    else {
      if (l < 1 && r > n) ;
      if (l < 1 && r <= n && a[r]) {
        ans++;
      }
      if (l >= 1 && r > n && a[l]) {
        ans++;
      }
      if (l >= 1 && r <= n && a[l] && a[r]) ans += 2;
      //cout << l << ' ' << r << ' ' << ans << endl;
    }
    l--, r++;
  }
  cout << ans << endl;

  return 0;
}


