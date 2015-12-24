/*************************************************************************
	> File Name: D.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Thu 24 Dec 2015 02:00:44 AM CST
 ************************************************************************/
#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 505;
int a[N], dp[N][N];

int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    REPP(i, 1, n) {
        cin >> a[i];
    }
    REPP(i, 1, n) dp[i][i] = 1;
    REPP(i, 1, n - 1) dp[i][i + 1] = 1 + (a[i] != a[i + 1]);
    REPP(k, 2, n - 1) {
        REPP(i, 1, n) {
            int j = i + k;
            if (j > n) break;
            dp[i][j] = dp[i][j - 1] + 1;
            for (int l = i; l < j - 1; l++) if (a[l] == a[j]) {
                dp[i][j] = min(dp[i][j], dp[i][l - 1] + dp[l + 1][j - 1]);
            }
            if (a[j - 1] == a[j]) {
                dp[i][j] = min(dp[i][j], dp[i][j - 2] + 1);
            }
        }
    }
    //REPP(i, 1, n) {
    //    REPP(j, 1, n) {
    //        cout << dp[i][j] << ' ';
    //    }
    //    cout << endl;
    //}
    cout << dp[1][n] << endl;


    return 0;
}


