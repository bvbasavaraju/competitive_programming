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

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator 
{
private:
  vector<int> container;
  vector<int>::iterator ptr = container.end();
  
public:
  PeekingIterator(const vector<int>& nums) : Iterator(nums) 
  {
      // Initialize any member here.
      // **DO NOT** save a copy of nums and manipulate it directly.
      // You should only use the Iterator interface methods.
    
    int l = nums.size();
    for(int i = 0; i < l; ++i)
    {
      container.push_back(nums[i]);
    }
    
    ptr = container.begin();
  }
  
    // Returns the next element in the iteration without advancing the iterator.
  int peek() 
  {
    if(hasNext())
    {
      return *ptr;
    }
    
    return 0;
  }
  
  // hasNext() and next() should behave the same as in the Iterator interface.
  // Override them if needed.
  int next() 
  {
    int ans = *ptr;
    ptr++;
    
    return ans;
  }
  
  bool hasNext() const 
  {
    return ptr != container.end();    
  }
};