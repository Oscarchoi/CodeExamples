#include <iostream>
#include <regex>

// Reference
// http://www.cplusplus.com/reference/regex/ECMAScript/
int main() {
  std::string str1 = "ID_123_NAME_KIM";

  std::regex re1("ID_\\d+_.*");
  std::cout << "TEST 1: " << std::regex_match(str1, re1) << std::endl;  // true

  std::regex re2("ID_\\d+_.*_KIM");
  std::cout << "TEST 2: " << std::regex_match(str1, re2) << std::endl;  // true

  // 1 or more +,  int {int} , int or more {int, }, between {min,max}
  std::regex re3("ID_\\d+_.{4}_KIM");
  std::cout << "TEST 3: " << std::regex_match(str1, re3) << std::endl;  // true

  // Beginning of line(^), End of line($)
  std::regex re4("^ID_.*_KIM$");
  std::cout << "TEST 4: " << std::regex_match(str1, re4) << std::endl;  // true

  // word \w , not word \W , digit \d , not digit \D, whitespace \s, not \S
  std::regex re5("^ID_\\d*_\\w*_KIM$");
  std::cout << "TEST 5: " << std::regex_match(str1, re5) << std::endl;  // true

  std::string str2 = "ID_.*_.*_.*";
  std::regex re6(str2);
  std::cout << "TEST 6: " << std::regex_match(str1, re6) << std::endl;  // true

  return 0;
}
