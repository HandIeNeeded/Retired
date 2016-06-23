/*************************************************************************
	> File Name: B.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Sat 18 Jun 2016 01:15:27 AM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;
const int N = 1e5 + 5;
int a[N];

int main() {
  int t;
  cin >> t;
  REP(i, t) cin >> a[i];
  sort(a, a + t);
  int now = 1;
  int ans = t + 1;
  REP(i, t) {
    if (a[i] < now) {
      ans--;
      continue;
    }
    now++;
  }
  cout << ans << endl;
  return 0;
}


