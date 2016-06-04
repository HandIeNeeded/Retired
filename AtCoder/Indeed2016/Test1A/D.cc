/*************************************************************************
	> File Name: D.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Sat 04 Jun 2016 07:39:51 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int MAX_N = 25;

char chocolate[MAX_N][MAX_N];
int height, width;
int minCostSplitHistory[MAX_N][MAX_N][MAX_N][MAX_N];
int partialSum[MAX_N][MAX_N];

void InitPartialSum() {
  REPP(row, 1, height) {
    REPP(column, 1, width) {
      partialSum[row][column] = partialSum[row - 1][column] + partialSum[row][column - 1] + chocolate[row][column] - '0';
      partialSum[row][column] -= partialSum[row - 1][column - 1];
    }
  }
  //Initial arrays
  REPP(row, 1, height) REPP(column, 1, width) REPP(a, 1, height) REPP(b, 1, width) minCostSplitHistory[row][column][a][b] = INT_MAX;
}

int GetSubRectSum(int leftUpperX, int leftUpperY, int rightLowerX, int rightLowerY) {
  return partialSum[rightLowerX][rightLowerY] - partialSum[leftUpperX - 1][rightLowerY] - 
    partialSum[rightLowerX][leftUpperY - 1] + partialSum[leftUpperX - 1][leftUpperY - 1];
}

int GetMinCostSplit(int leftUpperX, int leftUpperY, int rightLowerX, int rightLowerY) {
  if (leftUpperX == rightLowerX && leftUpperY == rightLowerY) {
    return 0;
  }
  if (minCostSplitHistory[leftUpperX][leftUpperY][rightLowerX][rightLowerY] != INT_MAX) {
    return minCostSplitHistory[leftUpperX][leftUpperY][rightLowerX][rightLowerY];
  }
  else {
    int &answer = minCostSplitHistory[leftUpperX][leftUpperY][rightLowerX][rightLowerY];
    int cost = GetSubRectSum(leftUpperX, leftUpperY, rightLowerX, rightLowerY);
    if (leftUpperX != rightLowerX) {
      REPP(row, leftUpperX, rightLowerX - 1) {
        answer = min(answer, GetMinCostSplit(leftUpperX, leftUpperY, row, rightLowerY) 
            + GetMinCostSplit(row + 1, leftUpperY, rightLowerX, rightLowerY));
      }
    }
    if (leftUpperY != rightLowerY) {
      REPP(column, leftUpperY, rightLowerY - 1) {
        answer = min(answer, GetMinCostSplit(leftUpperX, leftUpperY, rightLowerX, column) 
            + GetMinCostSplit(leftUpperX, column + 1, rightLowerX, rightLowerY));
      }
    }
    answer += cost;
    return answer;
  }
}

int main() {
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
  cin >> height >> width;
  REPP(row, 1, height) {
    cin >> (chocolate[row] + 1);
  }
  InitPartialSum();
  //cerr << GetSubRectSum(1, 1, height, width) << endl;
  //cerr << partialSum[height][width] << endl;
  cout << GetMinCostSplit(1, 1, height, width) << endl;
  return 0;
}


