/*************************************************************************
	> File Name: A.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> created Time: Fri 05 Feb 2016 01:06:47 AM CST
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
    int d, L, a, b;
    cin >> d >> L >> a >> b;
    L -= d;
    cout << fixed << setprecision(10) << 1.0 * L / (a + b) << endl;

    return 0;
}

