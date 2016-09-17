/*************************************************************************
  >         File: B.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Wed 14 Sep 2016 01:26:43 AM CST
*************************************************************************/
#include <bits/stdc++.h>
int count;
int X[2][2], Y[2][2];

void Ask(int a, int b, int c, int d) {
  std::cout << "? " << a << ' ' << b << ' ' << c << ' ' << d << std::endl;
  std::cin >> count;
}

void Print(int x) {
  std::cout << ' ' << X[x][0] << ' ' << Y[x][0] << ' ' << X[x][1] << ' ' << Y[x][1];
}

int GetUpBound(int l, int r, int down, int up) {
  int lo = down - 1, hi = up;
  while (lo + 1 < hi) {
    int mid = (lo + hi) >> 1;
    Ask(l, down, r, mid);
    if (count >= 1) hi = mid;
    else lo = mid;
  }
  return hi;
}

int GetDownBound(int l, int r, int down, int up) {
  int lo = down, hi = up + 1;
  while (lo + 1 < hi) {
    int mid = (lo + hi) >> 1;
    Ask(l, mid, r, up);
    if (count >= 1) lo = mid;
    else hi = mid;
  }
  return lo;
}

int GetLeftBound(int down, int up, int l, int r) {
  int lo = l, hi = r + 1;
  while (lo + 1 < hi) {
    int mid = (lo + hi) >> 1;
    Ask(mid, down, r, up);
    if (count >= 1) lo = mid;
    else hi = mid;
  }
  return lo;
}

int GetRightBound(int down, int up, int l, int r) {
  int lo = l - 1, hi = r;
  while (lo + 1 < hi) {
    int mid = (lo + hi) >> 1;
    Ask(l, down, mid, up);
    if (count >= 1) hi = mid;
    else lo = mid;
  }
  return hi;
}

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::cin >> n;
  //step 1, get bound | or --
  int rowBound = 0, columnBound = 0;

  //try |
  bool find = 0;
  int lo = 0, hi = n;
  while (lo + 1 < hi) {
    int mid = (lo + hi) >> 1;
    Ask(1, 1, mid, n);
    if (count > 0) hi = mid;
    else lo = mid;
  }
  Ask(1, 1, hi, n);
  if (count == 1) {
    Ask(hi + 1, 1, n, n);
    if (count == 1) find = 1, columnBound = hi;
  }
  //try --
  if (!find) {
    int lo = 0, hi = n;
    while (lo + 1 < hi) {
      int mid = (lo + hi) >> 1;
      Ask(1, 1, n, mid);
      if (count > 0) hi = mid;
      else lo = mid;
    }
    rowBound = hi;
    //step 2
    Y[0][1] = rowBound;
    Y[0][0] = GetDownBound(1, n, 1, rowBound);
    X[0][0] = GetLeftBound(Y[0][0], Y[0][1], 1, n);
    X[0][1] = GetRightBound(Y[0][0], Y[0][1], 1, n);

    Y[1][0] = GetDownBound(1, n, rowBound + 1, n);
    Y[1][1] = GetUpBound(1, n, rowBound + 1, n);
    X[1][0] = GetLeftBound(Y[1][0], Y[1][1], 1, n);
    X[1][1] = GetRightBound(Y[1][0], Y[1][1], 1, n);
  } else {
    // | conditionn
    // step 2
    X[0][1] = columnBound;
    X[0][0] = GetLeftBound(1, n, 1, columnBound);
    Y[0][0] = GetDownBound(X[0][0], X[0][1], 1, n);
    Y[0][1] = GetUpBound(X[0][0], X[0][1], 1, n);

    X[1][0] = GetLeftBound(1, n, columnBound + 1, n);
    X[1][1] = GetRightBound(1, n, columnBound + 1, n);
    Y[1][0] = GetDownBound(X[1][0], X[1][1], 1, n);
    Y[1][1] = GetUpBound(X[1][0], X[1][1], 1, n);
  }

  std::cout << "!";
  Print(0), Print(1);
  std::cout << std::endl;
  return 0;
}
