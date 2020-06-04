#include <vector>
using namespace std;

class Solution {
public:
  void reverseString(vector<char> &s) {
    int i = 0, f = s.size() - 1;
    while (i < f) {
      swap(s[i++], s[f--]);
    }
  }
};