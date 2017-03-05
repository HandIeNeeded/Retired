/*************************************************************************
  >         File: A.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sun Jan 22 03:28:34 2017
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

int get(int n, int m, int k) {
  int x = (n - 1) / k;
  x = std::min(x, (3 * k + 1) / k);
  if (2 * k + 3 <= m) return x;
  return -1;
}

int main() {
  #ifdef HOME
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
  #endif
  std::ios::sync_with_stdio(0);
  int t, cas = 0;
  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    int n, m, k;
    std::cin >> n >> m >> k;
    int ans = 1e9;
    auto update = [] (int &x, int y) {
      if (y > 0 && x > y) x = y;
    };
    int a = get(n, m, k) + 1;
    update(ans, a);
    int b = get(m, n, k) + 1;
    update(ans, b);
    if (ans > 1e8) ans = -1;
    std::cout << "Case #" << ++cas << ":";
    std::cout << " " << ans << std::endl;
  }
  return 0;
}
