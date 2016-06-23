/*************************************************************************
	> File Name: D.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Sat 11 Jun 2016 11:20:48 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

int main() {
  ios::sync_with_stdio(0);
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
  freopen((file.substr(0, file.find('.')) + ".out").c_str(), "w", stdout);
#endif
  int t, ca = 1;
  cin >> t;
  while (t--) {
    int n, L;
    cin >> n >> L;
    vector<string> strs;
    REP(i, n) {
      string str;
      cin >> str;
      strs.push_back(str);
    }
    string badStr;
    cin >> badStr;
    int bad = 0;
    REP(i, n) if (strs[i] == badStr) {
      bad = 1;
      break;
    }
    if (bad)
      cout << "Case #" << ca++ << ": " << "IMPOSSIBLE" << endl;
    else {
      if (L == 1) {
        cout << "Case #" << ca++ << ": " << "0" << ' ' << "?" << endl;
      }
      else if (L == 2) {
        cout << "Case #" << ca++ << ": " << "0?0?" << ' ' << "1" << endl;
      }
      else {
        string ans;
        REP(i, L) ans += "0?";
        cout << "Case #" << ca++ << ": " << ans << ' ' << string(L - 1, '1') << endl;
      }
    }
  }
  


  return 0;
}


