/*************************************************************************
	> File Name: E.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Sat 04 Jun 2016 10:26:45 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 1e6 + 6;
int a[N];

int main() {
  ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  REP(i, n) cin >> a[i];
  sort(a, a + n);

  return 0;
}


