/*************************************************************************
  >         File: C.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Fri 23 Sep 2016 10:20:33 PM CST
*************************************************************************/
#include <bits/stdc++.h>
const int N = 2;
const int NN = 1e5 + 5;
const int MO = 1e9 + 7;

void Add(int &x, int y) {
  x += y;
  if (x >= MO) x -= MO;
}

struct Matrix {
  int a[N][N];

  Matrix (bool ident = 0) {
    memset(a, 0, sizeof(a));
    if (ident) {
      for (int i = 0; i < N; ++i) a[i][i] = 1;
    }
  }

  int* operator [] (int i){
    return a[i];
  }

  const int* operator [] (int i) const {
    return a[i];
  }

  Matrix operator + (const Matrix& rhs) const {
    Matrix ans;
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) {
      ans[i][j] = a[i][j];
      Add(ans[i][j], rhs[i][j]);
    }
    return ans;
  }
};

Matrix operator * (const Matrix &a, const Matrix &b) {
  Matrix c;
  for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) for (int k = 0; k < N; ++k) {
    Add(c[i][j], 1LL * a[i][k] * b[k][j] % MO);
  }
  return c;
}

std::pair<int, int> operator * (const std::pair<int, int>&a, const Matrix &b) {
  return { (1LL * a.first * b[0][0] % MO + 1LL * a.second * b[1][0] % MO) % MO, 
    (1LL * a.first * b[0][1] % MO + 1LL * a.second * b[1][1] % MO) % MO};
}

std::pair<int, int> operator + (const std::pair<int, int> &a, const std::pair<int, int> &b) {
  return {(a.first + b.first) % MO, (a.second + b.second) % MO};
}

using LL = long long;

struct Segment {
  std::pair<int, int> mat;
  LL add;
}t[NN << 2];

int ql, qr, qd;
int a[NN];
#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID 
#define RC R, MID + 1, r

Matrix base, pw[111];

Matrix Powd(Matrix x, LL y) {
  Matrix ans(1);
  for (int now = 1; y; y >>= 1, now++) {
    if (y & 1) ans = ans * pw[now];
  }
  return ans;
}

int GetNthFib(LL x) {
  std::pair<int, int> start{0, 1};
  return (start * Powd(base, x)).first;
}

void build(int x, int l, int r) {
  if (l == r) {
    t[x].mat.first = GetNthFib(a[l] - 1);
    t[x].mat.second = GetNthFib(a[l]);
    t[x].add = 0;
  }
  else {
    build(LC), build(RC);
    t[x].mat = t[L].mat + t[R].mat;
    t[x].add = 0;
  }
}

void push(int x, int l, int r) {
  t[L].add += t[x].add;
  t[R].add += t[x].add;
  t[L].mat = t[L].mat * Powd(base, t[x].add);
  t[R].mat = t[R].mat * Powd(base, t[x].add);
  t[x].add = 0;
}

void update(int x, int l, int r) {
  if (ql <= l && qr >= r) {
    t[x].add += qd;
    t[x].mat = t[x].mat * Powd(base, qd);
  } else {
    if (t[x].add) push(x, l, r);
    if (ql <= MID) update(LC);
    if (qr > MID) update(RC);
    t[x].mat = t[L].mat + t[R].mat;
  }
}

std::pair<int, int> query(int x, int l, int r) {
  if (ql <= l && qr >= r) return t[x].mat;
  else {
    std::pair<int, int> A, B;
    if (t[x].add) push(x, l, r);
    if (ql <= MID) A = query(LC);
    if (qr > MID) B = query(RC);
    return A + B;
  }
}

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

int main() {
  base[0][1] = base[1][0] = base[1][1] = 1;
  pw[0] = Matrix(1), pw[1] = base;
  for (int i = 2; i < 100; ++i) {
    pw[i] = pw[i - 1] * pw[i - 1];
  }
  int n, m;
  //std::cin >> n >> m;
  in(n), in(m);
  //for (int i = 1; i <= n; ++i) std::cin >> a[i];
  for (int i = 1; i <= n; ++i) in(a[i]);
  build(1, 1, n);
  for (int i = 0; i < m; ++i) {
    int type;
    in(type); in(ql); in(qr);
    //std::cin >> type;
    //std::cin >> ql >> qr;
    if (type == 2) {
      out(query(1, 1, n).second);
      //std::cout << query(1, 1, n)[0][1] << std::endl;
    }
    else {
      //std::cin >> qd;
      in(qd);
      update(1, 1, n);
    }
  }
  return 0;
}
