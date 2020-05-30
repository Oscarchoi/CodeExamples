#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
  bool hasAllCodes(string s, int k) {

    long long variety = pow(2, k);
    int len = s.length();
    if (variety > len)
      return false;

    unordered_set<string> bank;
    for (int j = 0; j <= len - k; j++)
      bank.insert(s.substr(j, k));

    if (bank.size() != variety)
      return false;

    return true;
  }
};
