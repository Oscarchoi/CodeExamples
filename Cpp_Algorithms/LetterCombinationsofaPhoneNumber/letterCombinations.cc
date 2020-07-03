#include<string>
#include<vector>
using namespace std;

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    if(digits.empty()) return res;
    string temp;
    addCharacter(0,temp,digits.length(),digits);
    return res;        
  }
  

  void addCharacter(int index, string& temp, int length, string& digits){
    int n = digits[index]-'2';    
    for(int i = 0; i<keys[n].second; ++i){
      char c = 'a' + keys[n].first + i; 
      temp += c;      
      if(index==length-1) {
        res.push_back(temp);
      } else {
        addCharacter(index+1,temp,length,digits);
      }
      temp.pop_back();      
    }
  }
  
  vector<string> res;
  pair<int,int> keys[8] = {{0,3},{3,3},{6,3},{9,3},{12,3},{15,4},{19,3},{22,4}};
};