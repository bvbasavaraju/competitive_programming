/****************************************************
Date: June 14th

link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/604/week-2-june-8th-june-14th/3772/
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
  Q: Matchsticks to Square

  You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick.
  You want to use all the matchsticks to make one square. You should not break any stick,
  but you can link them up, and each matchstick must be used exactly one time.

  Return true if you can make this square and false otherwise.

  Example 1:
    Input: matchsticks = [1,1,2,2,2]
    Output: true
    Explanation:
      You can form a square with length 2, one side of the square came two sticks with length 1.

  Example 2:
    Input: matchsticks = [3,3,3,3,4]
    Output: false
    Explanation:
      You cannot find a way to form a square with all the matchsticks.

  Constraints:
    1 <= matchsticks.length <= 15
    0 <= matchsticks[i] <= 109

  Hide Hint #1  
    Treat the matchsticks as an array. Can we split the array into 4 equal halves?

  Hide Hint #2  
    Every matchstick can belong to either of the 4 sides. We don't know which one. Maybe try out all options!

  Hide Hint #3  
    For every matchstick, we have to try out each of the 4 options i.e. 
    which side it can belong to. We can make use of recursion for this.

  Hide Hint #4  
    We don't really need to keep track of which matchsticks belong to a particular side during recursion. 
    We just need to keep track of the length of each of the 4 sides.

  Hide Hint #5  
    When all matchsticks have been used we simply need to see the length of all 4 sides. 
    If they're equal, we have a square on our hands!
*/
class Solution 
{
private:
  bool backtrack(vector<int>& matchsticks,vector<int>visited, int target, int curr_sum, int i, int k) 
  {
    if (k == 1) // if k == 1 then we found all subsets
    {
      return true;
    }

    if (curr_sum == target) // we found one subset, go on to the next one starting from curr_sum = 0
    {
      return backtrack(matchsticks, visited, target, 0, 0, k-1);
    }

    for (int j = i; j < matchsticks.size(); j++) 
    {
      if (visited[j] || curr_sum + matchsticks[j] > target) 
      {
        continue; // if we visited this index already or curr_sum + matchsticks[j] > target then we can't use it
      }

      visited[j] = true;
      if (backtrack(matchsticks, visited, target, curr_sum + matchsticks[j], j+1, k)) 
      {
        return true;
      }
      
      visited[j] = false;
    }

    return false;
  }

public:
  bool makesquare(vector<int>& matchsticks) 
  {
    int sum = 0;
    sum = accumulate(matchsticks.begin(), matchsticks.end(), sum);
    if (matchsticks.size() < 4 || sum % 4) 
    {
      return false;
    }

    vector<int> visited(matchsticks.size(), false);
    return backtrack(matchsticks, visited, sum / 4, 0, 0, 4);
  }
};