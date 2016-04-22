/*************************************************************************
	> File Name: B2.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sun 10 Apr 2016 02:49:27 AM CST
*************************************************************************/

#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 10;
int dp[1 << N];

void bfs(int n) {
    queue<string> que;
    string str = string(n, '0');
    string::size_type pos = 0;
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0, que.push(str);
    while (que.size()) {
        string str = que.front(); que.pop();
        int x = stoi(str, &pos, 2);
        REP(i, n) {
            string tmp = str;
            reverse(tmp.begin(), tmp.begin() + i + 1);
            REP(j, i + 1) tmp[j] = '0' + '1' - tmp[j];
            int y = stoi(tmp, &pos, 2);
            //cout << y << endl;
            if (dp[y] > dp[x] + 1) {
                dp[y] = dp[x] + 1;
                que.push(tmp);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
#ifdef HOME
    std::string file(__FILE__);
    freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
    freopen((file.substr(0, file.find('.')) + ".out").c_str(), "w", stdout);
#endif
    int t, ca = 1;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << "Case #" << ca++ << ": ";
        bfs(str.size());
        REP(i, str.size()) {
            if (str[i] == '-') str[i] = '1';
            else str[i] = '0';
        }
        string::size_type pos = 0;
        int target = stoi(str, &pos, 2);
        cout << dp[target] << endl;
    }
    return 0;
}

