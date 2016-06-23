/*************************************************************************
	> File Name: A.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Sat 11 Jun 2016 01:58:13 AM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

int get(int x, int bit) {
  if (x < 0) return 0;
  int mask = ~((1 << bit) - 1);
  int ans = (x & mask) >> (bit + 1);
  ans <<= bit;
  if (x & (1 << bit)) {
    ans += (x & (~mask)) + 1;
  }
  return ans;
}

int main() {
  int l, r;
  cin >> l >> r;
  int tot = r - l + 1;
  int ans = 0;
  REP(i, 30) {
    int a = get(r, i), b = get(l - 1, i);
    int c = a - b, d = tot - c;
    if (c > d) {
      ans |= 1 << i;
    }
  }
  cout << ans << endl;

  return 0;
}


