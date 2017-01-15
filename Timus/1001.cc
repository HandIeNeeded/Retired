/*************************************************************************
  >         File: 1001.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Tue Jan  3 06:33:17 2017
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
#include <iomanip>

int main() {
  std::ios::sync_with_stdio(0);
  std::stack<double> res;
  double x;
  while (std::cin >> x) {
    res.push(sqrt(x));
  }
  while (res.size()) {
    std::cout << std::fixed << std::setprecision(4) << res.top() << std::endl;
    res.pop();
  }

  return 0;
}
