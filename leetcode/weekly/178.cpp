/****************************************************
Date: Mar 1st, 2020
Successful submissions : 1
Time expiration : 0
Not Solved : 3
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/weekly-contest-178
****************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;

/*
    Q:  1365. How Many Numbers Are Smaller Than the Current Number
*/
class Solution1_t
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        int l = nums.size();
        vector<int> result(l, 0);

        for (int i = 0; i < l; ++i)
        {
            int n = nums[i];
            int count = 0;

            for (int j = 0; j < l; ++j)
            {
                if ((i == j) || (nums[j] >= n))
                {
                    continue;
                }

                count++;
            }

            result[i] = count;
        }

        return result;
    }
};

/*
    Q:  1366. Rank Teams by Votes
*/

class Solution2_t
{
public:
    string rankTeams(vector<string> &votes)
    {
        map<int, map<int, int>> ranking;

        int s = votes.size();
        for (int i = 0; i < s; ++i)
        {
            string v = votes[0];
            int rank = 1;
            for (auto l : v)
            {
                ranking[rank++][l]++;
            }
        }

        string result = "";
        for (auto it = ranking.begin(); it != ranking.end(); ++it)
        {
            auto lettersWithRank = it->second;
            auto it2 = lettersWithRank.begin();

            if (lettersWithRank.size() == 1)
            {
                result += std::to_string(it2->first);
                continue;
            }

            int ch = it2->first;
            int count = it2->second;
            bool conflict = false;
            int conflictingCh;

            it2++;
            for (; it2 != lettersWithRank.end(); it2++)
            {
                if (it2->second > count)
                {
                    count = it2->second;
                    ch = it2->first;
                    conflict = false;
                    continue;
                }

                else if (it2->second == count)
                {
                    conflict = true;
                    conflictingCh = it2->first;
                }
            }

            if (!conflict)
            {
                result += std::to_string(ch);
            }
            else
            {
            }
        }

        /*map<int, int> concluded;
    for(int ch = 'A'; ch <= 'Z'; ch++)
    {
      if(ranking.count(ch) == 0)
      {
        continue;
      }
      
      for(auto it = ranking[ch].begin(); it != ranking[ch].end(); ++it)
      {
        if(it->second >= s/2);
        {
          
        }
        
        concluded[it->first] = ch;
      }
    }*/
    }
};

/*
    Q:  1367. Linked List in Binary Tree
*/

/**
 * Definition for singly-linked list.
 * */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for a binary tree node.
 * */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution3_t
{
public:
    bool isSubPath(ListNode *head, TreeNode *root)
    {
    }
};

/*
    Q:  1368. Minimum Cost to Make at Least One Valid Path in a Grid
*/

class Solution4_t
{
public:
    int minCost(vector<vector<int>> &grid)
    {
    }
};