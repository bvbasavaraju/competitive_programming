#include <iostream>
#include <vector>

using namespace std;

/*
  Q: 3Sum

  Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
  Find all unique triplets in the array which gives the sum of zero.

  Notice that the solution set must not contain duplicate triplets.

  Example 1:
    Input: nums = [-1,0,1,2,-1,-4]
    Output: [[-1,-1,2],[-1,0,1]]

  Example 2:
    Input: nums = []
    Output: []

  Example 3:
    Input: nums = [0]
    Output: []

  Constraints:
    0 <= nums.length <= 3000
    -105 <= nums[i] <= 105

  Hide Hint #1  
    So, we essentially need to find three numbers x, y, and z such that they add up to the given value. 
    If we fix one of the numbers say x, we are left with the two-sum problem at hand!
  
  Hide Hint #2  
    For the two-sum problem, if we fix one of the numbers, say
    x
    , we have to scan the entire array to find the next number
    y
    which is
    value - x
    where value is the input parameter. Can we change our array somehow so that this search becomes faster?
  
  Hide Hint #3  
    The second train of thought for two-sum is, without changing the array, 
    can we use additional space somehow? Like maybe a hash map to speed up the search?
*/

class Solution 
{
// private:
//   bool isTargetPresent(vector<int>& nums, int s, int e, int target)
//   {
//     while(s <= e)
//     {
//       int m = s + (e-s)/2;
      
//       if(nums[m] == target)
//       {
//         return true;
//       }
//       else if(nums[m] > target)
//       {
//         e = m - 1;
//       }
//       else
//       {
//         s = m + 1;
//       }
//     }
    
//     return false;
//   }
  
public:
  vector<vector<int>> threeSum(vector<int>& nums) 
  {
    //sort(n.begin(), n.end());
    
    unordered_map<int, int> freq;
    for(int n_ : nums)
    {
      if(freq[n_] < 3)
      {
        freq[n_]++;
      }
    }
    
    vector<int> n;
    for(auto it : freq)
    {
      while(it.second > 0)
      {
        n.push_back(it.first);
        it.second--;
      }
    }
    
    int l = n.size();
    vector<vector<int>> ans;
    set<vector<int>> combs;
    for(int i = 0; i < l-1; ++i)
    {
      if(freq[n[i]] <= 0)
      {
        continue;
      }
      
      freq[n[i]]--;
      
      int t1 = 0 - n[i];
      for(int j = i+1; j < l; ++j)
      {
        if(freq[n[j]] <= 0)
        {
          continue;
        }
        
        freq[n[j]]--;
        
        int t2 = t1 - n[j];
        if(freq[t2] > 0)
        {
          //freq[t2]--;
          int mini = min({n[i], n[j], t2});
          int maxi = max({n[i], n[j], t2});
          
          vector<int> temp = {mini, 0 - mini - maxi, maxi};
          
          if(combs.find(temp) == combs.end())
          {
            ans.push_back(temp);
            combs.insert(temp);
          }
        }
        
        freq[n[j]]++;
      }
      //freq[n[i]]++;
    }
    
    return ans;
  }
//     sort(n.begin(), n.end());
    
//     int count = 1;
//     vector<int> nums;
//     for(int a : n)
//     {
//       if(nums.size() > 0)
//       {
//         if(nums.back() == a)
//         {
//           count++;  
//         }
//         else
//         {
//           count = 1;
//         }
        
//         if(count <= 3)
//         {
//           nums.push_back(a);
//         }
//       }
//       else
//       {
//         nums.push_back(a);
//       }
//     }
    
//     vector<vector<int>> result;
//     int l = nums.size();
//     for(int i = 0; i < l - 2; ++i)
//     {
//       for(int j = i + 1; j < l - 1; ++j)
//       {
//         int t = 0 - (nums[i] + nums[j]);  
//         if(isTargetPresent(nums, j + 1, l - 1, t))
//         {
//           vector<int> v = {nums[i], nums[j], t};
//           if((result.size() == 0) || (result.size() > 0 && v != result.back()))
//           {
//             result.push_back(v);
//           }          
//         }
//       }
//     }
    
//     //now remove duplicates if any!
//     l = result.size();
//     if(l > 0)
//     {
//       sort(result.begin(), result.end());

//       l = result.size();
//       vector<vector<int>> ans;
//       ans.push_back(result[0]);
//       int j = 1;
//       for(int i = 1; i < l; i++)
//       {
//         if(result[i] != ans.back())
//         {
//           ans.push_back(result[i]);
//         }
//       }

//       return ans;
//     }
    
//     return result;
//   }
};