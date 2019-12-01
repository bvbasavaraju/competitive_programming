/****************************************************
Date: December 1st, 2019
Successful submissions : 1
Time expiration : 1
Not Solved : 2
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/weekly-contest-165
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
    Q:  1275. Find Winner on a Tic Tac Toe Game
*/

class Solution1_t
{
private:
    const int MOVES_REQUIRED_TO_DECIDE = 5;
    const int playerA = 1;
    const int playerB = 2;

    bool AreEqual(int a, int b, int c)
    {
        if ((a == b) && (b == c))
        {
            return true;
        }

        return false;
    }
    int GetWinner(vector<vector<int>> &data)
    {
        int retVal = 0;
        //Rows Check
        if (AreEqual(data[0][0], data[0][1], data[0][2]))
        {
            retVal = data[0][0];
            //printf("R0 = %d\n", retVal);
        }

        if ((retVal == 0) && (AreEqual(data[1][0], data[1][1], data[1][2])))
        {
            retVal = data[1][0];
            //printf("R1 = %d\n", retVal);
        }

        if ((retVal == 0) && (AreEqual(data[2][0], data[2][1], data[2][2])))
        {
            retVal = data[2][0];
            //printf("R2 = %d\n", retVal);
        }

        //Columns Check
        if ((retVal == 0) && (AreEqual(data[0][0], data[1][0], data[2][0])))
        {
            retVal = data[0][0];
            //printf("C0 = %d\n", retVal);
        }

        if ((retVal == 0) && (AreEqual(data[0][1], data[1][1], data[2][1])))
        {
            retVal = data[0][1];
            //printf("C1 = %d\n", retVal);
        }

        if ((retVal == 0) && (AreEqual(data[0][2], data[1][2], data[2][2])))
        {
            retVal = data[0][2];
            //printf("C2 = %d\n", retVal);
        }

        //Diagonal Check
        if ((retVal == 0) && (AreEqual(data[0][0], data[1][1], data[2][2])))
        {
            retVal = data[0][0];
            //printf("DL = %d\n", retVal);
        }

        if ((retVal == 0) && (AreEqual(data[0][2], data[1][1], data[2][0])))
        {
            retVal = data[0][2];
            //printf("DR = %d\n", retVal);
        }

        return retVal;
    }

public:
    string tictactoe(vector<vector<int>> &moves)
    {
        int c = moves.size();
        if (c < MOVES_REQUIRED_TO_DECIDE)
        {
            return "Pending";
        }

        vector<vector<int>> data(3, vector<int>(3, 0));
        for (int i = 0; i < c; i++)
        {
            vector<int> m = moves[i];

            data[m[0]][m[1]] = ((((i + 1) % 2) == 0) ? playerB : playerA);

            if (i >= (MOVES_REQUIRED_TO_DECIDE - 1))
            {
                int result = GetWinner(data);
                //printf("%d\n", result);
                if (result != 0)
                {
                    return (result == playerA) ? "A" : "B";
                }
            }
        }

        return (c < 9) ? "Pending" : "Draw";
    }
};

/*
    Q:  1276. Number of Burgers with No Waste of Ingredients
*/

class Solution2_t
{
private:
    vector<int> IsPossible(int ts, int cs, int s)
    {
        //printf("ts = %d, cs = %d, s = %d", ts, cs, s);
        for (int i = 0; i < ts; i++)
        {
            int usedTS = ts - i * s;
            int remainingTS = (ts - usedTS);

            //For Jumbo
            if (s == 4)
            {
                int usedCS = (usedTS / s);
                int remainingCS = (cs - usedCS);
                if ((usedCS > 0) && (remainingCS > 0))
                {
                    if ((usedTS == (usedCS * 4)) && (remainingTS == (remainingCS * 2)))
                    {
                        printf("i = %d, uTS = %d, rTS = %d, uCS = %d, rCS = %d", i, usedTS, remainingTS, usedCS, remainingCS);
                        return {usedCS, remainingCS};
                    }
                }
            }
            else
            {
                { //Jumbo
                    int usedCS = (usedTS / 4);
                    int remainingCS = (cs - usedCS);
                    if ((usedCS > 0) && (remainingCS > 0))
                    {
                        if ((usedTS == (usedCS * 4)) && (remainingTS == (remainingCS * 2)))
                        {
                            printf("i = %d, uTS = %d, rTS = %d, uCS = %d, rCS = %d", i, usedTS, remainingTS, usedCS, remainingCS);
                            return {usedCS, remainingCS};
                        }
                    }
                }
                { //Small
                    int usedCS = (usedTS / 2);
                    int remainingCS = (cs - usedCS);
                    if (remainingTS > 0)
                    {
                        if (remainingTS == (remainingCS * 2))
                        {
                            return {usedCS, remainingCS};
                        }
                    }
                    else
                    {
                        if (usedTS == (remainingCS * 2))
                        {
                            return {usedCS, remainingCS};
                        }
                    }
                }
            }
        }

        vector<int> empty;
        return empty;
    }

public:
    vector<int> numOfBurgers(int ts, int cs)
    {
        if ((ts == 0) && (cs == 0))
        {
            return {0, 0};
        }

        vector<int> retVal;
        if ((ts == 0) || (cs == 0) || ((ts % 2) != 0) || (ts < (cs * 2)))
        {
            return retVal;
        }

        retVal = IsPossible(ts, cs, 4);
        if (retVal.empty())
        {
            retVal = IsPossible(ts, cs, 2);
        }

        return retVal;
    }
};

/*
    Q: 1277. Count Square Submatrices with All Ones
*/

class Solution3_t
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
    }
};

/*
    Q:  1278. Palindrome Partitioning III
*/

class Solution4_t
{
public:
    int palindromePartition(string s, int k)
    {
    }
};