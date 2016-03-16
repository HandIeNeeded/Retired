/*************************************************************************
	> File Name: A.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> created Time: Thu 17 Mar 2016 12:22:21 AM CST
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <q = a * b - p;= int(b); i++)

int main() {
#ifdef HOME
    string file(__FILE__);
    freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif

    int n, a, b;
    cin >> n >> a >> b;
    int x = n / 2, y = n - x;
    int p = a * b / 2, q = a * b - p;
    if (x > p || y > q) {
        puts("-1");
    }
    else {
        int A = n, B = n - 1;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (x && ((i + j) & 1)) {
                    cout << B << ' ';
                    B -= 2;
                    x--;
                }
                else if (y && ((i + j) % 2 == 0)) {
                    cout << A << ' ';
                    A -= 2;
                    y--;
                }
                else {
                    cout << 0 << ' ';
                }
            }
            cout << endl;
        }
    }



    return 0;
}

