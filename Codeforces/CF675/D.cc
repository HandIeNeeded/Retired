/*************************************************************************
	> File Name: D.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Thu 19 May 2016 11:21:51 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  set<int> numbers;
  map<int, int> record;
  REP(i, n) {
    int x;
    scanf("%d", &x);
    record[x] = i;
    if (numbers.size() == 0) {
      numbers.insert(x);
      continue;
    }
    else {
      auto pos = numbers.lower_bound(x);
      if (pos == numbers.end()) {
        printf("%d ", *(--pos));
        numbers.insert(x);
        continue;
      }
      if (pos == numbers.begin()) {
        printf("%d ", *pos);
        numbers.insert(x);
        continue;
      }
      int right, left;
      right = *pos;
      left = *(--pos);
      int answer;
      if (record[left] > record[right]) answer = left;
      else answer = right;
      printf("%d ", answer);
      numbers.insert(x);
    }
  }
  puts("");
  return 0;
}



