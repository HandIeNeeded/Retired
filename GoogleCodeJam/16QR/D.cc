/*************************************************************************
	> File Name: D.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sun 10 Apr 2016 01:20:20 AM CST
*************************************************************************/

#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0);
#ifdef HOME
    std::string file(__FILE__);
    freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
    freopen((file.substr(0, file.find('.')) + ".out").c_str(), "w", stdout);
#endif

    int t, ca = 1;
    cin >> t;
    while (t--) {
        int k, c, s;
        cin >> k >> c >> s;
        assert(k == s);
        LL pw[111] = {1};
        REPP(i, 1, c) pw[i] = pw[i - 1] * k;
        cout << "Case #" << ca++ << ":";
        if (k == 1) {
            cout << ' ' << 1 << endl;
            continue;
        }
        REP(i, s) {
            cout << ' ' << (pw[c] - 1) / (k - 1) * i + 1;
        }
        cout << endl;
    }
    return 0;
}

