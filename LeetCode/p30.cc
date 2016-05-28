/*************************************************************************
  > File Name: p30.cc
  > Author: yuzhou627
  > Mail:   yuzhou627@gmail.com
  > Created Time: Mon 23 May 2016 10:02:07 PM CST
 *************************************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    typedef unsigned long long LL;
    int wordLength;
    LL powerOfBase;
    static const LL Base = 1201;
    string originStr;

    bool IsTwoVectorEqual(vector<LL> a, const vector<LL> &b) {
      if (a.size() != b.size()) return false;
      sort(a.begin(), a.end());
      for (int i = 0; i < a.size(); i++) if (a[i] != b[i]) return false;
      return true;
    }

    LL GetHashValueOfStr(const string& str) {
      LL answer = 0;
      for (int i = 0; i < str.size(); i++) {
        answer = Base * answer + str[i];
      }
      return answer;
    }

    vector<LL> GetNextHashValues(const vector<LL> &previousHashValues, int startIdx) {
      vector<LL> nextHashValues = previousHashValues;
      for (int i = 0; i < nextHashValues.size(); i++) {
        nextHashValues[i] = Base * nextHashValues[i] + originStr[startIdx + (i + 1) * wordLength];
        nextHashValues[i] -= originStr[startIdx + i * wordLength] * powerOfBase;
      }
      return nextHashValues;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
      vector<int> answer;
      if (s.size() == 0 || words.size() == 0 || words.size() * words[0].size() > s.size()) return answer;

      originStr = s;
      wordLength = words[0].size();
      powerOfBase = 1;
      for (int i = 0; i < wordLength; i++) powerOfBase *= Base;

      vector<LL> wordsHashValues, originHashValues;
      for (int i = 0; i < words.size(); i++) wordsHashValues.push_back(GetHashValueOfStr(words[i]));
      sort(wordsHashValues.begin(), wordsHashValues.end());
      for (int i = 0; i < words.size(); i++) {
        originHashValues.push_back(GetHashValueOfStr(originStr.substr(i * wordLength, wordLength)));
      }
      if (IsTwoVectorEqual(originHashValues, wordsHashValues)) answer.push_back(0);
      for (int idx = 1; idx < originStr.size(); idx++) {
        if (idx + wordLength * words.size() > originStr.size()) break;
        else {
          originHashValues = GetNextHashValues(originHashValues, idx - 1);
          //assert(originHashValues[0] == GetHashValueOfStr(originStr.substr(idx, wordLength)));
          if (IsTwoVectorEqual(originHashValues, wordsHashValues)) answer.push_back(idx);
        }
      }
      return answer;
    }
};

int main() {
  Solution solver;
  return 0;
}
