/****************************************************
Date: Feb 20th, 2022
Successful submissions : 2
Time expiration : 0
Not Solved : 1
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/weekly-contest-281
****************************************************/
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

/*
  Q: 2180. Count Integers With Even Digit Sum
*/
class Solution1_t
{
public:
  int countEven(int num) 
  {
    int ans = 0;
    while(num > 0)
    {
      int sum = 0;
      string num_s = std::to_string(num);
      for(auto ch : num_s)
      {
        sum += (ch - '0');
      }
      
      if(sum % 2 == 0)
      {
        ans++;
      }
      
      num--;
    }
    
    return ans;
  }
};

/*
  Q: 2181. Merge Nodes in Between Zeros
*/

struct ListNode 
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution2_t
{
public:
  ListNode* mergeNodes(ListNode* head) 
  {
    ListNode* ans = nullptr;
    ListNode* curr = ans;
    
    int sum = 0;
    while(head != nullptr)
    {
      if(head->val != 0)
      {
        sum += head->val;
      }
      else
      {
        if(sum > 0)
        {
          ListNode* temp = new ListNode(sum);
          if(curr != nullptr)
          {
            curr->next = temp;
            curr = curr->next;
          }
          else
          {
            ans = curr = temp;
          }
        }
        
        sum = 0;
      }
      
      head = head->next;
    }
    
    return ans;
  }
};

/*
  Q: 2182. Construct String With Repeat Limit - yet to resolve!! partial result
*/
class Solution3_t
{
private:
  int getNextPos(vector<int>& freq, int p)
  {
    while(p >= 0)
    {
      if(freq[p] == 0)
      {
        p--;
      }
      else
      {
        break;
      }
    }
    
    return p;
  }
  
  void construct(int ch,int r, string& ans)
  {
    while(r > 0)
    {
      ans += (ch + 'a');
      r--;
    }
  }

public:
  string repeatLimitedString(string s, int repeatLimit) 
  {
    vector<int> freq(26, 0);
    for(auto ch : s)
    {
      freq[ch-'a']++;
    }
    
    int p = 25;
    string ans = "";
    while(p >= 0)
    {
      int r_count = freq[p];
      
      int f = r_count / repeatLimit;
      int rem = f == 0 ? r_count : r_count % repeatLimit;
      
      freq[p] = 0;
      
      int ch = p;
      bool addSeperator = (f > 0) ? true : false;
      while(f > 0)
      {
        construct(ch, repeatLimit, ans);
        ch = getNextPos(freq, ch);
        
        if(ch < 0)
        {
          break;
        }

        if(rem > 0)
        {
          ans += (ch + 'a');
          freq[ch]--;
          ch = p;
        }

        f--;
      }
      
      if(ch < 0)
      {
        break;
      }
      
      if(rem > 0)
      {
        construct(p, rem, ans);
      }

      p = getNextPos(freq, p);
    }
    
    return ans;
  }
};

/*
  Q: 2183. Count Array Pairs Divisible by K
*/

class Solution4_t 
{
public:
  long long countPairs(vector<int>& nums, int k) 
  {

  }
};