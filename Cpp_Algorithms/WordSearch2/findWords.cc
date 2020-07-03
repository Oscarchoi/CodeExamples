#include <string>
#include <vector>
using namespace std;

class Solution {
  int row = 0;
  int col = 0;

public:
  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    vector<string> res;

    row = board.size();
    if (row < 0)
      return res;
    col = board[0].size();

    for (const auto &word : words)
      if (isIncluded(board, word))
        res.emplace_back(std::move(word));
    return res;
  }

  bool isIncluded(vector<vector<char>> &board, const string &word) {
    if (word.empty())
      return false;
    int len = word.size();

    for (int x = 0; x < row; x++) {
      for (int y = 0; y < col; y++) {
        if (board[x][y] == word[0] && dfs(board, x, y, 0, len, word))
          return true;
      }
    }
    return false;
  }

  bool dfs(vector<vector<char>> &board, int r, int c, int cur, int len,
           const string &word) {
    if (r < 0 || r >= row || c < 0 || c >= col || board[r][c] != word[cur])
      return false;
    if (cur == len - 1)
      return true;

    char temp = board[r][c];
    board[r][c] = '-';

    bool res = false;
    res |= dfs(board, r - 1, c, cur + 1, len, word);
    res |= dfs(board, r, c - 1, cur + 1, len, word);
    res |= dfs(board, r + 1, c, cur + 1, len, word);
    res |= dfs(board, r, c + 1, cur + 1, len, word);

    board[r][c] = temp;
    return res;
  }
};