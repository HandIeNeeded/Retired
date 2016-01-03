/*************************************************************************
	> File Name: C.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Mon 04 Jan 2016 12:39:32 AM CST
 ************************************************************************/
#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e5 + 5;
LL prefix[N], suffix[N];
int a[N];

int main() {
#ifdef HOME
    freopen("C.in", "r", stdin);
#endif

    int n, c;
    scanf("%d%d", &n, &c);
    REPP(i, 1, n) scanf("%d", a + i);
    sort(a + 1, a + n + 1);
    REPP(i, 1, n / 2) a[i] -= c;
    REPP(i, n / 2 + 1, n) a[i] += c;
    REPP(i, 1, n) prefix[i] = prefix[i - 1] + a[i];
    for (int i = n; i >= 1; i--) suffix[i] = suffix[i + 1] + a[i];
    LL ans = 0;
    for (int i = 1, a = 0, b = n - 1; i <= n; i++, a++, b--) {
        ans += 1LL * a * ::a[i] - prefix[i - 1] + suffix[i + 1] - 1LL * b * ::a[i];
    }
    cout << ans / 2 << endl;

    return 0;
}


