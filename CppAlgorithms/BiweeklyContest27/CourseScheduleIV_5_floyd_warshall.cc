#include <vector>
using namespace std;

class Solution {
public:
  vector<bool> checkIfPrerequisite(int n, vector<vector<int>> &prerequisites,
                                   vector<vector<int>> &queries) {

    vector<vector<bool>> graph(n, vector<bool>(n, false));

    for (auto &pair : prerequisites)
      graph[pair[0]][pair[1]] = true;

    // Floyd-Warshall Algorithm
    for (int k = 0; k < n; ++k)
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
          graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);

    vector<bool> res;
    for (auto &pair : queries)
      res.emplace_back(graph[pair[0]][pair[1]]);

    return res;
  }
};