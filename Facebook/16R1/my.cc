/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000005;
int n;
LL A, B, c[N], all, d[N];
void start (int k) {
    for (int i = 0; i < n; i ++) {
        d[i] = c[(i + k) % n];
    }
}
double gao () {
    double length = B - A , ans = 0;
    LL cnt = A / all;
    A -= cnt * all; B -= cnt * all;
    for (int i = 0 ; i < n ; i ++) {
        if (A >= c[i]) {
            A -= c[i];
            B -= c[i];
        }
        else {
            if (B <= c[i]) {
                return (A + B) / 2.0;
            }
            ans += (c[i] + A) / 2.0 * (c[i] - A);
            B -= c[i];
            A = 0;
            start (i + 1);
            break;
        }
    }

    LL tot = B / all;
    for (int i = 0 ; i < n ; i ++) {
        ans += d[i] / 2.0 * d[i] * tot;
    }

    B -= all * tot;
    for (int i = 0 ; i < n ; i ++) {
        if (B >= d[i]) {
            B -= d[i];
            ans += d[i] / 2.0 * d[i];
        }
        else {
            ans += B / 2.0 * B;
            break;
        }
    }
    return ans / length;
}
int main () {
    //freopen ("input.txt" , "r" , stdin);
    //freopen ("output.txt" , "w" , stdout);
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%d %lld %lld", &n, &A, &B);
        all = 0;
        for (int i = 0 ; i < n ; i ++) {
            scanf ("%lld", c + i);
            all += c[i];
        }

        printf ("Case #%d: %.10f\n" , ++ cas, gao ());
    }
    return 0;
}
