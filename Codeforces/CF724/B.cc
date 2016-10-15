/*************************************************************************
  >         File: B.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 08 Oct 2016 08:38:41 PM CST
*************************************************************************/
#include <bits/stdc++.h>

int A[22][22];
int tmp[22], n, m;

bool can(int a, int b, int c) {
  //swap columne first
  std::copy(A[c], A[c] + m, tmp);
  std::swap(tmp[a], tmp[b]);
  for (int i = 0; i < m; ++i) {
    for (int j = i; j < m; ++j) {
      std::swap(tmp[i], tmp[j]);
      if (std::is_sorted(tmp, tmp + m)) return 1;
      std::swap(tmp[i], tmp[j]);
    }
  }
  return 0;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> A[i][j];
    }
  }
  for (int i = 0; i < m; ++i) {
    for (int j = i; j < m; ++j) {
      int good = 1;
      for (int k = 0; k < n; ++k) good &= can(i, j, k);
      if (good) {
        std::cout << "YES" << std::endl;
        return 0;
      }
    }
  }
  std::cout << "NO" << std::endl;



  return 0;
}
