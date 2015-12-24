/*************************************************************************
	> File Name: B.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Thu 24 Dec 2015 12:44:29 AM CST
 ************************************************************************/
#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 2e5 + 5;
char s[2][N];
int cnt[2][N];

int main() {
    ios::sync_with_stdio(0);
    cin >> s[0] >> s[1];
    int n = strlen(s[0]), m = strlen(s[1]);
    REP(i, m) {
        REP(j, 2) cnt[j][i + 1] = cnt[j][i];
        cnt[s[1][i] - '0'][i + 1]++;
    }
    LL ans = 1LL * n * (m - n + 1);
    for (int i = 1, l = 1, r = m - n + 1; i <= n; i++, l++, r++) {
        //cout << i << ' ' << l << ' ' << r << endl;
        ans -= cnt[s[0][i - 1] - '0'][r] - cnt[s[0][i - 1] - '0'][l - 1];
    }
    cout << ans << endl;

    return 0;
}


