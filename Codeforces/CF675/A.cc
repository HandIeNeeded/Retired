/*************************************************************************
	> File Name: A.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Tue 17 May 2016 12:44:41 AM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

int main() {
  int t, ca = 1;
  int a, b, c;
  cin >> a >> b >> c;
  if (c == 0) {
    if (a == b) {
      cout << "YES" << endl;
    }
    else {
      cout << "NO" << endl;
    }
  }
  else if ((b - a) % c) {
    cout << "NO" << endl;
  }
  else {
    if ((b - a) / c >= 0) {
      cout << "YES" << endl;
    }
    else {
      cout << "NO" << endl;
    }
  }
  return 0;
}



