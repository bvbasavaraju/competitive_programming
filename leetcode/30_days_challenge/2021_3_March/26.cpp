/****************************************************
Date: March 26th

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
  Q: Word Subsets

  We are given two arrays A and B of words.  Each word is a string of lowercase letters.
  
  Now, say that word b is a subset of word a if every letter in b occurs in a,
  including multiplicity.  For example, "wrr" is a subset of "warrior", but is not a subset of "world".

  Now say a word a from A is universal if for every b in B, b is a subset of a. 

  Return a list of all universal words in A.  You can return the words in any order.

  Example 1:
    Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["e","o"]
    Output: ["facebook","google","leetcode"]

  Example 2:
    Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["l","e"]
    Output: ["apple","google","leetcode"]

  Example 3:
    Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["e","oo"]
    Output: ["facebook","google"]

  Example 4:
    Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["lo","eo"]
    Output: ["google","leetcode"]

  Example 5:
    Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["ec","oc","ceo"]
    Output: ["facebook","leetcode"]

  Note:
    1 <= A.length, B.length <= 10000
    1 <= A[i].length, B[i].length <= 10
    A[i] and B[i] consist only of lowercase letters.
    All words in A[i] are unique: there isn't i != j with A[i] == A[j].
*/

// Much faster solution. Lesson Learnt => Vectors are much faster in accessibility. if we do not have to seach for something!!
class Solution 
{
private:
  void getCount(const string& str, vector<int>& count)
  {
    for(char ch : str)
    {
      count[ch-'a']++;
    }
  }
  
public:
  vector<string> wordSubsets(vector<string>& A, vector<string>& B) 
  {
    vector<int> temp;
    vector<int> bCount(26, 0);
    for(string& str : B)
    {
      temp.clear();
      temp.resize(26, 0);
      getCount(str, temp);
      
      for(int i = 0; i < 26; ++i)
      {
        bCount[i] = max(bCount[i], temp[i]);
      }
    }
    
    vector<string> ans;
    
    int i = 0;
    int l = A.size();
    for(int j = 0; j < l; ++j)
    {
      string& str = A[j];
      
      temp.clear();
      temp.resize(26, 0);
      getCount(str, temp);
      
      for(i = 0; i < 26; ++i)
      {
        if(temp[i] < bCount[i])
        {
          break;
        }
      }
      
      if(i == 26)
      {
        ans.push_back(str);
      }
    }
    
    
    return ans;
  }
};

//Slower solution!!
// class Solution 
// {
// public:
//   vector<string> wordSubsets(vector<string>& A, vector<string>& B) 
//   {
//     unordered_map<int, int> bFreq;
//     for(string& str : B)
//     {
//       unordered_map<int, int> freq;
//       for(char& ch : str)
//       {
//         freq[ch]++;
//       }
      
//       for(auto& it : freq)
//       {
//         if((bFreq.find(it.first) == bFreq.end()) || (bFreq[it.first] < it.second))
//         {
//           bFreq[it.first] = it.second;
//         }
//       }
//     }
    
//     vector<string> ans;
    
//     bool add = true;
//     int l = A.size();
//     for(int i = 0; i < l; ++i)
//     {
//       string& str = A[i];
      
//       unordered_map<int, int> freq;
//       for(char& ch : str)
//       {
//         freq[ch]++;
//       }
      
//       add = true;
//       for(auto& it : bFreq)
//       {
//         if((freq.find(it.first) == freq.end()) || (freq[it.first] < it.second))
//         {
//           add = false;
//           break;
//         }
//       }
      
//       if(add)
//       {
//         ans.push_back(str);
//       }
//     }
    
    
//     return ans;
//   }
// };

int main()
{
  Solution s;
  vector<string> A = {"amazon","apple","facebook","google","leetcode"};
  vector<string> B = {"e","o"};
  s.wordSubsets(A, B);
}