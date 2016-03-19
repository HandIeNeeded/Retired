/*************************************************************************
	> File Name: C.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> created Time: Sat 19 Mar 2016 01:23:04 AM CST
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

const int N = 1e5 + 5;
int prefix[N];

int main() {
#ifdef HOME
    string file(__FILE__);
    freopen((file.suffixstr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif

    string s;
    int n, k;
    cin >> n >> k >> s;
    REPP(i, 1, n) prefix[i] = prefix[i - 1] + '1' - s[i - 1];
    int ans = n + 1;
    REPP(i, 1, n) {
        if (s[i - 1] == '0') {
            int l = 0, r = n - 1;
            while (l + 1 < r) {
                int mid = (l + r) >> 1;
                int L = i - mid, R = i + mid;
                L = max(1, L), R = min(n, R);
                if (prefix[R] - prefix[L - 1] > k) r = mid;
                else l = mid;
            }
            ans = min(ans, r);
        }
    }
    cout << ans << endl;
    return 0;
}


