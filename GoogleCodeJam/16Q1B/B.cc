/*************************************************************************
  > File Name: B.cc
  > Author: yuzhou627
  > Mail:   yuzhou627@gmail.com
  > Created Time: Sun 01 May 2016 01:08:41 AM CST
 *************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

string toMax(string s) {
  REP(i, s.size()) if (s[i] == '?') s[i] = '9';
  return s;
}

string toMin(string s) {
  REP(i, s.size()) if (s[i] == '?') s[i] = '0';
  return s;
}

string ans1, ans2;
LL ans;

void update(LL diff, const string& a, const string& b) {
  if (abs(diff) < ans) {
    ans = diff;
    ans1 = a, ans2 = b;
  }
  else if (abs(diff) == ans) {
    if (ans1 > a) {
      ans1 = a, ans2 = b;
    }
    else if (ans1 == a) {
      ans2 = min(ans2, b);
    }
  }
}

int main() {
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
  freopen((file.substr(0, file.find('.')) + ".out").c_str(), "w", stdout);
#endif
  ios::sync_with_stdio(0);
  int t, ca = 1;
  cin >> t;
  while (t--) {
    string a, b;
    cin >> a >> b;
    assert(a.size() == b.size());
    int n = a.size();
    ans = LLONG_MAX;
    LL diff = abs(stoll(toMin(a)) - stoll(toMin(b)));
    update(diff, toMin(a), toMin(b));
    for (int i = 0; i < n; i++) {
      char A = a[i], B = b[i];
      REP(x, 10) REP(y, 10) {
        if (A != '?' && A != '0' + x) continue;
        if (B != '?' && B != '0' + y) continue;
        a[i] = '0' + x;
        b[i] = '0' + y;
        //cerr << a << ' ' << b << endl;
        diff = abs(stoll(toMin(a)) - stoll(toMax(b)));
        update(diff, toMin(a), toMax(b));
        diff = abs(stoll(toMax(a)) - stoll(toMin(b)));
        update(diff, toMax(a), toMin(b));
      }
      if (A == '?') {
        if (B == '?') {
          a[i] = b[i] = '0';
        }
        else {
          a[i] = B;
        }
      }
      else {
        if (B == '?') {
          b[i] = A;
        }
        else if (A != B) break;
      }
    }
    cout << "Case #" << ca++ << ": " << ans1 << " " << ans2 << endl;
  }
  return 0;
}



