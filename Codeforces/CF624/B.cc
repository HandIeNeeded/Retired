/*************************************************************************
	> File Name: B.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> created Time: Fri 05 Feb 2016 01:12:08 AM CST
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

const int N = 30;
int a[N];

int main() {
#ifdef HOME
    string file(__FILE__);
    freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
    int n;
    cin >> n;
    REP(i, n) cin >> a[i];
    sort(a, a + n);
    LL ans = 0;
    a[n] = INT_MAX;
    for (int i = n - 1; i >= 0; i--) {
        a[i] = min(a[i], a[i + 1]);
        ans += a[i];
        if (a[i] && a[i] == a[i + 1]) {
            a[i]--, ans--;
        }
    }
    cout << ans << endl;



    return 0;
}


