/*************************************************************************
  >         File: D.cc
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 13 Aug 2016 08:10:59 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  string s;
  cin >> s;
  if (s.size() == 2) {
    if (s[0] == s[1]) {
      cout << 1 << ' ' << 2 << endl;
    }
    else cout << "-1 -1" << endl;
  }
  else {
    for (int i = 0; i < s.size(); i++) if (i + 2 < s.size()) {
      set<char> sc;
      sc.insert(s[i]);
      sc.insert(s[i + 1]);
      sc.insert(s[i + 2]);
      if (sc.size() <= 2) {
        cout << i + 1  << ' ' << i + 3 << endl;
        return 0;
      }
    }
    cout << "-1 -1" << endl;
  }


  return 0;
}
