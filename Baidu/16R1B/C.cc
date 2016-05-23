/*************************************************************************
	> File Name: C.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sun 22 May 2016 02:06:22 PM CST
*************************************************************************/

#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <utility>
#include <functional>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <cassert>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 1e5 + 5;
const int MO = 1e9 + 7;

int fac[N], inv[N];

void Init() {
  fac[0] = inv[0] = inv[1] = 1;
  REPP(i, 1, N - 1) fac[i] = 1LL * i * fac[i - 1] % MO;
  REPP(i, 2, N - 1) inv[i] = MO - 1LL * MO / i * inv[MO % i] % MO;
  REPP(i, 2, N - 1) inv[i] = 1LL * inv[i - 1] * inv[i] % MO;
}

int C(int a, int b) {
  if (a < 0 || b < 0 || a < b) return 0;
  return 1LL * fac[a] * inv[b] % MO * inv[a - b] % MO;
}

void add(int &x, int y) {
  x += y;
  if (x >= MO) x -= MO;
}

int main() {
  int t, ca = 1;
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
  Init();
  //REPP(i, 1, 10) {
  //  cout << i << ' ' << fac[i] << ' ' << inv[i] << endl;
  //}
  int n, m;
  while (scanf("%d%d", &n , &m) > 0) {
    n--, m--;
    int k = min(n, m);
    int answer = 0;
    for (int i = 1; i <= k; i++) {
      add(answer, 1LL * C(n - 1, i - 1) * C(m - 1, i - 1) % MO);
    }
    printf("%d\n", answer);
  }


  return 0;
}


