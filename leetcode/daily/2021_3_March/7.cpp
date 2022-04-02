/****************************************************
Date: March 7th

link: https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/588/week-1-march-1st-march-7th/3657/
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
  Q: Design HashMap

  Design a HashMap without using any built-in hash table libraries.

  To be specific, your design should include these functions:
    put(key, value) : Insert a (key, value) pair into the HashMap. If the value already exists in the HashMap, update the value.
    get(key): Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
    remove(key) : Remove the mapping for the value key if this map contains the mapping for the key.

  Example:
    MyHashMap hashMap = new MyHashMap();
      hashMap.put(1, 1);          
      hashMap.put(2, 2);         
      hashMap.get(1);            // returns 1
      hashMap.get(3);            // returns -1 (not found)
      hashMap.put(2, 1);          // update the existing value
      hashMap.get(2);            // returns 1 
      hashMap.remove(2);          // remove the mapping for 2
      hashMap.get(2);            // returns -1 (not found) 

  Note:
    All keys and values will be in the range of [0, 1000000].
    The number of operations will be in the range of [1, 10000].
    Please do not use the built-in HashMap library.
*/

class MyHashMap 
{
private:
  
  vector<vector<pair<int, int>>> data;
  
public:
    /** Initialize your data structure here. */
    MyHashMap() 
    {
      data.resize(10001);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) 
    {
      int hash = key % 10000;
      vector<pair<int, int>>& vals = data[hash];
      
      bool found = false;
      if(!vals.empty())
      {
        for(auto& p : vals)
        {
          if(p.first == key)
          {
            p.second = value;
            found = true;
          }
        }
      }
      
      if(!found)
      {
        data[hash].push_back({key, value});
      }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) 
    {      
      int hash = key % 10000;
      vector<pair<int, int>>& vals = data[hash];
      for(auto p : vals)
      {
        if(p.first == key)
        {
          return p.second;
        }
      }
      
      return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) 
    {
      int hash = key % 10000;
      vector<pair<int, int>>& vals = data[hash];
      for(auto it = vals.begin(); it != vals.end(); ++it)
      {
        if(it->first == key)
        {
          vals.erase(it);
          break;
        }
      }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

//Below code consumes too much memory!!
// class MyHashMap 
// {
// private:
  
//   struct Data_t
//   {
//     int val;
//     Data_t* next;
//     Data_t* prev;
    
//     Data_t(int val_) : val(val_), next(nullptr), prev(nullptr) {};
//   };
  
//   Data_t* data;
//   vector<Data_t*> keys;
  
// public:
//     /** Initialize your data structure here. */
//     MyHashMap() 
//       : data(nullptr)
//     {
//       keys.resize(1000001, nullptr);
//     }
    
//     /** value will always be non-negative. */
//     void put(int key, int value) 
//     {
//       Data_t* data_ =  new Data_t(value);
      
//       if(data == nullptr)
//       {
//         data = data_;
//       }
//       else
//       {
//         data->next = data_;
//         data_->prev = data;
//         data = data_;
//       }
      
//       keys[key] = data_;
//     }
    
//     /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
//     int get(int key) 
//     {      
//       return (keys[key] != nullptr) ? keys[key]->val : -1;
//     }
    
//     /** Removes the mapping of the specified value key if this map contains a mapping for the key */
//     void remove(int key) 
//     {
//       Data_t* data_ = keys[key];
//       if(data_ != nullptr)
//       {
//         Data_t* prev = data_->prev;
//         Data_t* next = data_->next;
        
//         if(prev != nullptr)
//         {
//           prev->next = data_->next;
//         }
//         if(next != nullptr)
//         {
//           next->prev = data_->prev;
//         }
        
//         if(data_ == data)
//         {
//           data = prev;
//         }
        
//         data_->next = nullptr;
//         data_->prev = nullptr;
//         delete data_;
        
//         keys[key] = nullptr;
//       }
//     }
// };

// /**
//  * Your MyHashMap object will be instantiated and called as such:
//  * MyHashMap* obj = new MyHashMap();
//  * obj->put(key,value);
//  * int param_2 = obj->get(key);
//  * obj->remove(key);
//  */