#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define LL long long

using namespace std;

const int N = 1e6 + 5;
const int M = 1e9;
int a[N];

int main() {
	ios :: sync_with_stdio(0);
    //freopen("tmp.in", "w", stdout);
	srand(time(0) % clock());
    int t = 2;
    cout << t << endl;
    while (t--) {
        int n = rand() % 10 + 1;
        int z = rand() % 10000 + 1;
        int m = rand() % 100000000 + 1;
        cout << n << ' ' << m << ' ' << z << endl;
        REP(i, n) {
            cout << rand() % m  << ' ';
        }
        cout << endl;
    }

	return 0;
}

