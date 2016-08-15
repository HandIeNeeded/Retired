/*************************************************************************
  >         File: E.cc
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 13 Aug 2016 08:44:25 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

const int N = 401;
const int MO = 1e9 + 7;
int pw[N][N], p[N][N], A[N], B[N];
int dp[N][N], n, c;

void Add(int &x, int y) {
  x += y;
  if (x >= MO) x -= MO;
}

int Powd(int x, int y) {
  int ans = 1;
  for (; y; y >>= 1) {
    if (y & 1) ans = 1LL * ans * x % MO;
    x = 1LL * x * x % MO;
  }
  return ans;
}

void Init() {
  for (int k = 0; k < N; k++) {
    for (int j = 0; j < N; j++) {
      p[k][j] = Powd(k, j);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= c; j++) {
      for (int k = A[i]; k <= B[i]; k++) {
        Add(pw[i][j], p[k][j]);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin >> n >> c;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> B[i];
  }
  Init();
  if (n == 1) {
    int ans = 0;
    for (int i = A[0]; i <= B[0]; i++) {
      Add(ans, Powd(i, c));
    }
    cout << ans << endl;
    return 0;
  }
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= c; j++) {
      for (int d = 0; d + j <= c; d++) {
        int sum = pw[i][d];
        Add(dp[i + 1][d + j], 1LL * dp[i][j] * sum % MO);
      }
    }
  }
  cout << dp[n][c] << endl;
  return 0;
}
