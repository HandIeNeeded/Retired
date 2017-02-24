/*************************************************************************
  >         File: C.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Tue Jan  3 19:58:00 2017
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

std::string str = "LRUD";

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::string s;
  std::cin >> n >> s;
  int a = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    int x = str.find(s[i]);
    a |= 1 << x;
    if ((a & 3) == 3 || (a >> 2 & 3) == 3) {
      ans++;
      --i;
      a = 0;
    }
  }
  std::cout << ans + 1 << std::endl;


  return 0;
}
