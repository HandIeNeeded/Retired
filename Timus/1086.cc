/*************************************************************************
  >         File: 1086.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Thu Jan  5 18:44:48 2017
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
  static constexpr int N = 2e5;
  static constexpr int MO = 1e9 + 7;
  using array = int[N];
  array mark, prime, mobius;
  int count = 0;
  std::vector<int> factor[N];

  void GetPrime() {
    factor[1].emplace_back(1);
    for (int i = 2; i < N; ++i) {
      if (!mark[i]) {
        prime[count++] = i;
        mobius[i] = MO - 1;
        factor[i].emplace_back(i);
      }
      for (int j = 0; j < count && i * prime[j] < N; ++j) {
        int now = i * prime[j];
        mark[now] = prime[j];
        mobius[now] = (MO - mobius[i]) % MO;
        factor[now] = factor[i];
        factor[now].emplace_back(prime[j]);
        if (i % prime[j] == 0) {
          mobius[now] = 0;
          factor[now].pop_back();
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
  PM::GetPrime();
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    std::cout << PM::prime[x - 1] << std::endl;
  }


  return 0;
}
