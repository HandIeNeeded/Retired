/*************************************************************************
  > File Name: 101-palindromes.cc
  > Author: Riho.Yoshioka
  > Mail:   riho.yoshioka@yandex.com
  > Created Time: Wed 27 Jul 2016 12:22:57 AM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

const int MO = 1e9 + 7;
const int N = 205;
const int K = 101;
int dp[N][N][K][4];
char s[N];

int Coef(int x) {
  if (x == 0) return 10;
  else if (x == 1) return 100;
  else if (x == 2) return 91;
  else if (x == 3) return 1;
  else return -1;
}

int Calc(int a, int mod, int l) {
  return (a * Coef(l) + mod * 10 + a) % K;
}

void Add(int &x, int y) {
  x += y;
  if (x >= MO) x -= MO;
}

int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n >> (s + 1);
  for (int i = 1; i <= n; i++) {
    dp[i][i][s[i] - '0'][1] = 1;
  }
  for (int i = 1; i <= n - 1; i++) {
    for (int k = 0; k < K; k++) {
      Add(dp[i][i + 1][k][1], dp[i][i][k][1]);
      Add(dp[i][i + 1][k][1], dp[i + 1][i + 1][k][1]);
    }
    if (s[i] == s[i + 1]) dp[i][i + 1][Calc(s[i] - '0', 0, 0)][2] = 1;
  }
  for (int length = 3; length <= n; length++) {
    for (int left = 1; left <= n - length + 1; left++) {
      int right = left + length - 1;
      for (int mod = 0; mod < K; mod++) {
        for (int pos = 0; pos < 4; pos++) {
          Add(dp[left][right][mod][pos], dp[left][right - 1][mod][pos]);
          Add(dp[left][right][mod][pos], dp[left + 1][right][mod][pos]);
          Add(dp[left][right][mod][pos], MO - dp[left + 1][right - 1][mod][pos]);
          if (s[left] == s[right]) {
            Add(dp[left][right][Calc(s[left] - '0', mod, pos)][(pos + 2) & 3], dp[left + 1][right - 1][mod][pos]);
          }
        }
      }
      if (s[left] == s[right]) Add(dp[left][right][Calc(s[left] - '0', 0, 0)][2], 1);
    }
  }
  int ans = 0;
  for (int i = 0; i < 4; i++) {
    Add(ans, dp[1][n][0][i]);
    cerr << ans << endl;
  }
  cout << ans << endl;

  return 0;
}
