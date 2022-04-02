/****************************************************
Date: September 6th

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
  char slowestKey(vector<int>& releaseTimes, string keysPressed) 
  {
    vector<int> keyDuration(26, 0);
    
    int ans = keysPressed[0] - 'a';
    keyDuration[keysPressed[0] - 'a'] = releaseTimes[0];
    
    int maxReleaseTime = releaseTimes[0];
    
    int l = keysPressed.size();
    for(int i = 1; i < l; ++i)
    {
      int delta = releaseTimes[i] - releaseTimes[i-1];
      
      if(delta > maxReleaseTime)
      {
        ans = keysPressed[i] - 'a';
        keyDuration[keysPressed[i] - 'a'] = delta;
        maxReleaseTime = delta;
      }
      else if(delta == maxReleaseTime)
      {
        keyDuration[keysPressed[i] - 'a'] = delta;
        
        ans = max(ans, keysPressed[i] - 'a');
      }
    }
    
    return ans + 'a';
  }
};