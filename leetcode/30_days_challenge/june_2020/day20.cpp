/****************************************************
Date: June 20th

link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/541/week-3-june-15th-june-21st/3366/
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
  Q: Permutation Sequence

  The set [1,2,3,...,n] contains a total of n! unique permutations.

  By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

  "123"
  "132"
  "213"
  "231"
  "312"
  "321"
  Given n and k, return the kth permutation sequence.

  Note:

  Given n will be between 1 and 9 inclusive.
  Given k will be between 1 and n! inclusive.
  Example 1:

  Input: n = 3, k = 3
  Output: "213"
  Example 2:

  Input: n = 4, k = 9
  Output: "2314"
*/

class Solution 
{
private:
  
  void getNum(vector<int>& fact, string& nums, int n, int k, string& ans)
  {
    if(n == 1)
    {
      ans += nums[0];
      return;
    }
    
    int index = k / fact[n-1];
    if(k % fact[n-1] == 0)
    {
      index--;
    }
    
    ans += nums[index];
    
    nums.erase(nums.begin() + index);
    
    k = k - (index * fact[n-1]);
    return getNum(fact, nums, n - 1, k, ans);
  }
  
public:
  string getPermutation(int n, int k) 
  {
    string nums = "";
    vector<int> fact(10, 1);
    
    for(int i = 1; i <= 9; ++i)
    {
      fact[i] = i * fact[i-1];
      nums.push_back(i + '0');
    }
    
    string ans = "";
    getNum(fact, nums, n, k, ans);
    return ans;
  }
};