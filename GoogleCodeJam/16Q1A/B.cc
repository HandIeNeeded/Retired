/*************************************************************************
	> File Name: B.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sat 16 Apr 2016 09:22:28 AM CST
*************************************************************************/

#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 55;
int cnt[N * N];

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
        memset(cnt, 0, sizeof(cnt));
        REPP(i, 1, 2 * n - 1) {
            REPP(j, 1, n) {
                int x;
                scanf("%d", &x);
                cnt[x]++;
            }
        }
        vector<int> num;
        REP(i, 2501) if (cnt[i] & 1) num.push_back(i);
        assert(int(num.size()) == n);
        printf("Case #%d:", ca++);
        for (auto &x: num) {
            printf(" %d", x);
        }
        puts("");
    }

    return 0;
}

