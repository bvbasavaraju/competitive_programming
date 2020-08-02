/****************************************************
Date: aug 2nd, 2020
Successful submissions : 2
Time expiration : 0
Not Solved : 1
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/weekly-contest-200
****************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

/*
    Q: 1534. Count Good Triplets
*/
class Solution1_t
{
public:
    int countGoodTriplets(vector<int> &arr, int a, int b, int c)
    {
        int l = arr.size();

        int ans = 0;
        for (int k = 0; k < l; ++k)
        {
            for (int j = 0; j < k; ++j)
            {
                for (int i = 0; i < j; ++i)
                {
                    if ((abs(arr[i] - arr[j]) <= a) && (abs(arr[j] - arr[k]) <= b) && (abs(arr[i] - arr[k]) <= c))
                    {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};

/*
    Q: 1535. Find the Winner of an Array Game
*/
class Solution2_t
{
public:
    int getWinner(vector<int> &arr, int k)
    {
        int ans = 0;
        int l = arr.size();
        if (k >= l)
        {
            ans = *max_element(arr.begin(), arr.end());
        }
        else
        {
            int win_count = 1;
            ans = max(arr[0], arr[1]);
            for (int i = 2; i < l; ++i)
            {
                if (win_count == k)
                {
                    break;
                }

                int maxi = max(arr[i], ans);
                if (maxi == ans)
                {
                    win_count++;
                }
                else
                {
                    win_count = 1;
                    ans = maxi;
                }
            }
        }

        return ans;
    }
};

/*
    Q: 1536. Minimum Swaps to Arrange a Binary Grid - partial or wrong answer
*/
class Solution3_t
{
public:
    int minSwaps(vector<vector<int>> &grid)
    {
        unordered_map<int, int> zero_count_pos;
        unordered_map<int, int> pos_count;

        int p = 0;
        for (vector<int> &v : grid)
        {
            int count = 0;
            for (int i = v.size() - 1; i >= 0; --i)
            {
                if (v[i] == 1)
                {
                    break;
                }
                count++;
            }

            zero_count_pos[count] = p++;
            pos_count[p] = count;
        }

        p = 0;
        int ans = 0;
        for (int i = grid.size() - 1; i > 0; --i)
        {
            if (zero_count_pos.find(i) == zero_count_pos.end())
            {
                ans = -1;
                break;
            }
            else
            {
                if (zero_count_pos[i] != p)
                {
                    int pos = zero_count_pos[i];
                    int zc = i;
                    for (int j = pos - 1; j >= p; --j)
                    {
                        int temp_zc = pos_count[j];
                        int temp_pos = zero_count_pos[temp_zc];

                        zero_count_pos[zc] = j;
                        pos_count[pos] = temp_zc;

                        zero_count_pos[temp_zc] = temp_pos;
                        pos_count[temp_pos] = zc;

                        ans++;
                    }
                }
                p++;
            }
        }

        return ans;
    }
};

/*
    Q: 1537. Get the Maximum Score
*/
class Solution4_t
{
public:
    int maxSum(vector<int> &nums1, vector<int> &nums2)
    {
    }
};