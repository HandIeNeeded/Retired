/*************************************************************************
  >         File: A.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sat Apr  8 21:37:31 2017
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

constexpr int N = 60;

int cnt[N][N];
int need[N];

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::string s;
    std::cin >> s;
    for (int c = 0; c < 26; ++c) {
      cnt[i][c] = std::count(s.begin(), s.end(), 'a' + c);
    }
  }
  std::string ans;
  for (int c = 0; c < 26; ++c) {
    need[c] = 55;
    for (int i = 0; i < n; ++i) {
      need[c] = std::min(need[c], cnt[i][c]);
    }
    ans += std::string(need[c], 'a' + c);
  }
  std::cout << ans << std::endl;
  


  return 0;
}
