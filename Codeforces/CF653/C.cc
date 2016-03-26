/*************************************************************************
	> File Name: C.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> created Time: Tue 22 Mar 2016 12:54:28 PM CST
*************************************************************************/

#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

const int N = 2e5 + 5;
int a[N], n;

bool check(const std::vector<int>& bad, int pos) {
    std::vector<int> checkIds;
    REP(i, bad.size()) {
        if (bad[i] == n) continue;
        checkIds.push_back(bad[i]);
    }
    if (pos > 1) checkIds.push_back(pos - 1);
    if (pos < n) checkIds.push_back(pos);
    for (auto &x: checkIds) {
        if (x & 1) if (a[x] >= a[x + 1]) return 0;
        if (x & 1 ^ 1) if (a[x] <= a[x + 1]) return 0;
    }
    return 1;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin >> n;
    REP(i, n) std::cin >> a[i + 1];
    std::vector<int> bad;
    REPP(i, 1, n - 1) {
        if (i & 1) {
            if (a[i] >= a[i + 1]) bad.push_back(i), bad.push_back(i + 1);
        }
        else {
            if (a[i] <= a[i + 1]) bad.push_back(i), bad.push_back(i + 1);
        }
    }
    sort(bad.begin(), bad.end());
    bad.resize(std::unique(bad.begin(), bad.end()) - bad.begin());
    if (bad.size() > 9) {
        std::cout << 0 << std::endl;
        return 0;
    }
    std::set<std::pair<int, int>> result;
    REPP(j, 1, n) {
        REP(i, bad.size()) {
            std::swap(a[bad[i]], a[j]);
            if (check(bad, j)) {
                std::pair<int, int> tmp = {bad[i], j};
                if(tmp.first > tmp.second) std::swap(tmp.first, tmp.second);
                result.insert(tmp);
            }
            std::swap(a[bad[i]], a[j]);
        }
    }
    std::cout << result.size() << std::endl;
    
    return 0;
}

