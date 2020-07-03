/*
 * 1456. Check If a Word Occurs As a Prefix of Any Word in a Sentence
 */

#include <string>
using namespace std;

class Solution {
public:
  int maxVowels(string s, int k) {

    int res = 0;
    for (int i = 0; i < k; ++i) {
      res += isVowel(s[i]);
    }

    int temp = res;
    for (int i = k, len = s.length(); i < len; ++i) {
      if (isVowel(s[i - k]))
        temp--;
      if (isVowel(s[i]))
        temp++;
      if (temp > res)
        res = temp;
    }

    return res;
  }

  bool isVowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
      return true;
    return false;
  }
};