#include <iostream>
#include <string>

using namespace std;

/*
  Q: Longest Common Prefix

  Write a function to find the longest common prefix string amongst an array of strings.

  If there is no common prefix, return an empty string "".

  Example 1:
    Input: strs = ["flower","flow","flight"]
    Output: "fl"

  Example 2:
    Input: strs = ["dog","racecar","car"]
    Output: ""
    Explanation: There is no common prefix among the input strings.

  Constraints:
    0 <= strs.length <= 200
    0 <= strs[i].length <= 200
    strs[i] consists of only lower-case English letters.
*/

class Solution 
{
public:
  string longestCommonPrefix(vector<string>& strs) 
  {
    if(strs.size() == 0)
    {
      return "";
    }
    
    int lowset_loop_count = INT_MAX;
    for(string& s : strs)
    {
      int l = s.size();
      lowset_loop_count = min(lowset_loop_count, l);
    }
    
    string ans = "";
    for(int i = 0; i < lowset_loop_count; ++i)
    {
      char ch = strs[0][i];
      for(string& s: strs)
      {
        if(ch != s[i])
        {
          return ans;
        }
      }
      
      ans += ch;
    }
    
    return ans;
  }
};