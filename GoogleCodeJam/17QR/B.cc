/*************************************************************************
  >         File: B.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sat Apr  8 16:48:51 2017
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
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  #endif
  int T;
  std::cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    using LL = long long;
    LL number;
    std::cin >> number;
    std::string string = std::to_string(number);
    int L = string.size();
    if (L == 1) {
      std::cout << "Case #" << cas << ": " << number << std::endl;
    } else {
      auto toMax = [] (std::string a, std::string b) {
        if (a.size() != b.size()) return a.size() > b.size() ? a : b;
        return a > b ? a : b;
      };
      auto isGood = [] (std::string a) {
        for (int i = 0; i < (int) a.size() - 1; ++i) {
          if (a[i] > a[i + 1]) return 0;
        }
        return 1;
      };
      std::string answer = std::string(L - 1, '9');
      for (int i = 0; i < L; ++i) {
        if (i > 0 && string[i - 1] > string[i]) break;
        std::string less;
        for (int j = 0; j < i; ++j) less += string[j];
        if (string[i] == '0') continue;
        if (i == 0 && string[i] == '1') continue;
        if (i && string[i] - 1 < string[i - 1]) continue;
        less += string[i] - 1;
        less += std::string(L - i - 1, '9');
        answer = toMax(answer, less);
      }
      if (isGood(string)) answer = toMax(answer, string);
      std::cout << "Case #" << cas << ": " << answer << std::endl;
    }
  }

  return 0;
}

