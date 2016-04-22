/*************************************************************************
	> File Name: C.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sat 16 Apr 2016 09:37:09 AM CST
*************************************************************************/

#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 1005;
int a[N];

bool check(const vector<int>& perm) {
    //for (auto &x: perm) {
    //    cout << x << ' ';
    //}
    //cout << endl;
    REP(i, perm.size()) {
        int l = i - 1, r = i + 1;
        if (l < 0) l += perm.size();
        if (r == perm.size()) r = 0;
        if (a[perm[i]] != perm[l] && a[perm[i]] != perm[r]) return 0;
    }
    return 1;
}

int main() {
    int t, ca = 1;
#ifdef HOME
    std::string file(__FILE__);
    freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
    freopen((file.substr(0, file.find('.')) + ".out").c_str(), "w", stdout);
#endif

    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        REPP(i, 1, n) scanf("%d", a + i);
        int ans = 0;
        for (int i = (1 << n) - 1; i > 0; i--) {
            vector<int> perm;
            REP(j, n) if ((i >> j) & 1) {
                perm.push_back(j + 1);
            }
            int find = 0;
            do {
                if (check(perm)) {
                    find = 1;
                    break;
                }
            }while (next_permutation(perm.begin(), perm.end()));
            if (find) {
                ans = max(ans, __builtin_popcount(i));
                continue;
            }
        }
        printf("Case #%d: %d\n", ca++, ans);
    }


    return 0;
}

