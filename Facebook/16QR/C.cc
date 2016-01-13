/*************************************************************************
	> File Name: C.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sun 10 Jan 2016 01:13:01 AM CST
 ************************************************************************/
#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e5 + 5;
LL prefix[N];

int main() {
#ifdef HOME
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
#endif
    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        int n, p;
        scanf("%d%d", &n, &p);
        REPP(i, 1, n) {
            scanf("%lld", prefix + i);
            prefix[i] += prefix[i - 1];
        }
        LL ans = 0;
        REPP(i, 1, n) {
            int pos = lower_bound(prefix, prefix + i, prefix[i] - p) - prefix;
            ans += i - pos;
        }
        printf("Case #%d: %lld\n", ca++, ans);
    }
    return 0;
}


