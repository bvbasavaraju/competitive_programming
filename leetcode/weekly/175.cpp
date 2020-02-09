/****************************************************
Date: Feb 9, 2020
Successful submissions : 2
Time expiration : 0
Not Solved : 2
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/biweekly-contest-175
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
    Q:  1346. Check If N and Its Double Exist
*/

class Solution1_t
{
private:
    int FindNumber(vector<int> &arr, int l, int h, int s, long long numToFind)
    {
        while ((l <= h) && (l < s))
        {
            int m = l + (h - l) / 2;

            //printf("size: %d, l: %d. h: %d, m: %d\n", s, l, h, m);

            if (arr[m] == numToFind)
            {
                return m;
            }

            if (arr[m] < numToFind)
            {
                l = m + 1;
            }
            else
            {
                h = m - 1;
            }
        }

        return -1;
    }

public:
    bool checkIfExist(vector<int> &arr)
    {
        int s = arr.size();

        sort(arr.begin(), arr.end());

        for (int i = 0; i < s; i++)
        {
            arr[i] *= 1000;
        }

        for (int i = 0; i < s - 1; ++i)
        {
            long long numToFind = 0;
            if (arr[i] > 0)
            {
                numToFind = arr[i] * 2;
            }
            else
            {
                numToFind = arr[i] / 2;
            }

            //printf("\nnum: %d, numToFind: %d", arr[i], numToFind);

            int l = i + 1;
            int h = s;

            int j = FindNumber(arr, l, h, s, numToFind);
            if (j > 0)
            {
                return true;
            }
        }

        return false;
    }
};

/*
    Q:  1347. Minimum Number of Steps to Make Two Strings Anagram
*/
class Solution2_t
{
public:
    int minSteps(string s, string t)
    {
        map<int, int> chMap;

        int l = s.size();
        for (int i = 0; i < l; i++)
        {
            chMap[s[i]]++;
        }

        for (int i = 0; i < l; i++)
        {
            chMap[t[i]]--;
        }

        int result = 0;
        for (auto it : chMap)
        {
            if (it.second < 0)
            {
                result += it.second;
            }
        }

        return abs(result);
    }
};

/*
    Q:  1348. Tweet Counts Per Frequency
*/
class TweetCounts
{
private:
    unordered_multimap<int, string> data;

public:
    TweetCounts()
    {
    }

    void recordTweet(string tweetName, int time)
    {
    }

    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime)
    {
    }
};

/*
    Q:  1349. Maximum Students Taking Exam
*/
class Solution4_t
{
public:
    int maxStudents(vector<vector<char>> &seats)
    {
    }
};