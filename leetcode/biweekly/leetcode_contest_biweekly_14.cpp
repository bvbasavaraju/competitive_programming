/****************************************************
Date: November 30, 2019
Successful submissions : 1
Time expiration :
Not Solved : 3
Wrong Answer/ Partial result : 

link: https://leetcode.com/contest/biweekly-contest-14
****************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

/*
    Q:  1271. Hexspeak
*/

class Solution1_t
{
public:
    string toHexspeak(string numInStr)
    {
        char *end;
        long long int numD = strtoll(numInStr.c_str(), &end, 10);
        stack<int> reminders;

        while (numD >= 16)
        {
            int r = numD % 16;
            numD = numD / 16;

            reminders.push(r);
        }
        reminders.push(numD);

        string retVal = "";
        while (!reminders.empty())
        {
            int i = reminders.top();
            reminders.pop();

            switch (i)
            {
            case 10:
                retVal += "A";
                break;

            case 11:
                retVal += "B";
                break;

            case 12:
                retVal += "C";
                break;

            case 13:
                retVal += "D";
                break;

            case 14:
                retVal += "E";
                break;

            case 15:
                retVal += "F";
                break;

            case 0:
                retVal += "O";
                break;

            case 1:
                retVal += "I";
                break;

            default:
                return "ERROR";
            }
        }

        return retVal;
    }
};

/*
    Q: 1272. Remove Interval
*/
class Solution2_t
{
public:
    vector<vector<int>> removeInterval(vector<vector<int>> &intervals, vector<int> &toBeRemoved)
    {
    }
};

/*
    Q:  1273. Delete Tree Nodes
*/
class Solution3_t
{
public:
    int deleteTreeNodes(int nodes, vector<int> &parent, vector<int> &value)
    {
    }
};

/*
    Q:  1274. Number of Ships in a Rectangle
*/
/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution4_t
{
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft)
    {
    }
};