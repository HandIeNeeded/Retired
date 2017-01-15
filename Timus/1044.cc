/*************************************************************************
  >         File: 1044.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Wed Jan  4 20:04:32 2017
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

const int N = 200;
int dp[N][N];

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::cin >> n;
  int K = 100;
  dp[0][K] = 1;
  for (int i = 1; i <= n; ++i) {
    if (i <= n / 2) {
      for (int j = 0; j < 10; ++j) {
        for (int sum = 0; sum <= 9 * (i - 1); ++sum) {
          dp[i][j + sum + K] += dp[i - 1][sum + K];
        }
      }
    } else {
      for (int j = 0; j < 10; ++j) {
        for (int sum = -9 * (i - n / 2 - 1); sum <= 9 * n / 2; ++sum) {
          dp[i][sum - j + K] += dp[i - 1][sum + K];
        }
      }
    }
  }
  std::cout << dp[n][K] << std::endl;

  return 0;
}
