/*************************************************************************
	> File Name: D.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> created Time: Fri 05 Feb 2016 02:40:36 AM CST
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

const int N = 1e6 + 5;
int A, B, a[N], n;
bool good[N], need[N];

bool test(int d, int i, int x) {
    if (x % d != 0 && ((x + 1) % d == 0 || (x - 1) % d == 0)) need[i] = 1;
    return x % d == 0 || (x + 1) % d == 0 || (x + d - 1) % d == 0;
}

LL get(int d) {
    LL ans = LLONG_MAX;
    LL prefix[2], L, suffix[2], R;
    REPP(i, 1, n) good[i] = test(d, i, a[i]);
    if (!good[1] && !good[n]) return LLONG_MAX;
    if (A >= B) {
        int posL = 1, posR = n, cntL = 0, cntR = 0;
        LL res = 0;
        while (posL <= n && good[posL]) cntL += need[posL], posL++;
        if (posL > n) return 1LL * cntL * B;
        while (posR >= 1 && good[posR]) cntR += need[posR], posR--;
        if (posR == 0) return 1LL * cntR * B;
        else return 1LL * (posR - posL + 1) * A + 1LL * (cntL + cntR) * B;
    }

    int posL = 1, posR = n;
    

    if (good[1] && !good[n]) {

    }
    else if (good[n] && !good[1]) {

    }
    else {

    }
}

int main() {
#ifdef HOME
    string file(__FILE__);
    freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
    cin >> n >> A >> B;
    REPP(i, 1, n) scanf("%d", a + i);
    vector<int> factor;
    for (int dx = -1; dx <= 1; dx++) {
        int x = a[1] + dx;
        for (int i = 2; i * i <= x; i ++) if (x % i == 0) {
            factor.push_back(i);
            factor.push_back(x / i);
        }
    }
    for (int dx = -1; dx <= 1; dx++) {
        int x = a[n] + dx;
        for (int i = 2; i * i <= x; i ++) if (x % i == 0) {
            factor.push_back(i);
            factor.push_back(x / i);
        }
    }
    sort(factor.begin(), factor.end());
    factor.resize(unique(factor.begin(), factor.end()) - factor.begin());
    LL ans = LLONG_MAX;
    for (auto &x: factor) {
        ans = min(ans, get(x));
    }
    cout << ans << endl;
    return 0;
}


