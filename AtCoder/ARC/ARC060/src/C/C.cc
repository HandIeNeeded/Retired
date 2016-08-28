/*************************************************************************
  >         File: C.cc
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sun 28 Aug 2016 08:00:43 PM CST
*************************************************************************/
#include <bits/stdc++.h>
using LL = long long;
const int N = 55;
LL dp[N][N][N * N];
int a[N];

int main() {
  std::ios::sync_with_stdio(0);
  
  int n, m;
  std::cin >> n >> m;
  dp[0][0][0] = 1;
  for (int i = 0; i < n; i++) std::cin >> a[i];
  for (int itr = 0; itr < n; itr++) {
    for (int cnt = 0; cnt < n; cnt++) {
      for (int sum = 0; sum < N * N; sum++) {
        dp[itr + 1][cnt][sum] += dp[itr][cnt][sum];
        dp[itr + 1][cnt + 1][sum + a[itr]] += dp[itr][cnt][sum];
      }
    }
  }
  LL answer = 0;
  for (int i = 0; i < n; i++) {
    answer += dp[n][i + 1][(i + 1) * m];
  }
  std::cout << answer << std::endl;
  return 0;
}
