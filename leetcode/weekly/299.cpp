/****************************************************
Date: June 26th, 2022
Successful submissions : 2
Time expiration : 0
Memory exhausted : 0
Not Solved : 1
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/weekly-contest-299
****************************************************/

#include<bits/stdc++.h>
using namespace std;

/*
  Q: 2319. Check if Matrix Is X-Matrix
*/
class Solution1_t
{
public:
  bool checkXMatrix(vector<vector<int>>& grid) 
  {
    int r = grid.size();
    int c = grid[0].size();
    
    for(int i = 0; i < r; ++i)
    {
      for(int j = 0; j < c; ++j)
      {
        if((i == j) || (j == (r - 1 - i)))
        {
          if(grid[i][j] == 0)
          {
            return false;
          }
          continue;
        }
        else if(grid[i][j] != 0)
        {
          return false;
        }
      }
    }
    
    return true;
  }
};

/*
  Q: 2320. Count Number of Ways to Place Houses
*/
class Solution2_t
{
public:
  int countHousePlacements(int n) 
  {
    const int MOD = 1e9+7;
    
    if(n == 1)
    {
      return 4;
    }
    
    vector<long long> numOfHousesOneSide(n+1, 0);
    numOfHousesOneSide[0] = 1;
    numOfHousesOneSide[1] = 2;
    
    for(int i = 2; i <=n; ++i)
    {
      numOfHousesOneSide[i] = ((numOfHousesOneSide[i-1] % MOD) + (numOfHousesOneSide[i-2] % MOD)) % MOD;
    }
    
    return ((numOfHousesOneSide[n] % MOD) * (numOfHousesOneSide[n] % MOD)) % MOD;
  }
};

/*
  Q: 2321. Maximum Score Of Spliced Array
*/
class Solution3_t
{
private:
  int getMaxSubArraySum(const vector<int>& n1, const vector<int>& n2)
  {
    int sum = 0;
    int ans = 0;
    int l = n1.size();
    for(int i = 0; i < l; ++i)
    {
      sum = max(n2[i]-n1[i], sum + n2[i]-n1[i]);
      ans = max(ans, sum);
    }
    
    return ans;
  }
public:
  int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) 
  {
    int l = nums1.size();
    
    int sum1 = 0;
    int sum2 = 0;
    for(int i = 0; i < l; ++i)
    {
      sum1 += nums1[i];
      sum2 += nums2[i];
    }
    
    return max(sum1 + getMaxSubArraySum(nums1, nums2), sum2 + getMaxSubArraySum(nums2, nums1));
  }
};

/*
  Q: 2322. Minimum Score After Removals on a Tree
*/
class Solution4_t
{
public:
  int minimumScore(vector<int>& nums, vector<vector<int>>& edges) 
  {
      
  }
};