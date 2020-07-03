/*
 * 1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence
 */

#include <string>
using namespace std;

class Solution {
public:
  int isPrefixOfWord(string sentence, string searchWord) {

    int index = 0, len = sentence.length();
    int res = 1;
    while (index < len) {
      int sub = searchWord.length();
      for (int i = 0; i < sub; ++i) {
        if (searchWord[i] != sentence[index++])
          break;
        if (i == sub - 1)
          return res;
      }

      while (index < len && sentence[index] != ' ')
        index++;
      while (index < len && sentence[index] == ' ')
        index++;
      res++;
    }

    return -1;
  }
};