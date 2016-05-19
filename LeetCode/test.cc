/*************************************************************************
	> File Name: test.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Tue 17 May 2016 08:36:58 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int  N = 1e5 + 5;
int a[N];

void quickSort(int l, int r) {
  if (l + 1 >= r) return ;
  int n = r - l;
  int index = rand() % n + l;
  swap(a[l], a[index]);
  int ptrLeft = l, ptrRight = r - 1;
  while (ptrLeft < ptrRight) {
    if (a[ptrLeft] < a[ptrLeft + 1]) {
      swap(a[ptrLeft + 1], a[ptrRight]);
      ptrRight--;
    }
    else {
      swap(a[ptrLeft], a[ptrLeft + 1]);
      ptrLeft++;
    }
  }
  quickSort(l, ptrLeft);
  quickSort(ptrLeft + 1, r);
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    cin >> a[n];
  }
  quickSort(0, n);
  REP(i, n) {
    cout << a[i] << ' ';
  }
  cout << endl;
  return 0;
}



