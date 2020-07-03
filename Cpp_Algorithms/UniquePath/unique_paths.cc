#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<int> arr(m);
    fill(arr.begin(), arr.end(), 1);
    for (int i = 1; i < n; ++i)
      for (int j = 1; j < m; ++j)
        arr[j] += arr[j - 1];
    return arr[m - 1];
  }
};