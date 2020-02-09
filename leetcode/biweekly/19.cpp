/****************************************************
Date: Feb 9, 2020
Successful submissions : 2
Time expiration : 
Not Solved : 2
Wrong Answer/ Partial result : 

link: https://leetcode.com/contest/biweekly-contest-19
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
    Q:  1342. Number of Steps to Reduce a Number to Zero
*/
class Solution1_t
{
public:
    int numberOfSteps(int num)
    {
        int result = 0;
        while (num)
        {
            if (num % 2 == 0)
            {
                num = num / 2;
            }
            else
            {
                num--;
            }

            result++;
        }

        return result;
    }
};

/*
    Q:  1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
*/

class Solution2_t
{
public:
    int numOfSubarrays(vector<int> &a, int k, int t)
    {
        int result = 0;

        int l = a.size();
        int sum = 0;
        for (int i = 0; i <= l; ++i)
        {
            if (i >= k)
            {
                if ((sum / k) >= t)
                {
                    result++;
                }
                //printf("i: %d, sum: %d, result: %d\n",i, sum, result);

                sum -= a[i - k];
            }

            if (i < l)
            {
                sum += a[i];
            }
        }

        return result;
    }
};

/*
    Q:  1344. Angle Between Hands of a Clock - Not solved!
*/
class Solution3_t
{
private:
    bool CalculateAngleToRight(int min, int min180, int hour)
    {
        hour = hour == 12 ? 0 : hour;
        min180 = min180 == 60 ? 0 : min180;

        int minPosInHour = min / 5;
        int min180PosInHour = min180 / 5;

        printf("hour: %d, min: %d[%d], min180: %d[%d]", hour, min, minPosInHour, min180, min180PosInHour);
        if (min > min180)
        {
            if ((hour >= min180PosInHour) && (hour <= minPosInHour))
            {
                return true;
            }
        }
        else
        {
            if ((hour >= minPosInHour) && (hour <= min180PosInHour))
            {
                return true;
            }
        }

        return false;
    }

public:
    double angleClock(int hour, int min)
    {
        double minHandDegreePerMin = 360.0 / 60.0;
        double hourHandDegreePerMin = (5.0 * minHandDegreePerMin) / 60.0;

        double result = 0.0;
        int min180 = (min > 30) ? min - 30 : 30 - min;

        min180 = min180 > 0 ? min180 : 60;
        if (CalculateAngleToRight(min, min180, hour))
        {
            hour = hour == 12 ? 0 : hour;
            min180 = min180 == 60 ? 0 : min180;
            //printf(" %d, %d", temp, (min * hourHandDegreePerMin));
            result = 180.0 - ((hour - min180 / 5) * 5.0 * 6.0) - (min * hourHandDegreePerMin);
        }
        else
        {
            hour = hour == 12 ? 0 : hour;
            min180 = min180 == 60 ? 0 : min180;
            result = 180.0 - ((hour - min180 / 5) * 5.0 * 6.0) + (min * hourHandDegreePerMin);
        }

        return (result > 180.0) ? 180.0 - result : result;
    }
};

/*
    Q:  1345. Jump Game IV
*/

class Solution4_t
{
public:
    int minJumps(vector<int> &arr)
    {
    }
};