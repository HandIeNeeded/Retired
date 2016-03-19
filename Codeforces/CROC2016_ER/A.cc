/*************************************************************************
	> File Name: A.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> created Time: Sat 19 Mar 2016 12:52:49 AM CST
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

void Erase(string& str) {
    if (str.find('X') != string::npos) str.erase(str.find('X'), 1);
}

int main() {
#ifdef HOME
    string file(__FILE__);
    freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif

    string a, b, c, d;
    cin >> a >> b >> c >> d;
    Erase(a), Erase(b), Erase(c), Erase(d);
    reverse(b.begin(), b.end());
    reverse(d.begin(), d.end());
    a += b, a += a;
    c += d;
    a.find(c) == string::npos ? puts("NO") : puts("YES");

    return 0;
}

