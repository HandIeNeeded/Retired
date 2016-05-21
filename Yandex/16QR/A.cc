/*************************************************************************
	> File Name: A.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sat 21 May 2016 10:39:42 AM CST
*************************************************************************/

#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 1005;
string str[N];

bool Check(const string& a, const string& b) {
  int cnt = 0;
  REP(i, a.size()) if (a[i] != b[i]) {
    cnt++;
    if (cnt > 1) return 0;
  }
  return 1;
}

int main() {
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  REP(i, n) cin >> str[i];
  string answer;
  REP(i, n) {
    int valid = 0;
    REP(j, n) if (j != i) {
      if (Check(str[i], str[j])) valid++;
    }
    if (valid == n - 1) {
      answer = str[i];
      break;
    }
  }
  cout << answer << endl;
  return 0;
}


