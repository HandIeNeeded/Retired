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

int main() {
  std::ios::sync_with_stdio(0);
  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    using LL = long long;
    LL ans = 1;
    int K = 1;
    int a, n, p;
    std::cin >> a >> n >> p;
    for (int i = 1; i <= n; ++i) K *= i;
    for (int i = 1; i <= K; ++i) {
      ans = 1LL * ans * a % p;
    }
    std::cout << "Case #" << i + 1 << ": " << ans << std::endl;
  }


  return 0;
}
