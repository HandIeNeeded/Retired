/*************************************************************************
  >         File: 1005.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Tue Jan  3 15:45:48 2017
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
#include <numeric>

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::vector<int> weights;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    weights.emplace_back(x);
  }
  int sum = std::accumulate(weights.begin(), weights.end(), 0);
  int ans = sum;
  for (int i = 0; i < (1 << n); ++i) {
    int now = 0;
    for (int j = 0; j < n; ++j) {
      if (i & (1 << j)) now += weights[j];
    }
    ans = std::min(ans, std::abs(sum - 2 * now));
  }
  std::cout << ans << std::endl;

  return 0;
}
