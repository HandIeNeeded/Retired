/*************************************************************************
  >         File: A.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sat Apr  1 21:02:44 2017
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

const int N = 1e5 + 5;
int a[N * 3];
using LL = long long;

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::cin >> n;
  n *= 3;
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  LL sum = 0;
  std::sort(a, a + n);
  int left = 0, right = n - 1;
  while (left < right) {
    sum += a[right - 1];
    left++, right -= 2;
  }
  std::cout << sum << std::endl;

  return 0;
}
