#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
  Q: Two Sum

  Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
  You may assume that each input would have exactly one solution, and you may not use the same element twice.
  You can return the answer in any order.

  Example 1:
    Input: nums = [2,7,11,15], target = 9
    Output: [0,1]
    Output: 
      Because nums[0] + nums[1] == 9, we return [0, 1].

  Example 2:
    Input: nums = [3,2,4], target = 6
    Output: [1,2]

  Example 3:
    Input: nums = [3,3], target = 6
    Output: [0,1]

  Constraints:
    2 <= nums.length <= 103
    -109 <= nums[i] <= 109
    -109 <= target <= 109
    Only one valid answer exists.

  Hide Hint #1  
    A really brute force way would be to search for all possible pairs of numbers but that would be too slow. 
    Again, it's best to try out brute force solutions for just for completeness. 
    It is from these brute force solutions that you can come up with optimizations.
  
  Hide Hint #2  
    So, if we fix one of the numbers, say
    x, 
    we have to scan the entire array to find the next number
    y
    which is
    value - x
    where value is the input parameter. Can we change our array somehow so that this search becomes faster?
  
  Hide Hint #3  
    The second train of thought is, without changing the array, can we use additional space somehow? 
    Like maybe a hash map to speed up the search?
*/

class Solution 
{
private:
  int getPos(const vector<int>& nums, int l, int h, int t)
  {    
    while(l <= h)
    {
      int m = l + (h-l)/2;
      
      if(nums[m] == t)
      {
        return m;
      }
      
      if(nums[m] > t)
      {
        h = m-1;
      }
      else
      {
        l = m+1;
      }
    }
    
    return -1;
  }
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    //Solution - O(2n)
    unordered_map<int, queue<int>> nums_pos;
    
    int i = 0;
    for(int n : nums)
    {
      nums_pos[n].push(i);
      i++;
    }
    
    int l = nums.size();
  
    vector<int> ans(2);
    for(i = 0; i < l-1; ++i)
    {
      ans[0] = nums_pos[nums[i]].front();
      nums_pos[nums[i]].pop();  // as we count use the same number position twice;
      
      int t = target - nums[i];
      if(!nums_pos[t].empty())
      {
        ans[1] = nums_pos[t].front();
        break;
      }
      
      nums_pos[nums[i]].push(i);  // as reminder not found, put it back to the container
    }
    
    return ans;
//     //Solution - O(n + 2nlogn)
//     unordered_map<int, queue<int> > org_positions;
//     int i = 0;
//     for(int n : nums)
//     {
//       org_positions[n].push(i);
//       i++;
//     }
    
//     sort(nums.begin(), nums.end());
    
//     int l = nums.size();
    
//     vector<int> ans(2);
//     for(i = 0; i < l; ++i)
//     {
//       int p = getPos(nums, i+1, l-1, target-nums[i]);
      
//       if(p > -1)
//       {        
//         ans[0] = org_positions[nums[i]].front();
//         org_positions[nums[i]].pop();
        
//         ans[1] = org_positions[nums[p]].front();
//         break;
//       }
//     }
    
//     return ans;
    
//    O(n*n) - solution
//       int length = nums.size();

//       vector<int> retVal;
//       for (int i = 0; i < length - 1; i++)
//       {
//           for (int j = (i + 1); j < length; j++)
//           {
//               if ((nums[i] + nums[j]) == target)
//               {
//                   retVal.push_back(i);
//                   retVal.push_back(j);

//                   return retVal;
//               }
//           }
//       }

//       return retVal;
  }
};