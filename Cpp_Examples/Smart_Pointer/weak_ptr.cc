#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class Widget {
public:
  Widget(string name) : name(name) {}
  string name;
};

int main() {
  auto spw = make_shared<Widget>("cat");
  // spw가 생성되고 참조 횟수는 1이다.

  std::weak_ptr<Widget> wpw(spw);
  // wpw는 여전히 spw와 같은 Widget을 가르킨다.
  // 횟수는 여전히 1 이다.

  spw = nullptr;
  // 횟수가 0이 되고 Widget이 파괴된다.
  // wpw는 대상을 잃는다.
  cout << "[INFO] isExpired? " << wpw.expired() << endl;

  spw = make_shared<Widget>("dog");
  wpw = spw; // assign-able
  {
    std::shared_ptr<Widget> temp = wpw.lock();
    if (temp) {
      cout << "[INFO] dereferenced widget -> " << temp->name << endl;
    }
    // 블록 내부에서 shared_ptr을 만들고 사용한 뒤 블록 밖으로 나가면서
    // 소멸시킨다.
  }

  return 0;
}