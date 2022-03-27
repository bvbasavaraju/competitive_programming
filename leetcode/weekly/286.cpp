/****************************************************
Date: Mar 27th, 2022
Successful submissions : 1
Time expiration : 1
Memory exhausted : 0
Not Solved : 2
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/weekly-contest-286
****************************************************/

#include <bits/stdc++.h>
using namespace std;

/*
  Q: 2215. Find the Difference of Two Arrays
*/
class Solution1_t
{
public:
  vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) 
  {
    unordered_map<int, int> freq1;
    for(int n : nums1)
    {
      freq1[n]++;
    }
    
    unordered_map<int, int> freq2;
    for(int n : nums2)
    {
      freq2[n]++;
    }
    
    vector<vector<int>> ans(2);
    for(auto it = freq1.begin(); it != freq1.end(); ++it)
    {
      if(freq2.count(it->first) == 0)
      {
        ans[0].push_back(it->first);
      }
    }
    
    for(auto it = freq2.begin(); it != freq2.end(); ++it)
    {
      if(freq1.count(it->first) == 0)
      {
        ans[1].push_back(it->first);
      }
    }
    
    return ans;
  }
};

/*
  Q: 2216. Minimum Deletions to Make Array Beautiful
*/
class Solution2_t
{
public:
  int minDeletion(vector<int>& nums) 
  {
      
  }
};

/*
  Q: 2217. Find Palindrome With Fixed Length - tried. but resulted in time limit exceeded
*/
class Solution3_t
{
private:
  long long getMin(int n)
  {
    int ans = 1;
    for(int i = 1; i < n; ++i)
    {
      ans = ans * 10;
    }
    
    return ans;
  }
    
  long long getMax(int n)
  {
    int ans = 9;
    for(int i = 1; i < n; ++i)
    {
      ans = (ans * 10) + 9;
    }
    
    return ans;
  }
  
  long long getNum(string s)
  {
    int l = s.size();
    long long ans = 0;
    for(int i = 0; i < l; ++i)
    {
      ans = (ans * 10) + s[i] - '0';
    }
    
    return ans;
  }
  
  void generatePalindrome(vector<string>& pali, int originalLeng, int len, long long maxValue, int count)
  {
    long long mini = getMin(len);
    
    pali.push_back(std::to_string(mini));
    while(pali.size() < count)
    {
      mini++;
      if(mini > maxValue)
      {
        break;
      }
      pali.push_back(std::to_string(mini));
    }
    
    mini = getMin(len);
    for(string& p : pali)
    {
      if((originalLeng % 2) == 0)
      {
        string s = p;
        reverse(s.begin(), s.end());
        
        p = p + s;
      }
      else
      {
        string s = p.substr(0, len-1);
        reverse(s.begin(), s.end());
        
        p = p + s;
      }
    }
  }
  
public:
  vector<long long> kthPalindrome(vector<int>& queries, int intLength) 
  {
    int maxi = INT_MIN;
    for(int& q : queries)
    {
      maxi = max(maxi, q);
    }
    
    vector<string> pali;
    if(intLength % 2 == 0)
    {
      generatePalindrome(pali, intLength, intLength/2, getMax(intLength/2), maxi);
    }
    else
    {
      generatePalindrome(pali, intLength, (intLength/2)+1, getMax((intLength/2)+1), maxi);
    }
    
    vector<long long> ans;
    for(int q : queries)
    {
      if(q > pali.size())
      {
        ans.push_back(-1);
      }
      else
      {
        ans.push_back(getNum(pali[q-1]));
      }
    }
    
    return ans;
  }
};

/*
  Q: 2218. Maximum Value of K Coins From Piles - yet to complete!
*/
class Solution4_t
{
private:
  vector< vector< vector<int> > > cache;
  void getMax(vector<int>& p1, vector<int> p2, int i, int j, int k, int sum, int& ans)
  {
    if((k == 0) || ((i > p1.size()) && (j > p2.size())))
    {
      return ;
    }
    
    if(cache[i][j][k] != -1)
    {
      ans = max(ans, cache[i][j][k]);
      return;
    }
    
    int sum1 = 0;
    int sum2 = 0;
    if(i < p1.size())
    sum1 = sum + p1[i];
    int sum2 = sum + p2[j];
    
    ans = max{ans, sum1, sum2};
    
    cache[i][j][k] = ans;
    
    getMax(p1, p2, i+1, j, sum1, ans);
    getMax(p1, p2, i, j+1, sum2, ans);
  }
  
public:
  int maxValueOfCoins(vector<vector<int>>& piles, int k) 
  {
    
    cache.resize(vector<>)
  }
};
