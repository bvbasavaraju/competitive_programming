/*
    Q: 12. Integer to Roman
    //Time Limit Exceeded - need to optimize the code!
    //TODO - optimize!!
*/

#include <iostream>
#include <algorithm>
#include <stdint.h>
#include <math.h>
#include <string>
#include <map>
#include <vector>

using namespace std;

// class Solution
// {
// public:
//     vector<vector<int>> threeSum(vector<int> &n)
//     {
//         int nl = n.size();
//         vector<vector<int>> retVal;
//         for (int i = 0; i < nl - 2; i++)
//         {
//             for (int j = i + 1; j < nl - 1; j++)
//             {
//                 for (int k = j + 1; k < nl; k++)
//                 {
//                     if (n[i] + n[j] + n[k] == 0)
//                     {
//                         vector<int> s = {n[i], n[j], n[k]};
//                         sort(s.begin(), s.end());
//                         retVal.push_back(s);
//                     }
//                 }
//             }
//         }

//         vector<vector<int>> result;
//         if (retVal.size() > 0)
//         {
//             sort(retVal.begin(), retVal.end());

//             result.push_back(retVal[0]);
//             for (int i = 1; i < retVal.size(); i++)
//             {
//                 if (retVal[i] != result[result.size() - 1])
//                 {
//                     result.push_back(retVal[i]);
//                 }
//             }
//         }

//         return result;
//     }
// };

class Solution 
{
private:
  bool findNumber(vector<int>& nums, int s, int e, int target, int& result)
  {
    while(s <= e)
    {
      int m = s + (e-s)/2;
      if(nums[m] == target)
      {
        result = m;
        return true;
      }
      else if(nums[m] > target)
      {
        e = m - 1;
      }
      else
      {
        s = m + 1;
      }
    }
    
    return false;
  }
  
public:
  vector<vector<int>> threeSum(vector<int>& nums) 
  {
    sort(nums.begin(), nums.end());
    
    vector<vector<int>> result;
    int l = nums.size();
    for(int i = 0; i < l - 2; ++i)
    {
      int start = i + 1;
      
      while(start < l - 1)
      {
        int target = 0 - (nums[i] + nums[start]);
        
        int p;
        if(findNumber(nums, start + 1, l - 1, target, p))
        {
          vector<int> r = {nums[i], nums[start], nums[p]};
          
          if((result.size() > 0) && (r != result.back()))
          {
            result.push_back(r);
          }
        }
        
        start++;
      }
    }

    //now remove duplicates if any!
    if(result.size() > 1)
    {
      sort(result.begin(), result.end());

      l = result.size();
      vector<vector<int>> ans;
      ans.push_back(result[0]);
      int j = 1;
      for(int i = 1; i < l; i++)
      {
        if(result[i] != ans.back())
        {
          ans.push_back(result[i]);
        }
      }

      return ans;
    }

    return result;
  }
};

int main()
{
    Solution s;
    // vector<int> v = {-1, 0, 1, 2, -1, -4};
    vector<int> v = {0,0,0,0};

    s.threeSum(v);
}