/*************************************************************************
  >         File: B.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sat Apr 15 10:35:03 2017
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
int N, P;

bool isGood(std::vector<int> p, std::vector<int> need) {
  for (int i = 0; i < N; ++i) {
    int x = need[i];
    int y = p[i];
    int hi = 10 * y / (9 * x) + 5;
    int lo = 10 * y / (11 * x) - 5;
    lo = std::max(0, lo);
    for (int cnt = lo; cnt <= hi; ++cnt) {
      bool good = 1;
      for (int j = 0; j < N; ++j) {
        int x = need[j];
        int y = p[j];
        if (x * cnt * 9L > y * 10L || x * cnt * 11L < y * 10L) {
          good = 0;
        }
      }
      if (good) {
        //std::cerr << "# cnt # is " << cnt << std::endl;
        return 1;
      }
    }
  }
  return 0;
}

int main() {
  std::ios::sync_with_stdio(0);
  int T;
  std::cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    std::cin >> N >> P;
    std::vector<int> need;
    std::vector<std::vector<int> > row(N); 
    for (int i = 0; i < N; ++i) {
      int x;
      std::cin >> x;
      need.push_back(x);
    }
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < P; ++j) {
        int x;
        std::cin >> x;
        row[i].push_back(x);
      }
    }
    int res = 0;
    if (N == 2) {
      std::sort(row[1].begin(), row[1].end());
      do {
        std::vector<std::vector<int> > packages(P); 
        for (int i = 0; i < N; ++i) {
          for (int j = 0; j < P; ++j) {
            packages[j].push_back(row[i][j]);
          }
        }
        int ans = 0;
        for (int i = 0; i < P; ++i) {
          if (isGood(packages[i], need)) ++ans;
        }
        res = std::max(res, ans);
      } while (std::next_permutation(row[1].begin(), row[1].end()));
    } else {
      std::vector<std::vector<int> > packages(P); 
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < P; ++j) {
          packages[j].push_back(row[i][j]);
        }
      }
      int ans = 0;
      for (int i = 0; i < P; ++i) {
        if (isGood(packages[i], need)) ++ans;
      }
      res = std::max(res, ans);
    }
    std::cout << "Case #" << cas << ": " << res << std::endl;
  }

  return 0;
}
