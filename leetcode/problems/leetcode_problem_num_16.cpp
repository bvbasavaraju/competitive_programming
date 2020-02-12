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
    vector<vector<int>> groups;

    void FillInPossibleCombination(vector<int> &nums, int l, int i, vector<int> set)
    {
        if (set.size() > 2)
        {
            groups.push_back(set);
            return;
        }

        set.push_back(nums[i]);
        FillInPossibleCombination(nums, l, i + 1, set);
        FillInPossibleCombination(nums, l, i + 2, set);
    }

public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int l = nums.size();

        vector<int> set;
        FillInPossibleCombination(nums, l, 0, set);
        for (int i = 0; i < groups.size(); i++)
        {
            vector<int> g = groups[i];
            for (auto a : g)
            {
                printf("%d, ", a);
            }
            printf("\n");
        }

        return 0;
    }
};

int main()
{
    vector<int> data = {-1, 2, 1, 4};

    Solution s;
    s.threeSumClosest(data, 1);
    return 0;
}