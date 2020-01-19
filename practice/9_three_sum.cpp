

//TODO : test
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution_t
{
private:
    int IsSumPossible(int numToSearch, vector<int> &nums, int posToStartFrom)
    {
        if (posToStartFrom >= nums.size() - 1)
        {
            return numToSearch == nums[posToStartFrom] ? numToSearch : -1;
        }

        if (binary_search(nums.begin() + posToStartFrom, nums.end(), numToSearch))
        {
            return numToSearch;
        }

        return -1;
    }

public:
    vector<vector<int>> GetThreeNums(vector<int> &nums, int sum)
    {
        sort(nums.begin(), nums.end());

        vector<vector<int>> retVal;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                if (IsSumPossible(sum - (nums[i] + nums[j]), nums, j + 1) >= 0)
                {
                    retVal.push_back({nums[i], nums[j], nums[j + 1]});
                }
            }
        }
    }
};