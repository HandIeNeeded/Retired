/*************************************************************************
	> File Name: C.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Fri 15 Jan 2016 01:40:55 AM CST
 ************************************************************************/
#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e5 + 5;
int cnt[N];
char s[N];

int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int sum  =0;
    REP(i, n) cin >> cnt[i], sum += cnt[i];
    int count = 0;
    REP(i, n) if (cnt[i] & 1) {
        count++;
    }
    if (n == 1) {
        cout << cnt[0] << endl;
        REP(i, cnt[0]) {
            cout << 'a';
        }
        cout << endl;
    }
    else if (count == 0) {
        if (n == 2 && cnt[0] == cnt[1]) {
            cout << sum / 2 << endl;
            int now = 0;
            REP(i, sum / 2) {
                REP(j, 2) {
                    s[now++] = 'a' + (i & 1);
                }
            }
            cout << s << endl;
        }
        else {
            int bad = 0;
            REP(i, n) if (cnt[i] % 4) {
                bad = 1;
            }
            if (!bad) {
                cout << 4 << endl;
                int k = sum / 4;
                int a = 1, b = 2 * k, c = 2 * k + 1, d = 4 * k;
                REP(i, n) {
                    REP(k, cnt[i] / 4) {
                        s[a++] = 'a' + i;
                        s[b--] = 'a' + i;
                        s[c++] = 'a' + i;
                        s[d--] = 'a' + i;
                    }
                }
                cout << s + 1 << endl;
            }
            else {
                cout << 2 << endl;
                int L = 0, R = sum - 1;
                REP(i, n) {
                    REP(k, cnt[i] / 2) {
                        s[L++] = 'a' + i;
                        s[R--] = 'a' + i;
                    }
                }
            }
            cout << s << endl;
        }
    }
    else {
        if (count == 1) {
            cout << 1 << endl;
            REP(i, n) if (cnt[i] & 1) {
                s[sum / 2] = 'a' + i;
                cnt[i]--;
            }
            int L = sum / 2 - 1, R = sum / 2 + 1;
            REP(i, n) {
                REP(j, cnt[i] / 2) {
                    s[L--] = 'a' + i;
                    s[R++] = 'a' + i;
                }
            }
            cout << s << endl;
        }
        else {
            cout << 0 << endl;
            REP(i, n) {
                REP(j, cnt[i]) {
                    cout << char('a' + i);
                }
            }
            cout << endl;
        }
    }
    return 0;
}


