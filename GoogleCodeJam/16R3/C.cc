/*************************************************************************
	> File Name: C.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Sat 11 Jun 2016 10:51:09 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 1005;
const double eps = 1e-7;

double sqr(double x) {
  return x * x;
}

int cmp(double x) {
  if (fabs(x) < eps) return 0;
  else if (x > 0) return 1;
  else return -1;
}

struct Point {
  double x, y, z;

  double norm() {
    return sqrt(sqr(x) + sqr(y) + sqr(z));
  }

  Point operator - (const Point& rhs) const {
    return (Point) {x - rhs.x, y - rhs.y, z - rhs.z};
  }

  Point operator + (const Point& rhs) const {
    return (Point) {x + rhs.x, y + rhs.y, z + rhs.z};
  }
}p[N];

bool mp[N][N], vis[N];
int n, m;

bool bfs() {
  queue<int> q;
  q.push(0), vis[0] = 1;
  while (q.size()) {
    int x = q.front(); q.pop();
    REP(i, n) if (!vis[i] && mp[x][i]) {
      if (i == 1) return 1;
      vis[i] = 1;
      q.push(i);
    }
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
  freopen((file.substr(0, file.find('.')) + ".out").c_str(), "w", stdout);
#endif
  int t, ca = 1;
  cin >> t;
  while (t--) {
    cin >> n >> m;

    REP(i, n) {
      int x, y, z, a, b, c;
      cin >> x >> y >> z >> a >> b >> c;
      p[i] = {1.0 * x, 1.0 * y, 1.0 * z};
    }

    double lo = 0, hi = 0;
    REP(i, n) {
      REPP(j, i + 1, n - 1) {
        hi = max(hi, (p[i] - p[j]).norm());
      }
    }
    REP(i, 50) {
      double mid = (lo + hi) / 2.0;
      REP(j, n) {
        REPP(k, j + 1, n - 1) {
          mp[j][k] = mp[k][j] = 0;
          //cout << j << ' ' << k << ' ' << (p[j] - p[k]).norm() << endl;
          if (cmp((p[j] - p[k]).norm() - mid) <= 0) {
            mp[j][k] = mp[k][j] = 1;
          }
        }
      }
      REP(i, n) vis[i] = 0;
      //cout << mid <<  ": " << endl;
      //REP(i, n) {
      //  REP(j, n) {
      //    cout << mp[i][j] << ' ';
      //  }
      //  cout << endl;
      //}
      if (bfs()) hi = mid;
      else lo = mid;
    }
    cout << "Case #" << ca++ << ": " << fixed << setprecision(10) << lo + eps << endl;
  }

  return 0;
}


