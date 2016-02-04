/*************************************************************************
	> File Name: B.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> created Time: Sat 30 Jan 2016 01:38:19 AM CST
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

const int N = 55;
int mp[N][N];
int cnt[N][N], p[N];

int main() {
#ifdef HOME
    string file(__FILE__);
    freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif

    int n;
    cin >> n;
    REPP(i, 1, n) {
        REPP(j, 1, n) {
            int x;
            cin >> x;
            cnt[x][i]++;
        }
    }
    REPP(i, 1, n - 1) {
        REPP(j, 1, n) {
            if (cnt[i][j] == n - i) {
                p[j] = i;
                break;
            }
        }
    }
    REPP(i, 1, n) if (p[i] == 0) {
        //cout << "hehe" << i << endl;
        p[i] = n;
    }
    REPP(i, 1, n) {
        cout << p[i] << ' ';
    }




    return 0;
}

