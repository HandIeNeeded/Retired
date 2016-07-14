/*************************************************************************
	> File Name: CHEFTET.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Sat 09 Jul 2016 10:48:22 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 1e5 + 5;
int vis[N], a[N], b[N];

int main() {
  ios::sync_with_stdio(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    REPP(i, 1, n) cin >> a[i];
    LL sum = 0;
    REPP(i, 1, n) cin >> b[i], sum += a[i] + b[i];
    if (sum % n) {
      cout << -1 << endl;
    }
    else {
      vis[0] = vis[n] = 1;
      REPP(i, 1, n) vis[i] = 0;
      int avg = sum / n, bad = 0;
      REPP(i, 1, n) {
        if (a[i] > avg || b[i] > avg) {
          bad = 1;
          break;
        }
        if (!vis[i - 1]) {
          b[i] += a[i - 1];
          vis[i - 1] = 1;
        }
        if (!vis[i] && avg - a[i] == b[i]) {
          b[i] += a[i];
          vis[i] = 1;
        }
        else if (!vis[i + 1] && avg - a[i + 1] == b[i]) {
          b[i] += a[i + 1];
          vis[i + 1] = 1;
        }
        else if (!vis[i] && !vis[i + 1] && avg - a[i] - a[i + 1] == b[i]) {
          b[i] += a[i] + a[i + 1];
          vis[i] = vis[i + 1] = 1;
        }
      }
      REPP(i, 1, n) if (!vis[i]) bad = 1;
      if (bad) {
        cout << -1  << endl;
      }
      else {
        cout << avg << endl;
      }
    }
  }

  return 0;
}


