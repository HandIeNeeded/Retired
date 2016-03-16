/*************************************************************************
	> File Name: B.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> created Time: Thu 17 Mar 2016 01:09:35 AM CST
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define next hehe
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

const int N = 2e5 + 5;
int T[N], D[N];

int main() {
#ifdef HOME
    string file(__FILE__);
    freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
    ios::sync_with_stdio(0);
    int n, B;
    LL now = 0;
    cin >> n >> B;
    REPP(i, 1, n) cin >> T[i] >> D[i];
    queue<tuple<int, int, int>> que;
    int index = 1, count = 0;
    while (que.empty() && index <= n) {
        now = max(now, 1LL * T[index]);
        now = now + D[index];
        cout << now << ' ';
        int next = index + 1;
        while (next <= n && T[next] < now) {
            que.push(make_tuple(T[next], D[next], count < B));
            if (count < B) count++;
            next++;
        }
        index = next;

        while (que.size()) {
            int a, b, c;
            tie(a, b, c) = que.front();
            que.pop();
            if (!c) {
                cout << -1 << ' ';
            }
            else {
                count--;
                now = max(now, 1LL * a);
                now = now + b;
                cout << now << ' ';
                int next = index;
                while (next <= n && T[next] < now) {
                    que.push(make_tuple(T[next], D[next], count < B));
                    if (count < B) count++;
                    next++;
                }
                index = next;
            }
        }

    }

    return 0;
}


