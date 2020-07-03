#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int twoCitySchedCost(vector<vector<int>> &costs) {
    int sum = 0;
    vector<int> A, B;
    for (auto &pair : costs) {
      if (pair[0] < pair[1]) {
        sum += pair[0];
        A.emplace_back(pair[1] - pair[0]);
      } else {
        sum += pair[1];
        B.emplace_back(pair[0] - pair[1]);
      }
    }

    int diff = (A.size() - B.size()) / 2;
    if (diff == 0)
      return sum;

    else if (diff < 0) {
      sort(B.begin(), B.end());
      for (int i = 0; i < -diff; ++i)
        sum += B[i];
    }

    else {
      sort(A.begin(), A.end());
      for (int i = 0; i < diff; ++i)
        sum += A[i];
    }

    return sum;
  }
};