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
#include <limits.h>

using namespace std;

/*
  Q: 387. First Unique Character in a String
*/

class Solution 
{
public:
  int firstUniqChar(string s) 
  {
    vector<int> freq(26, 0);
    for(char ch : s)
    {
      freq[ch-'a']++;
    }
    
    int i = 0;
    for(char ch : s)
    {
      if(freq[ch-'a'] == 1)
      {
        return i;
      }
      
      ++i;
    }
    
    return -1;
  }
};