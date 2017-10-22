/*************************************************************************
  >         File: A.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sat Apr 15 09:57:21 2017
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
  #ifdef HOME
  freopen("A.out", "w", stdout);
  #endif
  int T;
  std::cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    int n, m;
    static char mp[30][30];
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) std::cin >> mp[i];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (mp[i][j] != '?') {
          int k;
          k = i - 1;
          while (k >= 0 && mp[k][j] == '?') mp[k][j] = mp[i][j], k--;
          k = i + 1;
          while (k < n && mp[k][j] == '?') mp[k][j] = mp[i][j], k++;
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (mp[i][j] != '?') {
          int k;
          k = j - 1;
          while (k >= 0 && mp[i][k] == '?') mp[i][k] = mp[i][j], k--;
          k = j + 1;
          while (k < m && mp[i][k] == '?') mp[i][k] = mp[i][j], k++;
        }
      }
    }
    std::cout << "Case #" << cas << ":" << std::endl;
    for (int i = 0; i < n; ++i) {
      std::cout << mp[i] << std::endl;
    }
  }

  return 0;
}

