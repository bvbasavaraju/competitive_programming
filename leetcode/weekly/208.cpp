/****************************************************
Date: Sept 27th, 2020
Successful submissions : 3
Time expiration : 0
Not Solved : 0
Wrong Answer/ Partial result : 1
link: https://leetcode.com/contest/weekly-contest-208
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
    Q: 1598. Crawler Log Folder
*/
class Solution1_t
{
public:
    int minOperations(vector<string> &logs)
    {
        const string CURRENT_DIR = "./";
        const string PREVIOUS_DIR = "../";

        int ans = 0;
        for (string &log : logs)
        {
            if (log == PREVIOUS_DIR)
            {
                ans--;
            }
            else if (log != CURRENT_DIR)
            {
                ans++;
            }

            if (ans < 0)
            {
                ans = 0;
            }
        }

        return ans;
    }
};

/*
    Q: 1599. Maximum Profit of Operating a Centennial Wheel
*/
class Solution2_t
{
public:
    int minOperationsMaxProfit(vector<int> &customers, int bc, int rc)
    {
        int wait = 0;
        int total_on_wheel = 0;
        int profit = 0;
        int max_profit = 0;

        int ans = -1;
        int l = customers.size();
        for (int i = 1; (i <= l || wait > 0); ++i)
        {
            if (i <= l)
            {
                wait += customers[i - 1];
            }
            int count = wait > 4 ? 4 : wait;
            wait -= count;

            total_on_wheel += count;
            profit = (total_on_wheel * bc) - (i * rc);
            if (profit > max_profit)
            {
                max_profit = profit;
                ans = i;
            }
        }

        return ans;
    }
};

/*
    Q: 1600. Throne Inheritance
*/
class ThroneInheritance
{
private:
    string king_name;
    unordered_map<string, vector<string>> parent_children_map;
    unordered_set<string> death_list;

    void listInheritance(string &parent, vector<string> &list)
    {
        if (death_list.find(parent) == death_list.end())
        {
            list.push_back(parent);
        }

        vector<string> &childs = parent_children_map[parent];
        if (childs.empty())
        {
            return;
        }

        for (string &child : childs)
        {
            listInheritance(child, list);
        }
    }

public:
    ThroneInheritance(string kingName)
    {
        king_name = kingName;
        parent_children_map[king_name] = {};
    }

    void birth(string parentName, string childName)
    {
        parent_children_map[parentName].push_back(childName);

        parent_children_map[childName] = {};
    }

    void death(string name)
    {
        death_list.emplace(name);
    }

    vector<string> getInheritanceOrder()
    {
        vector<string> ans;
        listInheritance(king_name, ans);

        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */

/*
    Q: 1601. Maximum Number of Achievable Transfer Requests - wrong answer
*/
class Solution4_t
{
private:
    bool isPossible(unordered_map<int, int> &from_to_map, set<pair<int, int>> &processing, set<pair<int, int>> &completed, pair<int, int> &req, int dest, int &ans)
    {
        if (completed.find(req) != completed.end())
        {
            return false;
        }

        if (processing.find(req) != processing.end())
        {
            return false;
        }

        processing.insert(req);

        if (req.second == dest)
        {
            ans += processing.size();
            for (auto &p : processing)
            {
                completed.emplace(p);
            }
            processing.clear();
            return true;
        }
        else
        {
            pair<int, int> new_req = std::make_pair(req.second, from_to_map[req.second]);
            if (isPossible(from_to_map, processing, completed, new_req, dest, ans))
            {
                for (auto &p : processing)
                {
                    completed.emplace(p);
                }
                processing.clear();

                return true;
            }
        }

        return false;
    }

public:
    int maximumRequests(int n, vector<vector<int>> &requests)
    {
        unordered_map<int, int> from_to_map;
        for (vector<int> &req : requests)
        {
            from_to_map[req[0]] = req[1];
        }

        int ans = 0;
        set<pair<int, int>> completed;

        for (auto it = from_to_map.begin(); it != from_to_map.end(); it++)
        {
            pair<int, int> req = std::make_pair(it->first, it->second);

            set<pair<int, int>> processing;
            if (completed.find(req) == completed.end())
            {
                isPossible(from_to_map, processing, completed, req, req.second, ans);
            }
        }

        return ans;
    }
};