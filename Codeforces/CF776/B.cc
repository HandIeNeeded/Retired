/*************************************************************************
  >         File: B.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Thu Feb 23 23:51:52 2017
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

namespace PM {
  static constexpr int N = 2e5 + 5;;
  static constexpr int MO = 1e9 + 7;
  using array = int[N];
  array mark, prime, mobius;
  int count = 0;

  void GetPrime() {
    for (int i = 2; i < N; ++i) {
      if (!mark[i]) {
        prime[count++] = i;
        mobius[i] = MO - 1;
      }
      for (int j = 0; j < count && i * prime[j] < N; ++j) {
        int now = i * prime[j];
        mark[now] = prime[j];
        mobius[now] = (MO - mobius[i]) % MO;
        if (i % prime[j] == 0) {
          mobius[now] = 0;
          break;
        }
      }
    }
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::cin >> n;
  n++;
  int m = n >> 1;
  PM::GetPrime();
  int ans = 1;
  if (m >= 2) ans++;
  std::cout << ans << std::endl;
  int now = 2;
  for (int i = 2; i <= n; ++i) {
    if (i <= m && !PM::mark[i]) std::cout << now << std::endl;
    else std::cout << 1 << std::endl;
  }

  return 0;
}
