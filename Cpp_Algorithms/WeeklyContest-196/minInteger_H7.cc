#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
  string minInteger(string num, int k) {
    int pos = 0, len = num.size();
    if (k > ((len - 1) * (len - 1) / 2)) {
      sort(num.begin(), num.end());
      return num;
    }

    string res = num;
    while (pos < len && k > 0) {
      helper(res, pos, k, len);
    }
    return res;
  }

  void helper(string &num, int &pos, int &k, int len) {
    if (num[pos] == '0') {
      pos++;
      return;
    } else {
      int tmp = num[pos], idx = pos;
      int limit = min(pos + k, len - 1);

      for (int i = pos + 1; i <= limit; ++i) {
        if (num[i] < tmp) {
          tmp = num[i];
          idx = i;
        }
        if (tmp == '0')
          break;
      }

      num.replace(pos + 1, idx - pos, num, pos, idx - pos);
      num[pos] = tmp;
      k -= idx - pos;
      pos++;
    }
  }
};