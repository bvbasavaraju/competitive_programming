/****************************************************
Date: September 1st

link: https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/636/week-1-september-1st-september-7th/3960/
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

class Solution 
{
public:
  int arrayNesting(vector<int>& nums) 
  {
    int ans = 0;
    int l = nums.size();
    
    for(int i = 0; i < l ; ++i)
    {
      if(nums[i] < 0)
      {
        continue;
      }
      
      int curr = nums[i];
      int prev = -1;
      int count = 1;
      
      nums[i] = -1;
      
      while(nums[curr] >= 0)
      {
        prev = curr;
        curr = nums[curr];
        nums[prev] = -1;
        
        count++;
      }
      
      ans = max(ans, count);
    }
    return ans;
    
    //TLE
//     for(int i = 0; i <l; ++i)
//     {
//       int p = i;
//       vector<int> s;
//       vector<int> freq(l, 0);
//       while(freq[nums[p]] < 1)
//       {
//         s.push_back(nums[p]);
//         freq[nums[p]]++;
//         p = s.back();
//       }
      
//       ans = max(ans, static_cast<int>(s.size()));
//     }
    
    // return ans;
  }
};

int main()
{
  Solution s;
  vector<int> v = {5,4,0,3,1,6,2};
  s.arrayNesting(v);
  return 0;
}