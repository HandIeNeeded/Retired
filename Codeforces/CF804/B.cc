/*************************************************************************
  >         File: B.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Thu May  4 09:58:54 2017
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

constexpr int MO = 1e9 + 7;
constexpr int N = 1e6 + 6;

int cnt[N], next[N], delta[N];

void Add(int &x, int y) {
  x += y;
  if (x >= MO) x -= MO;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::string s;
  std::cin >> s;
  int n = s.size();
  int ans = 0;
  int now = 0;
  int pre = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == 'a') cnt[i] = now, delta[i] = now - pre, pre = cnt[i];
    else ++now;
  }
  int sum = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == 'a') {
      Add(sum, sum);
      Add(sum, delta[i]);
      Add(ans, sum);
    }
  }
  std::cout << ans << std::endl;

  return 0;
}
