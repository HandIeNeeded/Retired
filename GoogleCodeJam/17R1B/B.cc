/*************************************************************************
  >         File: B.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sun Apr 23 01:24:39 2017
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

bool test(int* a) {
  std::sort(a, a + 3);
  if (a[2] > a[0] + a[1]) return 0;
  return 1;
}

int main() {
  std::ios::sync_with_stdio(0);
  int T;
  std::cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    int n;
    int a[6];
    std::cin >> n;
    std::string ans;
    for (int i = 0; i < 6; ++i) std::cin >> a[i];
    std::swap(a[1], a[4]);
    // now red bule yellow green orange violet
    static const std::string CHAR = "RBYGOV";
    bool bad = 0;
    for (int i = 0; i < 3; ++i) if (a[i + 3] > a[i]) bad = 1;
    std::cout << "Case #" << cas << ": ";
    bool find = 0;
    for (int i = 0; i < 3; ++i) {
      if (a[i] == a[i + 3] && a[i]) {
        if (std::accumulate(a, a + 6, 0) - a[i] - a[i + 3]) bad = 1;
        else {
          for (int j = 0; j < a[i]; ++j) {
            ans += CHAR[i];
            ans += CHAR[i + 3];
          }
          std::cout << ans << std::endl;
          find = 1;
        }
      }
    }
    if (find) continue;
    if (bad) {
      std::cout << "IMPOSSIBLE" << std::endl;
      continue;
    }
    int b[3];
    for (int i = 0; i < 3; ++i) {
      b[i] = a[i] - a[i + 3];
    }
    if (!test(b)) bad = 1;
    if (bad) {
      std::cout << "IMPOSSIBLE" << std::endl;
    } else {
      std::vector<std::string> strings[3];
      std::string A[3];
      for (int i = 0; i < 3; ++i) if (a[i]) {
        for (int j = 0; j < a[i + 3]; ++j) {
          A[i] += CHAR[i];
          A[i] += CHAR[i + 3];
        }
        A[i] += CHAR[i];
        strings[i].push_back(A[i]);
        for (int j = 0; j < a[i] - a[i + 3] - 1; ++j) {
          strings[i].push_back(std::string(1, CHAR[i]));
        }
      }
      int sum = strings[0].size() + strings[1].size() + strings[2].size();
      int tmp[3];
      for (int i = 0; i < 3; ++i) tmp[i] = i;
      std::sort(tmp, tmp + 3, [strings] (int a, int b) {return strings[a].size() > strings[b].size();});
      int now = 0;
      std::vector<std::string> res(sum);
      for (int i = 0; i < 3; ++i) {
        int ii = tmp[i];
        for (int j = 0; j < strings[ii].size(); ++j) {
          res[now] = strings[ii][j];
          now += 2;
          if (now >= sum) now = 1;
        }
      }
      for (int i = 0; i < sum; ++i) {
        ans += res[i];
      }
      assert(ans.size() == n);
      for (int i = 0; i < n; ++i) {
        assert(ans[i] != (ans[(i + 1) % n]));
      }
      std::cout << ans << std::endl;
    }
  }

  return 0;
}
