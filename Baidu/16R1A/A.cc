/*************************************************************************
	> File Name: A.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sat 21 May 2016 09:03:41 PM CST
*************************************************************************/
#include <iostream>
#include <vector>
#include <bitset>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;
const int N = 1e4 + 5;
int MO;

int pmod(int a, LL b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = 1LL * a * ans % MO;
    b >>= 1;
    a = 1LL * a * a % MO;
  }
  return ans;
}

int main() {
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
  ios::sync_with_stdio(0);
  int t, ca = 1;
  cin >> t;
  while (t--) {
    int x, k, c;
    LL m;
    cin >> x >> m >> k >> c;
    MO = 9 * k;
    int answer = (pmod(10, m) + MO - 1) % MO / 9 * x % k;
    cout << "Case #" << ca++ << ":\n" << (answer == c ? "Yes" : "No") << endl;
  }
  return 0;
}



