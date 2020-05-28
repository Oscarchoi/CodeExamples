#include <string>
using namespace std;

class Solution {
public:
  int longestValidParentheses(string s) {
    int len = s.length();
    int arr[len + 1];
    int level = 0, res = 0;

    for (auto &n : arr)
      n = -1;

    for (int i = 0; i < len; ++i) {
      if (s[i] == '(') {
        if (arr[level] == -1)
          arr[level] = i;
        level++;
      } else {
        arr[level] = -1;
        if (level > 0)
          level--;

        if (arr[level] >= 0 && i - arr[level] > res)
          res = i - arr[level] + 1;
      }
    }
    return res;
  }
};