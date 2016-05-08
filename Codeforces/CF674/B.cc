/*************************************************************************
	> File Name: B.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sat 07 May 2016 11:20:40 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  if (m <= n || n <= 4) {
    cout << -1 << endl;
  }
  else if (n == 5) {
    int a[4];
    REP(i, 4) cin >> a[i];
    set<int> s;
    REPP(i, 1, n) s.insert(i);
    REP(i, 4) s.erase(a[i]);
    int x = *s.begin();
    cout << a[0] << ' ' << a[2] << ' ' << x << ' ' << a[3] << ' ' << a[1] << endl;
    cout << a[2] << ' ' << a[0] << ' ' << x << ' ' << a[1] << ' ' << a[3] << endl;
  }
  else {
    int a[4];
    REP(i, 4) cin >> a[i];
    set<int> s;
    REPP(i, 1, n) s.insert(i);
    REP(i, 4) s.erase(a[i]);
    int x = *s.begin(), y = *s.rbegin();

    cout << a[0] << ' ' << a[2] << ' ' << x << ' ';
    for (auto &z: s) if (z != x && z != y) {
      cout << z << ' ';
    }
    cout << a[3] << ' ' << y << ' ' << a[1] << endl;

    cout << a[2] << ' ' << a[0] << ' ' << y << ' ' << a[1] << ' ' << x << ' ';
    for (auto &z: s) if (z != x && z != y) {
      cout << z << ' ';
    }
    cout << a[3] << endl;
  }

  return 0;
}



