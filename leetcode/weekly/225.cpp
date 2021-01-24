/****************************************************
Date: Jan 24th, 2021
Successful submissions : 2
Time expiration : 0
Not Solved : 1
Wrong Answer/ Partial result : 1  //this was corrected after looking at the discussion

link: https://leetcode.com/contest/weekly-contest-224
****************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

/*
  Q: 1736. Latest Time by Replacing Hidden Digits
*/
class Solution1_t
{
public:
  string maximumTime(string time) 
  {
    int first_digit = time[0];
    int second_digit = time[1];
    
    //switch()
    
    if(first_digit == '?' && second_digit == '?')
    {
      time[0] = '2';
      time[1] = '3';
    }
    else if(first_digit == '?')
    {
      time[0] = (second_digit - '0') <= 3 ? '2' : '1';
    }
    else if(second_digit == '?')
    {
      time[1] = (first_digit - '0') == 2 ? '3' : '9';
    }
    
    time[3] = (time[3] == '?') ? '5' : time[3];
    time[4] = (time[4] == '?') ? '9' : time[4];
    
    return time;
  }
};

/*
  Q: 1737. Change Minimum Characters to Satisfy One of Three Conditions - Submitted wrongly but corrected later
  - this one earlier logic was correct but there was mistake in code, So, fixed after challenge was over and looking at one code in discussion
*/
class Solution2_t
{
public:
  int minCharacters(string a, string b) 
  {
    int al = a.size();
    int bl = b.size();
    
    vector<int> af(26, 0);
    for(auto ch : a)
    {
      af[ch - 'a']++;
    }
    
    vector<int> bf(26, 0);
    for(auto ch : b)
    {
      bf[ch - 'a']++;
    }
    
    int ans = INT_MAX;
    if(al == bl)
    { // to make strings equal
      int count = 0;
      for(int i = 0; i < 26; ++i)
      {
        count += abs(af[i] - bf[i]);
      }
      
      ans = min(ans, count);
    }
    
    for(int i = 1; i < 26; ++i)
    {
      int a_count = 0;
      int b_count = 0;
      
      for(int j = 0; j < i; ++j)  // for below ith character
      {
        a_count += af[j];
        b_count += bf[j];
      }
      
      for(int j = i; j < 26; ++j) // for above ith character
      {
        a_count += bf[j];
        b_count += af[j];
      }
      
      ans = min({ans, a_count, b_count});
    }
    
    return ans;
  }
};

/*
  Q: 1738. Find Kth Largest XOR Coordinate Value
*/
class Solution3_t
{
public:
  int kthLargestValue(vector<vector<int>>& matrix, int k) 
  {
    int row = matrix.size();
    int col = matrix[0].size();
    
    vector<int> xored_vals;
    for(int i = 0; i < row; ++i)
    {
      for(int j = 0; j < col; ++j)
      {
        if(i == 0 && j == 0)
        {
          xored_vals.push_back(matrix[i][j]);
          continue;
        }
        
        if(i == 0)
        {
          matrix[i][j] = matrix[i][j] ^ matrix[i][j-1];
        }
        else if(j == 0)
        {
          matrix[i][j] = matrix[i][j] ^ matrix[i-1][j];
        }
        else
        {
          //Note: here, the diagonal opposite will be xored already. So, i-1 and j-1 has be xored
          matrix[i][j] = matrix[i][j] ^ matrix[i][j-1] ^ matrix[i-1][j] ^ matrix[i-1][j-1];
        }
        
        
        xored_vals.push_back(matrix[i][j]);
      }
    }
    
    sort(xored_vals.begin(), xored_vals.end(), [](const int& a, const int b) -> bool 
         {
           return (a > b);
         });
    
    return xored_vals[k-1];
  }
};

/*
  Q: 1739. Building Boxes
*/
class Solution4_t 
{
public:
  int minimumBoxes(int n) 
  {
      
  }
};