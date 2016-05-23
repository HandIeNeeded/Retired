/*************************************************************************
	> File Name: p165.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sun 22 May 2016 07:29:47 PM CST
*************************************************************************/
class Solution {
public:

  void Modify(string& str) {
    int pos = 0;
    while (pos < int(str.size()) && str[pos] == '0') pos++;
    //if (pos == str.size()) str = "";
    //else str = str.substr(pos);
    str = str.substr(pos);
  }

  vector<string> GetVersionInfo(const string& versionStr) {
    vector<string> parts;
    int now = 0;
    size_t position;
    while ((position = versionStr.find('.', now)) != string::npos) {
      parts.push_back(versionStr.substr(now, position - now));
      now = position + 1;
    }
    parts.push_back(versionStr.substr(now));
    return parts;
  }

  int compareStr(const string&a, const string&b) {
    if (a.size() != b.size()) return a.size() < b.size() ? -1 : 1;
    else {
      for (int i = 0; i < a.size(); i++) if (a[i] != b[i]) {
        return a[i] < b[i] ? -1 : 1;
      }
      return 0;
    }
  }

  int compareVec(const vector<string> &a, const vector<string> &b) {
    int length = max(a.size(), b.size());
    for (int i = 0; i < length; i++) {
      string strA, strB;
      if (i >= a.size()) strA = "";
      else strA = a[i];
      if (i >= b.size()) strB = "";
      else strB = b[i];
      int result = compareStr(strA, strB);
      if (result) return result;
    }
    return 0;
  }

  int compareVersion(string version1, string version2) {
    vector<string> info1 = GetVersionInfo(version1);
    vector<string> info2 = GetVersionInfo(version2);
    for (auto &str: info1) Modify(str);
    for (auto &str: info2) Modify(str);
    //for (auto &str: info1) {
    //  cout << str << ' ';
    //}
    //cout << endl;
    //for (auto &str: info2) {
    //  cout << str << ' ';
    //}
    //cout << endl;
    return compareVec(info1, info2);
  }
};
