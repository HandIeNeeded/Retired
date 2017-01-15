/*************************************************************************
  >         File: 1048.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Wed Jan  4 20:30:53 2017
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
  std::vector<int> A[2];
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    int x, y;
    std::cin >> x >> y;
    A[0].emplace_back(x);
    A[1].emplace_back(y);
  }
  int carry = 0;
  std::vector<int> ans;
  for (int i = n - 1; i >= 0; --i) {
    int r = (A[0][i] + A[1][i] + carry);
    carry = r / 10;
    ans.emplace_back(r % 10);
  }
  for (int i = 0; i < int(ans.size()); ++i) {
    std::cout << ans[ans.size() - 1 - i];
  }
  std::cout << std::endl;

  return 0;
}
