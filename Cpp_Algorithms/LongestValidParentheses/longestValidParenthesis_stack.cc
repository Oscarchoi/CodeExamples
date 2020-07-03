#include <stack>
#include <string>
using namespace std;

class Solution {
public:
  int longestValidParentheses(string s) {
    int res = 0, len = s.length();
    stack<int> st;

    st.push(-1);
    for (int i = 0; i < len; ++i) {
      if (s[i] == '(') {
        st.push(i);
      } else {
        st.pop();
        if (st.empty())
          st.push(i);
        else
          res = max(res, i - st.top());
      }
    }
    return res;
  }
};