/****************************************************
Date: October 12, 2019
Successful submissions : 0
Time expiration : 0
Not Solved : 4                          // On travel to Edmonton, Canada
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/weekly-contest-158
****************************************************/
/*
    Q: Split a String in Balanced Strings
    Balanced strings are those who have equal quantity of 'L' and 'R' characters.
    Given a balanced string s split it in the maximum amount of balanced strings.
    Return the maximum amount of splitted balanced strings.

    Ex:
    Input: s = "RLRRLLRLRL"
    Output: 4
    Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.

    Input: s = "RLLLLRRRLR"
    Output: 3
    Explanation: s can be split into "RL", "LLLRRR", "LR", each substring contains same number of 'L' and 'R'.

    Input: s = "LLLLRRRR"
    Output: 1
    Explanation: s can be split into "LLLLRRRR".

    Constraints:
    1 <= s.length <= 1000
    s[i] = 'L' or 'R'

    https://leetcode.com/contest/weekly-contest-158/problems/split-a-string-in-balanced-strings/
*/

#include "iostream"
#include <string>
#include <stack>

using namespace std;
class Solution1_t
{
public:
    int balancedStringSplit(string s)
    {
        int length = s.length();

        int numOfBreaksInContinuity = 0;
        const char *sInCStr = s.c_str();
        char ch = sInCStr[0];
        int numOfContinuousLetters = 1;

        for (int i = 1; i < length; i++)
        {
            if (ch == sInCStr[i])
            {
                numOfContinuousLetters++;
            }
            else
            {
                numOfBreaksInContinuity++;

                //reset the required things
                i = i + numOfContinuousLetters;
                if (i < length)
                {
                    ch = sInCStr[i];
                    numOfContinuousLetters = 1;
                }
            }
        }

        return numOfBreaksInContinuity;
    }
};

// int main()
// {
//     Solution1_t s1;
//     printf("\n Split count of a String %s in Balanced Strings is: %d", "RLRRLLRLRL", s1.balancedStringSplit("RLRRLLRLRL"));
//     printf("\n Split count of a String %s in Balanced Strings is: %d", "RLLLLRRRLR", s1.balancedStringSplit("RLLLLRRRLR"));
//     printf("\n Split count of a String %s in Balanced Strings is: %d", "LLLLRRRR", s1.balancedStringSplit("LLLLRRRR"));
//     //TODO: Expected answer is: 2 for below problem
//     printf("\n Split count of a String %s in Balanced Strings is: %d", "RRLRRLRLLLRL", s1.balancedStringSplit("RRLRRLRLLLRL"));
//     return 0;
// }

/*
    Q: Queens That Can Attack the King

    On an 8x8 chessboard, there can be multiple Black Queens and one White King.
    Given an array of integer coordinates queens that represents the positions of the Black Queens, 
    and a pair of coordinates king that represent the position of the White King, 
    return the coordinates of all the queens (in any order) that can attack the King.

    https://leetcode.com/contest/weekly-contest-158/problems/queens-that-can-attack-the-king/
*/
#include <vector>

class Solution2_t
{
private:
    enum queenPositions_t
    {
        COLUMN_TOP = 0,
        COLUMN_BOTTOM = 1,
        ROW_LEFT = 2,
        ROW_RIGHT = 3,
        DIAG_TOP_LEFT = 4,
        DIAG_TOP_RIGHT = 5,
        DIAG_BOTTOM_LEFT = 6,
        DIAG_BOTTOM_RIGHT = 7,
    };

    vector<vector<int>> possibleQueenPositions;

    void CheckForQueenPositionInRows(vector<int> inputPos, vector<int> kingPos)
    {
        if (kingPos[1] == inputPos[1])
        {
            return;
        }

        if (kingPos[1] < inputPos[1]) //Row right
        {
            vector<int> existingPos = possibleQueenPositions[ROW_RIGHT];
            if ((existingPos.size() == 0) || (existingPos[1] > inputPos[1]))
            {
                possibleQueenPositions[ROW_RIGHT] = inputPos;
            }
        }

        else if (inputPos[1] < kingPos[1]) //Row left
        {
            vector<int> existingPos = possibleQueenPositions[ROW_LEFT];
            if ((existingPos.size() == 0) || (inputPos[1] > existingPos[1]))
            {
                possibleQueenPositions[ROW_LEFT] = inputPos;
            }
        }
    }

    void CheckForQueenPositionInColumns(vector<int> inputPos, vector<int> kingPos)
    {
        if (kingPos[0] == inputPos[0])
        {
            return;
        }

        if (kingPos[0] < inputPos[0]) //Column Bottom
        {
            vector<int> existingPos = possibleQueenPositions[COLUMN_BOTTOM];
            if ((existingPos.size() == 0) || (existingPos[0] > inputPos[0]))
            {
                possibleQueenPositions[COLUMN_BOTTOM] = inputPos;
            }
        }

        else if (inputPos[0] < kingPos[0]) //Column Top
        {
            vector<int> existingPos = possibleQueenPositions[COLUMN_TOP];
            if ((existingPos.size() == 0) || (inputPos[0] > existingPos[0]))
            {
                possibleQueenPositions[COLUMN_TOP] = inputPos;
            }
        }
    }

