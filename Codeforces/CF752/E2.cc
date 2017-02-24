/*************************************************************************
  >         File: E2.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Tue Jan  3 22:15:28 2017
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

const int K = 1e7 + 5;
using LL = long long;
LL cnt[K], a[K];

int main() {
  std::ios::sync_with_stdio(0);
  int n, k;
  std::cin >> n >> k;
  for (int i = 0; i < n; ++i) std::cin >> a[i], cnt[a[i]]++;
  LL sum = std::accumulate(a, a + n, 0LL);
  if (sum < k) {
    std::cout << -1 << std::endl;
    return 0;
  } 
  LL now = 0, count = n;
  for(int i = K - 1; i > now && i > 1; --i) {
    cnt[i / 2] += cnt[i], cnt[i - i / 2] += cnt[i];
    count -= cnt[i];
    if (i / 2 >= now) count += cnt[i];
    if (i / 2 + 1 >= now) count += cnt[i];
    while (count - cnt[now] >= k) {
      count -= cnt[now++];
    }
  }
  std::cout << now << std::endl;

  return 0;
}
