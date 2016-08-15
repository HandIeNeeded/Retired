/*************************************************************************
  >         File: F.cc
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 13 Aug 2016 08:23:39 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

const int N = 5555;
const int MO = 1e9 + 7;
int dp[N][N];
char s[N];

void Add(int &x, int y) {
  x += y;
  if (x >= MO) x -= MO;
}

int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  cin >> s;
  int m = strlen(s);
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i + 1; j++) {
      if (j < m) {
        if (s[j] == '0') Add(dp[i + 1][j + 1], dp[i][j]);
        if (s[j] == '1') Add(dp[i + 1][j + 1], dp[i][j]);
      }
      else {
        Add(dp[i + 1][j + 1], dp[i][j]);
        Add(dp[i + 1][j + 1], dp[i][j]);
      }
      if (j) Add(dp[i + 1][j - 1], dp[i][j]);
      else Add(dp[i + 1][j], dp[i][j]);
    }
  }
  for (int i = 1; i <= 3; i++) {
    for (int j = 0; j <= 3; j++) {
      cout << dp[i][j] << ' ';
    }
    cout << endl;
  }
  cout << dp[n][m] << endl;

  return 0;
}
