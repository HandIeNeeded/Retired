/*************************************************************************
  >         File: 1008.cc
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sun 14 Aug 2016 01:55:20 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

const int N = 222;

int Sqr(int x) {
  return x * x;
}

struct Point {
  int x, y, z;
  Point() {}
  Point(int a, int b, int c) {
    x = a, y = b, z = c;
  }

  int norm() {
    return Sqr(x) + Sqr(y) + Sqr(z);
  }

  Point operator - (const Point &rhs) const {
    return (Point) {x - rhs.x, y - rhs.y, z - rhs.z};
  }
}p[N];

int cnt[N][N];

int main() {
  ios::sync_with_stdio(0);
  int t, ca = 1;
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      int x, y, z;
      cin >> x >> y >> z;
      p[i] = Point(x, y, z);
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        for (int k = 1; k <= n; k++) {
          Point A = p[i] - p[k], B = p[j] - p[k];
          if (A.norm() == B.norm()) cnt[i][j]++;
        }
      }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) if (i != j) {
        for (int k = j + 1; k <= n; k++) if (i != k) {
          Point A = p[i] - p[k], B = p[j] - p[k];
          if (A.norm() == B.norm()) {
            ans += cnt[j][k] - 1;
          }
        }
      }
    }
    cerr << ans << endl;
    assert(ans % 4 == 0);
    printf("Case #%d: %d\n", ca++, ans / 4);
  }


  return 0;
}
