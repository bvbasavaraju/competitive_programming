/****************************************************
Date: May 31st

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/602/week-5-may-29th-may-31st/3760/
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
  Q: Search Suggestions System

  Given an array of strings products and a string searchWord.
  We want to design a system that suggests at most three product names from products after each
  character of searchWord is typed. Suggested products should have common prefix with the searchWord.
  If there are more than three products with a common prefix return the three lexicographically minimums products.

  Return list of lists of the suggested products after each character of searchWord is typed. 

  Example 1:
    Input: 
      products = ["mobile","mouse","moneypot","monitor","mousepad"], 
      searchWord = "mouse"
    Output: 
      [
        ["mobile","moneypot","monitor"],
        ["mobile","moneypot","monitor"],
        ["mouse","mousepad"],
        ["mouse","mousepad"],
        ["mouse","mousepad"]
      ]
    Explanation: 
      products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"]
      After typing m and mo all products match and we show user ["mobile","moneypot","monitor"]
      After typing mou, mous and mouse the system suggests ["mouse","mousepad"]

  Example 2:
    Input: 
      products = ["havana"], 
      searchWord = "havana"
    Output: 
      [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]

  Example 3:
    Input: 
      products = ["bags","baggage","banner","box","cloths"], 
      searchWord = "bags"
    Output: 
      [["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]

  Example 4:
    Input: 
      products = ["havana"], 
      searchWord = "tatiana"
    Output: 
      [[],[],[],[],[],[],[]]

  Constraints:
    1 <= products.length <= 1000
    There are no repeated elements in products.
    1 <= Σ products[i].length <= 2 * 10^4
    All characters of products[i] are lower-case English letters.
    1 <= searchWord.length <= 1000
    All characters of searchWord are lower-case English letters.

  Hide Hint #1  
    Brute force is a good choice because length of the string is ≤ 1000.

  Hide Hint #2  
    Binary search the answer.

  Hide Hint #3  
    Use Trie data structure to store the best three matching. Traverse the Trie.
*/

class Solution 
{
private:
  void calculateFreq(int chp, vector<int>& f, vector< std::pair<string, vector<int> > >& prodFreq, int& p, vector<string>& matched)
  {
    bool skipRest = false;
    for(int i = p; i < prodFreq.size(); ++i)
    {
      if(chp >= prodFreq[i].first.size())
      {
        continue;
      }
      
      prodFreq[i].second[prodFreq[i].first[chp] - 'a']++;
      
      if(!skipRest)
      {
        if(f == prodFreq[i].second)
        {
          if(matched.size() == 0)
          {
            p = i;
          }

          if(matched.size() < 3)
          {
            matched.push_back(prodFreq[i].first);
          }
          else
          {
            skipRest = true;
          }
        }
        else
        {
          skipRest = (matched.size() > 0);
        }
      }
    }
  }
  
public:
  vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
  {
    sort(products.begin(), products.end());
    
    int l = products.size();
    vector< std::pair<string, vector<int> > > prodFreq(l);
    for(int i = 0; i < l; ++i)
    {
      prodFreq[i].first = products[i];
      prodFreq[i].second.resize(26, 0);
    }
    
    int pos = 0;
    l = searchWord.size();
    vector<int> freq(26, 0);
    vector< vector<string> > ans(l);
    for(int i = 0; i < l; ++i)
    {
      freq[searchWord[i] - 'a']++;
      calculateFreq(i, freq, prodFreq, pos, ans[i]);
    }
    
    return ans;
  }
};