/*************************************************************************
	> File Name: B.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Thu 30 Jun 2016 01:07:00 AM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  string s;
  cin >> s;
  string r = s;
  reverse(r.begin(), r.end());
  cout << s + r << endl;

  return 0;
}


