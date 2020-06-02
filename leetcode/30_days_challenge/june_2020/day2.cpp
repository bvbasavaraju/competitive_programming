/****************************************************
Date: June 2nd

link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3348/
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
  Q: Delete Node in a Linked List

  Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
  Given linked list -- head = [4,5,1,9], which looks like following:

  Example 1:
    Input: head = [4,5,1,9], node = 5
    Output: [4,1,9]
    Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.

  Example 2:
    Input: head = [4,5,1,9], node = 1
    Output: [4,5,9]
    Explanation: You are given the third node with value 1, the linked list should become 4 -> 5 -> 9 after calling your function.

  Note:
    The linked list will have at least two elements.
    All of the nodes' values will be unique.
    The given node will not be the tail and it will always be a valid node of the linked list.
    Do not return anything from your function.
*/

struct ListNode 
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
  void deleteNode(ListNode* node) 
  {
    if((node == NULL) || (node->next == NULL))
    {
      return;
    }
    
    ListNode* prevNode = NULL;
    while(node->next != NULL)
    {
      node->val = node->next->val;
      prevNode = node;
      
      node = node->next;
    }
    
    prevNode->next = NULL;
  }
};