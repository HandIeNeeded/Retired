/*************************************************************************
	> File Name: E.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> created Time: Sun 07 Feb 2016 01:21:55 PM CST
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

const int N = 1e5 + 5;
int a[N];

int main() {
#ifdef HOME
    string file(__FILE__);
    freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
    ios :: sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        LL z;
        cin >> n >> m >> z;
        //cout << n << ' ' << m << ' ' << z << endl;
        REP(i, n) cin >> a[i];
        a[n] = 0;
        REP(i, n) {
            if (i & 1) {
                a[n] += m - a[n - i - 1];
            }
            else {
                a[n] += a[n - i - 1];
            }
            a[n] %= m;
        }
        z %= 2 * (n + 1);
        if (n % 2 == 0 && z > n) {
            //cout << z << ' ' << n << endl;
            cout << (m - a[z - n - 1]) % m << endl;
        }
        else if (n % 2 == 1 && z > n) {
            cout << a[z - n - 1] << endl;
        }
        else {
            cout << a[z] << endl;
        }
    }
    return 0;
}


