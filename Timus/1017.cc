/*************************************************************************
  >         File: 1017.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Thu Jan  5 19:31:33 2017
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

const int N = 555;
using LL = long long;
LL dp[N][N];

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::cin >> n;
  dp[1][1] = 1;
  for (int i = 2; i <= N - 1; ++i) {
    for (int j = 1; j <= i; ++j) {
      dp[i][j] = dp[i - j][j - 1] + dp[i - j][j];
    }
  }
  LL ans = 0;
  for (int i = 1; i <= n; ++i) ans += dp[n][i];
  std::cout << ans - 1 << std::endl;
  return 0;
}
