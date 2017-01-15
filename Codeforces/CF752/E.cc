/*************************************************************************
  >         File: E.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Tue Jan  3 20:09:25 2017
*************************************************************************/
#include <vector>
#include <cstdio>
#include <bitset>
#include <utility>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <cstring>
#include <cassert>
#include <numeric>
#include <set>
#include <map>
#include <deque>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
#include <iomanip>
using LL = long long;
const int N = 1e6 + 5;
const int K = 1e7 + 5;
int dp[K];
int a[N];
std::map<int, std::map<int, int>> mp;

void get(int x) {
  for (int i = 1; i < x; ++i) dp[i] = 0;
  for (int i = x; i <= K - 1; ++i) {
    dp[i] = std::max(1, dp[i / 2] + dp[i - i / 2]);
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  int n, k;
  std::cin >> n >> k;
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  LL sum = 0;
  sum = std::accumulate(a, a + n, 0LL);
  if (sum < k) {
    std::cout << -1 << std::endl;
    return 0;
  }
  int lo = 1, hi = *std::max_element(a, a + n) + 1;
  while (lo + 1 < hi) {
    int mid = (lo + hi) >> 1;
    get(mid);
    LL cnt = 0;
    for (int i = 0; i < n; ++i) {
      cnt += dp[a[i]];
    }
    if (cnt >= k) lo = mid;
    else hi = mid;
  }
  std::cout << lo << std::endl;
  return 0;
}
