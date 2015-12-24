/*************************************************************************
	> File Name: A2.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Thu 24 Dec 2015 12:40:08 AM CST
 ************************************************************************/
#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    int ans = 0;
    REPP(i, 1, n) {
        int x, y;
        cin >> x >> y;
        ans = max(ans, x + y);
    }
    ans = max(ans, s);
    cout << ans << endl;


    return 0;
}


