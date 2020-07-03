#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
    sort(people.begin(), people.end(), [](auto &lhs, auto &rhs) {
      if (lhs[0] == rhs[0])
        return lhs[1] > rhs[1];
      else
        return lhs[0] < rhs[0];
    });

    int sz = people.size();
    vector<vector<int>> res(sz);
    for (auto &person : people) {
      int idx = 0;
      for (int r = person[1]; idx < sz; idx++) {
        if (res[idx].empty()) {
          if (r == 0)
            break;
          else
            --r;
        }
      }
      swap(res[idx], person);
    }
    return res;
  }
};