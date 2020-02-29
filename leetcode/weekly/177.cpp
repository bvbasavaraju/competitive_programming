/****************************************************
Date: Feb 22, 2020
Successful submissions : 0
Time expiration : 0
Not Solved : 0
Wrong Answer/ Partial result : 0

Note: Week when personal work had more importance than this!!

link: https://leetcode.com/contest/biweekly-contest-177
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
    Q:  1360. Number of Days Between Two Dates - solved
*/
class Solution1_t
{
private:
    int year1;
    int year2;
    int month1;
    int month2;
    int date1;
    int date2;

    int numOfDays(int m, int d, int y)
    {
        //printf("y: %d, m: %d, d: %d\t", y, m, d);
        int numOfDays = 0;
        for (int i = 1; i < m; i++)
        {
            switch (i)
            {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                numOfDays += 31;
                break;

            case 4:
            case 6:
            case 9:
            case 11:
                numOfDays += 30;
                break;

            case 2:
                numOfDays += 28;
                if ((y % 4 == 0) && ((y % 100 != 0) || (y % 400 == 0)))
                {
                    numOfDays += 1;
                }
                break;

            default:
                return 0;
            }
        }

        numOfDays += d;

        //printf("- %d\n", numOfDays);
        return numOfDays;
    }

public:
    int daysBetweenDates(string date1, string date2)
    {
        int result = 0;

        int y1 = ((date1[0] - '0') * 1000) + ((date1[1] - '0') * 100) + ((date1[2] - '0') * 10) + (date1[3] - '0');
        int y2 = ((date2[0] - '0') * 1000) + ((date2[1] - '0') * 100) + ((date2[2] - '0') * 10) + (date2[3] - '0');
        int m1 = ((date1[5] - '0') * 10) + (date1[6] - '0');
        int m2 = ((date2[5] - '0') * 10) + (date2[6] - '0');
        int d1 = ((date1[8] - '0') * 10) + (date1[9] - '0');
        int d2 = ((date2[8] - '0') * 10) + (date2[9] - '0');

        bool date1IsGreater = false;
        int lly = y1;
        int upy = y2;
        if ((y1 > y2) || ((y1 == y2) && (m1 > m2)) || ((y1 == y2) && (m1 == m2) && (d1 > d2)))
        {
            lly = y2;
            upy = y1;
            date1IsGreater = true;
        }

        for (int i = lly; i < upy; i++)
        {
            result += 365;
            if (i % 4 == 0)
            {
                result += 1;
            }
        }

        result += numOfDays(date1IsGreater ? m1 : m2, date1IsGreater ? d1 : d2, date1IsGreater ? y1 : y2);
        result -= numOfDays(date1IsGreater ? m2 : m1, date1IsGreater ? d2 : d1, date1IsGreater ? y2 : y1);
        return result;
    }
};

/*
    Q:  1361. Validate Binary Tree Nodes 
*/
class Solution2_t
{
public:
    bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild)
    {
    }
};

/*
    Q:  1362. Closest Divisors - solved
*/
class Solution3_t
{
private:
    vector<int> getMin(vector<int> v1, vector<int> v2)
    {
        if (v1.size() == 0)
        {
            return v2;
        }

        if (v2.size() == 0)
        {
            return v1;
        }

        if ((v1[1] - v1[0]) <= (v2[1] - v2[0]))
        {
            return v1;
        }

        return v2;
    }

    vector<int> getFactors(int num)
    {
        vector<int> result;
        int h = sqrt(num) + 1;
        for (int i = 2; i <= h; i++)
        {
            if (num % i == 0)
            {
                int f2 = num / i;
                result = getMin(result, {i, f2});
            }
        }

        return result;
    }

public:
    vector<int> closestDivisors(int num)
    {
        vector<int> n1_factors = getFactors(num + 1);
        vector<int> n2_factors = getFactors(num + 2);

        return getMin(n1_factors, n2_factors);
    }
};

/*
    Q:  1363. Largest Multiple of Three - wrong!!
*/
class Solution4_t
{
private:
    string getNumsInString(int val, int count)
    {
        if (count <= 0)
        {
            return "";
        }

        int nums = 0;
        while (count > 0)
        {
            nums = (nums * 10) + val;
            count--;
        }

        printf("%d, %s\n", nums, std::to_string(nums).c_str());
        return std::to_string(nums);
    }

    int getCount(int processingNum, int reqNum, map<int, int> &counts)
    {
        int retVal = 0;
        if ((counts.count(processingNum) <= 0) || (counts.count(reqNum) <= 0))
        {
            return retVal;
        }

        if (counts[processingNum] >= counts[reqNum])
        {
            retVal = counts[reqNum];
            counts[reqNum] = 0;
            counts[processingNum] -= retVal;
        }
        else
        {
            retVal = counts[processingNum];
            counts[processingNum] = 0;
            counts[reqNum] -= retVal;
        }

        printf("%d\n", retVal);
        return retVal;
    }

    string getPossibleNums(int val, map<int, int> &counts)
    {
        string result = "";
        int nums_ = counts[val];
        if (nums_ % 3 == 0)
        {
            result += getNumsInString(val, nums_);
        }
        else
        {
            result += getNumsInString(val, nums_ - (nums_ % 3));
        }

        return result;
    }

public:
    string largestMultipleOfThree(vector<int> &digits)
    {
        map<int, int> counts;
        int l = digits.size();
        int fromEnd;
        for (int i = 0; i < l / 2; ++i)
        {
            fromEnd = l - 1 - i;
            counts[digits[i]]++;
            counts[digits[fromEnd]]++;
        }

        if (l % 2 != 0)
        {
            counts[digits[l / 2]]++;
        }

        map<int, string> values_to_append;
        string result = "";
        for (int i = 9; i >= 0; --i)
        {
            int rem = i % 3;
            if (rem == 0)
            {
                result += getNumsInString(i, counts[i]);
            }
            else
            {
                if (counts.count(i) <= 0)
                {
                    continue;
                }

                switch (i)
                {
                case 8:
                {
                    int num = getCount(8, 7, counts);
                    if (num > 0)
                    {
                        result += getNumsInString(8, num);
                        values_to_append[7].append(getNumsInString(7, num));
                    }

                    num = getCount(8, 4, counts);
                    if (num > 0)
                    {
                        result += getNumsInString(8, num);
                        values_to_append[4].append(getNumsInString(4, num));
                    }

                    num = getCount(8, 1, counts);
                    if (num > 0)
                    {
                        result += getNumsInString(8, num);
                        values_to_append[1].append(getNumsInString(1, num));
                    }
                }
                break;

                case 7:
                {
                    int num = getCount(7, 5, counts);
                    if (num > 0)
                    {
                        result += getNumsInString(7, num);
                        values_to_append[5].append(getNumsInString(5, num));
                    }

                    num = getCount(7, 2, counts);
                    if (num > 0)
                    {
                        result += getNumsInString(7, num);
                        values_to_append[2].append(getNumsInString(2, num));
                    }

                    //result += getNumsInString(7, values_to_append.count(7));
                    result += values_to_append[7];
                }
                break;

                case 5:
                {
                    int num = getCount(5, 4, counts);
                    if (num > 0)
                    {
                        result += getNumsInString(5, num);
                        values_to_append[4].append(getNumsInString(4, num));
                    }

                    num = getCount(5, 1, counts);
                    if (num > 0)
                    {
                        result += getNumsInString(5, num);
                        values_to_append[1].append(getNumsInString(1, num));
                    }

                    //result += getNumsInString(5, values_to_append.count(5));
                    result += values_to_append[5];
                }
                break;

                case 4:
                {
                    int num = getCount(4, 2, counts);
                    if (num > 0)
                    {
                        result += getNumsInString(4, num);
                        values_to_append[2].append(getNumsInString(2, num));
                    }

                    //result += getNumsInString(4, values_to_append.count(4));
                    result += values_to_append[4];
                }
                break;

                case 2:
                {
                    int num = getCount(2, 1, counts);
                    if (num > 0)
                    {
                        result += getNumsInString(2, num);
                        values_to_append[1].append(getNumsInString(1, num));
                    }

                    //result += getNumsInString(2, values_to_append.count(2));
                    result += values_to_append[2];
                }
                break;

                case 1:
                {
                    //result += getNumsInString(1, values_to_append.count(1));
                    result += values_to_append[1];
                }
                break;
                }

                result += getPossibleNums(i, counts);
            }
        }

        printf("%s\n", result.c_str());
        return result[0] == '0' ? "0" : result;
    }
};

int main()
{
    Solution4_t s4;
    //vector<int> n = {8, 9, 1};
    vector<int> n = {1, 1, 1, 2, 2, 2};
    string nums = s4.largestMultipleOfThree(n);

    printf("%s", nums.c_str());
    return 0;
}