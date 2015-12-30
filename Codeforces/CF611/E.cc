/*************************************************************************
	> File Name: E.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Thu 31 Dec 2015 12:27:45 AM CST
 ************************************************************************/
#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define LB(x) ((x) & (-(x)))
#define ALL(a) (a).begin(), (a).end()

using namespace std;

const int N = 2e5 + 5;

multiset<int> s;
int a, b, c, n, A, B, C;
int p[N], tot;
vector<int> num;
int cnt[N];

void add(int x, int d = 1) {
    while (x <= tot) {
        cnt[x] += d;
        x += LB(x);
    }
}

int query(int x) {
    int ans = 0;
    while (x) {
        ans += cnt[x];
        x -= LB(x);
    }
    return ans;
}

int calc() {
    int sum = s.size();
    int need = sum - query(b);
    need = max(need, (sum - query(a) + 1) / 2);
    need = max(need, (sum + 2) / 3);
    return need;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> a >> b >> c;
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);
    int ans = 0;
    REPP(i, 1, n) {
        cin >> p[i];
        num.push_back(p[i]);
        if (p[i] > a + b + c) {
            cout << "-1" << endl;
            return 0;
        }
    }
    sort(ALL(num));
    num.resize(unique(ALL(num)) - num.begin());
    tot = num.size();
    REPP(i, 1, n) {
        if (p[i] > b + c) {
            ans++;
            continue;
        }
        p[i] = lower_bound(ALL(num), p[i]) - num.begin() + 1;
        s.insert(p[i]);
        add(p[i]);
    }
    int res = n;
    A = b + c, B = a + c, C = a + b;
    a = upper_bound(ALL(num), a) - num.begin();
    b = upper_bound(ALL(num), b) - num.begin();
    c = upper_bound(ALL(num), c) - num.begin();
    A = upper_bound(ALL(num), A) - num.begin();
    B = upper_bound(ALL(num), B) - num.begin();
    C = upper_bound(ALL(num), C) - num.begin();
    if (!s.size() || c >= *s.rbegin()) {
        res = min(res, ans + calc());
    }
    while (s.size()) {
        ans++;
        int y = *s.rbegin();
        auto it = s.end();
        it--;
        s.erase(it);
        add(y, -1);
        if (s.size()) {
            int left = -1;
            if (C > c) {
                if(B < y) {
                    left = a;
                }
                else if (C < y) {
                    left = b;
                }
                else if (c >= y) {
                    left = C;
                }
                else {
                    left = c;
                }
            }
            else {
                if (B < y) {
                    left = a;
                }
                else if (c < y) {
                    left = b;
                }
                else if (C >= y) {
                    left = c;
                }
                else {
                    left = C;
                }
            }
            auto it = s.upper_bound(left);
            if (it == s.begin()) continue;
            int x = *(--it);
            s.erase(it);
            add(x, -1);
        }
        if (!s.size() || c >= *s.rbegin()) res = min(res, ans + calc());
    }
    res = min(res, ans);
    cout << res << endl;
    return 0;
}


