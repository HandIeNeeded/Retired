/*************************************************************************
	> File Name: D.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Wed 30 Dec 2015 11:48:14 PM CST
 ************************************************************************/
#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 5005;
const int MO = 1e9 + 7;
int a[N], dp[N][N], n;
int diff[N][N];

bool cmp(int i, int j, int c) {
    return a[i + c] > a[j + c];
}

void init() {
    for (int i = n; i >= 1; i--) {
        for (int j = n; j >= 1; j--) {
            if (a[i] == a[j]) {
                diff[i][j] = diff[i + 1][j + 1] + 1;
            }
            else {
                diff[i][j] = 0;
            }
        }
    }
}

void add(int &x, int y) {
    x += y;
    if (x >= MO) x -= MO;
}

char s[N];

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    cin >> s;
    REP(i, n) a[i + 1] = s[i] - '0';
    init();
    //REPP(i, 1, n) {
    //    REPP(j, 1, n) {
    //        cout << diff[i][j] << ' ';
    //    }
    //    cout << endl;
    //}
    dp[0][0] = 1;
    REPP(i, 1, n) dp[0][i] += dp[0][i - 1];
    REPP(i, 1, n) {
        REPP(j, 1, i) {
            int k = i - j;
            if (a[k + 1] == 0) continue;
            add(dp[i][j], dp[k][j - 1]);
            if (k - j < 0) continue;
            if (diff[k + 1][k - j + 1] >= j) continue;
            if (cmp(k + 1, k - j + 1, diff[k + 1][k - j + 1])) {
                add(dp[i][j], dp[k][j]);
                add(dp[i][j], MO - dp[k][j - 1]);
            }
        }
        REPP(j, 1, n) add(dp[i][j], dp[i][j - 1]);
    }
    cout << dp[n][n] << endl;
    //REPP(i, 0, n) {
    //    REPP(j, 0, n) {
    //        cout << dp[i][j] << ' ';
    //    }
    //    cout << endl;
    //}
    return 0;
}


