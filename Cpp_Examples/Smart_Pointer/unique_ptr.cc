#include <iostream>
#include <memory>
#include <string>
using namespace std;

class File {
public:
  File(const string &name) : name(name) {}
  virtual ~File(){}; // 기반 클래스 포인터로 파생 클래스 객체를 삭제하기 위한
                     // 필수적인 설계 요소
private:
  string name;
};

class Socket : public File {
public:
  Socket(string name) : File(name) { cout << "[INFO] Socket created" << endl; };
  ~Socket() override { cout << "[INFO] Socket destructed" << endl; };
};

// 팩토리 함수의 반환 형식으로 std::unique_ptr는 아주 적합하다.
// 팩토리 함수는 자신이 반환하는 객체를 호출자가 독점적으로 소유하려고 하는지
// 아니면 소유권을 공유하고자 하는지 알 필요가 없다.
std::unique_ptr<File> makeFile(const string &name) {
  std::unique_ptr<File> pFile(nullptr);
  if (name.empty())
    pFile.reset(new File("test.txt"));
  else
    pFile.reset(new File(name));
  return pFile;
}

// 커스텀 삭제자는 객체의 포인터를 매개변수로 받는다.
auto closeFile = [](File *pFile) {
  cout << "[INFO] closeFile() called" << endl;
  delete pFile;
};

int main() {
  {
    auto pFile = std::unique_ptr<File>();
    auto pSocket = std::unique_ptr<Socket, decltype(closeFile)>(
        new Socket("test"), closeFile);
    // 커스텀 삭제자를 이용할 때는 그 형식을 td::unique_ptr의 두 번째 형식
    // 인수로 지정해야 한다.

    std::shared_ptr<File> spFile = std::unique_ptr<File>(new File("test"));
    // std::unique_ptr에서 std::shared_ptr로 쉽게 변환될 수 있다.
  }
  return 0;
}
