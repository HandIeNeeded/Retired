/*************************************************************************
	> File Name: B.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Tue 17 May 2016 12:53:44 AM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

void update(int &L, int &R, int a, int b) {
  L = max(L, a);
  R = min(R, b);
}

int main() {
  int t, ca = 1;
  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  int L = 1, R = n;
  int l, r;
  l = 1 + c - b;
  r = n + c - b;
  update(L, R, l, r);
  l = 1 + d - a;
  r = n + d - a;
  update(L, R, l, r);
  l = 1 + d + c - a - b;
  r = n + d + c - a - b;
  update(L, R, l, r);

  if (L > R) cout << "0" << endl;
  else {
    cout << (R - L + 1LL) * n << endl;
  }


  return 0;
}



