/*************************************************************************
	> File Name: B.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Fri 15 Jan 2016 01:02:34 AM CST
 ************************************************************************/
#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e5 + 5;
LL a[N], b[N];
LL suffix[N], prefix[N];
int tmp[N];

bool cmp(int i , int j) {
    return a[i] < a[j];
}

int main() {
    ios::sync_with_stdio(0);
    LL n, A, f, m, B;
    cin >> n >> A >> f >> m >> B;
    REPP(i, 1, n) {
        cin >> a[i];
        b[i] = a[i];
    }
    REPP(i, 1, n) tmp[i] = i;
    sort(tmp + 1, tmp + n + 1, cmp);
    sort(a + 1, a + n + 1);
    suffix[n + 1] = 0;
    REPP(i, 1, n) {
        prefix[i] = prefix[i - 1] + a[i];
    }
    for (int i = n ; i >= 1; i--) {
        suffix[i] = suffix[i + 1] + A - a[i];
    }
    LL ans = -1;
    int best = 0;
    LL mi = 0;
    LL pre = B;
    for (int i = 0, j = n + 1; i <= n; i++, j--) {
        B = pre - suffix[j];
        a[j] = A;
        if (B <= 0) break;
        LL res = i * f;
        LL lo = a[1], hi = min(A + 1, B + a[n] + 1);
        while (lo + 1 < hi) {
            LL mid = (lo + hi) >> 1;
            int pos = upper_bound(a + 1, a + j, mid) - a - 1;
            if (pos * mid - prefix[pos] <= B) lo = mid;
            else hi = mid;
        }
        if (i == n) {
            res += A * m;
        }
        else {
            res += lo * m;
        }
        if (res > ans) {
            ans = res;
            best = i;
            mi = lo;
        }
    }
    for (int i = n, j = 0; j < best; j++, i--) {
        b[tmp[i]] = A;
    }
    for (int i = 1; i <= n - best; i++) {
        if (b[tmp[i]] < mi) {
            b[tmp[i]] = mi;
        }
    }
    
    cout << ans << endl;
    REPP(i, 1, n) {
        cout << b[i] << ' ';
    }


    return 0;
}


