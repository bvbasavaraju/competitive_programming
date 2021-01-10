/****************************************************
Date: Jan 9th, 2021
Successful submissions : 2
Time expiration : 0
Not Solved : 2
Wrong Answer/ Partial result : 0

Note: Could not attend challenge because I woke up way late than usual!!

link: https://leetcode.com/contest/weekly-contest-223
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
  Q: 1720. Decode XORed Array
*/
class Solution1_t
{
public:
  vector<int> decode(vector<int>& encoded, int first) 
  {
    int l = encoded.size();
    vector<int> ans(l+1, 0);
    
    ans[0] = first;
    for(int i = 0; i < l; ++i)
    {
      ans[i+1] = ans[i] ^ encoded[i];
    }
    
    return ans;
  }
};

/*
  Q: 1721. Swapping Nodes in a Linked List
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
  ListNode* swapNodes(ListNode* head, int k) 
  {
    vector<ListNode*> nodes;
    
    ListNode* node = head;
    while(node != nullptr)
    {
      nodes.push_back(node);
      node = node->next;
    }
    
    int l = nodes.size();
    
    if(l > 1)
    {
      int temp = nodes[k-1]->val;
      nodes[k-1]->val = nodes[l - k]->val;
      nodes[l - k]->val = temp;
    }
    
    return head;
  }
};

/*
  Q: 1722. Minimize Hamming Distance After Swap Operations
*/
class Solution3_t
{
public:
  int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) 
  {
      
  }
};

/*
  Q: 1723. Find Minimum Time to Finish All Jobs
*/
class Solution4_t
{
public:
  int minimumTimeRequired(vector<int>& jobs, int k) 
  {
      
  }
};