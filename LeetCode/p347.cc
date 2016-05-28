/*************************************************************************
  > File Name: p347.cc
  > Author: yuzhou627
  > Mail:   yuzhou627@gmail.com
  > Created Time: Sat 14 May 2016 05:50:10 PM CST
 *************************************************************************/
class Solution {
  public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      map<int, int> mp;
      int n = nums.size();
      for (int i = 0; i < n; i++) {
        mp[nums[i]]++;
      }
      vector<pair<int, int>> p;
      for (auto it = mp.begin(); it != mp.end(); it++) {
        p.push_back({it->second, it->first});
      }
      sort(p.begin(), p.end());
      vector<int> answer;
      for (int i = p.size() - 1, j = 0; j < k; j++, i--) {
        answer.push_back(p[i].second);
      }
      return answer;
    }
};
