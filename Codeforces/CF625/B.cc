/*************************************************************************
	> File Name: B.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> created Time: Sun 07 Feb 2016 05:26:26 PM CST
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
const int N = 1e5 + 5;
int dp[N];

int main() {
#ifdef HOME
    string file(__FILE__);
    freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif

    string s, r;
    cin >> s >> r;
    int n = s.size();
    REPP(i, 1, n) {
        if (i < r.size()) {
            dp[i] = 0;
            continue;
        }
        dp[i] = dp[i - 1];
        int a = r.size() - 1, b = i - 1;
        while (a >= 0 && s[b] == r[a]) a--, b--;
        if (a < 0) {
            dp[i] = INT_MAX;
            for (int a = i, b = r.size() - 1; b >= 0; a--, b--) {
                dp[i] = min(dp[i], dp[a - 1] + 1);
            }
        }
    }
    cout << dp[n] << endl;




    return 0;
}


