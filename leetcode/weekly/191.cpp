
/****************************************************
Date: May 31th, 2020
Successful submissions : 1
Time expiration : 1
Not Solved : 1
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/weekly-contest-191
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
  Q: 1464. Maximum Product of Two Elements in an Array
*/
class Solution1_t 
{
public:
  int maxProduct(vector<int>& nums) 
  {
    sort(nums.begin(), nums.end());
    
    int l = nums.size();
    
    return (nums[l-1] - 1) * (nums[l-2] - 1);
  }
};

/*
  Q: 1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts - time limit exceeded
*/
class Solution2_1 
{
public:
  int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) 
  {
    const int MOD = 1000000007;
    hc.push_back(h);
    vc.push_back(w);
    
    sort(hc.begin(), hc.end());
    sort(vc.begin(), vc.end());
    
    int lh = hc.size();
    int lc = vc.size();
    
    int ans = 0;
    vector<vector<int>> a(lh, vector<int>(lc, 0));
    vector<vector<int>> p(lh, vector<int>(lc, 0));
    for(int i = 0; i < lh; ++i)
    {
      int row_sum = 0;
      for(int j = 0; j < lc; ++j)
      {
        p[i][j] = ((hc[i] % MOD) * (vc[j] % MOD)) % MOD;
        
        if(i == 0 && j == 0)
        {
          a[i][j] = p[i][j];
        }
        else if(j == 0)
        {
          
          a[i][j] = (((p[i][j] - p[i-1][j]) % MOD ) + MOD) % MOD;
        }
        else if(i == 0)
        {
          a[i][j] = (((p[i][j] - p[i][j-1]) % MOD ) + MOD) % MOD;
        }
        else
        {
          a[i][j] = ((((((p[i][j] - p[i-1][j]) % MOD ) + MOD ) % MOD - row_sum) % MOD) + MOD ) % MOD;
        }
        
        row_sum = (row_sum + a[i][j]) % MOD;
        ans = max(ans, a[i][j]);
      }
    }
    
    return ans;
  }
};

/*
  Q: 1466. Reorder Routes to Make All Paths Lead to the City Zero
*/
class Solution3_t 
{
private:
  bool isReachable(int source, vector<bool>& v, unordered_map<int, vector<int>>& source_dest_map)
  {
    if(source == 0)
    {
      return true;
    }
    
    v[source] = true;
    for(auto s : source_dest_map[source])
    {
      if(isReachable(s, v, source_dest_map))
      {
        v[source] = false;
        return true;
      }
    }
    
    v[source] = false;
    return false;
  }
  
public:
  int minReorder(int n, vector<vector<int>>& connections) 
  {
    unordered_map<int, vector<int>> source_dest_map;
    unordered_map<int, vector<int>> dest_source_map;
    for(auto c : connections)
    {
      source_dest_map[c[0]].push_back(c[1]);
      dest_source_map[c[1]].push_back(c[0]);
    }
    
    int ans = 0;
    vector<bool> v(n, false);
    for(int i = 1; i < n; ++i)
    {
      if(!isReachable(i, v, source_dest_map))
      {
        if(dest_source_map.find(i) != dest_source_map.end() && dest_source_map[i].size() > 0)
        {
          source_dest_map[i].push_back(dest_source_map[i][0]);
        }
        
        ans++;
      }
    }
    
    return ans;
  }
};

/*
  Q: 1467. Probability of a Two Boxes Having The Same Number of Distinct Balls
*/
class Solution4_t
{
public:
  double getProbability(vector<int>& balls) 
  {
      return 0.0;
  }
};

int main()
{
  {
    Solution2_1 s2;
    vector<int> h = {1,2,4};
    vector<int> v = {1,3};
    cout << s2.maxArea(5, 4, h, v) << endl;
  }

  return 0;
}