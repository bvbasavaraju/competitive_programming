/****************************************************
Date: June 30th

link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/542/week-4-june-22nd-june-28th/3372/
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
#include <string_view>

using namespace std;

/*
  Q: Word Search II - time limit is exceeded!!

  Given a 2D board and a list of words from the dictionary, find all words in the board.
  Each word must be constructed from letters of sequentially adjacent cell, 
  where "adjacent" cells are those horizontally or vertically neighboring. 
  The same letter cell may not be used more than once in a word.

  Example:
    Input: 
    board = [
              ['o','a','a','n'],
              ['e','t','a','e'],
              ['i','h','k','r'],
              ['i','f','l','v']
            ]
    words = ["oath","pea","eat","rain"]
    Output: ["eat","oath"]
  

  Note:

  All inputs are consist of lowercase letters a-z.
  The values of words are distinct.
    
  Hide Hint #1  
    You would need to optimize your backtracking to pass the larger test. Could you stop backtracking earlier?
  Hide Hint #2  
    If the current candidate does not exist in all words' prefix, you could stop backtracking immediately.
    What kind of data structure could answer such query efficiently? Does a hash table work? Why or why not?
    How about a Trie? If you would like to learn how to implement a basic trie, 
    please work on this problem:Implement Trie (Prefix Tree) first.
*/

class Solution 
{
private:
  bool findWord(string w, vector<vector<char>>& b, int i, int j, int r, int c)
  {
    if(w.empty())
    {
      return true;
    }
    
    /*if(i < 0 || i >= r || j < 0 || j >= c || b[i][j] != w[0])
    {
      return false;
    }*/
    
    char letter = b[i][j];
    b[i][j] = ':';
    
    string sub_str = w.substr(1);
    if(i+1 < r && b[i+1][j] == w[0] && findWord(sub_str, b, i+1, j, r, c)
      || i-1 >= 0 && b[i-1][j] == w[0] && findWord(sub_str, b, i-1, j, r, c)
      || j+1 < c && b[i][j+1] == w[0] && findWord(sub_str, b, i, j+1, r, c)
      || j-1 >= 0 && b[i][j-1] == w[0] && findWord(sub_str, b, i, j-1, r, c)
      )
    {
      b[i][j] = letter;
      return true;
    }
    
    b[i][j] = letter;
    return false;
  }

public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
  {
    int r = board.size();
    int c = board[0].size();
    
    vector<string> ans;
    for(string& w : words)
    {
      int l = w.size();
      bool word_found = false;
      for(int i = 0; i < r; ++i)
      {
        for(int j = 0; j < c; ++j)
        {
          if(board[i][j] != w[0])
          {
            continue;
          }
          
          word_found = findWord(w.substr(1), board, i, j, r, c);
          if(word_found)
          {
            break;
          }
        }
        
        if(word_found)
        {
          break;
        }
      }
      
      if(word_found)
      {
        ans.push_back(w);
      }
    }
    
    return ans;
  }
};