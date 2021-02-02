#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

/*
  Q: 17. Letter Combinations of a Phone Number
*/

class Solution 
{
private:
  vector<string> getString(const string& s, int p, vector< vector<string> >& combs)
  {
    if(p >= s.size())
    {
      return {};
    }
    
    vector<string> comb = combs[s[p]-'0'];
    vector<string> next_comb = getString(s, p+1, combs);
    
    vector<string> ans;
    if(next_comb.size() != 0)
    {
      for(string c : comb)
      {
        for(string nc : next_comb)
        {
          ans.push_back(c + nc);
        }
      }
    }
    else
    {
      ans = comb;
    }

    return ans;
  }
    
public:
  vector<string> letterCombinations(string digits) 
  {
    vector< vector<string> > combs(10);
    combs[2] = {"a","b","c"};
    combs[3] = {"d","e","f"};
    combs[4] = {"g","h","i"};
    combs[5] = {"j","k","l"};
    combs[6] = {"m","n","o"};
    combs[7] = {"p","q","r","s"};
    combs[8] = {"t","u","v"};
    combs[9] = {"w","x","y","z"};
    
    return getString(digits, 0, combs);
  }
};