/*************************************************************************
  >         File: 1073.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Thu Jan  5 19:26:51 2017
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

const int N = 66666;
int f[N];

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  f[0] = 0;
  for (int i = 1; i <= 60000; ++i) {
    f[i] = N;
    for (int j = 1; j * j <= i; ++j) {
      f[i] = std::min(f[i], f[i - j * j] + 1);
    }
  }
  std::cin >> n;
  std::cout << f[n] << std::endl;
  assert(f[n] <= 4);

  return 0;
}
