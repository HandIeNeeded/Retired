/*************************************************************************
	> File Name: F.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sun 22 May 2016 02:41:05 PM CST
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

const int N = 8005;
int Left[N << 1 | 1];
int a[N], b[N], answer[N];

int Sign(int x) {
  if (x == 0) return 0;
  else if (x > 0) return 1;
  else return -1;
}

int main() {
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
  int n;
  while (scanf("%d", &n) > 0) {
    REPP(i, 1, n) scanf("%d", a + i);
    REPP(i, 1, n) {
      answer[i] = 0;
      REPP(j, 1, n) {
        b[j] = Sign(a[j] - a[i]);
      }
      int now = 0;
      for (int k = i; k >= 1; k--) {
        now += b[k];
        Left[now + N]++;
      }
      now = 0;
      for (int k = i; k <= n; k++) {
        now += b[k];
        answer[i] += Left[-now + N];
      }
      now = 0;
      for (int k = i; k >= 1; k--) {
        now += b[k];
        Left[now + N]--;
      }
      //REP(i, 2 * N + 1) assert(Left[i] == 0);
    }
    REPP(i, 1, n) printf("%d%c", answer[i], " \n"[i == n]);
  }
  return 0;
}



