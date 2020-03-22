/****************************************************
Date: March 07, 2020
Successful submissions : 0
Time expiration : 
Not Solved : 0
Wrong Answer/ Partial result : 

Note: Travelling to US. So could not attend the contest

link: https://leetcode.com/contest/biweekly-contest-21
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
  Q:  1370. Increasing Decreasing String
*/

class Solution 
{
private:

  bool getNextBigCharacter(char to_compare_with, const string& s, char& result, int& pos)
  {
    int l = 0;
    int h = s.size() - 1;
    while(l <= h)
    {
      int m = l + (h-l)/2;
      
      if(s[m] > to_compare_with)  // It could be next smaller
      {
        pos = m;
        result = s[m];
        h = m - 1;    // But we want the one which just next larger than to_copare_with. So look at the left side.
      }
      else
      {
        l = m + 1;
      }
    }
    
    return (to_compare_with != result);
  }
  
  bool getNextSmallCharacter(char to_compare_with, const string& s, char& result, int& pos)
  {
    int l = 0;
    int h = s.size() - 1;
    while(l <= h)
    {
      int m = l + (h-l)/2;
      
      if(s[m] < to_compare_with) // it could be the next largest,
      {
        pos = m;
        result = s[m];
        l = m + 1;      // But we want the one which just next smaller than to_copare_with. So look at the right side
      }
      else
      {
        h = m - 1;
      }
    }
    
    return (to_compare_with != result);
  }
  
  int updateResultAndReduceSourceAndReturnSourceSize(char char_to_append, int pos, string& result, string& source)
  {
    result += char_to_append;
    source.erase(pos, 1);
    return source.size();
  }
  
public:
  string sortString(string s) 
  {
    sort(s.begin(), s.end(), [](const char& ch1, const char& ch2) -> bool { return (ch1 < ch2); } );
    
    string result = "";
    while(!s.empty())
    {
      //For steps 1 to 3
      int pos = 0;
      char next_char = s[pos];  // initially first character is the biggest to append!
      char char_to_append = 0;
      do
      {
        char_to_append = next_char;
        if(updateResultAndReduceSourceAndReturnSourceSize(char_to_append, pos, result, s) <= 0)
        {
          break;
        }
      }while(getNextBigCharacter(char_to_append, s, next_char, pos) != false);
      
      //for steps 4 to 6
      pos = s.size() - 1; //Now biggest character should be at the end! as it has already been sorted!
      next_char = s[pos];
      do
      {
        char_to_append = next_char;
        if(updateResultAndReduceSourceAndReturnSourceSize(char_to_append, pos, result, s) <= 0)
        {
          break;
        }
      }while(getNextSmallCharacter(char_to_append, s, next_char, pos) != false);
    }
    
    return result;
  }
};

/*
  Q: 1371. Find the Longest Substring Containing Vowels in Even Counts
*/
class Solution2_t
{
public:
    int findTheLongestSubstring(string s) 
    {
        
    }
};

/*
  Q:  1372. Longest ZigZag Path in a Binary Tree
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution3_t
{
public:
    int longestZigZag(TreeNode* root) 
    {
        
    }
};

/*
  Q:  1373. Maximum Sum BST in Binary Tree
*/
class Solution {
public:
    int maxSumBST(TreeNode* root) 
    {
        
    }
};