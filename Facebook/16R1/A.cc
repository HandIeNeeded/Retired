/*************************************************************************
	> File Name: A.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sun 17 Jan 2016 12:19:09 PM CST
 ************************************************************************/

#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;
const int N = 1e5 + 5;
int a[N];

bool good(int x, int y) {
    if (x == y) return 1;
    if (x == y - 1) return a[y] > a[x] && a[y] - a[x] <= 30;
    if (x == y - 2) {
        if (a[x] >= a[x + 1] || a[x + 1] >= a[x + 2]) return 0;
        return (a[x] + 10 >= a[x + 1] && a[x + 1] + 20 >= a[x + 2])
        || (a[x] + 20 >= a[x + 1] && a[x + 1] + 10 >= a[x + 2]);
    }
    if (x == y - 3) {
        if (a[x] >= a[x + 1] || a[x + 1] >= a[x + 2] || a[x + 2] >= a[x + 3]) return 0;
        return a[x] + 10 >= a[x + 1] && a[x + 1] + 10 >= a[x + 2] && a[x + 2] + 10 >= a[x + 3];
    }
    return 0;
}

int main() {
#ifdef HOME
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
#endif
    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        REPP(i, 1, n) scanf("%d", a + i);
        int ans = 0;
        REPP(i, 1, n) {
            int j = min(i + 3, n);
            for (int k = j; k >= i; k--) {
                if (good(i, k)) {
                    ans += 3 - (k - i);
                    i = k;
                    break;
                }
            }
        }
        printf("Case #%d: %d\n", ca++, ans);
    }

    return 0;
}

