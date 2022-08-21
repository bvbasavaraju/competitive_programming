#include<bits/stdc++.h>
using namespace std;

class Solution 
{  
public:
  string reverseWords(string s) 
  {
    int first = 0;
    int current = 0;
    for(char ch : s)
    {
      if(ch == ' ')
      {
        if(first < current)
        {
          reverse(s.begin()+first, s.begin()+current);
        }
        
        first = current + 1;
      }
      
      current++;
    }
    
    return s;
  }
};

int main()
{
  Solution s;
  string str = "Let's take LeetCode contest";
  s.reverseWords(str);
  return 0;
}