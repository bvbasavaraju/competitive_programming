/****************************************************
Date: May 16th, 2021
Successful submissions : 1
Time expiration : 0
Not Solved : 3
Wrong Answer/ Partial result : 0

note: 2 problems solved as submitted after looking at solution

link: https://leetcode.com/contest/weekly-contest-241
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
  Q: 1863. Sum of All Subset XOR Totals 
*/
class Solution1_t
{
private:
  int getSum(vector<int>& nums, int p, int xored_val)
  {
    if(p >= nums.size())
    {
      return 0;
    }
    
    return ((nums[p] ^ xored_val) + getSum(nums, p+1, (nums[p] ^ xored_val))) + getSum(nums, p+1, xored_val);
  }
public:
  int subsetXORSum(vector<int>& nums) 
  {
    return getSum(nums, 0, 0);
  }
};

/*
  Q: 1864. Minimum Number of Swaps to Make the Binary String Alternating
*/
class Solution2_t
{
private:
  int getCount(string& str, int s, int e)
  {
    int i = 0;
    int j = 0;
    int l = str.size()-1;
    int ans = 0;
    
    while(i <= (l-j))
    {
      if((i%2 == 0 && str[i] == s) || (i%2 != 0 && str[i] != s))
      {
        ++i;
      }
      else if((j%2 == 0 && str[l-j] == e) || (j%2 != 0 && str[l-j] != e))
      {
        ++j;
      }
      else
      {
        ans++;
        ++i;
        ++j;
      }
    }
    
    return ans;
  }
public:
  int minSwaps(string s) 
  {
    vector<int> count(2, 0);
    for(char ch : s)
    {
      count[ch-'0']++;
    }
    
    int l = s.size();
    if(((l % 2 == 0) && (count[0] != count[1])) || abs(count[0] - count[1]) > 1)
    {
      return -1;
    }
    
    if(l%2 != 0)
    {
      return getCount(s, count[0] > count[1] ? '0' : '1', count[0] > count[1] ? '0' : '1');
    }
    
    return min(getCount(s, '0', '1'), getCount(s, '1', '0'));
  }
};

/*
  Q: 1865. Finding Pairs With a Certain Sum
*/
class FindSumPairs 
{
private:
  vector<int> n1;
  vector<int> n2;
  
  unordered_map<int, int> freq;
public:
  FindSumPairs(vector<int>& nums1, vector<int>& nums2) 
    : n1(nums1),
      n2(nums2)
  { 
    for(int n : nums2)
    {
      freq[n]++;
    }
  }

  void add(int index, int val) 
  {
    freq[n2[index]]--;
    n2[index] += val;
    freq[n2[index]]++;
  }

  int count(int tot) 
  {
    int ans = 0;
    for(int n : n1)
    {
      int count = freq.count(tot-n);
      if(count > 0)
      {
        ans += freq[tot-n];
      }
    }
    
    return ans;
  }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */

/*
  Q: 1866. Number of Ways to Rearrange Sticks With K Sticks Visible
*/

class Solution4_t
{
public:
  int rearrangeSticks(int n, int k) 
  {
    
  }
};