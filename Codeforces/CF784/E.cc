/*************************************************************************
  >         File: E.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sat Apr  1 00:21:45 2017
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
  int a[4], b[4], c[2], d;
  for (int i = 0; i < 4; ++i) std::cin >> a[i];
  int x = 8;
  for (int i = 0; i < 4; ++i) {
    if (x & (1 << i)) {
      a[i] ^= 1;
    }
  }
  b[0] = a[0] | a[1];
  b[1] = a[2] ^ a[3];
  b[2] = a[1] & a[2];
  b[3] = a[0] | a[3];
  c[0] = b[0] & b[1];
  c[1] = b[2] ^ b[3];
  d = c[0] | c[1];
  std::cout << d << std::endl;

  return 0;
}
