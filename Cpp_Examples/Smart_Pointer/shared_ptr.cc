#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Widget {};

int main() {
  auto loggingDelete = [](Widget *pWidget) {
    cout << "[INFO] Delete function called" << endl;
    delete pWidget;
  };

  // 삭제자의 형식이 포인터 형식의 일부임
  std::unique_ptr<Widget, decltype(loggingDelete)> upw(new Widget(),
                                                       loggingDelete);

  // shared_ptr은 삭제자의 형식이 포인터 형식의 일부가 아님 => 설계적 유연성
  std::shared_ptr<Widget> spw(new Widget());
  std::shared_ptr<Widget> spw2(new Widget(), [](Widget *pw) { delete pw; });

  // 형식이 같기 때문에 서로 다른 삭제자를 갖는 shared_ptr도 같은 컨테이너에
  // 저장될 수 있다. (unique_ptr에서는 불가능)
  vector<std::shared_ptr<Widget>> vec{spw, spw2};

  return 0;
}