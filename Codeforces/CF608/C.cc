/*************************************************************************
	> File Name: C.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Thu 24 Dec 2015 01:08:09 AM CST
 ************************************************************************/
#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;
const int N = 1e5 + 5;
pair<int, int> p[N];
int pos[N], dp[N];

int main() {
    ios::sync_with_stdio(0);
    int n;
    
    cin >> n;
    REPP(i, 1, n) {
        int x, y;
        cin >> x >> y;
        p[i] = {x, y};
    }
    sort(p + 1, p + n + 1);
    REPP(i, 1, n) pos[i] = p[i].first;
    dp[0] = 0;
    REPP(i, 1, n) {
        int now = lower_bound(pos + 1, pos + n + 1, p[i].first - p[i].second) - pos;
        dp[i] = dp[now - 1] + (i - now);
    }
    int ans = dp[n];
    for (int i = n - 1; i >= 1; i--) {
        ans = min(ans, dp[i] + n - i);
    }
    cout << ans << endl;


    return 0;
}


