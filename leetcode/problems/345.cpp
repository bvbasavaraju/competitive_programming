#include<bits/stdc++.h>
using namespace std;

class Solution 
{
private:
  bool isVowel(char ch)
  {
    switch(ch)
    {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
      case 'A':
      case 'E':
      case 'I':
      case 'O':
      case 'U':
        return true;
    }
    
    return false;
  }
public:
  string reverseVowels(string s) 
  {
    int l = 0;
    int r = s.size()-1;
    
    while(l < r)
    {
      bool lo = isVowel(s[l]);
      bool ro = isVowel(s[r]);
      if(lo && ro)
      {
        swap(s[l], s[r]);
        l++;
        r--;
      }
      else
      {
        if(!lo)
        {
          l++;
        }
        else if(!ro)
        {
          r--;
        }
      }
    }
    
    return s;
  }
};