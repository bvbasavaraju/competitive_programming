/****************************************************
Date: April 25th

link: https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/531/week-4/3309/
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
  Q: LRU Cache - Error in few cases!!

  Design and implement a data structure for Least Recently Used (LRU) cache.
  It should support the following operations: get and put.

  get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
  put(key, value) - Set or insert the value if the key is not already present.
                    When the cache reached its capacity, it should invalidate the least recently used item 
                    before inserting a new item.

  The cache is initialized with a positive capacity.

  Follow up:
  Could you do both operations in O(1) time complexity?

  Example:
  LRUCache cache = new LRUCache( 2 capacity );
  cache.put(1, 1);
  cache.put(2, 2);
  cache.get(1);       // returns 1
  cache.put(3, 3);    // evicts key 2
  cache.get(2);       // returns -1 (not found)
  cache.put(4, 4);    // evicts key 1
  cache.get(1);       // returns -1 (not found)
  cache.get(3);       // returns 3
  cache.get(4);       // returns 4
*/

class LRUCache 
{
private:
  struct DoubleLinkedList_t
  {
    int val;
    int key;
    DoubleLinkedList_t* prev;
    DoubleLinkedList_t* next;
    
    DoubleLinkedList_t(int v, int k)
    {
      val = v;
      key = k;
      prev = NULL;
      next = NULL;
    }
  };
  
  const int capacity;
  int count;
  DoubleLinkedList_t* head;
  DoubleLinkedList_t* tail;
  unordered_map<int, DoubleLinkedList_t*> key_ptr;

  void UpdateList(int key, int value)
  {
    DoubleLinkedList_t* node = key_ptr[key];
    if(node != head && count > 1)
    {
      if(node == tail)
      {
        //move to new tail!
        tail = node->next;
        tail->prev = NULL;
      }
      else if(node != tail && node != head)
      {
        //update the neighbour
        DoubleLinkedList_t* prev_node = node->prev;
        DoubleLinkedList_t* next_node = node->next;

        prev_node->next = next_node;
        next_node->prev = prev_node;
      }
    }

    //node is head
    head->next = node;
    node->prev = head;
    node->next = NULL;

    head = node;
    head->val = value;
  }

  void AddNew(int key, int value)
  {
    if(count >= capacity)
    {
      DoubleLinkedList_t* node = tail;
      
      if(capacity > 1)
      {
        //update tail;
        tail = tail->next;
        tail->prev = NULL;
      }
      else
      {
        //Else both head and tail are NULL
        tail = NULL;
        head = NULL;
      }

      key_ptr[node->key] = NULL;
      delete node;
    }

    DoubleLinkedList_t* node = new DoubleLinkedList_t(value, key);
    if(head != NULL)
    {
      node->prev = head;
      head->next = node;
    }
    else
    {
      tail = node;
    }
    head = node;
    key_ptr[key] = node;
  }
public:
  LRUCache(int capacity_)
    : capacity(capacity_),
      count(0),
      head(NULL),
      tail(NULL)
  {}

  int get(int key) 
  {
    if(key_ptr.count(key) > 0)
    {
      if(key_ptr[key] == NULL)
      {
        return -1;
      }

      int ans = key_ptr[key]->val;
      if(key_ptr[key] != head)
      {
        UpdateList(key, ans);
      }
      return ans;
    }

    return -1;
  }

  void put(int key, int value) 
  {
    if(key_ptr.count(key) > 0)
    {
      if(key_ptr[key] == NULL)
      {
        AddNew(key, value);
      }
      else
      {
        UpdateList(key, value);
      }
    }
    else
    {
      AddNew(key, value);
      if(count < capacity)
      {
        count++;
      }
    }
  }
};

