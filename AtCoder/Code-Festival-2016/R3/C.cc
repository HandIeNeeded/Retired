/*************************************************************************
  >         File: C.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sun 23 Oct 2016 10:16:05 PM CST
*************************************************************************/
#include <bits/stdc++.h>

const int N = 1e5 + 5;
int A[N], B[N], C[N], D[N];

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) std::cin >> A[i];
  for (int i = 0; i < n; ++i) std::cin >> B[i];
  for (int i = 0; i < n; ++i) {
    if (i == 0) C[i] = A[i];
    else if (A[i] != A[i - 1]) C[i] = A[i];
  }
  for (int i = n - 1; i >= 0; --i) {
    if (i == n - 1) D[i] = B[i];
    else if (B[i] != B[i + 1]) D[i] = B[i];
  }
  int ans = 1;
  const int MO = 1e9 + 7;
  for (int i = 0; i < n; ++i) {
    if (C[i] && C[i] > B[i]) ans = 0;
    if (D[i] && D[i] > A[i]) ans = 0;
    else if (!C[i] && !D[i]) ans = 1LL * ans * std::min(A[i], B[i]) % MO;
  }
  std::cout << ans << std::endl;
  return 0;
}
