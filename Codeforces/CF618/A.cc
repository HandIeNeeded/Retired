/*************************************************************************
	> File Name: A.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> created Time: Sat 30 Jan 2016 01:12:36 AM CST
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

void modify(vector<int> &a) {
    if (a.size() < 2) return ;
    for (int i = int(a.size()) - 1; i > 0; i--) {
        int x = a.back(); a.pop_back();
        int y = a.back(); a.pop_back();
        if (x == y) {
            a.push_back(x + 1);
        }
        else {
            a.push_back(y), a.push_back(x);
            break;
        }
    }
}

int main() {
#ifdef HOME
    string file(__FILE__);
    freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif

    int n;
    cin >> n;
    vector<int> num;
    REPP(i, 1, n) {
        num.push_back(1);
        modify(num);
    }
    for (auto &x: num) {
        cout << x << ' ';
    }
    cout << endl;



    return 0;
}

