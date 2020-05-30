/****************************************************
Date: May 24th, 2020
Successful submissions : 1
Time expiration : 0
Not Solved : 3
Wrong Answer/ Partial result : 0

Note: I was travelling and couldnot attend the contest

link: https://leetcode.com/contest/weekly-contest-190
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
  Q: 1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence
*/
class Solution1_t 
{
public:
  int isPrefixOfWord(string sentence, string searchWord) 
  {
    int ls = sentence.size();
    int lw = searchWord.size();
    
    if(ls < lw)
    {
      return -1;
    }
    
    vector<int> sc(27, 0);
    vector<int> wc(27, 0);
    
    for(int i = 0; i < lw; ++i)
    {
      wc[searchWord[i] - 'a']++;
      if(sentence[i] == ' ')
      {
        wc[26]++;
        sc[26]++;
      }
      else
      {
        sc[sentence[i] - 'a']++;
      }
      
    }

    bool spaceRemoved = false;
    bool found = false;
    for(int i = lw; i < ls; ++i)
    {
      if(spaceRemoved && sc == wc)
      {
        found = true;
        break;
      }
      
      if(sentence[i] == ' ')
      {
        wc[26]++;
        sc[26]++;
      }
      else
      {
        sc[sentence[i] - 'a']++;
      }

      if(sentence[i-lw] != ' ')
      {
        sc[sentence[i-lw] - 'a']--;
        spaceRemoved = false;
      }
      else
      {
        spaceRemoved = true;
      }
      
    }
    
    return found ? sc[26] + 1 : -1;
  }
};

/*
  Q: 1456. Maximum Number of Vowels in a Substring of Given Length
*/
class Solution2_t
{
public:
    int maxVowels(string s, int k) 
    {
        
    }
};

/*
  Q: 1457. Pseudo-Palindromic Paths in a Binary Tree
*/
struct TreeNode 
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution3_t
{
public:
    int pseudoPalindromicPaths (TreeNode* root) 
    {
        
    }
};

/*
  Q: 1458. Max Dot Product of Two Subsequences
*/
class Solution4_t
{
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) 
    {
        
    }
};

int main()
{
  {
    Solution1_t s;
    cout << s.isPrefixOfWord("i love eating burger", "burg") << endl;
  }
  {
    Solution1_t s;
    cout << s.isPrefixOfWord("this problem is an easy problem", "pro") << endl;
  }
  {
    Solution1_t s;
    cout << s.isPrefixOfWord("i am tired", "you") << endl;
  }
  {
    Solution1_t s;
    cout << s.isPrefixOfWord("i use triple pillow", "pill") << endl;
  }
  {
    Solution1_t s;
    cout << s.isPrefixOfWord("hello from the other side", "they") << endl;
  }
  {
    Solution1_t s;
    cout << s.isPrefixOfWord("hellohello hellohellohello", "ell") << endl;
  }

  return 0;
}