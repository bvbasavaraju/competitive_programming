/****************************************************
Date: October 12, 2019
Successful submissions : 1
Time expiration : 1 //Second question
Not Solved : 0
Wrong Answer/ Partial result : 

link: https://leetcode.com/contest/weekly-contest-159
****************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>

using namespace std;

/*
    Q: 5230. Check If It Is a Straight Line

    You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point.
    Check if these points make a straight line in the XY plane.

    Ex:
    Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
    Output: true

    Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
    Output: false

    Constraints:
    2 <= coordinates.length <= 1000
    coordinates[i].length == 2
    -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
    coordinates contains no duplicate point.
*/

class Solution1_t
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        int numOfPoints = coordinates.size();
        if (numOfPoints < 2)
        {
            return true;
        }

        int xDiff1 = coordinates[1][0] - coordinates[0][0];
        int yDiff1 = coordinates[1][1] - coordinates[0][1];

        double slope = 1.0000;
        if (yDiff1 != 0)
        {
            slope = ((xDiff1 * 1.0) / (yDiff1 * 1.0));
            //printf("x0 - %d, y0 - %d\nx1 - %d y1 - %d\nslope = %f\n", coordinates[0][0], coordinates[0][1], coordinates[1][0], coordinates[1][1], slope);
        }

        for (int i = 2; i < numOfPoints; i++)
        {
            int xDiff2 = coordinates[i][0] - coordinates[i - 1][0];
            int yDiff2 = coordinates[i][1] - coordinates[i - 1][1];

            if (yDiff2 != 0)
            {
                double newSlope = ((xDiff2 * 1.0) / (yDiff2 * 1.0));
                //printf("%f %f\n", slope, newSlope);
                if (newSlope != slope)
                {
                    return false;
                }
            }
        }

        return true;
    }
};

/*
    Q: 5231. Remove Sub-Folders from the Filesystem

    Given a list of folders, remove all sub-folders in those folders and return in any order the folders after removing.

    If a folder[i] is located within another folder[j], it is called a sub-folder of it.

    The format of a path is one or more concatenated strings of the form: / followed by one or more lowercase English letters. 
    For example, /leetcode and /leetcode/problems are valid paths while an empty string and / are not.

    Ex:
    Input: folder = ["/a","/a/b","/c/d","/c/d/e","/c/f"]
    Output: ["/a","/c/d","/c/f"]
    Explanation: Folders "/a/b/" is a subfolder of "/a" and "/c/d/e" is inside of folder "/c/d" in our filesystem.

    Input: folder = ["/a","/a/b/c","/a/b/d"]
    Output: ["/a"]
    Explanation: Folders "/a/b/c" and "/a/b/d/" will be removed because they are subfolders of "/a".

    Input: folder = ["/a/b/c","/a/b/ca","/a/b/d"]
    Output: ["/a/b/c","/a/b/ca","/a/b/d"]
*/

class Solution2_t
{
private:
    void SortBasedOnLength(vector<string> &folder)
    {
        int count = folder.size();
        for (int i = 1; i < count; i++)
        {
            for (int j = i; j > 0; j--)
            {
                if (folder[j].length() < folder[j - 1].length())
                {
                    swap(folder[j], folder[j - 1]);
                }
                else
                {
                    break;
                }
            }
        }
    }

    void ReplaceForwardSlash(string &data)
    {
        size_t pos = data.find_first_of('/');
        while (pos != std::string::npos)
        {
            data.replace(pos, 1, "");

            pos = data.find_first_of('/');
        }
    }

