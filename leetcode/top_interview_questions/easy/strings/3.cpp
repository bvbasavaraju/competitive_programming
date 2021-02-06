#include <iostream>

using namespace std;

/*
  Q: First Unique Character in a String

  Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.

  Examples:
    s = "leetcode"
    return 0.

    s = "loveleetcode"
    return 2.

  Note: You may assume the string contains only lowercase English letters.
*/

class Solution 
{
public:
  int firstUniqChar(string s) 
  {
    unordered_map<int, int> freq;
    for(auto ch : s)
    {
      freq[ch]++;
    }
    
    int l = s.size();
    for(int i = 0; i < l; ++i)
    {
      if(freq[s[i]] == 1)
      {
        return i;
      }
    }
    
    return -1;
//     int i = 0;
//     unordered_map<int, pair<int, int>> freq;
//     for(auto ch : s)
//     {
//       if(freq.count(ch) <= 0)
//       {
//         freq[ch] = std::make_pair(1, i);
//       }
//       else
//       {
//         freq[ch].first++;
//       }
//       i++;
//     }
    
//     int ans = INT_MAX;
//     for(auto it = freq.begin(); it != freq.end(); ++it)
//     {
//       if(it->second.first == 1)
//       {
//         ans = min(ans, it->second.second);
//       }
//     }
    
//     return ans == INT_MAX ? -1 : ans;
    /*int i = 0;
    unordered_map<int, int> freq;
    unordered_map<int, int> pos_map;
    for(auto ch : s)
    {
      freq[ch]++;
      if(pos_map.count(ch) <= 0)
      {
        pos_map[ch] = i;
      }
      i++;
    }
    
    int ans = INT_MAX;
    for(auto it = freq.begin(); it != freq.end(); ++it)
    {
      if(it->second == 1)
      {
        ans = min(ans, pos_map[it->first]);
      }
    }
    
    return ans == INT_MAX ? -1 : ans;*/
  }
};