#include<bits/stdc++.h>
using namespace std;

class Solution 
{
private:
  bool  isPalindrome(const string& s)
  {
    int start = 0;
    int end = s.size()-1;
    while(start < end)
    {
      if(s[start] != s[end])
      {
        return false;
      }
      
      start++;
      end--;
    }
    
    return true;
  }
  
  void getAllCombinations(const string& s, int p, vector<string>& strings, vector<vector<string>>& ans)
  {
    if(p >= s.size())
    {
      ans.push_back(strings);
    }
    
    for(int i = p; i < s.size(); ++i)
    {
      string substr = s.substr(p, i+1-p);
      if(isPalindrome(substr))
      {
        strings.push_back(substr);
        getAllCombinations(s, i+1, strings, ans);
        strings.pop_back();
      }
    }
  }
public:
  vector<vector<string>> partition(string s) 
  {
    vector<string> strings;
    vector<vector<string>> ans;
    getAllCombinations(s, 0, strings, ans);
    
    return ans;
  }
};