int main()
{
  {
    // ["LRUCache","put","get","put","get","get"]
    // [[1],[2,1],[2],[3,2],[2],[3]]
    LRUCache obj(1);
    obj.put(2,1);
    std::cout<< obj.get(2) << endl;
    obj.put(3,2);
    std::cout<< obj.get(2) << endl;
    std::cout<< obj.get(3) << endl;
    std::cout<< endl << endl;
  }
  {
    LRUCache obj(2);
    obj.put(1,1);
    obj.put(2,2);
    std::cout<< obj.get(1) << endl;
    obj.put(3,3);
    std::cout<< obj.get(2) << endl;
    obj.put(4,4);
    std::cout<< obj.get(1) << endl;
    std::cout<< obj.get(3) << endl;
    std::cout<< obj.get(4) << endl;
    std::cout<< endl << endl;
  }
  {
    LRUCache obj(1);
    std::cout<< obj.get(0) << endl;
    std::cout<< endl << endl;
  }
  {
    LRUCache obj(2);
    std::cout<< obj.get(2) << endl;
    obj.put(2, 6);
    std::cout<< obj.get(1) << endl;
    obj.put(1, 5);
    obj.put(1, 2);
    std::cout<< obj.get(1) << endl;
    std::cout<< obj.get(2) << endl;
    std::cout<< endl << endl;
  }
  {
    LRUCache obj(3);
    obj.put(1,1);
    obj.put(2,2);
    obj.put(3,3);
    obj.put(4,4);
    std::cout<< obj.get(4) << endl;
    std::cout<< obj.get(3) << endl;
    std::cout<< obj.get(2) << endl;
    std::cout<< obj.get(1) << endl;
    obj.put(5,5);
    std::cout<< obj.get(1) << endl;
    std::cout<< obj.get(2) << endl;
    std::cout<< obj.get(3) << endl;
    std::cout<< obj.get(4) << endl;
    std::cout<< obj.get(5) << endl;
    std::cout<< endl << endl;
  }
  {
    LRUCache obj(1);
    obj.put(2,1);
    std::cout<< obj.get(2) << endl;
    std::cout<< endl << endl;
  }
  {
    LRUCache obj(2);
    obj.put(2,1);
    obj.put(2,2);
    std::cout<< obj.get(2) << endl;
    obj.put(1,1);
    obj.put(4,1);
    std::cout<< obj.get(2) << endl;
    std::cout<< endl << endl;
  }
  {
    LRUCache obj(10);
    obj.put(10,13);
    obj.put(3,17);
    obj.put(6,11);
    obj.put(10,5);
    obj.put(9,10);
    std::cout<< obj.get(13) << endl;
    obj.put(2,19);
    std::cout<< obj.get(2) << endl;
    std::cout<< obj.get(3) << endl;   
    obj.put(5,25);
    std::cout<< obj.get(8) << endl;
    obj.put(9,22);
    obj.put(5,5);
    obj.put(1,30);
    std::cout<< obj.get(11) << endl;
    obj.put(9,12);
    std::cout<< obj.get(7) << endl;
    std::cout<< obj.get(5) << endl;
    std::cout<< obj.get(8) << endl;
    std::cout<< obj.get(9) << endl;
    obj.put(4,30);
    obj.put(9,3);
    std::cout<< obj.get(9) << endl;
    std::cout<< obj.get(10) << endl;
    std::cout<< obj.get(10) << endl;
    obj.put(6,14);
    obj.put(3,1);
    std::cout<< obj.get(3) << endl;
    obj.put(10,11);
    std::cout<< obj.get(8) << endl;
    obj.put(2,14);
    std::cout<< obj.get(1) << endl;
    std::cout<< obj.get(5) << endl;
    std::cout<< obj.get(4) << endl;
    obj.put(11,4);
    obj.put(12,24);
    obj.put(5,18);
    std::cout<< obj.get(13) << endl;
    obj.put(7,23);
    std::cout<< obj.get(8) << endl;
    std::cout<< obj.get(12) << endl;
    obj.put(3,27);
    obj.put(2,12);
    std::cout<< obj.get(5) << endl;
    obj.put(2,9);
    obj.put(13,4);
    obj.put(8,18);
    obj.put(1,7);
    std::cout<< obj.get(6) << endl;
    obj.put(9,29);
    obj.put(8,21);
    std::cout<< obj.get(5) << endl;
    obj.put(6,30);
    obj.put(1,12);
    std::cout<< obj.get(10) << endl;
    obj.put(4,15);
    obj.put(7,22);
    obj.put(11,26); // 12 should be deletd here
    obj.put(8,17);
    obj.put(9,29);
    std::cout<< obj.get(5) << endl;
    obj.put(3,4);
    obj.put(11,30);
    std::cout<< obj.get(12) << endl;
    obj.put(4,29);
    std::cout<< obj.get(3) << endl;
    std::cout<< obj.get(9) << endl;
    std::cout<< obj.get(6) << endl;
    obj.put(3,4);
    std::cout<< obj.get(1) << endl;
    std::cout<< obj.get(10) << endl;
    obj.put(3,29);
    obj.put(10,28);
    obj.put(1,20);
    obj.put(11,13);
    std::cout<< obj.get(3) << endl;
    obj.put(3,12);
    obj.put(3,8);
    obj.put(10,9);
    obj.put(3,26);
    std::cout<< obj.get(8) << endl;
    std::cout<< obj.get(7) << endl;
    std::cout<< obj.get(5) << endl;
    obj.put(13,17);
    obj.put(2,27);
    obj.put(11,15);
    std::cout<< obj.get(12) << endl;
    obj.put(9,19);
    obj.put(2,15);
    obj.put(3,16);
    std::cout<< obj.get(1) << endl;
    obj.put(12,17);
    obj.put(9,1);
    obj.put(6,19);
    std::cout<< obj.get(4) << endl;
    std::cout<< obj.get(5) << endl;
    std::cout<< obj.get(5) << endl;
    obj.put(8,1);
    obj.put(11,7);
    obj.put(5,2);
    obj.put(9,28); 
    std::cout<< obj.get(1) << endl;
    obj.put(2,2);
    obj.put(7,4);
    obj.put(4,22);
    obj.put(7,24);
    obj.put(9,26);
    obj.put(13,28);
    obj.put(11,26);
    std::cout<< endl << endl;
  }
/*
[null,null,null,1,null,-1,null,-1,3,4]
[null,-1]
[null,-1,null,-1,null,null,2,6]
[null,null,null,null,null,4,3,2,-1,null,-1,2,3,-1,5]
[null,null,1]
[null,null,null,2,null,null,-1]
[null,null,null,null,null,null,-1,null,19,17,null,-1,null,null,null,-1,null,-1,5,-1,12,null,null,3,5,5,null,null,1,null,-1,null,30,5,30,null,null,null,-1,null,-1,24,null,null,18,null,null,null,null,-1,null,null,18,null,null,-1,null,null,null,null,null,18,null,null,-1,null,4,29,30,null,12,-1,null,null,null,null,29,null,null,null,null,17,22,18,null,null,null,-1,null,null,null,20,null,null,null,-1,18,18,null,null,null,null,20,null,null,null,null,null,null,null]

[-1,19,17,-1,-1,-1,5,-1,12,3,5,5,1,-1,30,5,30,-1,-1,24,18,-1,18,-1,18,-1,4,29,30,12,-1,29,17,22,18,-1,20,-1,18,18,20]
[-1,19,17,-1,-1,-1,5,-1,12,3,5,5,1,-1,30,5,30,-1,-1,24,18,-1,18,-1,18,-1,4,29,30,12,-1,29,17,22,18,-1,20,-1,18,18,20]
*/
}