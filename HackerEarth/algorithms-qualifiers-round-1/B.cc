/*************************************************************************
	> File Name: B.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Mon 04 Jan 2016 12:30:21 AM CST
 ************************************************************************/
#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int n, k;
    cin >> k >> n;
    int res = 300000;
    REPP(i, 1, 300000) {
        int ans = abs(n - i) + min(k % i, i - k % i);
        res = min(res, ans);
    }
    cout << res << endl;


    return 0;
}


