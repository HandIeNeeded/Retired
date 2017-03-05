/*************************************************************************
  >         File: A.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sat Feb 18 18:07:23 2017
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
  int n;
  std::cin >> n;
  std::vector<int> numbers;
  int now = n;
  std::set<int> s;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x; s.insert(x);
    if (s.count(now)) {
      while (s.count(now)) {
        s.erase(now);
        std::cout << now-- << ' ';
      }
    }
    std::cout << "" << std::endl;
  }

  return 0;
}
