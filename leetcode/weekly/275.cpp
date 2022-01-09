/****************************************************
Date: Jan 9, 2022
Successful submissions : 1
Time expiration : 
Not Solved : 2
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/weekly-contest-275
****************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

/*
  Q: 2133. Check if Every Row and Column Contains All Numbers
*/
class Solution1_t
{
public:
  bool checkValid(vector<vector<int>>& matrix) 
  {
    int r = matrix.size();
    int c = matrix[0].size();
    
    for(int i = 0; i < r; ++i)
    {
      unordered_set<int> nums;
      for(int n : matrix[i])
      {
        nums.insert(n);
      }
      
      for(int j = 1; j <= c; ++j)
      {
        if(nums.count(j) == 0)
        {
          return false;
        }
      }
    }
    
    for(int i = 0; i < c; ++i)
    {
      unordered_set<int> nums;
      
      for(int j = 0; j < r; ++j)
      {
        nums.insert(matrix[j][i]);
      }
      
      for(int j = 1; j <= c; ++j)
      {
        if(nums.count(j) == 0)
        {
          return false;
        }
      }
    }
    
    return true;    
  }
};

/*
  Q: 2134. Minimum Swaps to Group All 1's Together II
*/
class Solution2_t 
{
public:
  int minSwaps(vector<int>& nums) 
  {
      
  }
};

/*
  Q: 2135. Count Words Obtained After Adding a Letter
*/

class Solution3_t
{
public:
  int wordCount(vector<string>& startWords, vector<string>& targetWords) 
  {
    int l = startWords.size();
    vector<vector<int>> sw(l, vector<int>(26, 0));
    
    for(int i = 0; i < l; ++i)
    {
      for(char ch : startWords[i])
      {
        sw[i][ch - 'a']++;
      }
    }
    
    int ans = 0;
    for(int i = 0; i < l; ++i)
    {
      vector<int> count(26, 0);
      int chCount = targetWords[i].size();
      
      for(char ch : targetWords[i])
      {
        count[ch - 'a']++;
      }
      
      for(vector<int>& sCount : sw)
      {
        if(chCount == startWords[i].size() + 1)
        {
          int matchCount = 0;
          for(int j = 0; j < 26; ++j)
          {
            if((count[j] > 0) && (sCount[j] == count[j]))
            {
              matchCount++;
            }
          }

          if(matchCount + 1  == chCount)
          {
            ans++;
            break;
          }
        }
      }
    }
    
    return ans;
  }
};

/*
  Q: 2136. Earliest Possible Day of Full Bloom
*/
class Solution4_t 
{
public:
  int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) 
  {
      
  }
};