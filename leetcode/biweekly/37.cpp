/****************************************************
Date: Oct 17th, 2020
Successful submissions : 1
Time expiration : 1
Not Solved : 0
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/biweekly-contest-37
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
#include <string_view>

using namespace std;
/*
    Q: 1619. Mean of Array After Removing Some Elements
*/
class Solution
{
public:
    double trimMean(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());

        int l = arr.size();
        int count_e = l / 20;

        int sum = 0;
        for (int i = count_e; i < (l - count_e); ++i)
        {
            sum += arr[i];
        }

        return ((((sum * 1.0) / (l * 1.0 - (2.0 * count_e))) * 100000.0) / 100000.0);
    }
};

/*
    Q: 1620. Coordinate With Maximum Network Quality - initially wrong ans. later corrected.
*/
class Solution
{
private:
    int getNetworkQuality(vector<int> &t, vector<vector<int>> &towers, int radius)
    {
        int ans = 0;
        for (vector<int> &t_ : towers)
        {
            long long int x = (t[0] - t_[0]) * (t[0] - t_[0]);
            long long int y = (t[1] - t_[1]) * (t[1] - t_[1]);
            double d = sqrt(x + y);
            if (d <= radius)
            {
                ans += (t_[2] / (1 + d));
            }
        }

        return ans;
    }

public:
    vector<int> bestCoordinate(vector<vector<int>> &towers, int radius)
    {
        int nq = 0;
        vector<int> ans;
        for (vector<int> t : towers)
        {
            int nq_ = getNetworkQuality(t, towers, radius);

            printf("%d\n", nq_);
            vector<int> p = {t[0], t[1]};
            if (nq_ > nq)
            {
                nq = nq_;
                ans = p;
            }
            else if (nq_ == nq)
            {
                if ((ans.size() == 0) || (p[0] < ans[0]) || ((p[0] == ans[0]) && (p[1] == ans[1])))
                {
                    ans = p;
                }
            }
        }

        return ans;
    }
};

/*
    Q: 1621. Number of Sets of K Non-Overlapping Line Segments - time limit exceeded
*/
class Solution
{
public:
    int numberOfSets(int n, int k)
    {
    }
};

/*
    Q: 1622. Fancy Sequence
*/
class Fancy
{
private:
    const int MOD;
    vector<vector<int>> seq;
    vector<int> op;
    vector<int> nums;

public:
    Fancy()
        : MOD(1e9 + 7)
    {
    }

    void append(int val)
    {
        int p = op.size();
        seq.push_back({val, p});
    }

    void addAll(int inc)
    {
        op.push_back('a');
        nums.push_back(inc);
    }

    void multAll(int m)
    {
        op.push_back('m');
        nums.push_back(m);
    }

    int getIndex(int idx)
    {
        if (idx >= seq.size())
        {
            return -1;
        }

        long long int ans = seq[idx][0];

        int l = op.size();
        for (int i = seq[idx][1]; i < l; ++i)
        {
            if (op[i] == 'a')
            {
                ans = ((long long int)(ans % MOD) + (long long int)(nums[i] % MOD)) % MOD;
            }
            else
            {
                ans = ((long long int)(ans % MOD) * (long long int)(nums[i] % MOD)) % MOD;
            }
        }

        seq[idx][0] = (int)ans;
        seq[idx][1] = op.size();
        return ans;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */