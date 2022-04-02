/****************************************************
Date: April 13th

link: https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/594/week-2-april-8th-april-14th/3701/
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
  Q: Flatten Nested List Iterator

  You are given a nested list of integers nestedList. Each element is either an integer or a list whose elements 
  may also be integers or other lists. Implement an iterator to flatten it.

  Implement the NestedIterator class:
    NestedIterator(List<NestedInteger> nestedList) Initializes the iterator with the nested list nestedList.
    int next() Returns the next integer in the nested list.
    boolean hasNext() Returns true if there are still some integers in the nested list and false otherwise.

  Example 1:
    Input: nestedList = [[1,1],2,[1,1]]
    Output: [1,1,2,1,1]
    Explanation: 
      By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].

  Example 2:
    Input: nestedList = [1,[4,[6]]]
    Output: [1,4,6]
    Explanation: 
      By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].

  Constraints:
    1 <= nestedList.length <= 500
    The values of the integers in the nested list is in the range [-106, 106].
*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator 
{
private:
  int pos;
  vector<int> vals;
  
  void collectVals(const NestedInteger& nestedInts)
  {
    if(nestedInts.isInteger())
    {
      vals.push_back(nestedInts.getInteger());
    }
    else
    {
      const vector<NestedInteger>& list_ = nestedInts.getList();
      
      NestedIterator temp(list_);
      while(temp.hasNext())
      {
        vals.push_back(temp.next());
      }
    }
  }
public:
  NestedIterator(const vector<NestedInteger>& nestedList) 
  {
    int l = nestedList.size();
    for(int i = 0; i < l; ++i)
    {
      collectVals(nestedList[i]);
    }
    
    pos = 0;
  }
    
  int next() 
  {
    return vals[pos++];
  }

  bool hasNext() 
  {
    return pos >= vals.size() ? false : true;
  }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */