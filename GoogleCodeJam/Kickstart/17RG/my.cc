/*************************************************************************
  >         File: A.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sun 22 Oct 2017 01:48:15 PM JST
*************************************************************************/
#include <bits/stdc++.h>

const int N = 100;
std::map<int, int> factors[2];

void getFactor(int x, std::map<int, int>& factors) {
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      int cnt = 0;
      while (x % i == 0) {
        ++cnt;
        x /= i;
      }
      factors[i] = cnt;
    }
  }
  if (x > 1) factors[x] = 1;
}

using LL = long long;
LL a[N], mod[N]; //x == a[i] (mod mod[i]), i = 0, 1, ... , n - 1

void exgcd( LL a, LL b, LL &d, LL &x, LL &y){
  if (!b) d = a, x = 1, y = 0;
  else exgcd(b, a % b, d, y, x), y -= (a / b) * x;
}

#define REP(i, n) for (int i = 0; i < (int) (n); ++i)

LL china (LL n, LL *a, LL *mod){// i = 0, 1, ... , n - 1
  LL re = 0, M = 1;
  REP(i, n) M *= mod[i];
  REP(i, n) {
    LL d, x, y;
    exgcd(M / mod[i], mod[i], d, x, y);
    if (x < 0) x += M;
    re = (re + M / mod[i] * x * a[i]) % M; //be careful overflow
  }
  return (re + M) % M;
}

int get(int x, int y) {
  int ans = 1;
  for (int i = 0; i < y; ++i) ans *= x;
  return ans;
}

int getPhi(int p, int k) {
  return (p - 1) * get(p, k - 1);
}

int getReminder(std::map<int, int>& factors, int a, int n, int p, int cnt) {
  int k = factors[p];
  int others = a / get(p, k);
  int tmp = k;
  if (k != 0) {
    bool isLarger = false;
    for (int i = 1; i <= n; ++i) {
      tmp *= i;
      if (tmp >= cnt) {
        isLarger = true;
        break;
      }
    }
    if (isLarger) return 0;
    tmp = get(p, tmp);
  } else {
    tmp = 1;
  }
  int phi = getPhi(p, cnt);
  int reminder = 1;
  //std::cout << others << std::endl;
  for (int i = 1; i <= n; ++i) {
    reminder = 1LL * reminder * i % phi;
  }
  //std::cout << reminder << std::endl;
  int ans = 1;
  int P = get(p, cnt);
  for (int i = 1; i <= reminder; ++i) {
    ans = 1LL * ans * others % P;
  }
  return 1LL * tmp * ans % P;
}

int solve(int a, int n, int p) {
  for (int i = 0; i < 2; ++i) factors[i].clear();
  getFactor(a, factors[0]);
  getFactor(p, factors[1]);
  int tot = 0;
  for (auto &pair: factors[1]) {
    int p, cnt;
    std::tie(p, cnt) = pair;
    mod[tot] = get(p, cnt);
    ::a[tot++] = getReminder(factors[0], a, n, p, cnt);
  }
  //for (int i = 0; i < tot; ++i) {
    //std::cout << ::a[i] << ' ' << mod[i] << std::endl;
  //}
  return china(tot, ::a, mod);
}

int main() {
  std::ios::sync_with_stdio(0);
  int t, cas = 1;
  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    int A, N, P;
    std::cin >> A >> N >> P;
    std::cout << "Case #" << cas++ << ": ";
    std::cout << solve(A, N, P) << std::endl;
  }

  return 0;
}
