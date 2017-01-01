/*************************************************************************
  >         File: A.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sun Jan  1 20:25:22 2017
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

int go(int a, int b) {
  std::string ans = "1";
  while (a && b) {
    if (a > b) {
      a -= b;
      ans += "0";
    } else {
      b -= a;
      ans += "1";
    }
    if (ans.size() > 60) break;
  }
  if (a + b != 1) return 0;
  if (ans.size() > 60) return 0;
  std::reverse(ans.begin(), ans.end());
  if (a) {
    for (int i = 0; i < ans.size(); ++i) ans[i] = '1' + '0' - ans[i];
  }
  std::cout << ans << std::endl;
  return 1;
}

int main() {
  std::ios::sync_with_stdio(0);
  const double magic = 0.5 * (sqrt(5) - 1);
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    int a = int(n * magic);
    int find = 0;
    if (n < 1e3) {
      for (int i = 1; i <= n - 1; ++i) {
        if (go(i, n - i)) {
          find = 1;
          break;
        }
      }
    } else {
      for (int i = 0; i < 1000; ++i) {
        int ta = a + i - 500;
        if (go(ta, n - ta)) {
          find = 1;
          break;
        }
      }
    }
    assert(find);
  }
  return 0;
}
