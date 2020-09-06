/****************************************************
Date: Sept 6th, 2020
Successful submissions : 3
Time expiration : 0
Not Solved : 1
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/weekly-contest-205
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
#include <limits.h>

using namespace std;

/*
    Q: 1576. Replace All ?'s to Avoid Consecutive Repeating Characters
*/
class Solution1_t
{
public:
    string modifyString(string s)
    {
        vector<int> chars(26);
        for (int i = 0; i < 26; ++i)
        {
            chars[i] = i + 'a';
        }

        int p = 0;
        int l = s.size();
        for (int i = 0; i < l; ++i)
        {
            if (s[i] == '?')
            {
                bool unique = false;
                while (!unique)
                {
                    if (s[i + 1] == chars[p])
                    {
                        p++;
                    }
                    if (i > 0 && s[i - 1] == chars[p])
                    {
                        p++;
                    }
                    else
                    {
                        unique = true;
                    }
                }

                s[i] = chars[p % 26];
                p++;
                p = p % 26;
            }
            else
            {
                p = 0;
            }
        }

        return s;
    }
};

/*
    Q: 1577. Number of Ways Where Square of Number Is Equal to Product of Two Numbers
*/
class Solution2_t
{
private:
    void getProducts(vector<int> &nums, map<long long int, int> &p)
    {
        int l = nums.size();
        for (int i = 0; i < l; ++i)
        {
            for (int j = i + 1; j < l; ++j)
            {
                long long int n1 = nums[i];
                long long int n2 = nums[j];

                long long int prod = n1 * n2;
                p[prod]++;
            }
        }
    }

    int getCount(vector<int> &nums, map<long long int, int> &p)
    {
        int retVal = 0;

        for (long long int n : nums)
        {
            long long int s = n * n;
            if (p.find(s) != p.end())
            {
                retVal += p[s];
            }
        }

        return retVal;
    }

public:
    int numTriplets(vector<int> &nums1, vector<int> &nums2)
    {
        map<long long int, int> n1p;
        getProducts(nums1, n1p);

        map<long long int, int> n2p;
        getProducts(nums2, n2p);

        int ans = getCount(nums1, n2p);
        ans += getCount(nums2, n1p);

        return ans;
    }
};

/*
    Q: 1578. Minimum Deletion Cost to Avoid Repeating Letters
*/
class Solution3_t
{
private:
public:
    int minCost(string s, vector<int> &cost)
    {
        int ans = 0;
        int l = s.size();
        for (int i = 0; i < l - 1; ++i)
        {
            if (s[i] == s[i + 1])
            {
                int sum = 0;
                int maxi = INT_MIN;
                while (s[i] == s[i + 1])
                {
                    sum += cost[i];
                    maxi = max(maxi, cost[i]);
                    i++;
                    if (i == l - 1)
                    {
                        break;
                    }
                }

                sum += cost[i];
                maxi = max(maxi, cost[i]);
                ans += sum - maxi;
            }
        }

        return ans;
    }
};

/*
    Q: 1579. Remove Max Number of Edges to Keep Graph Fully Traversable
*/
class Solution4_t
{
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
    {
    }
};