/****************************************************
Date: July 21th

link: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3377/
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

class Solution
{
private:
    bool isPosValid(int i, int j, int r, int c)
    {
        if (i >= r || j >= c || i < 0 || j < 0)
        {
            return false;
        }

        return true;
    }
    bool isWordExist(vector<vector<char>> &board, int i, int j, int r, int c, string &word, int p)
    {
        if (i >= r || j >= c || i < 0 || j < 0 || p > word.size())
        {
            return false;
        }

        p++;

        if (p == word.size())
        {
            return true;
        }

        int ch = board[i][j];
        board[i][j] = '.';

        bool ans = false;
        if (isPosValid(i - 1, j, r, c) && board[i - 1][j] == word[p] && isWordExist(board, i - 1, j, r, c, word, p))
        {
            ans = true;
        }
        else if (isPosValid(i, j - 1, r, c) && board[i][j - 1] == word[p] && isWordExist(board, i, j - 1, r, c, word, p))
        {
            ans = true;
        }
        else if (isPosValid(i + 1, j, r, c) && board[i + 1][j] == word[p] && isWordExist(board, i + 1, j, r, c, word, p))
        {
            ans = true;
        }
        else if (isPosValid(i, j + 1, r, c) && board[i][j + 1] == word[p] && isWordExist(board, i, j + 1, r, c, word, p))
        {
            ans = true;
        }

        board[i][j] = ch;
        return ans;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int r = board.size();
        int c = board[0].size();

        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                if (board[i][j] == word[0] && isWordExist(board, i, j, r, c, word, 0))
                {
                    return true;
                }
            }
        }

        return false;
    }
};