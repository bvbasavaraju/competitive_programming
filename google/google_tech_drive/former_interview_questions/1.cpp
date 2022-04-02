/*
  Q: Find longest word in dictionary that is a subsequence of a given string
  
  Given a string S and a set of words D, find the longest word in D that is a subsequence of S.
  Word W is a subsequence of S if some number of characters, possibly zero,
  can be deleted from S to form W, without reordering the remaining characters.

  Note: D can appear in any format (list, hash table, prefix tree, etc.

  For example, given the input of S = "abppplee" and D = {"able", "ale", "apple", "bale", "kangaroo"} the correct output would be "apple"

    The words "able" and "ale" are both subsequences of S, but they are shorter than "apple".
    The word "bale" is not a subsequence of S because even though S has all the right letters, they are not in the right order.
    The word "kangaroo" is the longest word in D, but it isn't a subsequence of S.

  Learning objectives
    This question gives you the chance to practice with algorithms and data structures. 
    It’s also a good example of why careful analysis for Big-O performance is often worthwhile, 
    as is careful exploration of common and worst-case input conditions.
*/

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <limits.h>

using namespace std;

class Solution
{
  public:
    string GetLongestWord(const string& s, vector<string>& d)
    {
      vector<int> count(d.size(), 0);

      int maxi = INT_MIN;
      int mp = -1;
      int l = s.size();
      for(int i = 0; i < l; ++i)
      {
        int ch = s[i];
        
        int wi = 0;
        int skip_count = 0;
        for(const string& w : d)
        {
          if(i < w.size())
          {
            if(w[i] == ch)
            {
              count[wi]++;
              maxi = max(maxi, count[wi]);
              mp = wi;
            }
          }
          else
          {
            skip_count++;
          }
          
          wi++;
        }

        if(skip_count == d.size())
        {
          break;
        }
      }

      string ans = "";
      if((mp >= 0) && (mp < d.size()))
      {
        ans = d[mp];
      }

      return ans;
    }
};

int main()
{
  Solution s;
  string str = "abppplee";
  vector<string> d = {"able", "ale", "apple", "bale", "kangaroo"};

  std::cout << s.GetLongestWord(str, d) << endl;

  return 0;
}