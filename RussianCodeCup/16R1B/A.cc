/*************************************************************************
	> File Name: A.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sun 29 May 2016 05:17:34 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;
const int N = 105;
bool vis[N];

int main() {
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
  ios::sync_with_stdio(0);
  int t, ca = 1;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    REPP(i, 1, n) vis[i] = 1;
    while (q--) {
      int x;
      char c;
      cin >> c >> x;
      //cout << c << ' ' << x << endl;
      if (c == '?') {
        int cnt = 0;
        REPP(i, 1, n) if (vis[i]) {
          cnt++;
          if (cnt == x) {
            cout << i << endl;
          }
        }
      }
      else {
        vis[x] = vis[n + 1 - x] = 0;
      }
    }
  }


  return 0;
}



