/*************************************************************************
  >         File: 1083.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Tue Jan  3 15:42:03 2017
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
  int n;
  std::string s;
  std::cin >> n >> s;
  int k = s.size();
  int ans = 1;
  for (int i = n; i > 0; --i) {
    if ((n - i) % k == 0) {
      ans *= i;
    }
  }
  std::cout << ans << std::endl;
  return 0;
}
