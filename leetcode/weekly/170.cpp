/****************************************************
Date: Jan 5, 2020
Successful submissions : 1
Time expiration : 1
Not Solved : 1
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/biweekly-contest-170
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
    Q: 1309. Decrypt String from Alphabet to Integer Mapping - Accepted!
*/
class Solution1_t
{
public:
    string freqAlphabets(string s)
    {
        string letters = "0abcdefghijklmnopqrstuvwxyz";

        string retVal = "";
        int ls = s.size();
        for (int i = 0; i < ls; i++)
        {
            if (s[i] == '#')
            {
                continue;
            }

            int p = s[i] - '0';

            if ((i + 2 < ls) && s[i + 2] == '#')
            {
                i++;
                p = p * 10 + s[i++] - '0';
            }

            retVal += letters[p];
        }

        return retVal;
    }
};

/*
    Q: 1310. XOR Queries of a Subarray - Time Limit Exceeded
*/

class Solution2_t
{
private:
    int GetXoredValue(vector<int> &a, int l, int h)
    {
        int retVal = 0;
        while (l < h)
        {
            retVal ^= a[l++];
        }

        retVal ^= a[h];
        return retVal;
    }

public:
    vector<int> xorQueries(vector<int> &a, vector<vector<int>> &q)
    {
        int lq = q.size();
        vector<int> r;

        for (int i = 0; i < lq; i++)
        {
            r.push_back(GetXoredValue(a, q[i][0], q[i][1]));
        }

        return r;
    }
};

/*
    Q: 1311. Get Watched Videos by Your Friends
*/
class Solution3_t
{
public:
    vector<string> watchedVideosByFriends(vector<vector<string>> &watchedVideos, vector<vector<int>> &friends, int id, int level)
    {
    }
};

/*
    Q: 1312. Minimum Insertion Steps to Make a String Palindrome - Wrong answer
*/
class Solution4_t
{
private:
    int GetInsertCount(string s, bool atEnd)
    {
        int retVal = 0;
        int l = 0;
        int h = s.size() - 1;

        while (h > 0 && l <= h)
        {
            if (s[l] == s[h])
            {
                l++;
                h--;
            }
            else
            {
                if (atEnd)
                {
                    s.insert(h, 1, s[l++]);
                }
                else
                {
                    s.insert(l, 1, s[h--]);
                }

                retVal++;
            }
        }

        return retVal;
    }

public:
    int minInsertions(string s)
    {
        return min(GetInsertCount(s, true), GetInsertCount(s, false));
    }
};