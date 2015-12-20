#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 5;
char mp[N][N];
int turn = 0;

int check() {
    int cnt = 0;
    REP(i, 3) {
        REP(j, 3) if (mp[i][j] == '#') {
            cnt++;
        }
    }
    if ((3 - cnt / 3) & 1) turn ^= 1;
    if (cnt == 9) return 2;
    if (mp[1][1] != '#') return 0;
    if (cnt == 3) return 0;
    return 1;
}

int main() {
#ifdef HOME
    freopen("C.in", "r", stdin);
#endif

    int n;
    cin >> n;
    int ans = 0;
    int a = 0, b = 0;
    REP(i, n) {
        REP(j, 3) scanf("%s", mp[j]);
        int tmp = check();
        ans ^= tmp;
    }
    if (turn) {
        if (ans) puts("Sothe");
        else puts("Snuke");
    }
    else {
        if (ans) puts("Snuke");
        else puts("Sothe");
    }
    

    return 0;
}


