/*************************************************************************
  >         File: sol.cc
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 13 Aug 2016 02:41:04 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    if (n & 1) cout << "No" << endl;
    else if (n == 2) {
      if (s == ")(") cout << "Yes" << endl;
      else cout << "No" << endl;
    }
    else {
      auto x = s.find_first_of(')');
      auto y = s.find_last_of('(');
      if (x == string::npos || y == string::npos) {
        cout << "No" << endl;
        continue;
      }
      swap(s[x], s[y]);
      int now = 0, mi = n + 1;
      for (int i = 0; i < n; i++) {
        if (s[i] == '(') now++;
        else now--;
        mi = min(mi, now);
      }
      if (now != 0 || mi < 0) cout << "No" << endl;
      else cout << "Yes" << endl;
    }
  }

  return 0;
}
