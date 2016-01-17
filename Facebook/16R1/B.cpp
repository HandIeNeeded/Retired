#include <bits/stdc++.h>
typedef long long LL;

const int N = 1000000 + 5;
int L,n,m,D;
int W[N];

bool solve(LL limit) {
    std::map<LL,int> map;
    for (int left = L; left > 0; ) {
        if (limit < D) return false;
        int tmp = std::min(left,m);
        limit -= D;
        map[limit] = tmp;
        left -= tmp;
    }
    for (int i = 0; i < n && !map.empty(); ++ i) {
        LL now = 0;
        while (true) {
            now += W[i];
            auto it = map.lower_bound(now);
            if (it == map.end()) break;
            it->second --;
            if (it->second == 0) {
                map.erase(it);
            }
        }
    }
    return map.empty();
}

LL work() {
    LL l = 0,r = (LL)2e15;
    while (l <= r) {
        LL mid = l + r >> 1;
        if (solve(mid)) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return r + 1;
}

int main() {
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    int cas,ca = 0;
    scanf("%d",&cas);
    while (cas--) {
        scanf("%d%d%d%d",&L,&n,&m,&D);
        for (int i = 0; i < n; ++ i) {
            scanf("%d",W + i);
        }
        printf("Case #%d: %I64d\n",++ca,work());
    }
}
