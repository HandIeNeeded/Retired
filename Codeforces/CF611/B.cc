/*************************************************************************
	> File Name: B.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Wed 30 Dec 2015 11:12:55 PM CST
 ************************************************************************/
#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    LL a, b;
    cin >> a >> b;
    set<LL> ans;
    REPP(i, 1, 63) {
        LL x = (1LL << i) - 1;
        //cout << i << ' ' << x << endl;
        REP(j, i - 1) {
            LL y = x - (1LL << j);
            if (y >= a && y <= b) {
                ans.insert(y);
            }
        }
    }
    cout << ans.size() << endl;


    return 0;
}


