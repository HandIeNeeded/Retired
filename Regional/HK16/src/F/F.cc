/*************************************************************************
  >         File: F.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 10 Sep 2016 03:39:41 PM CST
*************************************************************************/
#include <bits/stdc++.h>
using LL = long long;
const int N = 1e5 + 5;

int cost[N], T[N];

int main() {
  std::ios::sync_with_stdio(0);
  
  int n;
  std::cin >> n;
  for (int i = 0; i < n - 1; ++i) std::cin >> cost[i + 1];
  for (int i = 1; i <= n; ++i) std::cin >> T[i];
  int now = 0, minCost = cost[1];
  LL sum = 0;
  for (int i = 2; i <= n; ++i) {
    if (now + 1 >= T[i]) {
      sum += cost[i - 1];
      now++;
    }
    else {
      int diff = T[i] - now - 1;
      if (diff & 1) {
        now = T[i] + 1;
        sum += 1LL * minCost * (diff + 1) + cost[i - 1];
      }
      else {
        now = T[i];
        sum += 1LL * minCost * diff + cost[i - 1];
      }
    }
    minCost = std::min(minCost, cost[i]);
  }
  std::cout << sum << std::endl;
  return 0;
}
