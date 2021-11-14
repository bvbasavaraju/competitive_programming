/****************************************************
Date: November 13th

https://leetcode.com/problems/iterator-for-combination/
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
  Q: 1286. Iterator for Combination

  Design the CombinationIterator class:
    CombinationIterator(string characters, int combinationLength):
      Initializes the object with a string characters of sorted distinct lowercase English letters and 
      a number combinationLength as arguments.
    next():
      Returns the next combination of length combinationLength in lexicographical order.
    hasNext():
      Returns true if and only if there exists a next combination.

  Example 1:
  Input
    ["CombinationIterator", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
    [["abc", 2], [], [], [], [], [], []]
  Output
    [null, "ab", true, "ac", true, "bc", false]

  Explanation
    CombinationIterator itr = new CombinationIterator("abc", 2);
    itr.next();    // return "ab"
    itr.hasNext(); // return True
    itr.next();    // return "ac"
    itr.hasNext(); // return True
    itr.next();    // return "bc"
    itr.hasNext(); // return False

  Constraints:
    1 <= combinationLength <= characters.length <= 15
    All the characters of characters are unique.
    At most 104 calls will be made to next and hasNext.
    It's guaranteed that all calls of the function next are valid.
*/

class CombinationIterator 
{
private:
  string chars;
  vector<int> ptrs;
  
  void adjustPtrs()
  {
    int p = 0;
    int index = INT_MAX;
    int l = ptrs.size();
    for(int i = l-1; i >= 0; --i)
    {
      if((ptrs[i] + 1) >= (chars.size() - p))
      {
        index = i;
      }
      else
      {
        break;
      }
      
      p++;
    }
    
    if(index == INT_MAX)
    {
      ptrs[l-1]++;
    }
    else
    {
      index = index == 0 ? 0 : index-1;
      ptrs[index]++;
      for(int i = index+1; i < l; ++i)
      {
        ptrs[i] = ptrs[i-1] + 1;
      }
    }
  }
  
public:
  CombinationIterator(string characters, int combinationLength) 
  {
    chars = characters;
    ptrs.resize(combinationLength, 0);
    
    for(int i = 1; i < combinationLength; ++i)
    {
      ptrs[i] = i;
    }
  }

  string next() 
  {
    string ans = "";
    int l = ptrs.size();
    for(int i = 0; i < l; ++i)
    {
      ans += chars[ptrs[i]];
    }
    
    adjustPtrs();
    
    return ans;
  }

  bool hasNext() 
  {
    int l = ptrs.size();
    return ptrs[l-1] <= chars.size()-1 ? true : false;
  }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */