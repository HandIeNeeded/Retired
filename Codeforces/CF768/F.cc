/*************************************************************************
  >         File: F.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Tue 21 Feb 2017 03:36:58 AM JST
*************************************************************************/
#include <bits/stdc++.h>

namespace FC {
  static constexpr int N = 1e5 + 1;
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

int h;
const int MO = 1e9 + 7;

void Add(int &x, int y) {
  x += y;
  if (x >= MO) x -= MO;
}

int Powd(int x, int y) {
  int ans = 1;
  for (; y; y >>= 1) {
    if (y & 1) ans = 1LL * ans * x % MO;
    x = 1LL * x * x % MO;
  }
  return ans;
}

int getABA(int a, int b) {
  int ans = 0;
  for (int i = 0; i <= a; ++i) {
    if (1LL * (i + 1) * h > a) break;
    if (i == 0) {
      if (b) continue;
    }
    int A = a - (i + 1) * h;
    int B = b - i * h;
    if (B < 0) continue;
    Add(ans, 1LL * FC::C(A + i + 1, i) * FC::C(B + i, i - 1) % MO);
  }
  return ans;
}

int getAB(int a, int b) {
  int ans = 0;
  for (int i = 1; i <= a; ++i) {
    if (1LL * i * h > a) break;
    int A = a - i * h;
    int B = b - i * h;
    if (B < 0) continue;
    Add(ans, 1LL * FC::C(A + i, i - 1) * FC::C(B + i, i - 1) % MO);
  }
  return ans;
}

int getAll(int a, int b) {
  h = 1;
  int up = 0;
  Add(up, getAB(a, b));
  Add(up, getABA(a, b));
  return up;
}

int main() {
  std::ios::sync_with_stdio(0);
  int f, w;
  std::cin >> f >> w >> h;
  h++;
  FC::GetFactorial();
  int up = 0, down = 0;
  Add(up, getAB(f, w));
  Add(up, getAB(w, f));
  std::cerr << "# up # is " << up << std::endl;
  Add(up, getABA(f, w));
  Add(up, getABA(w, f));
  Add(down, getAll(f, w));
  Add(down, getAll(w, f));
  assert(down);
  std::cout << 1LL * up * Powd(down, MO - 2) % MO << std::endl;

  return 0;
}
