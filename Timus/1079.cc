/*************************************************************************
  >         File: 1079.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Tue Jan  3 16:56:56 2017
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

const int N = 100000;
int a[N] = {0, 1};

int main() {
  std::ios::sync_with_stdio(0);
  for (int i = 2; i < N; ++i) {
    if (i & 1) a[i] = a[i >> 1] + a[(i >> 1) + 1];
    else a[i] = a[i >> 1];
  }
  for (int i = 0; i < 10; ++i) {
    std::cout << a[i] << ',';
  }
  for (int i = 1; i < N; ++i) a[i] = std::max(a[i], a[i - 1]);
  int n;
  while (std::cin >> n) {
    if (n == 0) break;
    std::cout << a[n] << std::endl;
  }
  return 0;
}
