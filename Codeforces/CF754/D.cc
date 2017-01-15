/*************************************************************************
  >         File: D.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sat Jan  7 00:41:27 2017
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

const int N = 6e5 + 5;
int cnt[N], n, k;
int L[N], R[N];

void add(int x, int d) {
  for(; x < N; x += x & -x) {
    cnt[x] += d;
  }
}

int ask(int x) {
  int ans = 0;
  for(; x; x -= x & -x) {
    ans += cnt[x];
  }
  return ans;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin >> n >> k;
  std::vector<int> numbers;
  for (int i = 0; i < n; ++i) {
    std::cin >> L[i] >> R[i];
    numbers.emplace_back(L[i]);
    numbers.emplace_back(R[i]);
  }
  std::sort(numbers.begin(), numbers.end());
  numbers.resize(std::unique(numbers.begin(), numbers.end()) - numbers.begin());
  for (int i = 0; i < n; ++i) {
    L[i] = std::lower_bound(numbers.begin(), numbers.end(), L[i]) - numbers.begin() + 1;
    R[i] = std::lower_bound(numbers.begin(), numbers.end(), R[i]) - numbers.begin() + 1;
    add(L[i], 1);
  }
  std::vector<int> tmp(n, 0);
  std::iota(tmp.begin(), tmp.end(), 0);
  std::sort(tmp.begin(), tmp.end(), [] (int a, int b) { return R[a] < R[b] || (R[a] == R[b] && L[a] < L[b]);});
  int mx = 0, right = -1, left = -1;
  for (int i = 0; i < n; ++i) {
    int id = tmp[i];
    int bound = R[id];
    if (ask(bound) < k) {
      add(L[id], -1);
      continue;
    }
    int lo = 0, hi = bound;
    while (lo + 1 < hi) {
      int mid = (lo + hi) >> 1;
      if (ask(mid) >= k) hi = mid;
      else lo = mid;
    }
    if (numbers[bound - 1] - numbers[hi - 1] + 1 > mx) {
      mx = numbers[bound - 1] - numbers[hi - 1] + 1;
      right = bound, left = hi;
    }
    add(L[id], -1);
  }
  std::cout << mx << std::endl;
  if (right < 0 || left < 0) {
    for (int i = 0; i < k; ++i) {
      std::cout << i + 1 << " \n"[i == k - 1];
    }
    return 0;
  }
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (L[i] <= left && R[i] >= right) {
      cnt++;
      std::cout << i + 1 << " \n"[cnt == k];
      if (cnt == k) break;
    }
  }
  return 0;
}
