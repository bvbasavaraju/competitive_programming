#include<bits/stdc++.h>
using namespace std;

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
class Solution 
{
  private:
    ListNode* reverse(ListNode* node, int left, int right, int currPos, ListNode*& beforeLeft, ListNode*& leftNode, ListNode*& rightNode)
    {
      if(node == nullptr)
      {
        return node;
      }
      
      //if current Node is right node, & leftNode is not null, then left next = node->next and update right node
      if(currPos == right)
      {
        if(leftNode != nullptr)
        {
          leftNode->next = node->next;
        }
        rightNode = node;
        return node;
      }
      
      //if currPos is left, then update the left node;
      if(currPos == left)
      {
        leftNode = node;
      }
      
      // if it is less than left, then update before left
      if(currPos < left)
      {
        beforeLeft = node;
      }
      
      //recursive call for till both right and left nodes are captured;
      ListNode* nextNode = reverse(node->next, left, right, currPos+1, beforeLeft, leftNode, rightNode);
      
      //Update the nextNode->next as current till we reach left node
      if(currPos > left && nextNode != nullptr)
      {
        nextNode->next = node;
      }
      else if(currPos == left)
      {
        // if it is equal to left, by now we have traversed till right and reversed the till this point.
        //Just point next node to current, and then update the before left as rightNode!!
        if(nextNode != nullptr)
        {
          nextNode->next = node; 
        }
        
        if((rightNode != nullptr) && (beforeLeft != nullptr))
        {
          beforeLeft->next = rightNode;
        }
      }
      
      return node;
    }
      
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
      ListNode* beforeLeft = nullptr;
      ListNode* leftNode = nullptr;
      ListNode* rightNode = nullptr;
      
      ListNode* node = reverse(head, left, right, 1, beforeLeft, leftNode, rightNode);
      
      if(left == 1)
      {
        return rightNode;
      }
      
      return head;
    }
};