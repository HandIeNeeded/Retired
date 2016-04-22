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
int a[N], vis[N];
vector<int> b[N];
int pre[N], key[N], head, tail;

void dfs(int x) {
    vis[x] = 1;
    if (vis[a[x]]) {
        pre[a[x]] = x;
        head = x;
        tail = a[x];
        return;
    }
    else {
        pre[a[x]] = x;
        dfs(a[x]);
    }
}

int dfsIn(int x) {
    int ans = 0;
    vis[x] = 1;
    for (auto &y: b[x]) {
        if (key[y]) continue;
        ans = max(ans, dfsIn(y) + 1);
    }
    return ans;
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
        REPP(i, 1, n) a[i] = vis[i] = key[i] = pre[i] = 0;
        REPP(i, 1, n) b[i].clear();
        REPP(i, 1, n) scanf("%d", a + i), b[a[i]].push_back(i);
        int res = 0;
        vector<int> add;
        int mx = 0;
        REPP(i, 1, n) if (!vis[i]) {
            head = tail = -1;
            dfs(i);
            assert(head > 0 && tail > 0);
            int cnt = 1;
            int now = head;
            vector<int> tmp;
            key[tail] = 1;
            while (tail != now) {
                cnt++;
                key[now] = 1;
                now = pre[now];
            }
            now = head;
            tmp.push_back(dfsIn(tail));
            while (tail != now) {
                dfsIn(now);
                now = pre[now];
            }
            if (cnt == 2) {
                res += dfsIn(head) + dfsIn(tail) + 2;
            }
            else {
                mx = max(mx, cnt);
            }
        }
        res = max(mx, res);
        printf("Case #%d: %d\n", ca++, res);
    }
    return 0;
}

