#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

#define MOD 1000000007;

class Solution {
public:
  string longestDupSubstring(string S) {
    int l = 1, r = S.size();
    string res;
    while (l <= r) {
      int mid = (l + r) / 2;
      string temp = isDuplicate(mid, S);
      if (temp.empty()) {
        r = mid - 1;
      } else {
        res = temp;
        l = mid + 1;
      }
    }
    return res;
  }

  string isDuplicate(const int &len, string &S) {
    long long hash = S[0] - 'a' + 1, order = 1;
    for (int i = 1; i < len; ++i) {
      hash = (hash * 2 + S[i] - 'a' + 1) % MOD;
      order = (order * 2) % MOD;
    }
    // cout<<S.substr(0,len)<<": "<<hash<<endl;
    unordered_map<long long, vector<int>> bank{};
    bank[hash] = {0};

    for (int i = len; i < S.size(); i++) {
      hash -= ((S[i - len] - 'a' + 1) * order) % MOD;
      hash = (hash * 2 + S[i] - 'a' + 1) % MOD;
      if (hash < 0)
        hash += MOD;
      // cout<<S.substr(i-len+1,len)<<": "<<hash<<endl;
      if (bank.find(hash) == bank.end()) {
        bank[hash] = {i - len + 1};
      } else {
        string temp = S.substr(i - len + 1, len);
        for (auto index : bank[hash]) {
          if (S.substr(index, len) == temp) {
            // cout<<"["<<len<<"]"<<S.substr(index,len)<<endl;
            // cout<<"["<<len<<"]"<<temp<<endl;
            return temp;
          }
        }
        bank[hash].push_back(i - len + 1);
      }
    }
    return "";
  }
};