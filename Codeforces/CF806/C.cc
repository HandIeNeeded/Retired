/*************************************************************************
  >         File: C.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Mon May  8 01:44:47 2017
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
  int n;
  std::cin >> n;
  using LL = long long;
  constexpr int N = 1e5 + 5;
  static LL a[N];
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  std::multiset<LL> numbers;
  std::multiset<LL> badNumbers;
  for (int i = 0; i < n; ++i) {
    if (a[i] & (a[i] - 1)) {
      badNumbers.emplace(a[i]);
    } else {
      numbers.emplace(a[i]);
    }
  }
  std::vector<int> pairs[N];
  int cnt = 0;
  int add = 0;
  bool bad = 0;
  while (numbers.size() || badNumbers.size()) {
    for (int bit = 0; bit < 60; ++bit) {
      LL now = 1LL << bit;
      if (numbers.count(now)) {
        pairs[cnt].push_back(now);
        numbers.erase(numbers.find(now));
      } else {
        if (*badNumbers.rbegin() > now) {
          bad = 1;
          break;
        } else {
          pairs[cnt++].push_back(*badNumbers.rbegin());
          badNumbers.erase(--badNumbers.end());
        }
      }
    }
    if (bad) break;
  }
  if (bad) {
    std::cout << -1 << std::endl;
  } else {
    
  }


  return 0;
}
