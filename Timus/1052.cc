/*************************************************************************
  >         File: 1052.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Thu Jan 19 21:54:02 2017
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

int det(std::pair<int, int> &a, std::pair<int, int> &b) {
  return a.first * b.second - a.second * b.first;
}

std::pair<int, int> operator - (const std::pair<int, int> &a, const std::pair<int, int> &b) {
  return {a.first - b.first, a.second - b.second};
}

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> points;
  for (int i = 0; i < n; ++i) {
    int x, y;
    std::cin >> x >> y;
    points.push_back({x, y});
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (points[i] == points[j]) continue;
      int cnt = 0;
      std::pair<int, int> direct = points[i] - points[j];
      for (int k = 0; k < n; ++k) {
        if (k != i && k != j) {
          std::pair<int, int> now = points[k] - points[i];
          if (det(now, direct) == 0) cnt++;
        }
      }
      if (cnt > ans) {
        ans = cnt;
      }
    }
  }
  std::cout << ans + 2 << std::endl;
  return 0;
}

