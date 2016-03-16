/*************************************************************************
	> File Name: C.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> created Time: Thu 17 Mar 2016 12:45:28 AM CST
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

map<string, vector<string>> A;
map<vector<string>, vector<string>> B;

pair<string, string> split(const string& s) {
    string a, b;
    auto pos = s.find(':') + 3;
    auto pos2 = s.find('/', pos);
    if (pos2 == string::npos) return {s, ""};
    else return {s.substr(0, pos2), s.substr(pos2)};
}

int main() {
#ifdef HOME
    string file(__FILE__);
    freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif

    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string a, b, c;
        cin >> c;
        tie(a, b) = split(c);
        A[a].push_back(b);
    }
    for (auto &p: A) {
        auto& v = p.second;
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());
        B[v].push_back(p.first);
    }
    int count = 0;
    for (auto &p: B) {
        auto& v = p.second;
        if (int(v.size()) > 1) {
            count++;
        }
    }
    cout << count << endl;
    for (auto &p: B) {
        auto& v = p.second;
        if (int(v.size()) > 1) {
            for (auto &s: v) {
                cout << s << ' ';
            }
            cout << endl;
        }
    }

    return 0;
}


