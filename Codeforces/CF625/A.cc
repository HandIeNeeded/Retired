/*************************************************************************
	> File Name: A.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> created Time: Sun 07 Feb 2016 05:33:52 PM CST
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
    LL a, b, c, n;
    cin >> n >> a >> b >> c;
    LL ans = n / a;
    LL res = 0;
    if (n >= b) {
        res = (n - b) / (b - c) + 1;
        res += (n - res * (b - c)) / a;
    }
    cout << max(ans, res) << endl;



    return 0;
}


