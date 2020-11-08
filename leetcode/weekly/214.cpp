/****************************************************
Date: Nov 8th, 2020
Successful submissions : 2
Time expiration : 1
Not Solved : 1
Wrong Answer/ Partial result : 0
link: https://leetcode.com/contest/weekly-contest-214
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
    Q: 1646. Get Maximum in Generated Array
*/
class Solution1_t
{
public:
    int getMaximumGenerated(int n)
    {
        if (n <= 0)
        {
            return 0;
        }

        vector<int> nums(n + 1);
        nums[0] = 0;
        nums[1] = 1;

        int ans = 1;
        for (int i = 1; i <= (n - 1) / 2; ++i)
        {
            int index1 = i * 2;
            if ((2 <= index1) && (index1 <= n))
            {
                nums[index1] = nums[i];
            }

            int index2 = (i * 2) + 1;
            if ((2 <= index2) && (index2 <= n))
            {
                nums[index2] = nums[i] + nums[i + 1];
            }

            ans = max({ans, nums[index1], nums[index2]});
        }

        return ans;
    }
};

/*
    Q: 1647. Minimum Deletions to Make Character Frequencies Unique
*/
class Solution2_t
{
public:
    int minDeletions(string s)
    {
        vector<int> freq(26, 0);
        unordered_set<int> accepted_freq;

        for (int ch : s)
        {
            freq[ch - 'a']++;
        }

        int ans = 0;
        for (int i = 0; i < 26; ++i)
        {
            int f = freq[i];
            while (f > 0)
            {
                if (accepted_freq.find(f) == accepted_freq.end())
                {
                    freq[i] = f;
                    accepted_freq.insert(f);
                    break;
                }
                else
                {
                    f--;
                    ans++;
                }
            }
        }

        return ans;

        /*for(int i = 0; i < 26; ++i)
    {
      if(freq[i] > 0)
      {
        m[freq[i]].push_back(i+'a');
      }
    }
    
    int ans = 0;
    for(auto it = m.begin(); it != m.end(); ++it)
    {
      if(it->second.size() == 1)
      {
        continue;
      }
      
      vector<int> letters = it->second;
      for(int i = 1; i < letters.size(); ++i)
      {
        int f = it->first;
        f--;
        while(f >= 0)
        {
          if(m.find(f) == m.end())
          {
            freq[letters[i] - 'a'] = f;
            m[f].push_back(letters[i]);
            break;
          }
          f--;
          ans++;
        }
      }
    }
    
    return ans;*/
    }
};

/*
    Q: 1648. Sell Diminishing-Valued Colored Balls
*/
class Solution3_t
{
private:
    static const int MOD = 1e9 + 7;

    long long int SumToN(int n)
    {
        return ((n % MOD) * ((n + 1) % MOD) / 2) % MOD;
    }

public:
    int maxProfit(vector<int> &inventory, int orders)
    {

        int l = inventory.size();
        if (l == 1)
        {
            long long int n = inventory[0];

            return static_cast<int>(((n % MOD) * ((n + 1) % MOD) / 2) % MOD);
        }

        priority_queue<int> pq;
        for (int i = 0; i < l; ++i)
        {
            pq.push(inventory[i]);
        }

        long long int ans = 0;
        while (orders > 0)
        {
            long long int t1 = pq.top();
            pq.pop();
            long long int t2 = pq.top();
            pq.pop();

            long long int diff = t1 - t2;
            if (diff == 0)
            {
                orders--;
                ans = (t1 % MOD) + (ans % MOD);
                ans = (ans % MOD);

                t1--;
            }
            else
            {
                if (orders >= diff)
                {
                    orders = orders - diff;

                    long long int p = SumToN(static_cast<int>(t1)) - SumToN(static_cast<int>(t1 - diff - 1));
                    ans = (p % MOD) + (ans % MOD);
                    ans = (ans % MOD);
                    t1 = t1 - diff;
                }
                else
                {
                    long long int p = SumToN(static_cast<int>(t1)) - SumToN(static_cast<int>(t1 - orders));
                    ans = (p % MOD) + (ans % MOD);
                    ans = (ans % MOD);
                    t1 = t1 - orders;
                }
            }
            pq.push(t1);
            pq.push(t2);
            /*orders--;
      
      long long int t = pq.top();
      pq.pop();
      ans = (t % MOD) + (ans % MOD);
      ans = (ans % MOD);
      
      t--;
      pq.push(static_cast<int>(t));*/
        }

        return static_cast<int>(ans);
    }
};

/*
    Q: 1649. Create Sorted Array through Instructions
*/
class Solution4_t
{
public:
    int createSortedArray(vector<int> &instructions)
    {
    }
};