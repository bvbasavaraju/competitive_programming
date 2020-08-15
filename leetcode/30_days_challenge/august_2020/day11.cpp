/****************************************************
Date: July 11th

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
  Q: H-Index

  Given an array of citations (each citation is a non-negative integer) of a researcher, 
  write a function to compute the researcher's h-index.

  According to the definition of h-index on Wikipedia: 
  "A scientist has index h if h of his/her N papers have at least h citations each, 
  and the other N − h papers have no more than h citations each."

  Example:
    Input: citations = [3,0,6,1,5]
    Output: 3 
    Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had 
                received 3, 0, 6, 1, 5 citations respectively. 
                Since the researcher has 3 papers with at least 3 citations each and the remaining 
                two with no more than 3 citations each, her h-index is 3.
  
  Note: If there are several possible values for h, the maximum one is taken as the h-index.

  Hide Hint #1  
    An easy approach is to sort the array first.
  Hide Hint #2  
    What are the possible values of h-index?
  Hide Hint #3  
    A faster approach is to use extra space.
*/
class Solution
{
public:
  int hIndex(vector<int> &c)
  {
    if (c.size() <= 0)
    {
      return 0;
    }

    sort(c.begin(), c.end());

    int i = 0;
    int l = c.size();
    while (i < l && c[i] < l - i)
    {
      i++;
    }

    return l - i;
  }
};