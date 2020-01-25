/****************************************************
Date: November 10th, 2019
Successful submissions : 2
Time expiration :
Not Solved : 2
Wrong Answer/ Partial result : 

link: https://leetcode.com/contest/weekly-contest-162
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
    Q: 1252. Cells with Odd Values in a Matrix
    Given n and m which are the dimensions of a matrix initialized by zeros and given an array indices where indices[i] = [ri, ci].
    For each pair of [ri, ci] you have to increment all cells in row ri and column ci by 1.

    Return the number of cells with odd values in the matrix after applying the increment to all indices.

    Ex:
    Input: n = 2, m = 3, indices = [[0,1],[1,1]]
    Output: 6
    Explanation: Initial matrix = [[0,0,0],[0,0,0]].
    After applying first increment it becomes [[1,2,1],[0,1,0]].
    The final matrix will be [[1,3,1],[1,3,1]] which contains 6 odd numbers.

    Input: n = 2, m = 2, indices = [[1,1],[0,0]]
    Output: 0
    Explanation: Final matrix = [[2,2],[2,2]]. There is no odd number in the final matrix.

    Constraints:
    1 <= n <= 50
    1 <= m <= 50
    1 <= indices.length <= 100
    0 <= indices[i][0] < n
    0 <= indices[i][1] < m
*/

class Solution1_t
{
public:
    int oddCells(int r, int c, vector<vector<int>> &indices)
    {
        if (indices.size() <= 0)
        {
            return 0;
        }

        vector<int> rowIncrementCount(r, 0);
        vector<int> colIncrementCount(c, 0);
        for (int i = 0; i < indices.size(); i++)
        {
            rowIncrementCount[indices[i][0]]++;
            colIncrementCount[indices[i][1]]++;
        }

        vector<vector<int>> m(r, vector<int>(c, 0));
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                m[i][j] += rowIncrementCount[i];
            }
        }

        for (int i = 0; i < c; i++)
        {
            for (int j = 0; j < r; j++)
            {
                m[j][i] += colIncrementCount[i];
            }
        }

        int retVal = 0;
        for (int i = 0; i < c; i++)
        {
            for (int j = 0; j < r; j++)
            {
                if (m[j][i] % 2 != 0)
                {
                    retVal++;
                }
            }
        }

        return retVal;
    }
};

/*
    Q: 1253. Reconstruct a 2-Row Binary Matrix

    Given the following details of a matrix with n columns and 2 rows :
    The matrix is a binary matrix, which means each element in the matrix can be 0 or 1.
    The sum of elements of the 0-th(upper) row is given as upper.
    The sum of elements of the 1-st(lower) row is given as lower.
    The sum of elements in the i-th column(0-indexed) is colsum[i], where colsum is given as an integer array with length n.
    Your task is to reconstruct the matrix with upper, lower and colsum.

    Return it as a 2-D integer array.

    If there are more than one valid solution, any of them will be accepted.

    If no valid solution exists, return an empty 2-D array.

    Example:
    Input: upper = 2, lower = 1, colsum = [1,1,1]
    Output: [[1,1,0],[0,0,1]]
    Explanation: [[1,0,1],[0,1,0]], and [[0,1,1],[1,0,0]] are also correct answers.

    Input: upper = 2, lower = 3, colsum = [2,2,1,1]
    Output: []

    Input: upper = 5, lower = 5, colsum = [2,1,2,0,1,0,1,2,0,1]
    Output: [[1,1,1,0,1,0,0,1,0,0],[1,0,1,0,0,0,1,1,0,1]]

    Constraints:
    1 <= colsum.length <= 10^5
    0 <= upper, lower <= colsum.length
    0 <= colsum[i] <= 2
*/
class Solution2_t
{
private:
    bool IsSolutionPossible(int u, int l, vector<int> &colSum)
    {
        int s = colSum.size();
        if ((s < u) || (s < l))
        {
            return false;
        }

        int twoCount = 0;
        int totalSum = 0;
        for (int i = 0; i < s; ++i)
        {
            if (colSum[i] == 2)
            {
                twoCount++;
            }
            totalSum += colSum[i];
        }

        if ((twoCount > u) || (twoCount > l))
        {
            return false;
        }

        if (totalSum != (u + l))
        {
            return false;
        }

        return true;
    }

public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int> &colsum)
    {
        if (!IsSolutionPossible(upper, lower, colsum))
        {
            vector<vector<int>> empty;
            return empty;
        }

        int colCount = colsum.size();
        vector<vector<int>> retVal(2, vector<int>(colCount, 0));
        for (int i = 0; i < colCount; i++)
        {
            if (colsum[i] > 1)
            {
                retVal[0][i] = 1;
                retVal[1][i] = 1;

                upper--;
                lower--;
            }
        }

        for (int i = 0; i < colCount; i++)
        {
            if (colsum[i] != 1)
            {
                continue;
            }

            if (upper > 0)
            {
                retVal[0][i] = 1;
                upper--;
            }
            else if (lower > 0)
            {
                retVal[1][i] = 1;
                lower--;
            }
        }

        return retVal;
    }
};

