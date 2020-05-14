/****************************************************
Date: May 14th

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3329/
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
  Q: Implement Trie (Prefix Tree)

  Implement a trie with insert, search, and startsWith methods.

  Example:
    Trie trie = new Trie();

    trie.insert("apple");
    trie.search("apple");   // returns true
    trie.search("app");     // returns false
    trie.startsWith("app"); // returns true
    trie.insert("app");   
    trie.search("app");     // returns true
  
  Note:
    You may assume that all inputs are consist of lowercase letters a-z.
    All inputs are guaranteed to be non-empty strings.
*/
class Trie 
{
private:
  unordered_set<string> complete_words;
  unordered_set<string> words_sub_strs;
  
  void updateSubStrings(const string& word)
  {
    int l = word.size();
    for(int i = 1; i <= l; ++i)
    {
      string sub_str = word.substr(0, i);
      if(words_sub_strs.find(sub_str) == words_sub_strs.end())
      {
        words_sub_strs.insert(sub_str);
      }
    }
  }
public:
  /** Initialize your data structure here. */
  Trie() 
  {}

  /** Inserts a word into the trie. */
  void insert(string word) 
  {
    if(complete_words.find(word) == complete_words.end())
    {
      complete_words.insert(word);
    }
    updateSubStrings(word);
  }

  /** Returns if the word is in the trie. */
  bool search(string word) 
  {
    return complete_words.find(word) != complete_words.end();
  }

  /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(string prefix) 
  {
    return words_sub_strs.find(prefix) != words_sub_strs.end();
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */