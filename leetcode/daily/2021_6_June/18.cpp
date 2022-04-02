/****************************************************
Date: June 18th

link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/605/week-3-june-15th-june-21st/3781/
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
  Q: 
*/
class NumArray 
{
private:
  vector<int> nums; 
  vector<int> sum;
public:
  NumArray(vector<int>& nums_) 
    : nums(nums_.begin(), nums_.end())
  {
    sum.push_back(nums[0]);
    for(int i = 1; i < nums.size(); ++i)
    {
      sum.push_back(sum.back() + nums[i]);
    }
  }

  void update(int index, int val) 
  {
    int old_val = nums[index];
    
    sum[index] += val - nums[index];
    for(int i = index+1; i < nums.size(); ++i)
    {
      sum[i] = sum[i-1] + nums[i];
    }
  }

  int sumRange(int left, int right) 
  {
    return sum[right] - (left > 0 ? sum[left-1] : 0);
  }
};

int main()
{
  vector<int> nums = {5,18,13};
  NumArray s(nums);
  s.sumRange(0,2);
  s.update(1,-1);
  s.update(2,3);
  s.update(0,5);
  s.update(0,-4);
  s.sumRange(0,2);

  return 0;
}