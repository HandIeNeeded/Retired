/*************************************************************************
  > File Name: A.cc
  > Author: Riho.Yoshioka
  > Mail:   riho.yoshioka@yandex.com
  > Created Time: Tue 19 Jul 2016 09:07:34 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

const int N = 104;
const int INF = 1 << 30;
int dp[N][3], a[N];

int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    dp[i][0] = dp[i - 1][0] + 1;
    dp[i][0] = min(dp[i][0], dp[i - 1][1] + 1);
    dp[i][0] = min(dp[i][0], dp[i - 1][2] + 1);
    if (a[i] > 1) {
      dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
    }
    else dp[i][1] = INF;
    if (a[i] & 1) {
      dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
    }
    else dp[i][2] = INF;
  }
  int ans = min(dp[n][0], min(dp[n][1], dp[n][2]));
  cout << ans << endl;
  return 0;
}
