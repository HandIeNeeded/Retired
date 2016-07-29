static class FenwickTreeSolver {
  int[] A;
  public FenwickTreeSolver(int n) {
    A = new int[n + 5];
  }

  private int lowbit(int x) {
    return x & (-x);
  }

  void add(int index, int value) {
    while (index < A.length) {
      A[index] += value;
      index += lowbit(index);
    }
  }

  int query(int index) {
    int answer = 0;
    while (index != 0) {
      answer += A[index];
      index -= lowbit(index);
    }
    return answer;
  }
}
