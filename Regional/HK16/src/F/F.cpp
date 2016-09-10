#include <cstdio>
#include <iostream>

using namespace std;

const int INF = 1e7;
#define MAXN 1123456

int C[MAXN], T[MAXN];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i < N; ++i) {
        scanf("%d", &C[i]);
    }
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &T[i]);
    }
    int timeNow = 0;
    long long ans = 0;
    int minCost = INF;
    for (int i = 1; i <= N; ++i) {
        while (timeNow < T[i]) {
            timeNow += 2;
            ans += minCost * 2;
        }
        if (i == N) break;
        timeNow++;
        minCost = min(minCost, C[i]);
        ans += C[i];
    }
    cout << ans << endl;
    return 0;
}
