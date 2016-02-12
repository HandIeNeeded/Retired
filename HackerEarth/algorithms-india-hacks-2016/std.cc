#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

const int N = 2e5 + 5;
int a[N];

int main() {
#ifdef HOME
    string file(__FILE__);
    freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        LL z;
        cin >> n >> m >> z;
        REP(i, n) {
            cin >> a[i];
        }
        REPP(i, n, 10000) {
            a[i] = 0;
            for (int j = 1; j <= n; j++) {
                if (j & 1) {
                    a[i] += a[i - j];
                }
                else {
                    a[i] += m - a[i - j];
                }
                a[i] %= m;
            }
        }
        cout << n << ' ' << m << ' ' << z << endl;
        REP(i, 40) {
            cout << i << ' ' << a[i] << endl;
        }
        cout << endl;
        cout << a[z] << endl;
    }

    return 0;
}

