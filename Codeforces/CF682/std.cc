/*************************************************************************
	> File Name: A.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Sat 18 Jun 2016 01:10:50 AM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

int cnt[2][5];

int main() {
  int n, m;
  cin >> n >> m;
  REPP(i, 1, n) cnt[0][i % 5]++;
  REPP(j, 1, m) cnt[1][j % 5]++;
  LL ans = 0;
  REPP(i, 1, 4) {
    ans += 1LL * cnt[0][i] * cnt[1][5 - i];
  }
  ans += 1LL * cnt[0][0] * cnt[1][0];
  cout << ans << endl;


  return 0;
}


