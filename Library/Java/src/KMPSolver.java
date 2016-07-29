static class KMPSolver {
  int[] fail;
  String str;

  public KMPSolver(String a) {
    str = a;
    fail = new int[a.length() + 1];
    fail[0] = fail[1] = 0;
    for (int i = 1; i < a.length(); i++) {
      int j = fail[i];
      while (j != 0 && str.charAt(j) != str.charAt(i)) j = fail[j];
      fail[i + 1] = str.charAt(j) == str.charAt(i) ? j + 1 : 0;
    }
  }

  public boolean find(String a) {
    int position = 0;
    for (int i = 0; i < a.length(); i++) {
      if (position == str.length()) return true;
      if (position < str.length() && a.charAt(i) == str.charAt(position)) position++;
      else {
        int j = fail[position];
        while (j != 0 && a.charAt(i) != str.charAt(j)) j = fail[j];
        position = a.charAt(i) == str.charAt(j) ? j + 1 : 0;
      }
    }
    return false;
  }
}
