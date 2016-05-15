#include <bits/stdc++.h>

const int N = 100000 + 5;
int A[N],T[N],X[N];
int answer[N];
int idx[N];
int n;

void divide(int l,int r) {
    if (l == r) return ;
    int mid = l + r >> 1;
    divide(l,mid);
    divide(mid + 1,r);

    std::map<int,int> map;
    for (int i = mid + 1,j = l; i <= r; ++ i) {
        while (j <= mid && T[idx[j]] <= T[idx[i]]) {
            if (A[idx[j]] == 1) {
                map[X[idx[j]]] ++;
            } else if (A[idx[j]] == 2) {
                map[X[idx[j]]] --;
            }
            ++ j;
        }
        if (A[idx[i]] == 3) {
            answer[idx[i]] += map[X[idx[i]]];
        }
    }
    std::inplace_merge(idx + l,idx + mid + 1,idx + r + 1,[&](int a,int b) {
      return T[a] < T[b];
    });
}

int main() {
    scanf("%d",&n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d%d%d",A + i,T + i,X + i);
        idx[i] = i;
    }
    divide(0,n - 1);
    for (int i = 0; i < n; ++ i) {
        if (A[i] == 3) {
            printf("%d\n",answer[i]);
        }
    }
}