    void CheckForQueenPosInTopLeft(vector<int> inputPos, vector<int> kingPos)
    {
        if ((kingPos[0] <= inputPos[0]) || (kingPos[1] <= inputPos[1]))
        {
            return;
        }

        vector<int> existingPos = possibleQueenPositions[DIAG_TOP_LEFT];
        if ((existingPos.size() == 0) || ((inputPos[0] >= existingPos[0]) && (inputPos[1] > existingPos[1])))
        {
            possibleQueenPositions[DIAG_TOP_LEFT] = inputPos;
        }
    }

    void CheckForQueenPosInTopRight(vector<int> inputPos, vector<int> kingPos)
    {
        if ((kingPos[0] <= inputPos[0]) || (kingPos[1] > inputPos[1]))
        {
            return;
        }

        vector<int> existingPos = possibleQueenPositions[DIAG_TOP_RIGHT];
        if ((existingPos.size() == 0) || ((inputPos[0] >= existingPos[0]) && (inputPos[1] < existingPos[1])))
        {
            possibleQueenPositions[DIAG_TOP_RIGHT] = inputPos;
        }
    }

    void CheckForQueenPosInBottomLeft(vector<int> inputPos, vector<int> kingPos)
    {
        if ((kingPos[0] >= inputPos[0]) || (kingPos[1] <= inputPos[1]))
        {
            return;
        }

        vector<int> existingPos = possibleQueenPositions[DIAG_BOTTOM_LEFT];
        if ((existingPos.size() == 0) || ((inputPos[0] <= existingPos[0]) && (inputPos[1] > existingPos[1])))
        {
            possibleQueenPositions[DIAG_BOTTOM_LEFT] = inputPos;
        }
    }

    void CheckForQueenPosInBottomRight(vector<int> inputPos, vector<int> kingPos)
    {
        if ((kingPos[0] >= inputPos[0]) || (kingPos[1] >= inputPos[1]))
        {
            return;
        }

        vector<int> existingPos = possibleQueenPositions[DIAG_BOTTOM_RIGHT];
        if ((existingPos.size() == 0) || ((inputPos[0] <= existingPos[0]) && (inputPos[1] < existingPos[1])))
        {
            possibleQueenPositions[DIAG_BOTTOM_RIGHT] = inputPos;
        }
    }

    void CheckPositionAndUpdate(vector<int> inputPos, vector<int> kingPos)
    {
        if ((inputPos.size() != 2) || (kingPos.size() != 2))
        {
            return;
        }

        if (kingPos[0] == inputPos[0])
        {
            CheckForQueenPositionInRows(inputPos, kingPos);
        }
        else if (kingPos[1] == inputPos[1])
        {
            CheckForQueenPositionInColumns(inputPos, kingPos);
        }
        else
        {
            int rowDiff = inputPos[0] - kingPos[0];
            int columnDiff = inputPos[1] - kingPos[1];

            if ((rowDiff < 0) && (columnDiff < 0) && (rowDiff == columnDiff))
            {
                CheckForQueenPosInTopLeft(inputPos, kingPos);
            }
            else if ((rowDiff < 0) && (columnDiff > 0) && ((rowDiff * -1) == columnDiff))
            {
                CheckForQueenPosInTopRight(inputPos, kingPos);
            }
            else if ((rowDiff > 0) && (columnDiff < 0) && (rowDiff == (columnDiff * -1)))
            {
                CheckForQueenPosInBottomLeft(inputPos, kingPos);
            }
            else if ((rowDiff > 0) && (columnDiff > 0) && (rowDiff == columnDiff))
            {
                CheckForQueenPosInBottomRight(inputPos, kingPos);
            }
        }
    }

public:
    Solution2_t()
    {
        for (int i = 0; i < 8; i++)
        {
            vector<int> emptyPos;
            possibleQueenPositions.push_back(emptyPos);
        }
    }

    vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens, vector<int> &king)
    {
        int lengthOfPositions = queens.size();
        for (int i = 0; i < lengthOfPositions; i++)
        {
            if ((queens[i][0] == 3) && (queens[i][1] == 3))
            {
                int j = i;
            }
            CheckPositionAndUpdate(queens[i], king);
        }

        vector<vector<int>> retVal;
        for (int i = 0; i < 8; i++)
        {
            if (possibleQueenPositions[i].size() != 0)
            {
                retVal.push_back(possibleQueenPositions[i]);
            }
        }

        return retVal;
    }

    void PrintPositions(vector<vector<int>> positions)
    {
        printf("************\n");
        int length = positions.size();
        for (int i = 0; i < length; i++)
        {
            vector<int> pos = positions[i];
            if (pos.size() == 2)
            {
                printf("%d, %d\n", pos[0], pos[1]);
            }
        }
        printf("************\n\n");
    }
};

