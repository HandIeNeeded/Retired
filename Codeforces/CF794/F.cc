/*************************************************************************
  >         File: E.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sat May 13 19:42:08 2017
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

constexpr int N = 1e5 + 5;
int a[N], f[N << 2][10];
using LL = long long;
LL s[N << 2][10];
LL answer[10];

template<class T>
void in(T& x) {
  char c;
  while (!isdigit(c = getchar()) && c != '-');
  bool flag = (c == '-');
  if (flag) c = getchar();
  x = c - '0';
  while (isdigit(c = getchar())) x = x * 10 + c - '0';
  if (flag) x *= -1;
}

template<class T>
void out(T x) {
  if (x < 0) putchar('-'), x *= -1;
  int length = 0, bit[20];
  for (; x > 0; x /= 10) bit[length++] = x % 10;
  if (!length) bit[length++] = 0;
  while (length--) putchar(bit[length] + '0');
  putchar('\n');
}

int ql, qr, from, to;

#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID 
#define RC R, MID + 1, r

void merge(int x, int l, int r) {
  for (int i = 0; i < 10; ++i) {
    s[x][i] = s[L][i] + s[R][i];
    f[x][i] = i;
  }
}

void build(int x, int l, int r) {
  if (l == r) {
    for (int i = 0; i < 10; ++i) s[x][i] = 0, f[x][i] = i;
    LL now = 1;
    while (a[l]) {
      int d = a[l] % 10;
      s[x][d] += now;
      now *= 10;
      a[l] /= 10;
    }
  } else {
    build(LC), build(RC);
    merge(x, l, r);
  }
}

void combine(int *a, int *b, int *c) {
  for (int i = 0; i < 10; ++i) {
    c[i] = b[a[i]];
  }
}

void push(int x, int l, int r) {
  if (l == r) return ;

  static LL sum[10];
  static int tmp[10];
  for (int i = 0; i < 10; ++i) sum[i] = 0;
  for (int i = 0; i < 10; ++i) {
    sum[f[x][i]] += s[L][i];
  }
  for (int i = 0; i < 10; ++i) {
    s[L][i] = sum[i];
  }
  combine(f[L], f[x], tmp);
  for (int i = 0; i < 10; ++i) f[L][i] = tmp[i];

  for (int i = 0; i < 10; ++i) sum[i] = 0;
  for (int i = 0; i < 10; ++i) {
    sum[f[x][i]] += s[R][i];
  }
  for (int i = 0; i < 10; ++i) {
    s[R][i] = sum[i];
  }
  combine(f[R], f[x], tmp);
  for (int i = 0; i < 10; ++i) f[R][i] = tmp[i];
}

void update(int x, int l, int r) {
  if (ql <= l && qr >= r) {
    static int A[10], B[10];
    for (int i = 0; i < 10; ++i) A[i] = i;
    s[x][to] += s[x][from];
    s[x][from] = 0;
    A[from] = to;
    combine(f[x], A, B);
    for (int i = 0; i < 10; ++i) f[x][i] = B[i];
  } else {
    push(x, l, r);
    if (ql <= MID) update(LC);
    if (qr > MID) update(RC);
    merge(x, l, r);
  }
}

void query(int x, int l, int r) {
  if (ql <= l && qr >= r) {
    for (int i = 0; i < 10; ++i) answer[i] += s[x][i];
  } else {
    push(x, l, r);
    if (ql <= MID) query(LC);
    if (qr > MID) query(RC);
    merge(x, l, r);
  }
}

int main() {
  std::cerr << "[Line #" << __LINE__ << "] fuck !!!" << std::endl;
  int n, q;
  std::cin >> n >> q;
  for (int i = 0; i < n; ++i) in(a[i + 1]);
  build(1, 1, n);
  for (int i = 0; i < q; ++i) {
    int type;
    in(type), in(ql), in(qr);
    if (type == 1) {
      in(from), in(to);
      if (from == to) continue;
      update(1, 1, n);
    } else {
      for (int i = 0; i < 10; ++i) answer[i] = 0;
      query(1, 1, n);
      LL ans = 0;
      for (int i = 0; i < 10; ++i) ans += i * answer[i];
      out(ans);
    }
  }

  return 0;
}
