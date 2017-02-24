/*************************************************************************
  >         File: 1002.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Tue Jan  3 06:45:51 2017
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

#define REP(i, a) for (int i = 0; i < int(a); ++i)

const int N = 111;

int dp[N];
std::string pre[N];
std::map<std::string, std::string> mp;

int get(char c) {
  if (c == 'i' || c == 'j') return 1;
  if (c >= 'a' && c <= 'c') return 2;
  if (c >= 'd' && c <= 'f') return 3;
  if (c == 'g' || c == 'h') return 4;
  if (c == 'k' || c == 'l') return 5;
  if (c == 'm' || c == 'n') return 6;
  if (c == 'p' || c == 'r' || c == 's') return 7;
  if (c >= 't' && c <= 'v') return 8;
  if (c >= 'w' && c <= 'y') return 9;
  if (c == 'o' || c == 'q' || c == 'z') return 0;
  return -1;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::string string;
  while (std::cin >> string) {
    if (string == "-1") break;
    mp.clear();
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
      std::string str, newStr;
      std::cin >> str;
      for (int i = 0; i < int(str.size()); ++i) newStr += get(str[i]) + '0';
      mp[newStr] = str;
    }
    dp[0] = 0;
    for (int i = 0; i < int(string.size()); ++i) {
      dp[i + 1] = 111;
      for (int j = 1; j <= 50; ++j) {
        if (i + 1 < j) break;
        if (dp[i + 1 - j] == 111) continue;
        std::string suffix = string.substr(i + 1 - j, j);
        if (!mp.count(suffix)) continue;
        if (dp[i + 1] > dp[i + 1 - j] + 1) {
          dp[i + 1] = dp[i + 1 - j] + 1;
          pre[i + 1] = mp[suffix];
        }
      }
    }
    if (dp[int(string.size())] == 111) {
      std::cout << "No solution." << std::endl;
    } else {
      std::vector<std::string> ans;
      int now = int(string.size());
      while (now) {
        ans.push_back(pre[now]);
        now -= ans.back().size();
      }
      for (int i = int(ans.size()) - 1; i > 0; --i) {
        std::cout << ans[i] << ' ';
      }
      std::cout << ans[0] << std::endl;
    }
  }

  return 0;
}
