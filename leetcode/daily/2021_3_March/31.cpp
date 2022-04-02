/****************************************************
Date: March 31th

link: https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/592/week-5-march-29th-march-31st/3689/
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
  Q: Stamping The Sequence

  You want to form a target string of lowercase letters.
  At the beginning, your sequence is target.length '?' marks.  You also have a stamp of lowercase letters.

  On each turn, you may place the stamp over the sequence, and replace every letter 
  in the sequence with the corresponding letter from the stamp.  You can make up to 10 * target.length turns.

  For example, if the initial sequence is "?????", and your stamp is "abc",  
  then you may make "abc??", "?abc?", "??abc" in the first turn.  
  (Note that the stamp must be fully contained in the boundaries of the sequence in order to stamp.)

  If the sequence is possible to stamp, then return an array of the index of the 
  left-most letter being stamped at each turn.  If the sequence is not possible to stamp, return an empty array.

  For example, if the sequence is "ababc", and the stamp is "abc", 
  then we could return the answer [0, 2], corresponding to the moves "?????" -> "abc??" -> "ababc".

  Also, if the sequence is possible to stamp, it is guaranteed it is possible to stamp 
  within 10 * target.length moves.  Any answers specifying more than this number of moves will not be accepted.

  Example 1:
    Input: stamp = "abc", target = "ababc"
    Output: [0,2]
      ([1,0,2] would also be accepted as an answer, as well as some other answers.)

  Example 2:
    Input: stamp = "abca", target = "aabcaca"
    Output: [3,0,1]

  Note:
    1 <= stamp.length <= target.length <= 1000
    stamp and target only contain lowercase letters.
*/

class Solution 
{
private:
  int replace(string& target, string& stamp)
  {
    for(int i = 0; i < target.size(); i++)
    {
      int j = 0;
      int it = i;
      
      bool replaceFlag = false;
      while(j < stamp.size() && it < target.size() && (target[it] == '*' || target[it] == stamp[j]))
      {
        if(target[it] == stamp[j])
        {
          replaceFlag = true;
        }
        
        it++;
        j++;
      }
      
      if((j == stamp.size()) && replaceFlag)
      {
        for(int k = 0; k < stamp.size(); ++k)
        {
          target[i+k] = '*';
        }
        
        return i;
      }
    }
    
    return target.size();
  }
  
public:
  vector<int> movesToStamp(string stamp, string target) 
  {
    int tl = target.size();
    
    vector<int> ans;
    string stars(tl, '*');
    while(target != stars)
    {
      int p = replace(target, stamp);
      if(p == tl)
      {
        return {};
      }
      
      ans.push_back(p);
    }
    
    if(!ans.empty())
    {
      reverse(ans.begin(), ans.end());
    }
    return ans;
  }
};