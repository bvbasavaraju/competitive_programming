/****************************************************
Date: September 5th

link: https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/636/week-1-september-1st-september-7th/3965/
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
  string orderlyQueue(string s, int k) 
  {
    string original = s;
    
    int l = s.size();
    if(k > 1)
    {
      sort(s.begin(), s.end());
      return s;
    }

    string ans = s;
    for(int i = 0; i < l; ++i)
    {
      ans = min(ans, s.substr(i) + s.substr(0, i));
    }
    
    return ans;
  }
};