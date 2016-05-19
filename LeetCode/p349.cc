/*************************************************************************
  > File Name: p349.cc
  > Author: yuzhou627
  > Mail:   yuzhou627@gmail.com
  > Created Time: Wed 18 May 2016 11:21:31 PM CST
 *************************************************************************/
class Solution {
public:
#define ALL(a) (a).begin(), (a).end()
  vector<int> intersection(vector<int>& num1, vector<int>& num2) {
    sort(ALL(num1));
    sort(ALL(num2));
    vector<int> answer(max(num1.size(), num2.size()));
    answer.resize(set_intersection(ALL(num1), ALL(num2), answer.begin()) - answer.begin());
    answer.resize(unique(answer.begin(), answer.end()) - answer.begin());
    return answer;
  }
};
