/*************************************************************************
  >         File: D.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sat Apr  8 21:20:34 2017
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
constexpr int MO = 1e9 + 7;
constexpr int N = 2e5;

int a[N], b[N];

void Add(int &x, int y) {
  x += y;
  if (x >= MO) x -= MO;
}

int get(int n) {
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    Add(ans, 1LL * i * (n - i) % MO * b[i] % MO);
  }
  return ans;
}

int main() {
  std::ios::sync_with_stdio(0);
  int cnt[2];
  for (int i = 0; i < 2; ++i) {
    std::cin >> cnt[i];
  }
  int ans = 1;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < cnt[i]; ++j) {
      std::cin >> a[j];
    }
    for (int j = 1; j < cnt[i]; ++j) {
      b[j] = a[j] - a[j - 1];
    }
    ans = 1LL * ans * get(cnt[i]) % MO;
  }
  std::cout << ans << std::endl;

  return 0;
}
