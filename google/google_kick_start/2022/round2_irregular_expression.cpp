#include<bits/stdc++.h>
using namespace std;

class Solution_t
{
private:

    bool isVowel(char ch)
    {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            return true;
        }
        
        return false;
    }
    
    bool middlePartHasVowel(const string& word, int l, int r, int totalLength)
    {
        for(int i = l; i < (totalLength - l); ++i)
        {
            if(isVowel(word[i]))
            {
                return true;
            }
        }
        
        return false;
    }
    bool isSpell(const string& word, int l, int m, int r, int totalLength, int syllableCount, unordered_map<string, bool>& dp)
    {
        if(syllableCount >= 2)
        {
            if(middlePartHasVowel(word, l, r, totalLength))
            {
                return true;
            }
        }

        if(l >= m || r >= totalLength)
        {
            return false;
        }
        
        string s = std::to_string(l) + "_" + std::to_string(r) + "_" + std::to_string(syllableCount);
        if(dp.find(s) != dp.end())
        {
            return dp[s];
        }
        
        bool skipLeft = false;
        bool skipRight = false;
        bool incaseOfMatch = false;
        bool skipBoth = false;
        if(word[l] == word[r])
        {
            if(isVowel(word[l]))
            {
                syllableCount++;
            }
            
            incaseOfMatch = isSpell(word, l+1, m, r+1, totalLength, syllableCount, dp);
        }
        else
        {
          skipLeft = isSpell(word, l+1, m, r, totalLength, syllableCount, dp);
          skipRight = isSpell(word, l, m, r+1, totalLength, syllableCount, dp);
          skipBoth = isSpell(word, l+1, m, r+1, totalLength, syllableCount, dp);
        }

        dp[s] = incaseOfMatch || skipLeft || skipRight || skipBoth;
        return dp[s];
    }
    
public:
    bool isSpell(const string& word)
    {
      int l = word.size();
      int m = l/2;
      int right = m+1;
      if(l % 2 == 0)
      {
        m--;
        right++;
      }
      
      unordered_map<string, bool> dp;
      return isSpell(word, 0, m, right, l, 0, dp);
    }
};

int main()
{
    int T;
    std::cin>> T;
    
    Solution_t s;
    int count = 1;
    while(count <= T)
    {
        string word;
        std::cin >> word;
        
        string result = s.isSpell(word) ? "Spell!" : "Nothing.";
        std::cout << "Case #" << count << ": " << result << std::endl;
        
        count++;
    }
    
    return 0;
}