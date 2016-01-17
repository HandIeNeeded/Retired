/*************************************************************************
	> File Name: C.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> created Time: Sun 17 Jan 2016 01:57:33 PM CST
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

const int N = 1e5 + 5;
int a[N], n;
LL sum;
double res;

double get(int x) {
    int tot = x;
    double ans = 0;
    LL k = x / sum;
    x %= sum;
    ans = res * k * sum / tot;
    REPP(i, 1, n) {
        if (x >= a[i]) {
            ans += 1.0 * a[i] / 2 * a[i] / tot;
            x -= a[i];
        }
        else break;
    }
    ans += 1.0 * x / 2 * x / tot;
    return ans;
}

int main() {
#ifdef HOME
    string file(__FILE__);
    freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
    freopen((file.substr(0, file.find('.')) + ".out").c_str(), "w", stdout);
#endif

    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        int a, b;
        scanf("%d%d%d", &n, &a, &b);
        REPP(i, 1, n) scanf("%d", ::a + i);
        sum = 0;
        REPP(i, 1, n) sum += ::a[i];
        res = 0.0;
        REPP(i, 1, n) {
            res += 1.0 * ::a[i] / 2.0 * ::a[i] / sum;
        }
        if (a == 0) {
            printf("Case #%d: %.10f\n", ca++, get(b));
            continue;
        }
        double A = get(a), B = get(b);
        double ans = (B * b - A * a) / (b - a);
        printf("Case #%d: %.10f\n", ca++, ans);
    }

    return 0;
}


