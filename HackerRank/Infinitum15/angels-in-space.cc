/*************************************************************************
	> File Name: angels-in-space.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sat 16 Apr 2016 12:03:05 AM CST
*************************************************************************/

#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 105;
struct Point {
    int x, y, z;
}p[N];

int Sqr(int x) {
    return x * x;
}

int Distance(const Point&a, const Point&b) {
    return Sqr(a.x - b.x) + Sqr(a.y - b.y) + Sqr(a.z - b.z);
}

double GetAngle(const Point &a, const Point &b, const Point &c) {
    return acos((Distance(b, c) + Distance(a, b) - Distance(a, c)) / (2.0 * sqrt(Distance(b, c)) * sqrt(Distance(b, a))));
}

int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    REPP(i, 1, n) {
        int x, y, z;
        cin >> x >> y >> z;
        p[i] = (Point) {x, y, z};
    }
    double ans = 0;
    REPP(i, 1, n) REPP(j, i + 1, n) REPP(k, j + 1, n) {
        ans += GetAngle(p[i], p[j], p[k]);
        //cout << ans << endl;
    }
    cout << fixed << setprecision(10) << ans / (n * (n - 1) * (n - 2) / 6) << endl;
    return 0;
}