// int main()
// {
//     {
//         Solution2_t s2;
//         vector<vector<int>> queens = {{0, 1}, {1, 0}, {4, 0}, {0, 4}, {3, 3}, {2, 4}};
//         vector<int> king = {0, 0};
//         vector<vector<int>> attackableQueens = s2.queensAttacktheKing(queens, king);
//         s2.PrintPositions(attackableQueens);
//     }

//     {
//         Solution2_t s2;
//         vector<vector<int>> queens = {{0, 0}, {1, 1}, {2, 2}, {3, 4}, {3, 5}, {4, 4}, {4, 5}};
//         vector<int> king = {3, 3};
//         vector<vector<int>> attackableQueens = s2.queensAttacktheKing(queens, king);
//         s2.PrintPositions(attackableQueens);
//     }

//     {
//         Solution2_t s2;
//         vector<vector<int>> queens = {{5, 6}, {7, 7}, {2, 1}, {0, 7}, {1, 6}, {5, 1}, {3, 7}, {0, 3}, {4, 0}, {1, 2}, {6, 3}, {5, 0}, {0, 4}, {2, 2}, {1, 1}, {6, 4}, {5, 4}, {0, 0}, {2, 6}, {4, 5}, {5, 2}, {1, 4}, {7, 5}, {2, 3}, {0, 5}, {4, 2}, {1, 0}, {2, 7}, {0, 1}, {4, 6}, {6, 1}, {0, 6}, {4, 3}, {1, 7}};
//         vector<int> king = {3, 4};
//         vector<vector<int>> attackableQueens = s2.queensAttacktheKing(queens, king);
//         s2.PrintPositions(attackableQueens);
//     }

//     {
//         Solution2_t s2;
//         vector<vector<int>> queens = {{2, 0}, {1, 6}, {3, 4}, {4, 1}};
//         vector<int> king = {3, 5};
//         vector<vector<int>> attackableQueens = s2.queensAttacktheKing(queens, king);
//         s2.PrintPositions(attackableQueens);
//     }

//     return 0;
// }

/*
    Q: Dice Roll Simulation

    A die simulator generates a random number from 1 to 6 for each roll.
    You introduced a constraint to the generator such that it cannot roll the number i more than rollMax[i] (1-indexed) consecutive times.

    Given an array of integers rollMax and an integer n, return the number of distinct sequences that can be obtained with exact n rolls.

    Two sequences are considered different if at least one element differs from each other.
    Since the answer may be too large, return it modulo 10^9 + 7.

    Ex:
    Input: n = 2, rollMax = [1,1,2,2,2,3]
    Output: 34
    Explanation: There will be 2 rolls of die, if there are no constraints on the die, there are 6 * 6 = 36 possible combinations.
    In this case, looking at rollMax array, the numbers 1 and 2 appear at most once consecutively,
    therefore sequences (1,1) and (2,2) cannot occur, so the final answer is 36-2 = 34.

    Input: n = 2, rollMax = [1,1,1,1,1,1]
    Output: 30

    Input: n = 3, rollMax = [1,1,1,2,2,3]
    Output: 181

    Constraints:
    1 <= n <= 5000
    rollMax.length == 6
    1 <= rollMax[i] <= 15
*/

class Solution3_t
{
public:
    int dieSimulator(int n, vector<int> &rollMax)
    {
    }
};

/*
    Q: Maximum Equal Frequency
    Given an array nums of positive integers, return the longest possible length of an array prefix of nums,
    such that it is possible to remove exactly one element from this prefix so that every number 
    that has appeared in it will have the same number of occurrences.

    If after removing one element there are no remaining elements,
    it's still considered that every appeared number has the same number of occurrences (0).

    Ex:
    Input: nums = [2,2,1,1,5,3,3,5]
    Output: 7
    Explanation: For the subarray [2,2,1,1,5,3,3] of length 7, if we remove nums[4]=5, we will get [2,2,1,1,3,3],
    so that each number will appear exactly twice.

    Input: nums = [1,1,1,2,2,2,3,3,3,4,4,4,5]
    Output: 13

    Input: nums = [1,1,1,2,2,2]
    Output: 5

    Input: nums = [10,2,8,9,3,8,1,5,2,3,7,6]
    Output: 8

    Constraints:
    2 <= nums.length <= 10^5
    1 <= nums[i] <= 10^5
*/

class Solution4_t
{
public:
    int maxEqualFreq(vector<int> &nums)
    {
    }
};