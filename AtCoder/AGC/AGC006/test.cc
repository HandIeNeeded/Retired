/*************************************************************************
  >         File: test.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 29 Oct 2016 08:28:11 PM CST
*************************************************************************/
#include <bits/stdc++.h>
const int N = 100;
int a[N], A[N], B[N], cnt[N];

int Solve(int n) {
  for (int i = 0; i < 2 * n - 1; ++i) A[i] = a[i];
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < 2 * n - 1 - 2 * i - 2; ++j) {
      std::vector<int> tmp;
      tmp.emplace_back(A[j]);
      tmp.emplace_back(A[j + 1]);
      tmp.emplace_back(A[j + 2]);
      std::sort(tmp.begin(), tmp.end());
      A[j] = tmp[1];
    }
  }
  return A[0];
}

int Try(int n) {
  for (int i = 0; i < 2 * n - 1; ++i) A[i] = 0;
  A[0] = 1;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < 2 * i + 3; ++j) {
      B[j] = 0;
      for (int k = 0; k < 3; ++k) if (j - k >= 0) B[j] += A[j - k];
    }
    for (int j = 0; j < 2 * i + 3; ++j) A[j] = B[j];
    for (int j = 0; j < 2 * i + 3; ++j) {
      std::cout << A[j] << ' ';
    }
    std::cout << std::endl;
  }
  for (int i = 0; i < 2 * n - 1; ++i) {
    std::cerr << "# A[i] # is " << A[i] << std::endl;
  }
  int tot = std::accumulate(A, A + 2 * n - 1, 0);
  std::cerr << "# tot # is " << tot << std::endl;
  for (int i = 0; i < 2 * n - 1; ++i) {
    cnt[a[i]] = A[i];
  }
  int ans = 0;
  for (int i = 0; i < 2 * n - 1; ++i) {
    ans += cnt[i];
    if (ans >= tot / 2 + 1) return i;
  }
  return -1;
}

int mark[N];

int main() {
  std::ios::sync_with_stdio(0);
  int n = 4;
  for (int i = 0; i < 2 * n - 1; ++i) a[i] = i;
  do {
    int ans = Solve(n);
    //int res = Try(n);
    //std::cerr << "# permutation # is " << std::endl;
    //for (int i = 0; i < 2 * n - 1; ++i) {
    //  std::cout << a[i] << ' ';
    //}
    //std::cout << std::endl;
    //std::cerr << "# ans # is " << ans << std::endl;
    //std::cerr << "# res # is " << res << std::endl;
    //assert(ans == res);
    if (!mark[ans]) {
      std::cerr << "# ans # is " << ans << std::endl;
      std::cerr << "# permutation # is " << std::endl;
      for (int i = 0; i < 2 * n - 1; ++i) {
        std::cout << a[i] << ' ';
      }
      std::cout << std::endl;
      mark[ans] = 1;
    }
  }while (std::next_permutation(a, a + 2 * n - 1));
  std::cout << "AC" << std::endl;
  return 0;
}
