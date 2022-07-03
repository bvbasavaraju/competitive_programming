/****************************************************
Date: July 3rd, 2022
Successful submissions : 2
Time expiration : 0
Memory exhausted : 0
Not Solved : 1
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/weekly-contest-300
****************************************************/

#include<bits/stdc++.h>
using namespace std;

/*
  Q: 2325. Decode the Message
*/
class Solution1_t
{
public:
  string decodeMessage(string key, string message) 
  {
    char letter = 'a';
    vector<char> mappings(26, 0);
    for(char ch : key)
    {
      if(ch == ' ')
      {
        continue;
      }
      
      if(mappings[ch - 'a'] == 0)
      {
        mappings[ch-'a'] = letter;
        letter++;
      }
    }
    
    string ans = "";
    for(char ch : message)
    {
      if(ch == ' ')
      {
        ans += " ";
        continue;
      }
      
      ans += mappings[ch-'a'];
    }
    
    return ans;
  }
};

/*
  Q: 2326. Spiral Matrix IV
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution2_t
{
public:
  vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) 
  {
    vector<vector<int>> ans(m, vector<int>(n, -1));
    
    int r = 0;
    int c = 0;
    
    int direction = 0;  // 0-> right, 1 -> down, 2 -> left, 3 -> up
    while(head != nullptr)
    {
      ans[r][c] = head->val;
      head = head->next;
      
      switch(direction)
      {
        case 0: //right
            if((c >= n-1) || (ans[r][c+1] != -1))
            {
              r++;
              direction = 1;
            }
            else
            {
              c++;
            }
          break;
          
        case 1: //down
            if((r >= m-1) || (ans[r+1][c] != -1))
            {
              c--;
              direction = 2;
            }
            else
            {
              r++;
            }
          break;
          
        case 2: //left
            if((c <= 0) || (ans[r][c-1] != -1))
            {
              r--;
              direction = 3;
            }
            else
            {
              c--;
            }
          break;
          
        case 3: //up
            if((r <= 0) || (ans[r-1][c] != -1))
            {
              c++;
              direction = 0;
            }
            else
            {
              r--;
            }
          break;
      }
    }
    
    if((head != nullptr) && (ans[r][c] == -1))
    {
      ans[r][c] = head->val;
    }
    
    return ans;
  }
};

/*
  Q: 2327. Number of People Aware of a Secret - wrong answer!! - could not submit!!
*/
class Solution3_t
{
public:
  int peopleAwareOfSecret(int n, int delay, int forget) 
  {
    vector<int> count(n+1, 0);
    
    count[1] = 1;
    int forgottenCount = 0;
    for(int i = 2; i <= n; ++i)
    {
      int known = count[i-1];
      if((i - forget) > 0)
      {
        forgottenCount = count[i-forget] - forgottenCount;
      }
      
      known -= forgottenCount;
      
      int spread = 0;
      if(i-1-delay > 0)
      {
        spread = (known - count[i-1-delay]) * 2;
      }
      
      count[i] = known + spread;
    }
    
    return count[n];
  }
};

/*
  Q: 2328. Number of Increasing Paths in a Grid
*/
class Solution4_t
{
public:
  int countPaths(vector<vector<int>>& grid) 
  {
      
  }
};