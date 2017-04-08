/*************************************************************************
  >         File: A.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sat Apr  8 18:05:51 2017
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
  int T;
  std::cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    std::string s;
    int k;
    std::cin >> s >> k;
    int answer = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
      if (i + k > (int) s.size()) break;
      if (s[i] == '+') continue;
      ++answer;
      for (int j = 0; j < k; ++j) {
        s[i + j] = '+' + '-' - s[i + j];
      }
    }
    std::cout << "Case #" << cas << ": ";
    if (s.find('-') != std::string::npos) {
      std::cout << "IMPOSSIBLE" << std::endl;
    } else  {
      std::cout << answer << std::endl;
    }
  }

  return 0;
}
