/*************************************************************************
  >         File: 1020.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Tue Jan  3 16:45:40 2017
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

const int N = 111;
double A[N], B[N];

double sqr(double x) {
  return x * x;
}

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  double r;
  std::cin >> n >> r;
  double ans = acos(-1.0) * r * 2;
  for (int i = 0; i < n; ++i) {
    std::cin >> A[i] >> B[i];
  }
  for (int i = 0; i < n; ++i) {
    int x = i, y = (i + 1) % n;
    ans += sqrt(sqr(A[y] - A[x]) + sqr(B[y] - B[x]));
  }
  std::cout << std::fixed << std::setprecision(2) << ans << std::endl;
  return 0;
}
