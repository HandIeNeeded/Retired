/*************************************************************************
  >         File: D.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Tue Jan  3 21:18:52 2017
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

std::map<std::string, std::vector<int>> mp;

bool isGood(const std::string &s) {
  for (int i = 0, j = int(s.size()) - 1; i < j; ++i, --j) {
    if (s[i] != s[j]) return 0;
  }
  return 1;
}

int main() {
  std::ios::sync_with_stdio(0);
  int n, k;
  std::cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    std::string s;
    int x;
    std::cin >> s >> x;
    mp[s].emplace_back(x);
  }
  for(auto &p: mp) {
    std::sort(p.second.begin(), p.second.end());
    std::reverse(p.second.begin(), p.second.end());
  }
  int ans = 0;
  std::set<std::string> cover;
  int mx = 0;
  for(auto &p: mp) {
    if (cover.count(p.first)) continue;
    auto s = p.first;
    if (isGood(s)) {
      int pos = 0;
      for (int i = 0; i + 1 < (int) p.second.size(); i += 2, pos = i) {
        if (p.second[i] + p.second[i + 1] > 0) {
          ans += p.second[i] + p.second[i + 1];
        } else {
          break;
        }
      }
      if (pos < p.second.size() && pos >= 0 && p.second[pos] > 0) mx = std::max(mx, p.second[pos]);
      if (pos > 0 && p.second[pos - 1] < 0) mx = std::max(mx, -p.second[pos - 1]);
    } else {
      auto r = s;
      std::reverse(r.begin(), r.end());
      if (mp.count(r)) {
        for (int i = 0; i < std::min(int(mp[s].size()), int(mp[r].size())); ++i) {
          if (mp[s][i] + mp[r][i] > 0) {
            ans += mp[s][i] + mp[r][i];
          }
        }
        cover.insert(r);
      }
    }
  }
  std::cout << ans + mx << std::endl;

  return 0;
}
