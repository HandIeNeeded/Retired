/*************************************************************************
	> File Name: D.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Sat 18 Jun 2016 01:04:53 AM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;
const int N = 1006;
const int K = 12;
int dp[N][N][K];
int suffix[N][N];

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  string s, t;
  cin >> s >> t;
  REPP(i, 1, n) {
    REPP(j, 1, m) {
      suffix[i][j] = (s[i - 1] == t[j - 1] ? suffix[i - 1][j - 1] + 1 : 0);
    }
  }
  REPP(cnt, 1, k) {
    REPP(i, 1, n) {
      REPP(j, 1, m) {
        dp[i][j][cnt] = max(dp[i - 1][j][cnt], dp[i][j - 1][cnt]);
        int x = suffix[i][j];
        dp[i][j][cnt] = max(dp[i][j][cnt], dp[i - x][j - x][cnt - 1] + x);
      }
    }
  }
  cout << dp[n][m][k] << endl;
  return 0;
}


