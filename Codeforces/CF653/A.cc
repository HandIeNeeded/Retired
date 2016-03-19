/*************************************************************************
	> File Name: A.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> created Time: Sat 19 Mar 2016 04:42:05 PM CST
*************************************************************************/

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
    int n;
    cin >> n;
    int a[1001] = {0};
    REP(i, n) {
        int x;
        cin >> x;
        a[x]++;
    }
    REPP(i, 1, 998) if (a[i] && a[i + 1] && a[i + 2]) {
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;

    return 0;
}