/*
    Q: 1254. Number of Closed Islands

    Given a 2D grid consists of 0s (land) and 1s (water). 
    An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

    Return the number of closed islands.

    Example 1:
    Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
    Output: 2
    Explanation: 
    Islands in gray are closed because they are completely surrounded by water (group of 1s).
    
    Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
    Output: 1
    
    Input: grid = [[1,1,1,1,1,1,1],
                [1,0,0,0,0,0,1],
                [1,0,1,1,1,0,1],
                [1,0,1,0,1,0,1],
                [1,0,1,1,1,0,1],
                [1,0,0,0,0,0,1],
                [1,1,1,1,1,1,1]]
    Output: 2
    
    Constraints:
    1 <= grid.length, grid[0].length <= 100
    0 <= grid[i][j] <=1
*/

class Solution3_t
{
public:
    int closedIsland(vector<vector<int>> &grid)
    {
    }
};

/*
    Q: 1255. Maximum Score Words Formed by Letters
    Given a list of words, list of  single letters (might be repeating) and score of every character.
    Return the maximum score of any valid set of words formed by using the given letters (words[i] cannot be used two or more times).
    It is not necessary to use all characters in letters and each letter can only be used once.
    Score of letters 'a', 'b', 'c', ... ,'z' is given by score[0], score[1], ... , score[25] respectively.

    Example 1:
    Input: words = ["dog","cat","dad","good"], letters = ["a","a","c","d","d","d","g","o","o"], score = [1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0]
    Output: 23
    Explanation:
    Score  a=1, c=9, d=5, g=3, o=2
    Given letters, we can form the words "dad" (5+1+5) and "good" (3+2+2+5) with a score of 23.
    Words "dad" and "dog" only get a score of 21.
    
    Input: words = ["xxxz","ax","bx","cx"], letters = ["z","a","b","c","x","x","x"], score = [4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10]
    Output: 27
    Explanation:
    Score  a=4, b=4, c=4, x=5, z=10
    Given letters, we can form the words "ax" (4+5), "bx" (4+5) and "cx" (4+5) with a score of 27.
    Word "xxxz" only get a score of 25.
    
    Input: words = ["leetcode"], letters = ["l","e","t","c","o","d"], score = [0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0]
    Output: 0
    Explanation:
    Letter "e" can only be used once.
    
    Constraints:
    1 <= words.length <= 14
    1 <= words[i].length <= 15
    1 <= letters.length <= 100
    letters[i].length == 1
    score.length == 26
    0 <= score[i] <= 10
    words[i], letters[i] contains only lower case English letters.
*/

class Solution4_t
{
private:
    void GivenLetterCount(vector<char> &letters, map<int, int> &result)
    {
        int s = letters.size();
        for (int i = 0; i < s; i++)
        {
            result[letters[i]]++;
        }
    }

    void GetLetterCountForWord(string &word, map<int, int> &result)
    {
        int s = word.size();
        for (int i = 0; i < s; i++)
        {
            result[word[i]]++;
        }
    }

    bool IsWordPossible(string &word, map<int, int> &letterCount)
    {
        map<int, int> wordLetterCount;
        GetLetterCountForWord(word, wordLetterCount);
        int s = word.size();
        for (int i = 0; i < s; i++)
        {
            if (wordLetterCount[word[i]] > letterCount[word[i]])
            {
                return false;
            }
        }

        return true;
    }

public:
    int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score)
    {
        map<int, int> letterCount;
        GivenLetterCount(letters, letterCount);

        vector<string> possibleWords;
        for (int i = 0; i < words.size(); i++)
        {
            if (IsWordPossible(words[i], letterCount))
            {
                possibleWords.push_back(words[i]);
            }
        }

        if (possibleWords.size() <= 0)
        {
            return 0;
        }

        //TODO: Complete it!!

        return -1;
    }
};