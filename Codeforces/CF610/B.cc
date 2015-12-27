/*************************************************************************
	> File Name: B.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sun 27 Dec 2015 08:15:12 PM CST
 ************************************************************************/
#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 2e5 + 5;
int a[N];

int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    REPP(i, 1, n) cin >> a[i];
    int ans = *min_element(a + 1, a + n + 1);
    REPP(i, 1, n) a[i] -= ans;
    int pre = 0;
    int L = 0, R = n + 1, res = 0;
    REPP(i, 1, n + 1) {
        if (a[i] == 0) {
            res = max(res, i - 1 - pre);
            pre = i;
        }
    }
    while (a[L + 1]) L++;
    while (a[R - 1]) R--;
    res = max(res, L + n + 1 - R);
    cout << 1LL * n * ans  + res << endl;



    return 0;
}


