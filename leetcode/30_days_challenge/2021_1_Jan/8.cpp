/****************************************************
Date: Jan 8th

link: https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/580/week-2-january-8th-january-14th/3597/
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

class Solution 
{
public:
  bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) 
  {
    string w1Str = "";
    for(string& w : word1)
    {
      w1Str += w;
    }
    
    string w2Str = "";
    for(string& w : word2)
    {
      w2Str += w;
    }
    
    return w1Str == w2Str;
  }
};