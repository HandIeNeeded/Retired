/*************************************************************************
	> File Name: C.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sun 29 May 2016 07:05:25 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;
const int N = 1e5 + 5;
int a[N];

int main() {
  ios::sync_with_stdio(0);
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
  int t, ca = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int mi = INT_MAX;
    REP(i, n) {
      cin >> a[i];
      mi = min(mi, a[i]);
    }
    int answer = 0;
    for (int i = 1; i * i <= mi; i++) if (mi % i == 0) {
      int gcd = 0;
      REP(j, n) if (a[j] % i) gcd = __gcd(gcd, a[j]);
      if (gcd == 0) gcd = i;
      answer = max(answer, min(gcd, i));
      gcd = 0;
      REP(j, n) if (a[j] % (mi / i)) gcd = __gcd(gcd, a[j]);
      if (gcd == 0) gcd = mi / i;
      answer = max(answer, min(gcd, mi / i));
    }
    cout << answer << endl;
  }

  return 0;
}



