#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
  {
    unordered_set<string> words;
    for(string s : wordList)
    {
      words.insert(s);
    }
    
    if((words.find(endWord) == words.end()) || (beginWord == endWord)) 
    {
      return 0;
    }
    
    unordered_map<string, int> cache;
    cache[beginWord] = 1;
    
    queue<string> chain;
    chain.push(beginWord);
    
    while(!chain.empty())
    {
      string top = chain.front();
      chain.pop();
      
      string temp = top;
      for(int i = 0; i < temp.size(); ++i)
      {
        char backup = temp[i];
        for(char ch = 'a'; ch <= 'z'; ++ch)
        {
          temp[i] = ch;
          
          if(words.find(temp) == words.end())
          {
            continue;
          }
          
          if((cache.find(temp) == cache.end()) || (cache[temp] > cache[top] + 1))
          {
            cache[temp] = cache[top] + 1;
            chain.push(temp);
          }
        }
        
        temp[i] = backup;
      }
    }
    
    if(cache.find(endWord) == cache.end())
    {
      return 0;
    }
    
    return cache[endWord];
  }
};