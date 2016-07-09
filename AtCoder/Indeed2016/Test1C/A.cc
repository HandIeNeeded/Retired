/*************************************************************************
	> File Name: A.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Sat 09 Jul 2016 07:02:12 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

string Replace(const string& str, int a, int b) {
  string ans = str;
  REP(i, ans.size()) if (ans[i] == 'a' + a) {
    ans[i] = 'a' + b;
  }
  return ans;
}

int main() {
  string s, r;
  cin >> s >> r;
  REP(i, 26) {
    REP(j, 26) {
      string ts = Replace(s, i, j), tr = Replace(r, i, j);
      if (ts == tr) {
        cout << "Possible" << endl;
        return 0;
      }
    }
  }
  cout << "Impossible" << endl;

  return 0;
}


