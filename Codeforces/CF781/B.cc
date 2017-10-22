/*************************************************************************
  >         File: B.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sun Mar  5 23:20:32 2017
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

const int N = 2222;
std::string A[N], B[N];
bool vis[N];

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::string a, b;
    std::cin >> a >> b;
    std::string L = a.substr(0, 3), R = a.substr(0, 2) + b[0];
    A[i] = L, B[i] = R;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (A[i] == A[j] && B[i] == B[j]) {
        std::cout << "NO" << std::endl;
        return 0;
      }
      if (A[i] == A[j]) vis[i] = vis[j] = 1;
    }
  }
  std::queue<int> q;
  for (int i = 0; i < n; ++i) if (vis[i]) q.push(i);
  while (q.size()) {
    int x = q.front(); q.pop();
    for (int j = 0; j < n; ++j) if (x != j && !vis[j] && A[j] == B[x]) {
      vis[j] = 1;
      q.push(j);
    }
  }
  for (int i = 0; i < n; ++i) if (vis[i]) {
    for (int j = i + 1; j < n; ++j) if (vis[j] && B[j] == B[i]) {
      std::cout << "NO" << std::endl;
      return 0;
    }
  }

  std::cout << "YES" << std::endl;
  for (int i = 0; i < n; ++i) {
    if (vis[i]) std::cout << B[i] << std::endl;
    else std::cout << A[i] << std::endl;
  }

  return 0;
}
