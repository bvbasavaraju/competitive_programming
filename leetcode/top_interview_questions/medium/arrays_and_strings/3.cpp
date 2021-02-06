#include <iostream>
#include <vector>

using namespace std;

/*
  Q: Group Anagrams

  Given an array of strings strs, group the anagrams together. You can return the answer in any order.
  An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

  Example 1:
    Input: strs = ["eat","tea","tan","ate","nat","bat"]
    Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

  Example 2:
    Input: strs = [""]
    Output: [[""]]

  Example 3:
    Input: strs = ["a"]
    Output: [["a"]]

  Constraints:
    1 <= strs.length <= 104
    0 <= strs[i].length <= 100
    strs[i] consists of lower-case English letters.
*/

class Solution 
{
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) 
  {
    map<vector<int>, vector<string>> group;
    for(string& s : strs)
    {
      vector<int> freq(26, 0);
      for(char ch : s)
      {
        freq[ch - 'a']++;
      }
      
      group[freq].push_back(s);
    }
    
    vector<vector<string>> ans;
    for(auto p : group)
    {
      ans.push_back(p.second);
    }
    
    return ans;
//     unordered_map<string, vector<string>> anagrams;
//     for(auto& s : strs)
//     {
//       string dup = s;
      
//       sort(dup.begin(), dup.end());
//       anagrams[dup].push_back(s);
//     }
    
//     vector<vector<string>> result;
//     for(auto& p : anagrams)
//     {
//       result.push_back(p.second);
//     }
    
//     return result;
  }
};