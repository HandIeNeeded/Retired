/*************************************************************************
  >         File: E.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Tue Mar 14 20:07:41 2017
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
  int a[3];
  std::set<std::pair<int, int>> set;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 3; ++j) std::cin >> a[j];
    for (int x = 0; x < 3; ++x) {
      for (int y = x + 1; y < 3; ++y) {
        int A = a[x], B = a[y];
        if (A > B) std::swap(A, B);
        set.emplace(A, B);
      }
    }
  }
  std::cout << 2 * set.size() - 6 << std::endl;

  return 0;
}
