#include <limits.h>
#include <vector>
using namespace std;

class Solution {
public:
  int numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    int p = 1, sq = 1;
    while (sq <= n) {
      dp[sq] = 1;
      for (int i = 1; i <= n - sq; ++i)
        if (dp[i])
          dp[i + sq] = min(dp[i + sq], dp[i] + 1);
      p++;
      sq = p * p;
    }
    return dp[n];
  }
};