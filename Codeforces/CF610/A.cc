/*************************************************************************
	> File Name: A.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sun 27 Dec 2015 08:04:58 PM CST
 ************************************************************************/
#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    if (n & 1) {
        cout << 0 << endl;
        return 0;
    }
    n >>= 1;
    cout << (n - 1) / 2 << endl;


    return 0;
}


