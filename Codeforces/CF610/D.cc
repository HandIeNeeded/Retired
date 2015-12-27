/*************************************************************************
	> File Name: D.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sun 27 Dec 2015 08:23:02 PM CST
 ************************************************************************/
#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;
const int N = 1e5 + 5;
vector<tuple<int, int, int>> row, col;
vector<int> pos;

int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    REPP(i, 1, n) {
        int x, y, p, q;
        cin >> x >> y >> p >> q;
        if (x > p || y > q) {
            swap(x, p);
            swap(y, q);
        }
        if (x == p) {
            col.push_back({y, q, x});
            pos.push_back(x);
        }
        else {
            row.push_back({x, p, y});
            pos.push_back(y);
        }
    }
    sort(pos.begin(), pos.end());
    pos.resize(unique(pos.begin(), pos.end()) - pos.begin());


    return 0;
}


