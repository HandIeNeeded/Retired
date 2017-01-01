/*************************************************************************
  >         File: A.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Fri Dec 30 23:01:33 2016
*************************************************************************/
#include <vector>
#include <cstdio>
#include <bitset>
#include <utility>
#include <cstdlib>
#include <sstream>
#include <fstream>
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

int main() {
  std::ios::sync_with_stdio(0);
  int n, k;
  std::cin >> n >> k;
  int left = 240 - k;
  int sum = 0;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    sum += i;
    if (5 * sum <= left) {
      ans++;
    }
  }
  std::cout << ans << std::endl;


  return 0;
}
