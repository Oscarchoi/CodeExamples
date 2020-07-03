#include <climits>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int minDistance(string word1, string word2) {
    int n = word1.length();
    int m = word2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    // Assume dp[i][j] = minimum cost to delete all the characters which have
    // index equal to or before i-th and j-th index, respectively, to the word1
    // and word2.

    for (int i = 0; i <= m; ++i)
      dp[i][0] = i;
    for (int i = 0; i <= n; ++i)
      dp[0][i] = i;

    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        int check = word2[i - 1] != word1[j - 1] ? 1 : 0;
        dp[i][j] =
            min(min(dp[i][j - 1], dp[i - 1][j]) + 1, dp[i - 1][j - 1] + check);
        // dp[i][i] = min( dp[i][j-1]+1, dp[i-1][j]+1, dp[i-1][j-1] + check);
        //                  ㄴdelete       ㄴinsert         ㄴreplace
      }
    }

    return dp[m][n];
  }
};