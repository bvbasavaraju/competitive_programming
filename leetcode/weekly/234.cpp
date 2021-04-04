/****************************************************
Date: Mar 28th, 2021
Successful submissions : 3
Time expiration : 0
Not Solved : 1
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/weekly-contest-234
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
  Q: 1805. Number of Different Integers in a String
*/
class Solution1_t
{
public:
  int numDifferentIntegers(string word) 
  {
    unordered_set<string> nums;
    
    bool addNum = false;
    string num = "0";
    int l = word.size();
    for(int i = 0; i < l; ++i)
    {
      if(word[i] >= '0' && word[i] <= '9')
      {
        num = (word[i] == '0' && num == "0") ? num : ((num == "0") ? (std::to_string(word[i]-'0')) : (num + word[i]));
        addNum = true;
      }
      else
      {
        if(addNum)
        {
          nums.insert(num);
        }
        num = "0";
        addNum = false;
      }
    }
    
    if(addNum)
    {
      nums.insert(num);
    }
    
    return nums.size();
  }
};

/*
  Q: 1806. Minimum Number of Operations to Reinitialize a Permutation
*/
class Solution2_t
{
private:
  void reArrange(int n, vector<int>& perm)
  {
    vector<int> nums = perm;
    for(int i = 1; i < n-1; ++i)
    {
      if(i%2 == 0)
      {
        perm[i] = nums[i/2];
      }
      else
      {
        perm[i] = nums[(n/2) + (i-1)/2];
      }
    }
  }
public:
  int reinitializePermutation(int n) 
  {
    vector<int> perm(n);
    for(int i = 0; i < n; ++i)
    {
      perm[i] = i;
    }
    
    int ans = 0;
    bool done = true;
    do
    {
      reArrange(n, perm);  
      ans++;
      
      done = true;
      for(int i = 0; i < n; ++i)
      {
        if(perm[i] != i)
        {
          done = false;
          break;
        }
      }
    } while(!done);
    
    return ans;
  }
};

/*
  Q: 1807. Evaluate the Bracket Pairs of a String
*/
class Solution3_t
{
public:
  string evaluate(string s, vector<vector<string>>& knowledge) 
  {
    unordered_map<string, string> kt;
    for(vector<string>& k : knowledge)
    {
      kt[k[0]] = k[1];
    }
    
    string ans = "";
    string key = "";
    bool startRecordingKey = false;
    for(char& ch : s)
    {
      if(ch == '(')
      {
        startRecordingKey = true;
      }
      else if(ch == ')')
      {
        ans += kt.find(key) == kt.end() ? "?" : kt[key];
        
        key = "";
        startRecordingKey = false;
      }
      else
      {
        if(startRecordingKey)
        {
          key += ch;
        }
        else
        {
          ans += ch;
        }
      }
    }
    
    return ans;
  }
};

/*  
  Q: 1808. Maximize Number of Nice Divisors
*/
class Solution4_t
{
public:
  int maxNiceDivisors(int primeFactors) 
  {
    
  }
};