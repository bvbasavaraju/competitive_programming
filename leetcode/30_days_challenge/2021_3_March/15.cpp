/****************************************************
Date: March 15th

link: https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/590/week-3-march-15th-march-21st/3673/
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
  Q: Encode and Decode TinyURL

  Note: This is a companion problem to the System Design problem: Design TinyURL.
  TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.

  Design the encode and decode methods for the TinyURL service. 
  There is no restriction on how your encode/decode algorithm should work. 
  You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.
*/

class Solution 
{
private:
  string possibleStr = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  unordered_map<string, string> data;
public:
  // Encodes a URL to a shortened URL.
  string encode(string longUrl) 
  {
    string key;
    while(data.find(key) == data.end())
    {
      random_shuffle(possibleStr.begin(), possibleStr.end());
      key = possibleStr.substr(0,6);
      
      if(data.find(key) == data.end())
      {
        data[key] = longUrl;
      }
    }
    return "http://tinyurl.com/"+key;
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl) 
  {
    int pos = shortUrl.find_last_of('/');
    return data[shortUrl.substr(pos+1)];
  }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));