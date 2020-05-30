#include <vector>
using namespace std;

class Solution {
public:
  int size;
  vector<bool> checkIfPrerequisite(int n, vector<vector<int>> &prerequisites,
                                   vector<vector<int>> &queries) {
    size = n;

    vector<vector<bool>> graph(n, vector<bool>(n, false));
    for (auto &pair : prerequisites)
      graph[pair[0]][pair[1]] = true;

    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i)
      dfs(i, graph, prerequisites, visited);

    vector<bool> res;
    for (auto &pair : queries)
      res.emplace_back(graph[pair[0]][pair[1]]);
    return res;
  }

  void dfs(int i, vector<vector<bool>> &graph, vector<vector<int>> &prereq,
           vector<bool> &visited) {
    if (visited[i])
      return;

    for (int j = 0; j < size; j++)
      if (graph[i][j])
        dfs(j, graph, prereq, visited);

    for (int j = 0; j < size; j++)
      if (graph[i][j])
        for (int k = 0; k < size; ++k)
          graph[i][k] = graph[i][k] || graph[j][k];

    visited[i] = true;
  }
};