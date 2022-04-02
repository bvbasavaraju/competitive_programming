/****************************************************
Date: Sept 6th

link: https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/554/week-1-september-1st-september-7th/3448/
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

using namespace std;

/*
    Q: Image Overlap

    Two images A and B are given, represented as binary, square matrices of the same size.  
    (A binary matrix has only 0s and 1s as values.)

    We translate one image however we choose (sliding it left, right, up, or down any number of units), 
    and place it on top of the other image.  After, the overlap of this translation is the number of positions that have a 1 in both images.

    (Note also that a translation does not include any kind of rotation.)

    What is the largest possible overlap?

    Example 1: 
        Input: 
                A = [[1,1,0],
                        [0,1,0],
                        [0,1,0]]
                B = [[0,0,0],
                        [0,1,1],
                        [0,0,1]]
    Output: 3
        Explanation: We slide A to right by 1 unit and down by 1 unit.
    
    Notes: 
        1 <= A.length = A[0].length = B.length = B[0].length <= 30
        0 <= A[i][j], B[i][j] <= 1
*/

class Solution
{
private:
    int overlap(vector<vector<int>> &A, vector<vector<int>> &B)
    {
        int retVal = -1;
        int n = A.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int count = 0;
                for (int x = i; x < n; ++x)
                {
                    for (int y = j; y < n; ++y)
                    {
                        if (A[x][y] == 1 && B[x - i][y - j] == 1)
                        {
                            count++;
                        }
                    }
                }

                retVal = max(retVal, count);
            }
        }

        return retVal;
    }

public:
    int largestOverlap(vector<vector<int>> &A, vector<vector<int>> &B)
    {
        return max(overlap(A, B), overlap(B, A));
    }
};