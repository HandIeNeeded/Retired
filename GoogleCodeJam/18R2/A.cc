/*************************************************************************
  >         File: A.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@fb.com
  > Created Time: Sat 19 May 15:00:52 2018
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

const int N = 222;
char mp[N][N];
int cnt[N], C;

void reset() {
  for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) mp[i][j] = '.';
}

bool check(int x) {
  int row = 0;
  int used = 0;
  for (int i = 1; i <= C; ++i) {
    if (cnt[i] == 0) continue;
    int l = used + 1;
    int r = used + cnt[i];
    for (int j = l, k = 0; j < i; ++k, ++j) {
      if (j >= i) break;
      mp[k + 1][j] = '\\';
    }
    for (int j = r, k = 0; j > i; ++k, --j) {
      mp[k + 1][j] = '/';
    }
    row = std::max(row, std::max(abs(i - l), abs(r - i)));
    used += cnt[i];
  }
  return row <= x;
}

int main() {
  std::ios::sync_with_stdio(0);
  #ifdef HOME
  freopen("A.in", "r", stdin);
  #endif
  int T;
  std::cin >> T;
  for (int cas = 0; cas < T; ++cas) {
    std::cin >> C;
    for (int i = 0; i < C; ++i) std::cin >> cnt[i + 1];
    bool bad = cnt[1] == 0 || cnt[C] == 0;
    int lo = -1, hi = 3 * C;
    while (lo + 1 < hi) {
      int mid = (lo + hi) >> 1;
      if (check(mid)) hi = mid;
      else lo = mid;
    }
    std::cout << "Case #" << cas + 1 << ": ";
    if (bad) {
      std::cout << "IMPOSSIBLE" << std::endl;
    } else {
      reset();
      check(hi);
      int ans = hi + 1;
      std::cout << ans << std::endl;
      for (int i = 1; i <= ans; ++i) {
        for (int j = 1; j <= C; ++j) {
          std::cout << mp[i][j];
        }
        std::cout << "" << std::endl;
      }
    }
  }
  return 0;
}
