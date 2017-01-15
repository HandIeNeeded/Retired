/*************************************************************************
  >         File: 1084.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Thu Jan  5 19:09:01 2017
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
  double x, y;
  std::cin >> x >> y;
  x /= 2;
  if (x > y) {
    std::cout << std::fixed << std::setprecision(3) << acos(-1.0) * y * y << std::endl;
  } else if (x <= y && sqrt(2.0) * x > y) {
    double angle = acos(x / y) * 2;
    double ans = y * y * sin(angle) * 2;
    angle = 2 * acos(-1.0) - angle * 4;
    ans += angle * y * y / 2.0;
    std::cout << std::fixed << std::setprecision(3) << ans << std::endl;
  } else {
    std::cout << std::fixed << std::setprecision(3) << 4 * x * x << std::endl;
  }
  return 0;
}
