/****************************************************
Date: Feb 8th

link: https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/585/week-2-february-8th-february-14th/3633/
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
  Q: Peeking Iterator

  Given an Iterator class interface with methods: next() and hasNext(), 
  design and implement a PeekingIterator that support the peek() operation
  -- it essentially peek() at the element that will be returned by the next call to next().

  Example:
    Assume that the iterator is initialized to the beginning of the list: [1,2,3].
      Call next() gets you 1, the first element in the list.
      Now you call peek() and it returns 2, the next element. Calling next() after that still return 2. 
      You call next() the final time and it returns 3, the last element. 
      Calling hasNext() after that should return false.

  Follow up: How would you extend your design to be generic and work with all types, not just integer?

  Hide Hint #1  
    Think of "looking ahead". You want to cache the next element.
  
  Hide Hint #2  
    Is one variable sufficient? Why or why not?
  
  Hide Hint #3  
    Test your design with call order of peek() before next() vs next() before peek().
  
  Hide Hint #4  
    For a clean implementation, check out Google's guava library source code.
*/

class Iterator 
{
  struct Data;
  Data* data;
  Iterator(const vector<int>& nums);
  Iterator(const Iterator& iter);

  // Returns the next element in the iteration.
  int next();

  // Returns true if the iteration has more elements.
  bool hasNext() const;
};

class PeekingIterator : public Iterator 
{
private:
  int val;
  bool has_next;
  
public:
  PeekingIterator(const vector<int>& nums) : Iterator(nums), val(0), has_next(false)
  {
    has_next = Iterator::hasNext();
    if(has_next)
    {
      val = Iterator::next();
    }
  }
  
  int peek() 
  {
    return val;
  }
  
  // hasNext() and next() should behave the same as in the Iterator interface.
  // Override them if needed.
  int next() 
  {
    int ans = val;
    has_next = Iterator::hasNext();
    if(has_next)
    {
      val = Iterator::next();
    }
    
    return ans;
  }
  
  bool hasNext() const 
  {
    return has_next;
  }
};