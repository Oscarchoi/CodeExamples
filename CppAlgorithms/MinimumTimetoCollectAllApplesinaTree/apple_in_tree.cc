#include <vector>
using namespace std;

class Solution {
public:
  int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple) {
    int res = 0;

    vector<pair<int, bool>> dp(n);
    dp[0].second = true;

    for (auto &edge : edges)
      dp[edge[1]].first = edge[0];

    for (int i = 0; i < n; ++i)
      if (hasApple[i]) {
        int tmp = i;
        while (!dp[tmp].second) {
          res += 2;
          dp[tmp].second = true;
          tmp = dp[tmp].first;
        }
      }

    return res;
  }
};
