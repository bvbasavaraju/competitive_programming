#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
  Q: Move Zeroes

  Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

  Example:
    Input: [0,1,0,3,12]
    Output: [1,3,12,0,0]

  Note:
    You must do this in-place without making a copy of the array.
    Minimize the total number of operations.

  Hide Hint #1  
    In-place means we should not be allocating any space for extra array. But we are allowed to modify the existing array. 
    However, as a first step, try coming up with a solution that makes use of additional space. 
    For this problem as well, first apply the idea discussed using an additional array and the in-place solution will pop up eventually.
  Hide Hint #2  
    A two-pointer approach could be helpful here. The idea would be to have one pointer for iterating the array 
    and another pointer that just works on the non-zero elements of the array.
*/

class Solution 
{
public:
  void moveZeroes(vector<int>& nums) 
  {
    int j = 0;
    int l = nums.size();
    for(int i = 0; i < l-1; ++i)
    {
      if(nums[i] != 0)
        continue;
      
      if(j == 0)
        j = i + 1;
      
      for(; j < l; j++)
      {
        if(nums[j] == 0)
          continue;
        
        nums[i] = nums[j];
        nums[j++] = 0;
        break;
      }
      
      if(j == l)
        break;
    }
  }
};