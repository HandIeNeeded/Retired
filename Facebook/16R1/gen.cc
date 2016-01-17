/*************************************************************************
	> File Name: gen.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> created Time: Sun 17 Jan 2016 01:47:41 PM CST
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

int main() {
#ifdef HOME
    string file(__FILE__);
    freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif

    int t = 10;
    cout << t << endl;
    while (t--) {
        int n = rand() % 100000 + 1;
        int A = rand() % 1000000000, B = rand() % 1000000000;
        if (A > B) swap(A, B);
        if (A == B) B++;
        cout << n << ' ' << A << ' ' << B << endl;
        REPP(i, 1, n) {
            cout << rand() % 100000000 + 1 << ' ';
        }
        cout << endl;
    }

    return 0;
}


