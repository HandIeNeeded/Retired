/*************************************************************************
  >         File: C.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sun Jan 22 04:06:26 2017
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

constexpr int N = 8e5 + 5;
constexpr int MO = 1e9 + 7;
using LL = long long;

LL D[N], W[N], S[N], Z[N];
int n, m, w, Aw, Bw, d, Ad, Bd, s, As, Bs;

void get() {
  std::cin >> n >> m;
  std::cin >> w >> Aw >> Bw;
  std::cin >> d >> Ad >> Bd;
  std::cin >> s >> As >> Bs;
  W[1] = w;
  for (int i = 2; i <= m; ++i) {
    W[i] = (Aw * W[i - 1] + Bw) % n + 1;
  }
  D[1] = d;
  for (int i = 2; i <= m; ++i) {
    D[i] = (Ad * D[i - 1] + Bd) % 3;
  }
  for (int i = 1; i <= m; ++i) {
    Z[i] = std::max(1LL, std::min(1LL * n, W[i] + D[i] - 1));
  }
  S[1] = s;
  for (int i = 2; i <= m; ++i) {
    S[i] = (As * S[i - 1] + Bs) % 1000000000 + 1;
  }
}

void show() {
  for (int i = 1; i <= m; ++i) {
    std::cout << W[i] << ' ';
  }
  std::cout << std::endl;
  for (int i = 1; i <= m; ++i) {
    std::cout << Z[i] << ' ';
  }
  std::cout << std::endl;
  for (int i = 1; i <= m; ++i) {
    std::cout << S[i] << ' ';
  }
  std::cout << std::endl;
}

void add(int &x, int y) {
  x += y;
  if (x >= MO) x -= MO;
};

constexpr int K = 2;
struct Matrix {
  int v[K][K];

  int* operator [] (int x) {
    return v[x];
  }

  const int * operator [] (int x) const {
    return v[x];
  }

  Matrix(int x = 0) {
    memset(v, 0, sizeof(v));
    if (x) {
      for (int i = 0; i < K; ++i) v[i][i] = x;
    }
  }
};

Matrix mul(const Matrix &a, const Matrix &b) {
  Matrix ans(0);
  for (int i = 0; i < K; ++i) {
    for (int j = 0; j < K; ++j) {
      for (int k = 0; k < K; ++k) {
        add(ans[i][j], 1LL * a[i][k] * b[k][j] % MO);
      }
    }
  }
  return ans;
}

#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID 
#define RC R, MID + 1, r

Matrix M[N << 2];
int A[N], B[N], C[N];
//A i -> i, B i -> i - 1, C i -> i + 1
int qx, qd, ql, qr;

Matrix set(int a, int b, int c, int d) {
  Matrix res;
  res[0][0] = a, res[0][1] = b;
  res[1][0] = c, res[1][1] = d;
  return res;
}

void build(int x, int l, int r) {
  if (l == r) {
    M[x] = Matrix();
  } else {
    build(LC), build(RC);
    M[x] = mul(M[L], M[R]);
  }
}

void update(int x, int l, int r) {
  if (l == r) {
    M[x] = set(0, 1LL * B[qd] * C[qd - 1] % MO, 1, A[qd]);
  } else {
    if (qx <= MID) update(LC);
    else update(RC);
    M[x] = mul(M[L], M[R]);
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  #ifdef HOME
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  #endif
  int t, cas = 0;
  std::cin >> t;
  while (t--) {
    get();
    //show();
    for (int i = 1; i <= n; ++i) {
      A[i] = 1;
      B[i] = C[i] = 0;
    }
    if (n == 1) {
      int ans = 0;
      for (int i = 1; i <= m; ++i) {
        add(ans, S[i]);
      }
      std::cout << "Case #" << ++cas << ":";
      std::cout << " " << ans << std::endl;
      continue;
    }
    build(1, 1, n - 1);
    for (int i = 1; i <= n - 1; ++i) {
      qx = i, qd = i + 1;
      update(1, 1, n - 1);
    }
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
      if (W[i] > Z[i]) {
        add(B[W[i]], S[i]);
        qx = W[i] - 1, qd = W[i];
        update(1, 1, n - 1);
      } else if (W[i] == Z[i]) {
        add(A[W[i]], S[i]);
        qx = W[i] - 1, qd = W[i];
        if (qx) update(1, 1, n - 1);
      } else {
        add(C[W[i]], S[i]);
        qx = W[i], qd = W[i] + 1;
        update(1, 1, n - 1);
      }
      Matrix s = set(1, A[1], 0, 0);
      add(ans, mul(s, M[1])[0][1]);
    }
    std::cout << "Case #" << ++cas << ":";
    std::cout << " " << ans << std::endl;
  }
  return 0;
}
