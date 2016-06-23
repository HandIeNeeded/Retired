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
      //if (L == 1) {
      //  cout << "Case #" << ca++ << ": " << char('0' + '1' - badStr[0]) << ' ' << "?" << endl;
      //}
      //else if (L == 2) {
      //  cout << "Case #" << ca++ << ": " << "0?0?" << ' ' << "1" << endl;
      //}
      //else {
      //string ans;
      //REP(i, L) ans += "0?";
      //cout << "Case #" << ca++ << ": " << ans << ' ' << string(L - 1, '1') << endl;
      //}
      
      cout << "Case #" << ca++ << ": ";
      if (L == 1) {
        if (badStr == "0") {
          cout << "1" << ' ' << "1?" << endl;
        }
        else {
          cout << "0" << ' ' << "0?" << endl;
        }
        continue;
      }
      string ans = badStr;
      for (int i = 0; i < ans.size() - 1; i++) {
        if (ans[i] == ans[i + 1]) {
          ans = badStr.substr(0, i) + badStr.substr(i + 1);
          break;
        }
      }
      //find duplicated char
      if (ans.size() != badStr.size()) {
        string res;
        REP(i, badStr.size()) {
          res += char('0' + '1' - badStr[i]);
          res += '?';
        }
        cout << ans << ' ' << res << endl;
      }
      //no duplicated
      else {
        ans = ans.substr(0, ans.size() - 1);
        string res;
        if (ans[0] == '0') {
          res += '1';
          REP(i, L) res += '?';
        }
        else {
          res += '0';
          REP(i, L) res += '?';
        }
        cout << ans << ' ' << res << endl;
      }
    }
  }

  return 0;
}


