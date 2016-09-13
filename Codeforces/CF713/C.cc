/*************************************************************************
  >         File: C.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Wed 14 Sep 2016 12:56:53 AM CST
*************************************************************************/
#include <bits/stdc++.h>
using LL = long long;

constexpr int N = 3333;
LL a[N], b[N], dp[2][N];

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) std::cin >> a[i + 1];
  for (int i = 1; i <= n; ++i) a[i] -= i;
  memcpy(b, a, sizeof(a));
  std::sort(b+1,b+n+1);
  int now=0,la=1;
  for(int i=1;i<=n;i++) {
    std::swap(la,now);
    dp[now][1]=dp[la][1]+abs(a[i]-b[1]);
    for(int j=2;j<=n;j++)
      dp[now][j]=std::min(dp[now][j-1],dp[la][j]+std::abs(a[i]-b[j]));
  }
  std::cout << dp[now][n] << std::endl;
  return 0;
}
