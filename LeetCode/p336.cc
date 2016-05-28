/*************************************************************************
  > File Name: p336.cc
  > Author: yuzhou627
  > Mail:   yuzhou627@gmail.com
  > Created Time: Sun 22 May 2016 10:19:19 PM CST
 *************************************************************************/
class Solution {
  public:
    static const int MO = 1e9 + 9;

    unsigned long long GetHashVal(const string& str) {
      //cout << str << endl;
      unsigned long long answer = 0;
      for (int i = 0; i < str.size(); i++) {
        //answer = 1LL * answer * 1201 % MO + str[i];
        //answer %= MO;
        answer = answer * 1201 + str[i];
      }
      return answer;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
      vector<vector<int>> answer;
      vector<unsigned long long> hashVals, reverseHashVals;
      vector<unsigned long long> powers;
      int mx = 0;
      for (auto &str: words) hashVals.push_back(GetHashVal(str)), mx = max(mx, int(str.size()));
      for (auto &str: words) {
        reverse(str.begin(), str.end());
        reverseHashVals.push_back(GetHashVal(str));
      }

      unsigned long long now = 1;
      powers.push_back(now);
      //for (int i = 1; i <= mx; i++) powers.push_back(now), now = 1LL * now * 1201 % MO;
      for (int i = 1; i <= mx; i++) now = now * 1201, powers.push_back(now);
      int n = words.size();
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) if (i != j) {
          //int combineHash = 1LL * hashVals[i] * powers[words[j].size()] % MO + hashVals[j];
          //combineHash %= MO;
          unsigned long long combineHash = hashVals[i] * powers[words[j].size()] + hashVals[j];
          //int reverseCombineHash = 1LL * reverseHashVals[j] * powers[words[i].size()] % MO + reverseHashVals[i];
          //reverseCombineHash %= MO;
          unsigned long long reverseCombineHash = reverseHashVals[j] * powers[words[i].size()] + reverseHashVals[i];
          if (combineHash == reverseCombineHash) {
            vector<int> tmp;
            tmp.push_back(i);
            tmp.push_back(j);
            answer.push_back(tmp);
          }
        }
      }
      return answer;
    }
};
