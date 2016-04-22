/*************************************************************************
	> File Name: k-element-sequences.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Fri 15 Apr 2016 11:47:53 PM CST
*************************************************************************/

#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 2e6 + 6;
const int MO = 1e9 + 7;
int fac[N], inv[N];

void Init() {
    fac[0] = inv[0] = inv[1] = 1;
    REPP(i, 1, N - 1) fac[i] = 1LL * fac[i - 1] * i % MO;
    REPP(i, 2, N - 1) inv[i] = MO - 1LL * MO / i * inv[MO % i] % MO;
    REPP(i, 2, N - 1) inv[i] = 1LL * inv[i] * inv[i - 1] % MO;
}

int C(int a, int b) {
    if (a < 0 || b < 0 || a < b) return 0;
    return 1LL * fac[a] * inv[b] % MO * inv[a - b] % MO;
}

int main() {
    ios::sync_with_stdio(0);
    Init();
    int t;
    cin >> t;
    while (t--) {
        int k, n;
        cin >> n >> k;
        cout << C(n - 1, k - 1) << endl;
    }
    return 0;
}

