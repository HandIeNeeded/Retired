/*************************************************************************
  >         File: B.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Fri Dec 30 23:22:23 2016
*************************************************************************/
#include <vector>
#include <cstdio>
#include <bitset>
#include <utility>
#include <cstdlib>
#include <sstream>
#include <fstream>
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

void NO() {
  std::cout << "NO" << std::endl;
  exit(0);
}

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::cin >> n;
  int now = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    std::string s;
    std::cin >> x >> s;
    if (now == 0) {
      if (s[0] != 'S' || now + x > 20000) {
        NO();
      }
      now += x;
    } else if (now == 20000) {
      if (s[0] != 'N' || now - x < 0) {
        NO();
      }
      now -= x;
    } else {
      if (s[0] == 'E' || s[0] == 'W') continue;
      if (s[0] == 'S') {
        if (now + x > 20000) NO();
        now += x;
      }
      if (s[0] == 'N') {
        if (now - x < 0) {
          NO();
        }
        now -= x;
      }
    }
  }
  if (now != 0) NO();
  std::cout << "YES" << std::endl;
  return 0;
}
