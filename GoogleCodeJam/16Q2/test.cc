#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

class Person {
public:
  Person() {}
  ~Person() {}

  virtual void sayHello() {
    cout << "Hello!" << endl;
  }
};

class Chinese: public Person {
public:
  Chinese() {}
  ~Chinese() {}

  void sayHello() {
    cout << "你好" << endl;
  }
};

int main() {
  int t, ca = 1;
  Person *a = new Person;
  //a.sayHello();
  //b.sayHello();
  a->sayHello();
  return 0;
}


