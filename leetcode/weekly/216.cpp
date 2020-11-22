/****************************************************
Date: Nov 22nd, 2020
Successful submissions : 2
Time expiration : 0
Not Solved : 1
Wrong Answer/ Partial result : 1
link: https://leetcode.com/contest/weekly-contest-216
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
#include <limits.h>

using namespace std;

/*
    Q: 1662. Check If Two String Arrays are Equivalent
*/  
class Solution1_t
{
public:
  bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) 
  {
    string w1 = "";
    int l = word1.size();
    for(int i = 0; i < l; ++i)
    {
      w1 += word1[i];
    }
    
    string w2 = "";
    l = word2.size();
    for(int i = 0; i < l; ++i)
    {
      w2 += word2[i];
    }
    
    return (w1 == w2);
  }
};

/*
    Q: 1663. Smallest String With A Given Numeric Value
*/
class Solution2_t
{
private:
  void appendZed(int count, string& ans)
  {
    while(count > 0)
    {
      ans += 'z';
      count--;
    }
  }
  
public:
  string getSmallestString(int n, int k) 
  {
    string ans = "";
    //int p = 0;
    
    if(k / n >= 26)
    {
      appendZed(n, ans);
    }
    else
    {
      while(n > 0)
      {
        if(n > 1)
        {
          int val = 0;
          do
          {
            val++;
          } while((double)(k-val)/(double)(n-1) > (double)26.0);

          if((k - val)/(n-1) < 26)
          {
            ans += (val-1) + 'a';
            n--;
            k = k-val;
          }
          else if((k - val)/(n-1) == 26)
          {
            ans += (val-1) + 'a';
            appendZed(n-1, ans);
            break;
          }          
        }
        else
        {
          ans += (k-1) + 'a';
          break;
        }
      }
    }
    
    return ans;
  }
};

/*
    Q: 1664. Ways to Make a Fair Array - partial / wrong!
*/
class Solution3_t
{
public:
  int waysToMakeFair(vector<int>& nums) 
  {
    int tes = 0;
    int tos = 0;
    
    
    int l = nums.size();
    vector<vector<int>> eos(l+1, vector<int>(4, 0));
    for(int i = 0; i < l; ++i)
    {
      if(i%2 == 0)
      {
        tes += nums[i];
      }
      else
      {
        tos += nums[i];
      }
      
      if(i > 0)
      {
        if((i-1) % 2 == 0)
        {
          eos[i+1][2] += nums[i-1];
        }
        else
        {
          eos[i+1][3] += nums[i-1];
        }
      }
    }
    
    eos[0][0] = tes;
    eos[0][1] = tos;
    for(int i = 0; i < l; ++i)
    {
      int res = eos[i][0];
      int ros = eos[i][1];
      
      res -= nums[i];
      
      eos[i+1][0] = ros;
      eos[i+1][1] = res;
    }
    
    int ans = 0;
    for(int i = 1; i <= l; ++i)
    {
      if(i%2 == 0)
      {
        if((eos[i][2] + eos[i][1]) == (eos[i][3] + eos[i][0]))
        {
          ans++;
        }
      }
      else
      {
        if((eos[i][0] + eos[i][2]) == (eos[i][1] + eos[i][3]))
        {
          ans++;
        }
      }
    }
    
    return ans;
  }
};

/*
    Q: 1665. Minimum Initial Energy to Finish Tasks
*/
class Solution4_t
{
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        
    }
};