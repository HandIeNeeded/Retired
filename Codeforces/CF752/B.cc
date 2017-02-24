/*************************************************************************
  >         File: B.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Tue Jan  3 19:44:15 2017
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
  std::string a, b;
  std::cin >> a >> b;
  std::map<char, char> set;
  for (int i = 0; i < int(a.size()); ++i) {
    if (a[i] != b[i]) {
      if (a[i] > b[i]) std::swap(a[i], b[i]);
      if (set.count(a[i])) {
        if (set[a[i]] != b[i]) {
          std::cout << -1 << std::endl;
          return 0;
        } 
      } else if (set.count(b[i])) {
        if (set[b[i]] != a[i]) {
          std::cout << -1 << std::endl;
          return 0;
        }
      } else {
        set[a[i]] = b[i];
        set[b[i]] = a[i];
      }
    } else {
      if (set.count(a[i]) && set[a[i]] != a[i]) {
        std::cout << -1 << std::endl;
        return 0;
      }
      set[a[i]] = b[i];
      set[b[i]] = a[i];
    }
  }
  int cnt = 0;
  for(auto &p: set) {
    if (p.first != p.second) cnt++;
  }
  std::cout << cnt / 2 << std::endl;
  for (auto &p: set) {
    if (p.first != p.second && p.first < p.second) {
      std::cout << p.first << ' ' << p.second << std::endl;
    }
  }
  return 0;
}
