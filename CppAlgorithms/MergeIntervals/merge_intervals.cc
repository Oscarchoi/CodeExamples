#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intv) {
    if (intv.size() == 0)
      return intv;
    vector<vector<int>> res;

    sort(intv.begin(), intv.end(),
         [](const auto &lhs, const auto &rhs) { return lhs[0] < rhs[0]; });

    vector<int> temp = intv[0];
    for (auto &pair : intv) {
      if (pair[0] > temp[1]) {
        res.push_back(temp);
        temp = pair;
      } else if (pair[1] > temp[1]) {
        temp[1] = pair[1];
      }
    }
    res.push_back(temp);
    return res;
  }
};