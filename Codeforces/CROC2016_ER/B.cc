/*************************************************************************
	> File Name: B.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> created Time: Sat 19 Mar 2016 01:16:51 AM CST
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

int main() {
#ifdef HOME
    string file(__FILE__);
    freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
    int n, k;
    cin >> n >> k;
    if (n >= 2 * k) {
        cout << 2LL * k * n - 2LL * k * k - k << endl;
    }
    else {
        cout << 1LL * n * (n - 1) / 2 << endl;
    }
    return 0;
}


