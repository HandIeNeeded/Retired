/*************************************************************************
  >         File: 1009.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Tue Jan  3 15:59:36 2017
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
#include <typeinfo>
using LL = long long;

LL pow(LL a, int b) {
  LL ans = 1;
  while (b) {
    if (b & 1) ans *= a;
    a *= a;
    b >>= 1;
  }
  return ans;
}

LL dp[20][2];

int main() {
  std::ios::sync_with_stdio(0);
  int n, k;
  std::cin >> n >> k;
  dp[1][1] = k - 1;
  for (int pos = 2; pos <= n; ++pos) {
    dp[pos][0] = dp[pos - 1][1];
    dp[pos][1] = (dp[pos - 1][0] + dp[pos - 1][1]) * (k - 1);
  }
  std::cout << dp[n][0] + dp[n][1] << std::endl;
  return 0;
}
