/*************************************************************************
	> File Name: B.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sun 29 May 2016 05:25:43 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 105;
int a[N], b[N];

int main() {
  ios::sync_with_stdio(0);
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
  int t, ca = 1;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    REP(i, n) cin >> a[i];
    REP(j, m) cin >> b[j];
    sort(a, a + n), sort(b, b + m);
    string str;
    cin >> str;
    int now = 0;
    int idx = 0;
    int answer = 0;
    REP(i, str.size()) {
      if (str[i] == '-') {
        if (now >= b[idx]) {
          now -= b[idx++];
        }
        else {
          answer++;
        }
      }
      else {
        now += a[--n];
      }
    }
    cout << answer << endl;
  }


  return 0;
}



