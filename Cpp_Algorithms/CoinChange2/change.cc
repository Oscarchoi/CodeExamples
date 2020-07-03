#include <vector>
using namespace std;

class Solution {
public:
  int change(int amount, vector<int> &coins) {
    vector<int> res(amount + 1, 0);
    res[0] = 1;

    for (auto n : coins) {
      for (int i = 0; i <= amount - n; i++) {
        res[i + n] += res[i];
      }
    }
    return res[amount];
  }
};