/*************************************************************************
  >         File: P1008.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 10 Sep 2016 12:35:04 PM CST
*************************************************************************/
#include <bits/stdc++.h>

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

constexpr int N = 1e5 + 5;
constexpr int K = 17;
int a[N], dp[N][K], n;

void Init() {
  for (int i = 1; i <= n; ++i) dp[i][0] = a[i];
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= K - 1; ++j) {
      if (i + (1 << j) > n) break;
      dp[i][j] = std::min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
    }
  }
}

int Ask(int l, int r) {
  if (l == r) return a[l];
  int now = l + 1, x = a[l];
  while (now <= r) {
    for (int k = K - 1; k >= 0; k--) {
      if (dp[now][k] > x) {
        now += (1 << k);
      }
      if (now > r) break;
    }
    x %= a[std::min(r, now - 1)];
  }
  return x;
}

int main() {
  int t; in(t);
  while (t--) {
    in(n);
    for (int i = 1; i <= n; ++i) in(a[i]);
    Init();
    int q; in(q);
    while (q--) {
      int l, r;
      in(l), in(r);
      out(Ask(l, r));
    }
  }
  return 0;
}
