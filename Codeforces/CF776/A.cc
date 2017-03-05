/*************************************************************************
  >         File: A.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Thu Feb 23 23:42:38 2017
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
  std::string a, b;
  std::cin >> a >> b;
  int n;
  std::cin >> n;
  std::set<std::string> candidates;
  candidates.insert(a);
  candidates.insert(b);
  for (auto &s: candidates) {
    std::cout << s << " ";
  }
  std::cout << "" << std::endl;
  for (int i = 0; i < n; ++i) {
    std::string c, d;
    std::cin >> c >> d;
    candidates.erase(c);
    candidates.insert(d);
    for (auto &s: candidates) {
      std::cout << s << " ";
    }
    std::cout << "" << std::endl;
  }


  return 0;
}