    bool IsFolderASubFolder(string &folderToBeChecked, string &folder)
    {
        size_t pos = folderToBeChecked.find_last_of('/');
        if ((pos == std::string::npos) || (pos == 0))
        {
            return false;
        }

        string parentFolder = folderToBeChecked.substr(0, pos);
        ReplaceForwardSlash(parentFolder);
        if (parentFolder.empty())
        {
            return false;
        }

        ReplaceForwardSlash(folder);
        if (parentFolder.find(folder) != std::string::npos)
        {
            return true;
        }

        return false;
    }

public:
    vector<string> removeSubfolders(vector<string> &folder)
    {
        SortBasedOnLength(folder);

        // for (string s : folder)
        // {
        //     printf(" %s,", s.c_str());
        // }
        // printf("\n");

        vector<string> retVal;
        retVal.push_back(folder[0]);
        int inputCount = folder.size();
        for (int i = 1; i < inputCount; i++)
        {
            string pathToBeValidated = folder[i];
            //ReplaceForwardSlash(pathToBeValidated);

            int retValCount = retVal.size();
            bool found = false;
            for (int j = 0; j < retValCount; j++)
            {
                string validFolder = retVal[j];
                if (IsFolderASubFolder(pathToBeValidated, validFolder))
                {
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                retVal.push_back(folder[i]);
            }
        }

        // for (string s : retVal)
        // {
        //     printf(" %s,", s.c_str());
        // }
        // printf("\n");

        return retVal;
    }
};

/*
    Q: 1234. Replace the Substring for Balanced String

    You are given a string containing only 4 kinds of characters 'Q', 'W', 'E' and 'R'.

    A string is said to be balanced if each of its characters appears n/4 times where n is the length of the string.

    Return the minimum length of the substring that can be replaced with any other string of the same length to make the original string s balanced.

    Return 0 if the string is already balanced.

    Ex:
    Input: s = "QWER"
    Output: 0
    Explanation: s is already balanced.

    Input: s = "QQWE"
    Output: 1
    Explanation: We need to replace a 'Q' to 'R', so that "RQWE" (or "QRWE") is balanced.

    Input: s = "QQQW"
    Output: 2
    Explanation: We can replace the first "QQ" to "ER". 

    Input: s = "QQQQ"
    Output: 3
    Explanation: We can replace the last 3 'Q' to make s = "QWER".

    Constraints:
    1 <= s.length <= 10^5
    s.length is a multiple of 4
    s contains only 'Q', 'W', 'E' and 'R'
*/
class Solution3_t
{
    //TODO: Solution is wrong. My understanding of the question is wrong.
public:
    int balancedString(string s)
    {
        int sLength = s.length();
        if ((sLength % 4) != 0)
        {
            return -1;
        }

        int subStrLength = 4;
        int balanceCountInSubStr = 1;
        const char *sInCStr = s.c_str();

        int retVal = 0;
        for (int count = 0; count < sLength; count = count + subStrLength)
        {
            int qCount = 0;
            int wCount = 0;
            int eCount = 0;
            int rCount = 0;
            for (int i = 0; i < subStrLength; i++)
            {
                bool withinBalance = false;
                switch (sInCStr[i + count])
                {
                case 'Q':
                    if (qCount < balanceCountInSubStr)
                    {
                        withinBalance = true;
                        qCount++;
                    }
                    break;

                case 'W':
                    if (wCount < balanceCountInSubStr)
                    {
                        withinBalance = true;
                        wCount++;
                    }
                    break;

                case 'E':
                    if (eCount < balanceCountInSubStr)
                    {
                        withinBalance = true;
                        eCount++;
                    }
                    break;

                case 'R':
                    if (rCount < balanceCountInSubStr)
                    {
                        withinBalance = true;
                        rCount++;
                    }
                    break;

                default:
                    printf("Error\n");
                    break;
                }

                if (withinBalance != true)
                {
                    retVal++;
                }
            }
        }

        return retVal;
    }
};

/*
    Q: 1235. Maximum Profit in Job Scheduling

    We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

    You're given the startTime , endTime and profit arrays, you need to output the maximum profit you can take such that
    there are no 2 jobs in the subset with overlapping time range.

    If you choose a job that ends at time X you will be able to start another job that starts at time X.

    Ex:
    Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
    Output: 120
    Explanation: The subset chosen is the first and fourth job. 
    Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.

    Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
    Output: 150
    Explanation: The subset chosen is the first, fourth and fifth job. 
    Profit obtained 150 = 20 + 70 + 60.

    Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
    Output: 6

    Constraints:
    1 <= startTime.length == endTime.length == profit.length <= 5 * 10^4
    1 <= startTime[i] < endTime[i] <= 10^9
    1 <= profit[i] <= 10^4
*/

int main(void)
{
    {
        Solution2_t s;
        vector<string> input = {"/a", "/a/b/c", "/a/b/d"}; //{"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"}; // {"/a/b/c", "/a/b/ca", "/a/b/d"};
        vector<string> result = s.removeSubfolders(input);
    }
    {
        Solution3_t s;
        int replaceCount = s.balancedString("WWEQERQWQWWRWWERQWEQ");
    }
    return 0;
}
