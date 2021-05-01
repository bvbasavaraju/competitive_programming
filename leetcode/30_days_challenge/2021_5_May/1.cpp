/****************************************************
Date: May 1st

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3728/
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
  Q: Prefix and Suffix Search

  Design a special dictionary which has some words and allows you to search the words in it by a prefix and a suffix.

  Implement the WordFilter class:
    + WordFilter(string[] words) Initializes the object with the words in the dictionary.
    + f(string prefix, string suffix) Returns the index of the word in the dictionary which has 
      the prefix prefix and the suffix suffix. If there is more than one valid index,
      return the largest of them. If there is no such word in the dictionary, return -1.

  Example 1:
    Input
      ["WordFilter", "f"]
      [[["apple"]], ["a", "e"]]
    Output
      [null, 0]
    Explanation
      WordFilter wordFilter = new WordFilter(["apple"]);
      wordFilter.f("a", "e"); // return 0, because the word at index 0 has prefix = "a" and suffix = 'e".

  Constraints:
    1 <= words.length <= 15000
    1 <= words[i].length <= 10
    1 <= prefix.length, suffix.length <= 10
    words[i], prefix and suffix consist of lower-case English letters only.
    At most 15000 calls will be made to the function f.

  Hide Hint #1  
    For a word like "test", consider "#test", "t#test", "st#test", "est#test", "test#test".
    Then if we have a query like prefix = "te", suffix = "t", we can find it by searching 
    for something we've inserted starting with "t#te".
*/

class WordFilter 
{
private:
  vector<string> words;
  
  unordered_map<char, vector<int> > indexes; 
public:
  WordFilter(vector<string>& words_) 
  {
    words = words_;
    
    int i = 0;
    for(string& s : words_)
    {
      if(s.size() > 0)
      {
        indexes[s[0]].push_back(i);
      }
      
      i++;
    }
  }

  int f(string prefix, string suffix) 
  {
    if(prefix.size() <= 0)
    {
      return -1;
    }
    
    vector<int>& indexes_ = indexes[prefix[0]];
    
    int p = indexes_.size() - 1;
    for( ;p >= 0; --p)
    {      
      int lp = prefix.size();
      int ls = suffix.size();
      
      string& word = words[indexes_[p]];
        
      int ld = word.size();
      if((ld < lp) || (ld < ls))
      {
        continue;
      }
      
      bool matched = false;
      for(int i = 0, j = ls-1; ;)
      {
        if(word[i] != prefix[i] || word[ld-(ls-j)] != suffix[j])
        {
          break;
        }

        if((i == lp-1) && (j == 0))
        {
          matched = true;
          break;
        }

        if(i < lp-1)
        {
          i++;
        }
        if(j > 0)
        {
          j--;
        }
      }
      
      if(matched)
      {
        return indexes_[p];
      }
    }
    
    return -1;
  }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */

// //Little slower
// class WordFilter 
// {
// private:
//   unordered_map<char, vector< std::pair<string, int> > > data; 
// public:
//   WordFilter(vector<string>& words) 
//   {
//     int i = 0;
//     for(string& s : words)
//     {
//       if(s.size() > 0)
//       {
//         data[s[0]].push_back({s, i});
//       }
      
//       i++;
//     }
//   }

//   int f(string prefix, string suffix) 
//   {
//     if(prefix.size() <= 0)
//     {
//       return -1;
//     }
    
//     vector<std::pair< string, int> >& data_ = data[prefix[0]];
    
//     int p = data_.size() - 1;
//     for( ;p >= 0; --p)
//     {      
//       int lp = prefix.size();
//       int ls = suffix.size();
      
//       std::pair<string, int>& d = data_[p];
      
//       int ld = d.first.size();
//       if((ld < lp) || (ld < ls))
//       {
//         continue;
//       }
      
//       bool matched = false;
//       for(int i = 0, j = ls-1; ;)
//       {
//         if(d.first[i] != prefix[i] || d.first[ld-(ls-j)] != suffix[j])
//         {
//           break;
//         }

//         if((i == lp-1) && (j == 0))
//         {
//           matched = true;
//           break;
//         }

//         if(i < lp-1)
//         {
//           i++;
//         }
//         if(j > 0)
//         {
//           j--;
//         }
//       }
      
//       if(matched)
//       {
//         return d.second;
//       }
//     }
    
//     return -1;
//   }
// };

// /**
//  * Your WordFilter object will be instantiated and called as such:
//  * WordFilter* obj = new WordFilter(words);
//  * int param_1 = obj->f(prefix,suffix);
//  */