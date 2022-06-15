#include<bits/stdc++.h>
using namespace std;

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
      prev = nullptr;
      next = nullptr;
    }
  };
  
  const int capacity;
  int count;
  DoubleLinkedList_t* head;
  DoubleLinkedList_t* tail;
  unordered_map<int, DoubleLinkedList_t*> key_ptr;

  void UpdateList(int key)
  {
    DoubleLinkedList_t* node = key_ptr[key];
    if(node != head && count > 1)
    {
      if(node == tail)
      {
        //move to new tail!
        DoubleLinkedList_t* prev = tail->prev;
        prev->next = nullptr;
        tail = prev;
      }
      else if(node != tail && node != head)
      {
        //update the neighbour
        DoubleLinkedList_t* prev_node = node->prev;
        DoubleLinkedList_t* next_node = node->next;

        prev_node->next = next_node;
        next_node->prev = prev_node;
      }
      
      node->prev = nullptr;
      node->next = head;
      head->prev = node;
      head = node;
    }
  }

  void AddNew(int key, int value)
  {
    DoubleLinkedList_t* node = new DoubleLinkedList_t(value, key);
    if(head != nullptr)
    {
      node->next = head;
      head->prev = node;
      head = node;
    }
    else
    {
      head = node;
      tail = node;
    }
    
    key_ptr[key] = node;
    
    while(key_ptr.size() > capacity)
    {
      DoubleLinkedList_t* prev = tail->prev;
      prev->next = nullptr;
      
      key_ptr.erase(tail->key);
      delete tail;
      
      tail = prev;
    }
  }
public:
  LRUCache(int capacity_)
    : capacity(capacity_),
      count(0),
      head(nullptr),
      tail(nullptr)
  {}

  int get(int key) 
  {
    int ans = -1;
    if(key_ptr.find(key) != key_ptr.end())
    {
      ans = key_ptr[key]->val;
      if(key_ptr[key] != head)
      {
        UpdateList(key);
      }
    }

    return ans;
  }

  void put(int key, int value) 
  {
    if(key_ptr.find(key) != key_ptr.end())
    {
      key_ptr[key]->val = value;
      UpdateList(key);
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