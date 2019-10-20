/*
Two Sum:

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Ex:
    Given nums = [2, 7, 11, 15], target = 9,
    Because nums[0] + nums[1] = 2 + 7 = 9,
    return [0, 1].
*/

#include <iostream>
#include <vector>

using namespace std;
class Solution_t
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int length = nums.size();

        vector<int> retVal;
        for (int i = 0; i < length - 1; i++)
        {
            for (int j = (i + 1); j < length; j++)
            {
                if ((nums[i] + nums[j]) == target)
                {
                    retVal.push_back(i);
                    retVal.push_back(j);

                    return retVal;
                }
            }
        }

        return retVal;
    }
};

int main()
{
    vector<int> input = {2, 7, 11, 15};
    int target = 26;

    Solution_t s;
    vector<int> indicies = s.twoSum(input, target);

    printf("\n");
    for (int i : indicies)
    {
        printf("%d,", i);
    }

    return 0;
}