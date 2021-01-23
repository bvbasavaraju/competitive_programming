/****************************************************
Date: Jan 23rd, 2021
Successful submissions : 1
Time expiration : 1
Not Solved : 2
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/biweekly-contest-43
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
#include <string_view>

using namespace std;

/*
  Q: 1732. Find the Highest Altitude
*/
class Solution1_t
{
public:
  int largestAltitude(vector<int>& gain) 
  {
    int l = gain.size();
    
    int alt = 0;
    int ans = alt;
    for(int i = 0; i < l; ++i)
    {
      alt = alt + gain[i];
      ans = max(ans, alt);
    }
    
    return ans;
  }
};

/*
  Q: 1733. Minimum Number of People to Teach
*/
class Solution2_t 
{
public:
  int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) 
  {
      
  }
};

/*
  Q: 1734. Decode XORed Permutation - time limit exceeded
*/
class Solution3_t
{
private:
  bool decode(const vector<int>& encoded, int l, int val, int p, vector<int>& ans)
  {
    if(p >= l)
    {
      return true;
    }
    
    if((val > l) || (val <= 0) || (ans[p-1] > l) || (ans[p-1] <= 0))
    {
      return false;
    }
    
    ans[p] = val ^ encoded[p-1];
    
    return decode(encoded, l, ans[p], p+1, ans);
  }
public:
  vector<int> decode(vector<int>& encoded) 
  {
    int l = encoded.size();
    
    vector<int> ans(l+1, 0);
    
    for(int i = 1; (i <= l) && (ans[l] == 0); ++i)
    {
      ans[0] = i;
      /*if(decode(encoded, l+1, i, 1, ans))
      {
        break;
      }*/
      for(int j = 0; j < l; ++j)
      {
        ans[j+1] = ans[j] ^ encoded[j];
        if((ans[j+1] > (l + 1)) || (ans[j+1] ==0))
        {
          break;
        }
      }
    }
    
    return ans;
  }
};

/*
  Q: 1735. Count Ways to Make Array With Product
*/
class Solution4_t
{
public:
    vector<int> waysToFillArray(vector<vector<int>>& queries) 
    {
        
    }
};
