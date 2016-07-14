/*************************************************************************
	> File Name: EGRANDR.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Sat 09 Jul 2016 08:23:35 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 1e5 + 5;
int a[N];

int main() {
  ios::sync_with_stdio(0);
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
  int n, t;
  cin >> t;
  while (t--) {
    cin >> n;
    int bad = 0, good = 0, sum = 0;
    REPP(i, 1, n) {
      cin >> a[i];
      if (a[i] <= 2) bad = 1;
      if (a[i] == 5) good = 1;
      sum += a[i];
    }
    if (bad) {
      cout << "No" << endl;
      continue;
    }
    else {
      if (good && sum >= 4 * n) {
        cout << "Yes" << endl;
      }
      else {
        cout << "No" << endl;
      }
    }
  }


  return 0;
}


