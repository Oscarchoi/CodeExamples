#include <vector>
using namespace std;

class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>> &prereq) {
    vector<vector<int>> edges(numCourses);

    for (auto &e : prereq)
      edges[e[0]].push_back(e[1]);

    vector<bool> visited(numCourses + 1, false), onCheck(numCourses + 1, false);
    for (auto &e : prereq) {
      if (!dfs(edges, visited, onCheck, e[0]))
        return false;
    }

    return true;
  }

  bool dfs(vector<vector<int>> &edges, vector<bool> &visited,
           vector<bool> &onCheck, int node) {
    if (onCheck[node])
      return false;
    else if (visited[node])
      return true;

    onCheck[node] = true;
    for (auto dest : edges[node]) {
      if (!dfs(edges, visited, onCheck, dest))
        return false;
    }
    onCheck[node] = false;

    visited[node] = true;
    return true;
  }
};