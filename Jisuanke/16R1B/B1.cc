/*************************************************************************
	> File Name: B1.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Sun 05 Jun 2016 01:13:59 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

int main() {
  ios::sync_with_stdio(0);
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    set<tuple<int, int, int, int>> s;
    set<pair<int, int>> row, column;
    REPP(i, 1, n) {
      REPP(j, 1, m) {
        REPP(x, 1, n) {
          REPP(y, j, m) {
            int h = x - i;
            int w = y - j;
            if (h == 0 && w == 0) continue;
            int d = __gcd(h, w);
            d = abs(d);
            h /= d, w /= d;
            int a = i, b = j;
            if (h == 0) {
              row.insert({x, 0});
            }
            else if (w == 0) {
              column.insert({0, y});
            }
            else {
              while (a >= 0) a -= abs(h), b -= w;
              s.insert(make_tuple(a, b, h, w));
            }
          }
        }
      }
    }
    cout << row.size() + column.size() + s.size() << endl;
  }

  return 0;
}


