/****************************************************
Date: March 5, 2022
Successful submissions : 2
Time expiration : 0
Not Solved : 2
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/biweekly-contest-73
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
  Q: 2190. Most Frequent Number Following Key In an Array
*/
class Solution1_t
{
public:
  int mostFrequent(vector<int>& nums, int key) 
  {
    unordered_map<int, int> freq;
    for(int n : nums)
    {
      freq[n]++;
    }
    
    int ans = INT_MIN;
    int mFreq = INT_MIN;
    int l = nums.size();
    for(int i = 0; i < l-1; ++i)
    {
      int k = nums[i];
      int t = nums[i+1];
      
      freq[k]--;
      if(k == key)
      {
        if(mFreq <= freq[t])
        {
          ans = t;
          mFreq = freq[t];
        }
      }
    }
    
    return ans;
  }
};

/*
  Q: 2191. Sort the Jumbled Numbers
*/
class Solution2_t
{
private:
  int getMappedNum(vector<int>& mapping, int num)
  {
    string numS = "" + std::to_string(num);
    
    int ans = 0;
    for(int n : numS)
    {
      ans = ans * 10 + mapping[n-'0'];
    }
    
    return ans;
  }
public:
  vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) 
  {
    int l = nums.size();
    unordered_map< int, queue<int> > mappedNums;
    
    vector<int> nums_;
    for(int n : nums)
    {
      int mn = getMappedNum(mapping, n);
      
      mappedNums[mn].push(n);
      nums_.push_back(mn);
    }
    
    sort(nums_.begin(), nums_.end());
    vector<int> ans;
    for(int n : nums_)
    {
      ans.push_back(mappedNums[n].front());
      mappedNums[n].pop();
    }
    
    return ans;
  }
};

/*
  Q: 2192. All Ancestors of a Node in a Directed Acyclic Graph - not complete
*/
class Solution3_t
{
private:
  vector<int> getFamilyHistory(vector<int> vector< vector<int> >& ans)
    
public:
  vector<vector<int>> getAncestors(int n, vector< vector<int> >& edges) 
  {
    unodered_map<int, vector<int>> fh;
    for(vector<int>& e : edges)
    {
      fh[e[1]].push_back(e[0]);
    }
   
    vector< vector<int> > ans(n);
    for(int i = 0; i < n; ++i)
    {
      vector<int> h = fh[i];
      
    }
  }
};

/*
  Q: 2193. Minimum Number of Moves to Make Palindrome - not complete
*/
class Solution4_t
{
private:
  bool isPalindrome(string str, int l)
  {
    for(int i = 0; i < l/2; ++i)
    {
      if(str[i] != str[l-1-i])
      {
        return false;
      }
    }
    
    return true;
  }
  
  int getCount(string str, int p, int l, int count)
  {
    if(p >= l-1)
    {
      return INT_MAX;
    }
    
    if(isPalindrome(str, l))
    {
      return count;
    }
    
    string s1 = str;
    int ch = str[p];
    str[p] = str[p+1];
    str[p+1] = ch;
    
    return min(getCount(str, p+1, l, count+1), getCount(s1, p+1, l, count));
  }
public:
  int minMovesToMakePalindrome(string s) 
  {
    int l = s.size();
    int ans = INT_MAX;
    for(int i = 0; i < l-1; ++i)
    {
      int count = 0;
      ans = min(ans, getCount(s, i, l, count));
    }
    
    return ans;
  }
};