/*************************************************************************
  > File Name: test.cc
  > Author: yuzhou627
  > Mail:   yuzhou627@gmail.com
  > Created Time: Thu 12 May 2016 04:14:09 PM CST
 *************************************************************************/
class Solution {
public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> answer;
    int n = words.size();
    bool valid = true;
    for (int i = 0; i < n; i++) if (words[i].size() > maxWidth) valid = false;
    if (n == 0 || valid == false) return answer;
    reverse(words.begin(), words.end());
    while (words.size()) {
      string wordInOneLine;
      int cnt = 0, sum = 0;
      vector<string> wordUsed;
      while (words.size() && sum + (cnt > 0) + words.back().size() <= maxWidth){
        wordUsed.push_back(words.back());
        sum += words.back().size() + (cnt > 0);
        words.pop_back();
        cnt++;
      }
      if (cnt == 1) {
        wordInOneLine = wordUsed[0];
        wordInOneLine.resize(maxWidth, ' ');
      }
      else {
        int blankSpace = maxWidth - sum + cnt - 1;
        int a = blankSpace / (cnt - 1), b = blankSpace % (cnt - 1);
        wordInOneLine += wordUsed[0];
        for (int i = 1; i < cnt; i++) {
          wordInOneLine += string(a, ' ');
          if (i <= b) wordInOneLine += ' ';
          wordInOneLine += wordUsed[i];
        }
      }
      if (words.size() == 0) {
        wordInOneLine = wordUsed[0];
        for (int i = 1; i < cnt; i++) {
          wordInOneLine += ' ';
          wordInOneLine += wordUsed[i];
        }
        wordInOneLine.resize(maxWidth, ' ');
      }
      answer.push_back(wordInOneLine);
    }
    for (auto &str: answer) {
      cout << str << endl;
    }
    return answer;
  }
};
