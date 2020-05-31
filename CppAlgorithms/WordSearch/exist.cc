#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  bool exist(vector<vector<char>> &board, string word) {
    r = board.size();
    c = board[0].size();

    for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j)
        if (check(board, word, i, j, 0))
          return true;

    return false;
  }

  bool check(vector<vector<char>> &board, string &word, int x, int y, int pos) {
    if (x < 0 || x >= r || y < 0 || y >= c || board[x][y] != word[pos])
      return false;

    if (pos == word.length() - 1)
      return true;

    // instead of put visited flag vector,
    // make character not to be the candidate.
    char tmp = word[pos];
    board[x][y] = '.';

    if (check(board, word, x - 1, y, pos + 1) ||
        check(board, word, x + 1, y, pos + 1) ||
        check(board, word, x, y - 1, pos + 1) ||
        check(board, word, x, y + 1, pos + 1))
      return true;

    // recover the character
    board[x][y] = tmp;

    return false;
  }

  // member
  int r, c;
};