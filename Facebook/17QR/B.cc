/*************************************************************************
  >         File: B.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sat Jan  7 23:51:27 2017
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

int main() {
  std::ios::sync_with_stdio(0);
  #ifdef HOME
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  #endif
  int t, cas = 0;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::vector<int> numbers;
    for (int i = 0; i < n; ++i) {
      int x;
      std::cin >> x;
      numbers.push_back(x);
    }
    std::sort(numbers.begin(), numbers.end());
    int ans = 0;
    for (int i = 0, j = int(numbers.size() - 1); i <= j; ++i, --j) {
      int need = 49 / numbers[j];
      while (need && i < j) ++i, --need;
      if (need) break;
      --i, ++ans;
    }
    std::cout << "Case #" << ++cas << ":";
    std::cout << " " << ans << std::endl;
  }
  return 0;
}
