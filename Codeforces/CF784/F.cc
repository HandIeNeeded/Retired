/*************************************************************************
  >         File: F.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sat Apr  1 02:07:17 2017
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
//#include <unistd.h>

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::cin >> n;
  std::vector<int> A;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    A.push_back(x);
  }
  //usleep(1000000000);
  std::sort(A.begin(), A.end());
  for (int i = 0; i < n - 1; ++i) {
    std::cout << A[i] << ' ';
  }
  std::cout << A.back() << std::endl;
  return 0;
}
