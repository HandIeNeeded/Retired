/*************************************************************************
	> File Name: C.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Sat 09 Jul 2016 07:28:31 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 55;
char mp[N][N];

int Check(int a, int b) {
  if (a + b == 0) return 4;
  else if (a == 0) {
    if (mp[a][b - 1] == '?') return 2;
    else if (mp[a][b - 1] == 'R') return 0;
    else return 4;
  }
  else if (b == 0) {
    if (mp[a - 1][b] == '?') return 2;
    else if (mp[a - 1][b] == 'C') return 0;
    else return 4;
  }
  else {
    if (mp[a - 1][b] == 'C' || mp[a][b - 1] == 'R') return 0;
    else if (mp[a - 1][b] == 'R') {
      if (mp[a][b - 1] == 'C') return 4;
      else return 2;
    }
    else if (mp[a][b - 1] == 'C') {
      if (mp[a - 1][b] == 'R') return 4;
      else return 2;
    }
    else return 1;
  }
}

int main() {
  ios::sync_with_stdio(0);
  int r, c;
  cin >> r >> c;
  REP(i, r) cin >> mp[i];
  int ans = 0;
  REP(i, r) {
    REP(j, c) {
      ans += Check(i, j);
    }
  }
  cout << fixed << setprecision(10) << ans / 4.0 << endl;

  return 0;
}


