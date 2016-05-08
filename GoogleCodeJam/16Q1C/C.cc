/*************************************************************************
  > File Name: C.cc
  > Author: yuzhou627
  > Mail:   yuzhou627@gmail.com
  > Created Time: Sun 08 May 2016 06:33:35 PM CST
 *************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;
const int N = 30;
int J, P, S, K;
int now;
tuple<int, int, int> a[N];
bool vis[4][4][4];
int cnt[3][4][4];

bool check(int x) {
  memset(vis, 0, sizeof(vis));
  memset(cnt, 0, sizeof(cnt));
  REP(i, now) if (x & (1 << i)) {
    int j, p, s;
    tie(j, p, s) = a[i];
    if (vis[j][p][s]) return 0;
    vis[j][p][s] = 1;
    cnt[0][j][p]++, cnt[1][j][s]++, cnt[2][p][s]++;
    if (cnt[0][j][p] > K || cnt[1][j][s] > K || cnt[2][p][s] > K) return 0;
  }
  return 1;
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
    cin >> J >> P >> S >> K;
    now = 0;
    REPP(j, 1, J) {
      REPP(p, 1, P) {
        REPP(s, 1, S) {
          a[now++] = make_tuple(j, p, s);
        }
      }
    }
    assert(now == J * P * S);
    int ans = -1;
    int index = -1;
    for (int i = (1 << now) - 1; i > 0; i--) {
      //cout << i << ' ' << now << endl;
      if (i < (1 << ans)) break;
      else if (check(i)) {
      //if (check(i)) {
        int tmp = __builtin_popcount(i);
        if (tmp > ans) {
          ans = tmp;
          index = i;
        }
      }
    }
    cout << "Case #" << ca++ << ": " << ans << endl;
    REP(i, now) if (index & (1 << i)) {
      int j, p, s;
      tie(j, p, s) = a[i];
      cout << j << ' ' << p << ' ' << s << endl;
    }
  }
  return 0;
}

