/*************************************************************************
  >         File: test.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Mon 19 Sep 2016 02:34:24 PM CST
*************************************************************************/
#include <bits/stdc++.h>

namespace FC {
  static constexpr int N = 100000;
  static constexpr int MO = 1e9 + 7;
  using array = int[N];
  array factorial, inverse, fInverse;

  void GetFactorial() {
    inverse[0] = 0; inverse[1] = factorial[0] = 1;
    fInverse[0] = fInverse[1] = 1;
    for (int i = 1; i <= N - 1; ++i) factorial[i] = 1LL * i * factorial[i - 1] % MO;
    for (int i = 2; i <= N - 1; ++i) inverse[i] = 1LL * (MO - MO / i) * inverse[MO % i] % MO;
    for (int i = 2; i <= N - 1; ++i) fInverse[i] = 1LL * fInverse[i - 1] * inverse[i] % MO;
  }

  int C(int a, int b) {
    if (a < 0 || b < 0 || a < b) return 0;
    return 1LL* factorial[a] * fInverse[b] % MO * fInverse[a - b] % MO;
  }
}

namespace PM {
  static constexpr int N = 100000;
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

namespace PR {
  int euler, G, prime;
  std::vector<int> factors;
  
  int Powd(int x, int y, int MO) {
    int answer = 1;
    for (; y > 0; y >>= 1) {
      if (y & 1) answer = 1LL * answer * x % MO;
      x = 1LL * x * x % MO;
    }
    return answer;
  }

  void GetFactor(int euler) {
    factors.clear();
    for (int i = 2; i * i <= euler; ++i) {
      if (euler % i == 0) {
        factors.emplace_back(i);
        while (euler % i == 0) euler /= i;
      }
    }
    if (euler > 1) factors.emplace_back(euler);
  }

  //prime ^ k, 2 * prime ^ k, 2, 4
  int GetRoot(int p) {
    if (p == 2) return 1;
    if (p == 4) return 3;
    prime = p, euler = p - 1; 
    GetFactor(euler);
    for (int i = 1; i <= euler; ++i) {
      bool bad = false;
      for (auto &factor: factors) {
        if (Powd(i, euler / factor, prime) == 1) {
          bad = 1;
          break;
        }
      }
      if (!bad) return G = i;
    }
    return 0;
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cerr << "---------------------------" << std::endl;
  std::cerr << "Time used: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec." << std::endl;
  
  PM::GetPrime();
  FC::GetFactorial();
  for (int i = 0; i < 10; ++i) {
    std::cout << PM::prime[i] << std::endl;
  }
  for (int i = 0; i < 5; ++i) {
    std::cout << FC::C(5, i) << std::endl;
  }
  return 0;
}
