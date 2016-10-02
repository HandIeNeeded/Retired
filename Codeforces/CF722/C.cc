/*************************************************************************
  >         File: C.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 01 Oct 2016 10:07:56 PM CST
*************************************************************************/
#include <bits/stdc++.h>
const int N = 111111;
int a[N], b[N];
using LL = long long;
int f[N], has[N];
LL sum[N], answer[N], result;

int find(int x) {
  return f[x] == x ? x : f[x] = find(f[x]);
}

void merge(int a, int b) {
  int tx = find(a);
  int ty = find(b);
  if (tx == ty) return ;
  f[tx] = ty;
  sum[ty] += sum[tx];
  result = std::max(result, sum[ty]);
}

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) std::cin >> a[i + 1];
  for (int i = 0; i < n; ++i) std::cin >> b[i];
  for (int i = 0; i < n; ++i) f[i + 1] = i + 1;
  result = 0;
  for (int i = n - 1; i >= 0; --i) {
    answer[i] = result;
    int x = b[i];
    has[x] = 1;
    sum[x] = a[x];
    result = std::max(result, sum[x]);
    if (has[x - 1]) merge(x - 1, x);
    if (has[x + 1]) merge(x, x + 1);
  }
  for (int i = 0; i < n; ++i) {
    std::cout << answer[i] << std::endl;
  }

  return 0;
}
