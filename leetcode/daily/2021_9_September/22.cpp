/****************************************************
Date: September 22th

https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/639/week-4-september-22nd-september-28th/3984/
****************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <limits.h>

using namespace std;

/*
  Q: 
*/

class Solution 
{
// private:
//   bool isStillUnique(vector<int>& freq, string& s)
//   {
//     bool retVal = true;
//     for(char ch : s)
//     {
//       freq[ch-'a']++;
//       if(retVal)
//       {
//         retVal = freq[ch-'a'] == 1;
//       }
//     }
    
//     return retVal;
//   }
  
//   void removeString(vector<int>& freq, string& s)
//   {
//     for(char ch : s)
//     {
//       freq[ch-'a']--;
//     }
//   }
  
public:
  int maxLength(vector<string>& arr) 
  {
    //Resulting in wrong, in edge conditions
    // int ans = 0;
    // int l = arr.size();
    // for(int i = 0; i < l; ++i)
    // {
    //   int len = arr[i].size();
    //   vector<int> freq(26, 0);
    //   isStillUnique(freq, arr[i]);
      
    //   for(int j = i+1; j < l; ++j)
    //   {
    //     if(!isStillUnique(freq, arr[j]))
    //     {
    //       removeString(freq, arr[j]);
    //     }
    //     else
    //     {
    //       len += arr[j].size();
    //     }
    //   }
      
    //   ans = max(ans, len);
    // }
    
    // return ans;

    int ans = 0;
    vector< bitset<26> > dp = {bitset<26>()};
    for(string& s : arr)
    {
      bitset<26> freq;
      for(char ch : s)
      {
        freq.set(ch-'a');
      }
      int count = freq.count();
      if(count < s.size())
      {
        continue;
      }
      
      for(int i = dp.size()-1; i >= 0; --i)
      {
        bitset current = dp[i];
        if((current & freq).any())
        {
          continue;
        }
        
        dp.push_back(current | freq);
        ans = max(ans, static_cast<int>(current.count()) + count);
      }
    }
    
    return ans;
  }
};

int main()
{
  vector<string> v = {"un","iq","ue"};
  Solution s;
  s.maxLength(v);
  return 0;
}