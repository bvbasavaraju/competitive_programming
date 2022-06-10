#include<bits/stdc++.h>
using namespace std;

struct ListNode 
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution 
{
private:
    void reverseBetweenNodes(ListNode* node, ListNode*& head, ListNode*& nextNode, ListNode*& leftNode, ListNode*& rightNode, ListNode*& rightNodeNext, int left, int right)
    {
      if(node == nullptr)
      {
        return;
      }
      
      if(node->val == right)
      {
        rightNode = node;
        rightNodeNext = node->next;
        nextNode = rightNode;
        
        return;
      }

      
      nextNode = node;
      reverseBetweenNodes(node->next, head, nextNode, leftNode, rightNode, rightNodeNext, left, right);
      
      if(leftNode != nullptr && rightNode!= nullptr)
      {
        if(node != nullptr)
        {
          node->next = rightNode;
        }
        else
        {
          head = rightNode;
        }
        leftNode->next = rightNodeNext;

        return;
      }
      else
      {
        if(nextNode != nullptr)
        {
          nextNode->next = node;
          nextNode = node;
        }
      }
      
      if(node->val == left)
      {
        leftNode = node;
      }
    }
      
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
//       ListNode* nextNode = nullptr;
//       ListNode* leftNode = nullptr;
//       ListNode* rightNode = nullptr;
//       ListNode* rightNextNode = nullptr;
      
      /*
        [5]
1
1
[1,2,3,4,5]
2
5
[1,2,3,4,5]
1
4
[1,2,3,4,5]
1
5
      */
//       reverseBetweenNodes(head, head, nextNode, leftNode, rightNode, rightNextNode, left, right);
      
      ListNode* node = head;
      ListNode* prev = nullptr;
      
      ListNode* leftNode = nullptr;
      ListNode* rightNode = nullptr;
      
      stack<ListNode*> nodes;
      while(node != nullptr)
      {
        if(node->val == left)
        {
          leftNode = node;
          nodes.push(prev);
          nodes.push(node);
          node = node->next;
          break;
        }
        prev = node;
        node = node->next;
      }

      while(node != nullptr)
      {
        if(node->val == right)
        {
          rightNode = node;
          nodes.push(node);
          nodes.push(node->next);
          break;
        }
        nodes.push(node);
        node = node->next;
      }

      if(leftNode == nullptr && rightNode == nullptr)
      {
        return head;
      }
      
      ListNode* rightNext = nodes.top();
      
      nodes.pop();
      while(nodes.size() > 1)
      {
        ListNode* top = nodes.top();
        nodes.pop();
        
        top->next = nodes.top();
      }
      
      if(leftNode != nullptr)
      {
        leftNode->next = rightNext;
      }
      
      if(!nodes.empty())
      {
        if(nodes.top() == nullptr && rightNode != nullptr)
        {
          head = rightNode;
        }
        else
        {
          nodes.top()->next = rightNode;
        }
      }
      
      return head;
    }
};

int main()
{
  ListNode* head = nullptr;
  ListNode* next = head;
  for(int i = 5; i <= 5; ++i)
  {
    ListNode* node = new ListNode(i);
    if(next == nullptr)
    {
      head = node;
      next = head;
    }
    else
    {
      next->next = node;
      next = next->next;
    }
  }

  Solution s;
  s.reverseBetween(head, 1, 1);

  return 0;
}