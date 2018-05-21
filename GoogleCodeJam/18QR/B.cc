/*************************************************************************
  >         File: B.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@fb.com
  > Created Time: Sat  7 Apr 00:49:54 2018
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
  int T;
  std::cin >> T;
  for (int i = 0; i < T; ++i) {
    std::vector<int> a, b;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
      int x;
      std::cin >> x;
      if (i & 1) b.emplace_back(x);
      else a.emplace_back(x);
    }
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    std::vector<int> c;
    for (int i = 0; i < a.size(); ++i) {
      c.push_back(a[i]);
      if (i < b.size()) {
        c.push_back(b[i]);
      }
    }
    std::cout << "Case #" << i + 1 << ": ";
    if (std::is_sorted(c.begin(), c.end())) {
      std::cout << "OK" << std::endl;
    } else {
      std::cout << std::is_sorted_until(c.begin(), c.end()) - c.begin() - 1 << std::endl;
    }
  }


  return 0;
}
