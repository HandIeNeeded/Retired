/*************************************************************************
  >         File: D.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sat Feb 18 19:00:34 2017
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

std::vector<int> A, B;
int k;

bool check(const std::vector<int> &A) {
  for (int i = 0; i < A.size(); ++i) {
    if (A[i] < i / k) return 1;
  }
  return 0;
}

int main() {
  std::ios::sync_with_stdio(0);
  int n, m;
  std::cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x; A.emplace_back(x);
  }
  for (int i = 0; i < m; ++i) {
    int x;
    std::cin >> x;
    B.emplace_back(x);
  }
  std::sort(A.begin(), A.end());
  std::vector<int> tmp(m, 0);
  std::iota(tmp.begin(), tmp.end(), 0);
  std::sort(tmp.begin(), tmp.end(), [](int a, int b) {return B[a] > B[b];});
  if (check(A)) {
    std::cout << -1 << std::endl;
  } else {
    int lo = 0, hi = m + 1;
    while (lo + 1 < hi) {
      int mid = (lo + hi) >> 1;
      std::vector<int> C = A;
      for (int i = 0; i < mid; ++i) {
        C.emplace_back(B[tmp[i]]);
      }
      std::reverse(C.begin() + n, C.end());
      std::inplace_merge(C.begin(), C.begin() + n, C.end());
      if (check(C)) hi = mid;
      else lo = mid;
    }
    std::cout << lo << std::endl;
    for (int i = 0; i < lo; ++i) {
      std::cout << tmp[i] + 1 << ' ';
    }
  }

  return 0;
}
