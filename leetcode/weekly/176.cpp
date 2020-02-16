/****************************************************
Date: Feb 16, 2020
Successful submissions : 2
Time expiration : 0
Not Solved : 2
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/biweekly-contest-176
****************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;

/*
    Q:  1351. Count Negative Numbers in a Sorted Matrix
 */
class Solution1_t
{
public:
  int countNegatives(vector<vector<int>>& m) 
  {
    int r = m.size();
    int c = m[0].size();
    
    int result = 0;
    for(int i = r - 1; i >= 0; --i)
    {
      for(int j = c - 1; j >= 0; --j)
      {
        if(m[i][j] < 0)
        {
          result++;
        }
        else
        {
          break;
        }
      }
    }
    
    return result;
  }
};

/*
    Q:  1352. Product of the Last K Numbers
 */
/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
class ProductOfNumbers_t
{
private:
  bool hasZero;
  int zeroPosFromLast;
  vector<int> nums;
  
public:
  ProductOfNumbers_t() 
    : hasZero(false),
      zeroPosFromLast(-1)
  {
  }

  void add(int num) 
  {
    nums.push_back(num);
    
    if(num == 0)
    {
      hasZero = true;
      zeroPosFromLast = 1;
    }
    else if(hasZero)
    {
      zeroPosFromLast++;
    }
  }

  int getProduct(int k) 
  {
    if((hasZero && (zeroPosFromLast <= k)) || (nums.size() == 0))
    {
      return 0;
    }
    
    int count = 0; 
    int result = 1;
    for(int i = nums.size() - 1; i >= 0; --i)
    {
      result *= nums[i];
      count++;
      
      if(count >= k)
      {
        break;
      }
    }
    
    return result;
  }
};

/*
    Q:  1353. Maximum Number of Events That Can Be Attended
 */
class Solution3_t 
{
public:
    int maxEvents(vector<vector<int>>& events) 
    {
        
    }
};

/*
    Q:  1354. Construct Target Array With Multiple Sums - Not solved yet!!
 */
class Solution4_t
{
private:
  int targetSum;
  bool sumMatched;
  
  bool CanProduce(vector<int>& s, int maxVal, int length, int pos, int lastSum)
  {
    //printf("%d\n", lastSum);
    
    if(sumMatched)
    {
      return true;
    }
    
    if(lastSum > maxVal)
    {
      return false;
    }
    
    int sum = 0;
    s[pos] = lastSum;
    for(int i = 0; i < length; i++)
    {
      sum += s[i];
    }
    
    if(sum == targetSum)
    {
      sumMatched = true;
      return true;
    }
    
    if(sum > maxVal)
    {
      return false;
    }
    
    return CanProduce(s, maxVal, length, (pos + 1) % length, sum);
  }
  
public:
  bool isPossible(vector<int>& target) 
  {
    int l = target.size();

    targetSum = 0;
    sumMatched = false;
    int maxVal = 0;
    for(int i = 0; i < l; ++i)
    {
      targetSum += target[i];
      maxVal = max(maxVal, target[i]);
    }
    
    if(l >= maxVal)
    {
      return false;
    }
    
    //printf("%d, %d\n", maxVal, targetSum);
    vector<int> s(l, 1);
    return CanProduce(s, maxVal, l, 0, l);
  }
};