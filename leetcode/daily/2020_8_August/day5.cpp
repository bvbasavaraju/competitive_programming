/****************************************************
Date: July 5th

link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3409/
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
  Q: Add and Search Word - Data structure design

  Design a data structure that supports the following two operations:
  void addWord(word)
  bool search(word)
  search(word) can search a literal word or a regular expression string containing only 
  letters a-z or .. A . means it can represent any one letter.

  Example:
    addWord("bad")
    addWord("dad")
    addWord("mad")
    search("pad") -> false
    search("bad") -> true
    search(".ad") -> true
    search("b..") -> true
  
  Note:
    You may assume that all words are consist of lowercase letters a-z.

  Hide Hint #1  
    You should be familiar with how a Trie works. If not, please work on this problem: Implement Trie (Prefix Tree) first.
*/

class WordDictionary 
{
private:
  unordered_map<int, unordered_set<string>> data;
public:
    /** Initialize your data structure here. */
    WordDictionary() 
    {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) 
    {
      data[word.size()].insert(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) 
    {
      unordered_set<string>& d = data[word.size()];
      if(d.find(word) != d.end())
      {
        return true;
      }
      
      
      for(auto it = d.begin(); it != d.end(); ++it)
      {
        string temp = *it;
        
        int i = 0;
        for(char w : word)
        {
          if(w == '.')
          {
            temp[i] = '.';
          }
          i++;
        }
        
        if(temp == word)
        {
          return true;
        }
      }
      
      return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */