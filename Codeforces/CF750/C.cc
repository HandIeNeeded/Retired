/*************************************************************************
  >         File: C.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Fri Dec 30 23:29:16 2016
*************************************************************************/
#include <vector>
#include <cstdio>
#include <bitset>
#include <utility>
#include <cstdlib>
#include <sstream>
#include <fstream>
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

void inf() {
  std::cout << "Infinity" << std::endl;
  exit(0);
}

void NO() {
  std::cout << "Impossible" << std::endl;
  exit(0);
}

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::cin >> n;
  int mi = 1e9, mx = -1e9;
  int x, d;
  std::cin >> x >> d;
  int diff = 0;
  if (d == 1) {
    mi = 1900;
    mx = 1e9;
  }
  else {
    mi = -1e9;
    mx = 1899;
  }
  diff += x;
  for (int i = 0; i < n - 1; ++i) {
    int x, d;
    std::cin >> x >> d;
    int l = mi + diff, r = mx + diff;
    if (d == 1) {
      if (r < 1900) NO();
      mi = std::max(mi, 1900 - diff);
    }
    else {
      if (l >= 1900) NO();
      mx = std::min(mx, 1899 - diff);
    }
    diff += x;
  }
  if (mx > 1e8) inf();
  std::cout << mx + diff << std::endl;

  return 0;
}
