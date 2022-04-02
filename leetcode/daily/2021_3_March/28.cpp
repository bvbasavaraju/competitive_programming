/****************************************************
Date: March 28th

link: https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/591/week-4-march-22nd-march-28th/3681/
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
  Q: Reconstruct Original Digits from English

  Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.

  Note:
    Input contains only lowercase English letters.
    Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
    Input length is less than 50,000.

  Example 1:
    Input: "owoztneoer"
    Output: "012"
  
  Example 2:
    Input: "fviefuro"
    Output: "45"
*/

class Solution 
{
private:
  void getNums(int num, vector<int>& freq, vector<string>& ans)
  {
    int count = 0;
    string numInStr;
    
    switch(num)
    {
      case 0: //zero
          count = freq['z'-'a'];
          numInStr = "zero";
        break;
        
      case 1: //one
          count = freq['o'-'a'];
          numInStr = "one";
        break;
        
      case 2: //two
          count = freq['w'-'a'];
          numInStr = "two";
        break;
        
      case 3: //three
          count = freq['h'-'a'];
          numInStr = "three";
        break;
        
      case 4: //four
          count = freq['u'-'a'];
          numInStr = "four";
        break;
        
      case 5: //five
          count = freq['f'-'a'];
          numInStr = "five";
        break;
        
      case 6: //six
          count = freq['x'-'a'];
          numInStr = "six";
        break;
        
      case 7: //seven
          count = freq['s'-'a'];
          numInStr = "seven";
        break;
        
      case 8: //eight
          count = freq['g'-'a'];
          numInStr = "eight";
        break;
        
      case 9: //nine
          count = freq['i'-'a'];
          numInStr = "nine";
        break;
        
      default:
        break;
    }
    
    for(char& ch : numInStr)
    {
      freq[ch-'a'] -= count;
    }
    
    if(count > 0)
    {
      string digit = std::to_string(num);
      while(count > 0)
      {
        ans[num] += digit;
        count--;
      }
    }
  }
public:
  string originalDigits(string s) 
  {    
    vector<int> freq(26, 0);
    for(char& ch : s)
    {
      freq[ch-'a']++;
    }
    
    vector<string> nums(10, "");
    getNums(0, freq, nums);
    getNums(6, freq, nums);
    getNums(2, freq, nums);
    getNums(4, freq, nums);
    getNums(8, freq, nums);
    getNums(3, freq, nums);
    getNums(1, freq, nums);
    getNums(5, freq, nums);
    getNums(7, freq, nums);
    getNums(9, freq, nums);
    
    string ans = "";
    for(string& n : nums)
    {
      if(!n.empty())
      {
        ans += n;
      }
    }
    
    return ans;
  }
};
