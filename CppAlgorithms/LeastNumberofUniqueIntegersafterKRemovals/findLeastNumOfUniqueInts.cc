#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int findLeastNumOfUniqueInts(vector<int> &arr, int k) {
    unordered_map<int, int> counts;
    for (auto n : arr)
      counts[n]++;

    int res = 0, back = -1;
    sort(arr.begin(), arr.end(), [&counts](const auto &lhs, const auto &rhs) {
      if (counts[lhs] == counts[rhs])
        return lhs < rhs;
      return counts[lhs] < counts[rhs];
    });

    for (auto n : arr) {
      if (k > 0) {
        k--;
        continue;
      } else if (back == n)
        continue;
      else {
        back = n;
        res++;
      }
    }

    return res;
  }
};