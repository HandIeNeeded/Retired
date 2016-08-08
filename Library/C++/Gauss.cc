//运行结束后a[i][n]是第i个未知数的值 lrj Page154
//已经加了对精度的优化
void Gauss(Matrix& a, int n){
  REP(i, n) {
    int rank = i;
    for (int j = i + 1; j < n; ++j) if (fabs(a[j][i]) > fabs(a[rank][i])) rank = j;
    if (rank != i) 
      for (j = 0; j <= n; ++j) swap(a[rank][j], a[i][j]);

    for (int j = n; j >= i; --j) 
      for (int k = i + 1; k < n; ++k) 
        a[k][j] -= a[k][i] / a[i][i] * a[i][j];
  }
  for (int i = n - 1; i >= 0; --i){
    for (int j = i + 1; j < n; ++j){
      a[i][n] -= a[j][n] * a[i][j];
    }
    a[i][n] /= a[i][i];
  }
}

//Gauss Elimination
int Gauss(int n) {
  int rank = 0;
  for (int i = 0; i < K; i++) {
    bool find = 0;
    for (int j = rank; j < n; j++) {
      if (a[j] & (1LL << i)) {
        find = 1;
        swap(a[rank], a[j]);
        break;
      }
    }
    if (find) {
      for (int j = 0; j < n; j++) if (j != rank) {
        if (a[j] & (1LL << i)) {
          a[j] ^= a[rank];
        }
      }
      rank++
    }
  }
  return rank;
}

