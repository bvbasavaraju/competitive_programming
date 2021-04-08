/****************************************************
Date: April 8th

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
  Q: Letter Combinations of a Phone Number

  Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
  A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

  Example 1:
    Input: digits = "23"
    Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

  Example 2:
    Input: digits = ""
    Output: []

  Example 3:
    Input: digits = "2"
    Output: ["a","b","c"]

  Constraints:
    0 <= digits.length <= 4
    digits[i] is a digit in the range ['2', '9'].
*/

class Solution 
{
private:
  vector<string> getString(const string& s, int p, vector< vector<string> >& combs)
  {
    if(p >= s.size())
    {
      return {};
    }
    
    vector<string> comb = combs[s[p]-'0'];
    vector<string> next_comb = getString(s, p+1, combs);
    
    vector<string> ans;
    if(next_comb.size() != 0)
    {
      for(string c : comb)
      {
        for(string nc : next_comb)
        {
          ans.push_back(c + nc);
        }
      }
    }
    else
    {
      ans = comb;
    }
    

    return ans;
  }
    
public:
  vector<string> letterCombinations(string digits) 
  {
    vector< vector<string> > combs(10);
    combs[2] = {"a","b","c"};
    combs[3] = {"d","e","f"};
    combs[4] = {"g","h","i"};
    combs[5] = {"j","k","l"};
    combs[6] = {"m","n","o"};
    combs[7] = {"p","q","r","s"};
    combs[8] = {"t","u","v"};
    combs[9] = {"w","x","y","z"};
    
    return getString(digits, 0, combs);
  }
};