static class SegmentTreeSolver {
  int[] A, B;

  public SegmentTreeSolver(int n) {
    A = new int[(n * 4) + 5];
    B = new int[(n * 4) + 5];
  }

  public void push(int x, int l, int r) {
    int mid = (r + l) >> 1;
    int L = x << 1, R = x << 1 | 1;
    A[L] += (mid - L + 1) * B[x];
    A[R] += (r - mid) * B[x];
    B[L] += B[x];
    B[R] += B[x];
    B[x] = 0;
  }

  public void update(int x, int l, int r, int ql, int qr, int value) {
    if (ql <= l && qr >= r) {
      A[x] += (r - l + 1) * value;
      B[x] += value;
    }
    else {
      if (B[x] > 0) {
        push(x, l, r);
      }
      int mid = (l + r) >> 1;
      if (ql <= mid) update(x << 1, l, mid, ql, qr, value);
      if (qr > mid) update(x << 1 | 1, mid + 1, r, ql, qr, value);
    }
  }

  public int query(int x, int l, int r, int qx) {
    if (l == r) {
      return A[x];
    }
    else {
      int mid = (l + r) >> 1;
      if (B[x] > 0) {
        push(x, l, r);
      }
      if (qx < mid) return query(x << 1, l, mid, qx);
      else return query(x << 1 | 1, mid + 1, r, qx);
    }
  }
}

