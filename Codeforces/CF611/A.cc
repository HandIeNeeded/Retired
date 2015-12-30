/*************************************************************************
	> File Name: A.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Wed 30 Dec 2015 11:06:18 PM CST
 ************************************************************************/
#include <bits/stdc++.h>

#define LL long long1300
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    char s[10];
    int n;
    scanf("%d of %s", &n, s);
    if (s[0] == 'w') {
        int ans = 0;
        for (int i = 0, j = 5; i < 366; i++, j++) {
            if (j % 7 == n % 7) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    else {
        if (n <= 29) {
            cout << 12 << endl;
        }
        else if (n == 30) {
            cout << 11 << endl;
        }
        else {
            cout << 7 << endl;
        }
    }

    return 0;
}


