/*************************************************************************
	> File Name: A.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sat 28 May 2016 10:01:59 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

string str = "PRS";
int a[10], b[10], tot;

int win(int x, int y) {
  if (x > y) swap(x, y);
  if (x == 0 && y == 1) return 0;
  if (x == 1 && y == 2) return 1;
  if (x == 0 && y == 2) return 2;
  return -1;
}

bool check() {
  int cnt = tot;
  REP(i, tot) b[i] = a[i];
  while (cnt > 1) {
    int now = 0;
    for (int i = 0; i < cnt; i += 2) {
      b[now++] = win(b[i], b[i + 1]);
      if (b[now - 1] < 0) return 0;
    }
    cnt >>= 1;
  }
  return 1;
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
    int n, r, p, s;
    cin >> n >> r >> p >> s;
    tot = 1 << n;
    int now = 0;
    REP(i, p) a[now++] = 0;
    REP(i, r) a[now++] = 1;
    REP(i, s) a[now++] = 2;
    int find = 0;
    do {
      //REP(i, tot) cout << a[i] << ' ';
      //cout << endl;
      if (check()) {
        find = 1;
        break;
      }
    }while (next_permutation(a, a + tot));
    cout << "Case #" << ca++ << ": ";
    if (find) {
      REP(i, tot) {
        cout << str[a[i]];
      }
      cout << endl;
    }
    else {
      cout << "IMPOSSIBLE" << endl;
    }
  }
  return 0;
}



