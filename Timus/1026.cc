/*************************************************************************
  >         File: 1026.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Thu Jan  5 19:05:41 2017
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
int a[N];

int main() {
  std::ios::sync_with_stdio(0);
  
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  std::sort(a, a + n);
  std::string s; std::cin >> s;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    std::cout << a[x - 1] << std::endl;
  }
  return 0;
}
