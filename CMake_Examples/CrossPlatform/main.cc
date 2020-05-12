#include <iostream>
using namespace std;

int main() {

#if defined(__x86_64) || defined(__i386__)
  cout << "Hello World[x86]" << endl;
#elif defined(__aarch64) || defined(__arm__)
  cout << "Hello World[ARM]" << endl;
#endif

  return 0;
}