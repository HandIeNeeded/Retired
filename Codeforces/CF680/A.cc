/*************************************************************************
	> File Name: A.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Thu 09 Jun 2016 01:08:27 AM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

int main() {
  int a[5] = {0};
  REP(i, 5) cin >> a[i];
  int sum = 0;
  REP(i, 5) sum += a[i];
  sort(a, a + 5);
  int ans = sum;
  REP(i, 4) {
    if (a[i] == a[i + 1]) {
      ans = min(ans, sum - 2 * a[i]);
    }
  }
  REP(i, 3) {
    if (a[i] == a[i + 2]) {
      ans = min(ans, sum - 3 * a[i]);
    }
  }
  cout << ans << endl;


  return 0;
}


