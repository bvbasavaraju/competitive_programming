/****************************************************
Date: July 13th

link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/550/week-2-august-8th-august-14th/3417/
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
#include <set>

using namespace std;
/*
  Q: Iterator for Combination

  Design an Iterator class, which has:
  A constructor that takes a string characters of sorted distinct lowercase English letters and a number combinationLength as arguments.
  A function next() that returns the next combination of length combinationLength in lexicographical order.
  A function hasNext() that returns True if and only if there exists a next combination.

  Example:
    CombinationIterator iterator = new CombinationIterator("abc", 2); // creates the iterator.

    iterator.next(); // returns "ab"
    iterator.hasNext(); // returns true
    iterator.next(); // returns "ac"
    iterator.hasNext(); // returns true
    iterator.next(); // returns "bc"
    iterator.hasNext(); // returns false

  Constraints:
    1 <= combinationLength <= characters.length <= 15
    There will be at most 10^4 function calls per test.
    It's guaranteed that all calls of the function next are valid.
  
  Hide Hint #1  
    Generate all combinations as a preprocessing.
  Hide Hint #2  
    Use bit masking to generate all the combinations.
*/

class CombinationIterator
{
private:
  set<string> combs;
  set<string>::iterator it;
  void prepare(string &str, int len)
  {
    int l = str.size();
    int num = 0;

    int i = 0;
    while (i < len)
    {
      num |= (1 << i);
      ++i;
    }

    int maxi = pow(2, l);
    for (i = num; i < maxi; ++i)
    {
      int n = i;
      int p = 0;

      string s = "";
      while (n > 0)
      {
        if ((n & 0x01) && (p < l))
        {
          s += str[p];
        }
        ++p;
        n >>= 1;
      }

      if (s.size() == len)
      {
        combs.insert(s);
      }
    }

    it = combs.begin();
  }

public:
  CombinationIterator(string characters, int combinationLength)
  {
    prepare(characters, combinationLength);
  }

  string next()
  {
    if (it == combs.end())
    {
      return "";
    }

    string ans = *it;
    it++;

    return ans;
  }

  bool hasNext()
  {
    return it != combs.end() ? true : false;
  }
};

int main()
{
  {
    CombinationIterator c("abcdef", 4);
    c.next();
    c.hasNext();
    c.next();
    c.hasNext();
    c.next();
    c.hasNext();
  }
}

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */