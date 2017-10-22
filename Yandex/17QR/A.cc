/*************************************************************************
  >         File: A.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sun Apr 30 09:38:50 2017
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
  std::map<int, int> position;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    position[x] = i;
  }
  int ans = 1;
  for (int i = 1; i <= n - 1; ++i) {
    if (position[i] > position[i + 1]) ans++;
  }
  std::cout << ans << std::endl;
  return 0;
}
