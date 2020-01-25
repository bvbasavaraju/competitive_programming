/****************************************************
Date: October 12, 2019
Successful submissions : 2
Time expiration :
Not Solved : 2
Wrong Answer/ Partial result : 

link: https://leetcode.com/contest/biweekly-contest-12
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
    Q: 1243. Array Transformation

    Given an initial array arr, every day you produce a new array using the array of the previous day.

    On the i-th day, you do the following operations on the array of day i-1 to produce the array of day i:
    + If an element is smaller than both its left neighbor and its right neighbor, then this element is incremented.
    + If an element is bigger than both its left neighbor and its right neighbor, then this element is decremented.
    + The first and last elements never change.
    After some days, the array does not change. Return that final array.

    Example 1:
    Input: arr = [6,2,3,4]
    Output: [6,3,3,4]
    Explanation: 
    On the first day, the array is changed from [6,2,3,4] to [6,3,3,4].
    No more operations can be done to this array.

    Example 2:
    Input: arr = [1,6,3,4,3,5]
    Output: [1,4,4,4,4,5]
    Explanation: 
    On the first day, the array is changed from [1,6,3,4,3,5] to [1,5,4,3,4,5].
    On the second day, the array is changed from [1,5,4,3,4,5] to [1,4,4,4,4,5].
    No more operations can be done to this array.

    Constraints:
    1 <= arr.length <= 100
    1 <= arr[i] <= 100

    Note: There was one failed attempt. Instead of duplicating the array input to another, I just replaced the entries.
*/

class Solution1_t
{
public:
    vector<int> transformArray(vector<int> &arr)
    {
        int l = arr.size();
        bool changed = false;
        do
        {
            changed = false;
            vector<int> result(arr.begin(), arr.end());

            for (int i = 1; i < (l - 1); i++)
            {
                if ((arr[i] < arr[i - 1]) && (arr[i] < arr[i + 1]))
                {
                    changed = true;
                    result[i] = result[i] + 1;
                }
                else if ((arr[i] > arr[i - 1]) && (arr[i] > arr[i + 1]))
                {
                    changed = true;
                    result[i] = result[i] - 1;
                }
            }

            if (changed)
            {
                arr.clear();
                for (int x : result)
                {
                    arr.push_back(x);
                }
            }
        } while (changed);

        return arr;
    }
};

/*
Q: 1244. Design A Leaderboard

Design a Leaderboard class, which has 3 functions:
+ addScore(playerId, score): Update the leaderboard by adding score to the given player's score.
    If there is no player with such id in the leaderboard, add him to the leaderboard with the given score.
+ top(K): Return the score sum of the top K players.
+ reset(playerId): Reset the score of the player with the given id to 0.
    It is guaranteed that the player was added to the leaderboard before calling this function.

Initially, the leaderboard is empty.

Example 1:
    Input: 
    ["Leaderboard","addScore","addScore","addScore","addScore","addScore","top","reset","reset","addScore","top"]
    [[],[1,73],[2,56],[3,39],[4,51],[5,4],[1],[1],[2],[2,51],[3]]
    Output: 
    [null,null,null,null,null,null,73,null,null,null,141]

    Explanation: 
    Leaderboard leaderboard = new Leaderboard ();
    leaderboard.addScore(1,73);   // leaderboard = [[1,73]];
    leaderboard.addScore(2,56);   // leaderboard = [[1,73],[2,56]];
    leaderboard.addScore(3,39);   // leaderboard = [[1,73],[2,56],[3,39]];
    leaderboard.addScore(4,51);   // leaderboard = [[1,73],[2,56],[3,39],[4,51]];
    leaderboard.addScore(5,4);    // leaderboard = [[1,73],[2,56],[3,39],[4,51],[5,4]];
    leaderboard.top(1);           // returns 73;
    leaderboard.reset(1);         // leaderboard = [[2,56],[3,39],[4,51],[5,4]];
    leaderboard.reset(2);         // leaderboard = [[3,39],[4,51],[5,4]];
    leaderboard.addScore(2,51);   // leaderboard = [[2,51],[3,39],[4,51],[5,4]];
    leaderboard.top(3);           // returns 141 = 51 + 51 + 39;

    Constraints:
    1 <= playerId, K <= 10000
    It's guaranteed that K is less than or equal to the current number of players.
    1 <= score <= 100
    There will be at most 1000 function calls.

    Note: Failed attempts 2.
        1. I did ordered in ascending order rather than descending order.
        2. Instead of adding to the existing player's score, I was replacing it.
*/

class Leaderboard_t
{
private:
    unordered_map<int, int> scoreBoard;

public:
    Leaderboard_t()
    {
        printf("New Board\n");
    }

    void addScore(int playerId, int score)
    {
        scoreBoard[playerId] += score;
    }

    int top(int K)
    {
        vector<int> scores(scoreBoard.size(), 0);

        //printf("\n");
        auto it = scoreBoard.begin();
        for (int i = 0; it != scoreBoard.end(); it++, i++)
        {
            scores[i] = it->second;
            //printf("%d, ", scores[i]);
        }

        //printf("\n");
        int retVal = 0;
        sort(scores.begin(), scores.end(), [](const int &num1, const int &num2) {if(num2 < num1){  return true; } return false; });
        for (int i = 0; i < K; i++)
        {
            retVal += scores[i];
            //printf("%d, ", scores[i]);
        }

        return retVal;
    }

    void reset(int playerId)
    {
        //printf("(%d, %d)\n",playerId, scoreBoard[playerId]);
        scoreBoard.erase(playerId);
    }
};

/*
    Q: 1245. Tree Diameter
    Link:    https://leetcode.com/contest/biweekly-contest-12/problems/tree-diameter/

    Given an undirected tree, return its diameter: the number of edges in a longest path in that tree.

    The tree is given as an array of edges where edges[i] = [u, v] is a bidirectional edge between nodes u and v.  Each node has labels in the set {0, 1, ..., edges.length}.

    Example 1:
    Input: edges = [[0,1],[0,2]]
    Output: 2
    Explanation: 
    A longest path of the tree is the path 1 - 0 - 2.

    Example 2:
    Input: edges = [[0,1],[1,2],[2,3],[1,4],[4,5]]
    Output: 4
    Explanation: 
    A longest path of the tree is the path 3 - 2 - 1 - 4 - 5. 

    Constraints:
    0 <= edges.length < 10^4
    edges[i][0] != edges[i][1]
    0 <= edges[i][j] <= edges.length
    The given edges form an undirected tree

    Note: I am still learnign the Graph Theory and its algorithms. For people who ae familiar with that, it would be piece of cake I think.
*/
class Solution2_t
{
public:
    int treeDiameter(vector<vector<int>> &edges)
    {
    }
};

/*
    Q: 1246. Palindrome Removal

    Given an integer array arr, in one move you can select a palindromic subarray arr[i], arr[i+1], ..., arr[j] where i <= j, 
    and remove that subarray from the given array. Note that after removing a subarray, 
    the elements on the left and on the right of that subarray move to fill the gap left by the removal.

    Return the minimum number of moves needed to remove all numbers from the array.

    Example 1:
    Input: arr = [1,2]
    Output: 2

    Example 2:
    Input: arr = [1,3,4,1,5]
    Output: 3
    Explanation: Remove [4] then remove [1,3,1] then remove [5].

    Constraints:
    1 <= arr.length <= 100
    1 <= arr[i] <= 20

    Note: I am assuming I have to use the sliding winodw algorithm here. I am sure. Context time was over, So, I will come back and solve it later!!
*/
class Solution3_t
{
public:
    int minimumMoves(vector<int> &arr)
    {
    }
};