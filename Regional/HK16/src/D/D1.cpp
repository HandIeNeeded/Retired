#include <bits/stdc++.h>
#define MAXN 51234
#define MAXM 51234
#define BLOCK_NUM 250
#define INF 1e7
#define MAXK 1123456

using namespace std;

int colA[MAXN], colB[MAXN], ans[MAXN];
int colCntA[MAXK], colCntB[MAXK];
int ansNow, LNow, RNow;

struct node {
    int l, r, lab;
} g[MAXN];

int com(node A, node B) {
    return (A.l < B.l)
        || (A.l == B.l && A.r < B.r);
}

int getBlock(int x) {
    return x / BLOCK_NUM;
}

void modify(int col, int delta, int whi) {
    int oldAns = min(colCntA[col], colCntB[col]);
    if (whi) colCntB[col] += delta;
    else colCntA[col] += delta;
    ansNow += min(colCntA[col], colCntB[col]) - oldAns;
}

void handle(int index, int delta) {
    modify(colA[index], delta, 0);
    modify(colB[index], delta, 1);
}

int getAns(int l, int r) {
    if (getBlock(l) != getBlock(LNow)) {
        for (int i = 0; i < MAXK; ++i) {
            colCntA[i] = 0;
            colCntB[i] = 0;
            ansNow = 0;
            LNow = INF;
            RNow = -INF;
        }
    }
    int lim = (getBlock(l) + 1) * BLOCK_NUM;
    for (int i = max(RNow + 1, lim); i <= r; ++i) {
        handle(i, 1);
    }
    for (int i = l; i <= min(r, lim - 1); ++i) {
        handle(i, 1);
    }
    int ansTmp = ansNow;
    LNow = l;
    RNow = r;
    for (int i = l; i <= min(r, lim - 1); ++i) {
        handle(i, -1);
    }
    return ansTmp;
}


int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &colA[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &colB[i]);
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &g[i].l, &g[i].r);
        g[i].lab = i;
    }
    sort(g + 1, g + m + 1, com);
    LNow = INF;
    RNow = -INF;
    ansNow = 0;
    for (int i = 1; i <= m; ++i) {
        ans[g[i].lab] = getAns(g[i].l, g[i].r);
    }
    for (int i = 1; i <= m; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
