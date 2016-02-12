/*************************************************************************
	> File Name: C.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> created Time: Sun 07 Feb 2016 05:14:12 PM CST
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
const int N = 505;
int mp[N][N];

int main() {
#ifdef HOME
    string file(__FILE__);
    freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif

    int n, k;
    cin >> n >> k;
    int now = n * n, st = 1;
    REPP(i, 1, n) {
        for (int j = n; j >= k; j--) {
            mp[i][j] = now--;
        }
        for (int j = 1; j < k; j++) {
            mp[i][j] = st++;
        }
    }
    int sum = 0;
    REPP(i, 1, n) sum += mp[i][k];
    cout << sum << endl;
    REPP(i, 1, n) {
        REPP(j, 1, n) {
            cout << mp[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}


