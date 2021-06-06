/****************************************************
Date: June 6th, 2021
Successful submissions : 2
Time expiration : 0
Not Solved : 1
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/weekly-contest-244
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
  Q: 1886. Determine Whether Matrix Can Be Obtained By Rotation
*/
class Solution1_t
{
private:
  void rotateMatrix(vector<vector<int>>& mat, vector<vector<int>>& rotated)
  {
    int r = mat.size();
    
    for(int l = 0; l < r; ++l)
    {
      int c = r-l-1;
      vector<int> row = mat[l];
      for(int i = 0; i < r; ++i)
      {
        rotated[i][c] = row[i];
      }
    }
  }
public:
  bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) 
  {
    int count = mat.size();
    vector<vector<int>> rotated(count, vector<int>(count,0));
    
    for(int i = 0; i < 4; ++i)
    {
      rotateMatrix(mat, rotated);
      if(rotated == target)
      {
        return true;
      }
      
      mat = rotated;
    }
    
    return false;
  }
};

/*
  Q: 1887. Reduction Operations to Make the Array Elements Equal
*/
class Solution2_t
{
public:
  int reductionOperations(vector<int>& nums) 
  {
    priority_queue<int> uniques;
    unordered_map<int, int> freq;
    for(int n : nums)
    {
      freq[n]++;
      if(freq[n] == 1)
      {
        uniques.push(n);
      }
    }
    
    int ans = 0;
    while(uniques.size() > 1)
    {
      int l = uniques.top();
      uniques.pop();
      int nl = uniques.top();

      int count = freq[l];
      freq[l] = 0;
      ans += count;

      freq[nl] = freq[nl] + count;
    }
    
    return ans;
  }
};

/*
  Q: 1888. Minimum Number of Flips to Make the Binary String Alternating - wrong answer
*/
class Solution3_t
{
public:
  int minFlips(string s) 
  {
    int l = s.size();
    
    if(l <= 1)
    {
      return 0;
    }
    
    int i = 0;
    while(s[i] == s[i+1])
    {
      s = s.substr(1) + s[i];
    }
    
    i = i+2;
    int ans = 0;
    for(; i < l; ++i)
    {
      if(s[i] == s[i-1])
      {
        s[i] = (s[i-1] == '0') ? '1' : '0';
        ans++;
      }
    }
    
    return ans;
  }
};

/*
  Q: 1889. Minimum Space Wasted From Packaging
*/
class Solution4_t
{
public:
  int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) 
  {
      
  }
};