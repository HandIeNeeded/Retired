/*************************************************************************
  >         File: 1013.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Wed Jan  4 22:13:38 2017
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

LL n, k, MO;
const int N = 2;

typedef LL Matrix[N][N];
Matrix ret, tmp, base;

void Add(LL &x, LL y) {
  x += y;
  if (x >= MO) x -= MO;
}

LL mul(LL a, LL b) {
  LL ans = 0;
  a %= MO;
  for (; b; b >>= 1) {
    if (b & 1) Add(ans, a);
    Add(a, a);
  }
  return ans;
}

void Mul(Matrix &a, Matrix &b) {
  for(int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) tmp[i][j] = 0;
  for(int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) {
    for (int k = 0; k < N; ++k) Add(tmp[i][j], mul(a[i][k], b[k][j]));
  }
  memcpy(a, tmp, sizeof(a));
}

void Powd(LL b) {
  for(int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) ret[i][j] = i == j;
  for(; b; b >>= 1) {
    if (b & 1) Mul(ret, base);
    Mul(base, base);
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin >> n >> k >> MO;
  base[1][0] = 1;
  base[0][1] = base[1][1] = k - 1;
  Powd(n - 1);
  LL ans = mul(k - 1, ret[1][0]);
  Add(ans, mul(k - 1, ret[1][1]));
  std::cout << ans << std::endl;
  return 0;
}
