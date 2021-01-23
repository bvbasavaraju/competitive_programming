/*
Remove Duplicates from Sorted Array:

Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Ex:
Given nums = [1,1,2],
Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned length.

Given nums = [0,0,1,1,1,2,2,3,3,4],
Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.
It does not matter what values are set beyond the returned length.

Note:
Confused why the returned value is an integer but your answer is an array?
Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.
Internally you can think of this:

Link:   https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/

#include <iostream>
#include <vector>

using namespace std;
class Solution_t
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() <= 0)
        {
            return 0;
        }

        for (int i = 0; i < (nums.size() - 1); i++)
        {
            int currNum = nums[i];
            for (int j = (i + 1); j < nums.size(); j++)
            {
                if (currNum == nums[j])
                {
                    nums.erase(nums.begin() + j);
                    j--;
                }
                else
                {
                    break;
                }
            }
        }

        return nums.size();
    }
};