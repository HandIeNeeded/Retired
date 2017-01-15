/*************************************************************************
  >         File: A.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Tue Jan  3 19:33:50 2017
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
  int n, m, k;
  std::cin >> n >> m >> k;
  --k;
  m <<= 1;
  int r = k / m;
  int c = k % m;
  std::cout << ++r << ' ' << c / 2 + 1 << ' ' << (c & 1 ? 'R' : 'L') << std::endl;


  return 0;
}
