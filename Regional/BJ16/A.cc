/*************************************************************************
  >         File: A.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 24 Sep 2016 01:00:58 PM CST
*************************************************************************/
#include <bits/stdc++.h>
constexpr int N = 33;

struct Layer {
  std::string name;
  Layer* nextLevel[N];
  int count;
}pool[N], *ptr, *root;

Layer* Node(const std::string& string = "") {
  ptr->name = string;
  ptr->count = 0;
  std::fill(ptr->nextLevel, ptr->nextLevel + N, nullptr);
  return ptr++;
}

void Init() {
  ptr = pool;
  root = Node();
}

void StringSplit(const std::string& string, std::vector<std::string> &answer, char delimter = '/') {
  int position = 0, now;
  while ((now = string.find_first_of(delimter, position)) != std::string::npos) {
    answer.emplace_back(string.substr(position, now - position));
    position = now + 1;
  }
  if (position != string.size()) answer.emplace_back(string.substr(position));
}

void Insert(const std::string& string) {
  Layer* now = root;
  std::vector<std::string> strings;
  StringSplit(string, strings);
  //for(auto &str: strings) {
  //  std::cerr << "# str # is " << str << std::endl;
  //}
  for (auto &str: strings) {
    bool find = false;
    for (int i = 0; i < now->count; ++i) {
      if (str == now->nextLevel[i]->name) {
        find = true;
        now = now->nextLevel[i];
        break;
      }
    }
    if (!find) {
      now->nextLevel[now->count++] = Node(str);
      now = now->nextLevel[now->count - 1];
    }
  }
}

void Print(Layer* root, int indent = -4) {
  std::vector<int> idx(root->count, 0);
  std::iota(idx.begin(), idx.end(), 0);
  std::sort(idx.begin(), idx.end(), [root] (int a, int b) {
      if ((root->nextLevel[a]->count == 0 && 
          root->nextLevel[b]->count == 0) ||
          (root->nextLevel[a]->count > 0 && 
           root->nextLevel[b]->count > 0)) {
        return root->nextLevel[a]->name < root->nextLevel[b]->name;
      } else return root->nextLevel[a]->count != 0;
      });
  if (root->name != "") {
    for (int i = 0; i < indent; ++i) putchar(' ');
    puts(root->name.c_str());
  }
  for (auto &i: idx) {
    Print(root->nextLevel[i], indent + 4);
  }
}

int main() {
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
  int cas = 1;
  while (true) {
    Init();
    static std::string s;
    while (std::getline(std::cin, s)) {
      if (s == "0") break;
      Insert(s);
    }
    if (std::cin.eof()) break;
    printf("Case %d:\n", cas++);
    Print(root);
  }
  return 0;
}
