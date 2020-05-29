#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    vector<int> column;
    string line = string(n, '.');
    board = vector<string>(n, line);
    for (int i = 0; i < n; ++i)
      solve(column, 0, i, n);
    return res;
  }

  void solve(vector<int> &column, int r, int c, int n) {
    for (int i = 0; i < column.size(); ++i) {
      if (c == column[i] || r + c == i + column[i] || r - c == i - column[i])
        return;
    }
    column.push_back(c);
    if (r == n - 1)
      printBoard(column, n);
    else
      for (int j = 0; j < n; ++j)
        solve(column, r + 1, j, n);
    column.pop_back();
  }

  void printBoard(vector<int> &column, int n) {
    for (int i = 0; i < n; ++i)
      board[i][column[i]] = 'Q';
    res.push_back(board);
    for (int i = 0; i < n; ++i)
      board[i][column[i]] = '.';
  }

  vector<string> board;
  vector<vector<string>> res;
};