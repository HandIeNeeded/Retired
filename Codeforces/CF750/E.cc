/*************************************************************************
  >         File: E.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Tue Jan  3 05:23:23 2017
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

const int N = 5;
const int L = 2e5 + 5;
const int inf = 1e6;
int n, q;
char string[L];

class Matrix {
public:
  int v[N][N];
}mat[L << 1];

Matrix merge(const Matrix &a, const Matrix &b) {
  Matrix res;
  memset(res.v, 0x3f, sizeof(res.v));
  for (int i = 0; i < N; ++i) {
    for (int j = i; j < N; ++j) {
      for (int k = j; k < N; ++k) {
        res.v[i][k] = std::min(res.v[i][k], a.v[i][j] + b.v[j][k]);
      }
    }
  }
  return res;
}

void set(int id) {
  memset(mat[id].v, 0x3f, sizeof(mat[id].v));
  for (int i = 0; i < N; ++i) mat[id].v[i][i] = 0;
  int x = string[id - n] - '0';
  if (x == 2) {
    mat[id].v[0][0] = 1;
    mat[id].v[0][1] = 0;
  }
  if (x == 0) {
    mat[id].v[1][1] = 1;
    mat[id].v[1][2] = 0;
  }
  if (x == 1) {
    mat[id].v[2][2] = 1;
    mat[id].v[2][3] = 0;
  }
  if (x == 6) {
    mat[id].v[3][3] = 1;
    mat[id].v[4][4] = 1;
  }
  if (x == 7) {
    mat[id].v[3][3] = 1;
    mat[id].v[3][4] = 0;
  }
}

void init() {
  for (int i = n; i < 2 * n; ++i) set(i);
  for (int i = n - 1; i > 0; --i) mat[i] = merge(mat[i << 1], mat[i << 1 | 1]);
}

int ask(int l, int r) {
  l += n, r += n;
  Matrix a, b;
  memset(a.v, 0x3f, sizeof(a.v));
  memset(b.v, 0x3f, sizeof(b.v));
  for (int i = 0; i < N; ++i) a.v[i][i] = b.v[i][i] = 0;
  while (l < r) {
    if (l & 1) a = merge(a, mat[l++]);
    if (r & 1) b = merge(mat[--r], b);
    l >>= 1, r >>= 1;
  }
  a = merge(a, b);
  return a.v[0][4] > inf ? -1 : a.v[0][4];
}

int main() {
  //std::cin >> n >> q;
  //std::cin >> string;
  scanf("%d%d", &n, &q);
  scanf("%s", string);
  init();
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", ask(l - 1, r));
  }
  return 0;
}
