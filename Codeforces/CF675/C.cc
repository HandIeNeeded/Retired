/*************************************************************************
	> File Name: C.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Tue 17 May 2016 12:37:02 AM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 2e5 + 5;
LL prefix[N], a[N];
map<LL, int> mp;

int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  REPP(i, 1, n) cin >> a[i];
  partial_sum(a + 1, a + n + 1, prefix + 1);
  int ans = 0;
  REPP(i, 1, n) {
    mp[prefix[i]]++;
    ans = max(ans, mp[prefix[i]]);
  }
  cout << n - ans << endl;

  return 0;
}



