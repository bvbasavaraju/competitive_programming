/*
    Q: 16. 3Sum Closest
*/

#include <iostream>
#include <algorithm>
#include <stdint.h>
#include <math.h>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution
{
private:
  // vector<vector<int>> groups;

  // bool FillInPossibleCombination(vector<int> &nums, int l, int i, vector<int> set)
  // {
  //   if ((set.size() > 2) || (i >= l))
  //   {
  //     if(set.size() > 2)
  //     {
  //       groups.push_back(set);
  //     }

  //     // No need to call the recursive function with incremented value of i again!
  //     return false;
  //   }

  //   set.push_back(nums[i]);
  //   for(int j = i; j < l; j++)
  //   {
  //     if(!FillInPossibleCombination(nums, l, j + 1, set))
  //     {
  //       break;
  //     }
  //   }
  //   // {
  //   //   //Only if the function has to be called again with incremented value of "i", only then call the function again!
  //   //   FillInPossibleCombination(nums, l, i + 2, set);
  //   // }

  //   return true;
  // }

  int ans;
  int prevSmallDiff;
  int tar;
  bool SumOfThreeNumbersInSet(vector<int> &nums, int l, int pos, int numsAdded, int currSum)
  {
    if((numsAdded == 3) || (pos >= l))
    {
      if(numsAdded == 3)
      {
        //If the currSum is closest then update the diff of sum and target and update the answer
        if(prevSmallDiff > abs(currSum - tar))
        {
          prevSmallDiff = abs(currSum - tar);
          ans = currSum;
        }
      }

      return false;
    }

    currSum += nums[pos];
    numsAdded++;
    for(int i = pos; i < l; i++)
    {
      if(!SumOfThreeNumbersInSet(nums, l, i+1, numsAdded, currSum))
      {
        break;
      }
    }

    return true;
  }

public:
  int threeSumClosest(vector<int> &nums, int target)
  {
    ans = 1e9;
    prevSmallDiff = 1e9;
    tar = target;
    int l = nums.size();

    // As three numbers need to be added, excluding last 2 number loop for all other numbers.
    for(int i = 0; i < l - 2; i++)
    {
      // vector<int> set;
      // FillInPossibleCombination(nums, l, i, set);

      SumOfThreeNumbersInSet(nums, l, i, 0, 0);
    }

    return (ans == 1e9) ? 0 : ans;
  }
};

int main()
{
    vector<int> data = {0, 1, 2};
    int target = 3;

    // vector<int> data = {-1, 2, 1, 4};
    // int target = 1;

    // vector<int> data = {1,2,4,8,16,32,64,128};
    // int target = 82;

    Solution s;
    s.threeSumClosest(data, target);
    return 0;
}