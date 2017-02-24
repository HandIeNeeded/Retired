/*************************************************************************
  >         File: 1022.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Thu Jan  5 18:52:52 2017
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
const int N = 111;
int in[N], ans[N];
std::vector<int> edges[N];

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    while (std::cin >> x, x) {
      edges[i + 1].push_back(x);
      in[x]++;
    }
  }
  std::queue<int> q;
  int now = 0;
  for (int i = 0; i < n; ++i) if (in[i + 1] == 0) {
    q.push(i + 1);
  }
  while (q.size()) {
    int x = q.front(); q.pop();
    ans[now++] = x;
    for (auto &y: edges[x]) {
      in[y]--;
      if (in[y] == 0) q.push(y);
    }
  }
  for (int i = 0; i < n; ++i) {
    std::cout << ans[i] << " \n"[i == n - 1];
  }
  return 0;
}
