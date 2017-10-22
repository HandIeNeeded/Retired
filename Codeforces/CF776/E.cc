/*************************************************************************
  >         File: E.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Fri Feb 24 00:24:42 2017
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
  static constexpr int N = 1e6 + 5;
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

int phi(int k, int n) {
  if (k != 1) return phi(1, phi(k - 1, n));
  else {
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      if (std::__gcd(i, n) == 1) ans++;
    }
    return ans;
  }
}

using LL = long long;
std::map<LL, int> get(LL n) {
  std::map<LL, int> map;
  for (int i = 0; i < PM::count && 1LL * PM::prime[i] * PM::prime[i] <= n; i++) {
    if (n % PM::prime[i] == 0) {
      while (n % PM::prime[i] == 0) {
        map[PM::prime[i]]++;
        n /= PM::prime[i];
      }
    }
  }
  if (n > 1) map[n]++;
  return map;
}

int main() {
  std::ios::sync_with_stdio(0);
  LL n, k;

  //for (int i = 2; i <= 10; ++i) {
  //  for (int j = 2; j <= 10; ++j) {
  //    if (std::__gcd(i, j) == 1) {
  //      if (phi(2, i) * phi(2, j) != phi(2, i * j)) {
  //        std::cout << i << ' ' << j << std::endl;
  //      }
  //    }
  //  }
  //}
  //for (int i = 1; i <= 20; ++i) {
  //  std::cerr << "# i << ' ' << phi(2, i) # is " << i << ' ' << phi(2, i) << std::endl;
  //}
  //std::cout << "OK" << std::endl;
  PM::GetPrime();
  std::cin >> n >> k;
  k = (k + 1) >> 1;
  if (k > 10000) {
    std::cout << 1 << std::endl;
  } else {
    std::map<LL, int> map = get(n);
    for (auto &p: map) {
      LL x;
      int y;
      std::tie(x, y) = p;
      std::cerr << "# x << ' ' << y # is " << x << ' ' << y  << std::endl;
    }
    for (int i = 0; i < k; ++i) {
      auto newMap = map;
      for(auto &p: map) {
        LL x;
        int y;
        std::tie(x, y) = p;
        newMap[x]--;
        if (newMap[x] == 0) newMap.erase(x);
        auto tmp = get(x - 1);
        for (auto &q: tmp) {
          LL x; 
          int y;
          std::tie(x, y) = q;
          newMap[x] += y;
        }
      }
      map = newMap;
    }
    LL ans = 1;
    for (auto &p: map) {
      LL x;
      int y;
      std::tie(x, y) = p;
      for (int i = 0; i < y; ++i) ans *= x;
    }
    std::cout << ans % PM::MO << std::endl;
  }

  return 0;
}
