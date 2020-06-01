#include <vector>
using namespace std;

class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &T) {
    int sz = T.size();
    vector<int> res(sz, 0);

    for (int i = sz - 2; i >= 0; --i) {
      for (int j = i + 1; j < sz;) {
        if (T[j] > T[i]) {
          res[i] = j - i;
          break;
        } else if (res[j] == 0) {
          break;
        } else {
          j += res[j];
        }
      }
    }
    return res;
  }
};