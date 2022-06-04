#include<bits/stdc++.h>
using namespace std;

class Solution 
{
private:
  void addLine(vector<string> words, int maxWidth, int onlyWordCount, bool isLastLine, vector<string>& ans)
  {
    int totalSpaces = maxWidth - onlyWordCount;
    if(isLastLine)
    {
      for(int wordIndex = 0; wordIndex < words.size(); ++wordIndex)
      {
        if(wordIndex == 0)
        {
          ans.push_back(words[wordIndex]);
        }
        else
        {
          totalSpaces--;
          ans.back() += " ";
          ans.back() += words[wordIndex];
        }
      }
      
      while(totalSpaces > 0)
      {
        ans.back() += " ";
        totalSpaces--;
      }
      
      return;
    }
    
    int availableSlots = words.size() - 1;
    if(availableSlots == 0)
    {
      ans.push_back(words.back());
      
      while(totalSpaces != 0)
      {
        ans.back() += " ";
        totalSpaces--;
      }
    }
    else
    {
      vector<int> spaceCount(availableSlots, totalSpaces/availableSlots);
      
      int extraSpaces = totalSpaces % availableSlots;
      for(int i = 0; i < extraSpaces; ++i)
      {
        spaceCount[i]++;
      }
      
      int spaceIndex = 0;
      for(int wordIndex = 0; wordIndex < words.size(); ++wordIndex)
      {
        if(wordIndex > 0)
        {
          ans.back() += (words[wordIndex]);
        }
        else
        {
          ans.push_back(words[wordIndex]);
        }

        if(spaceIndex < spaceCount.size())
        {
          while(spaceCount[spaceIndex] != 0)
          {
            ans.back() += " ";
            spaceCount[spaceIndex]--;
          }

          spaceIndex++;
        }
      }
    }
  }
public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) 
  {
    int width = 0;
    
    vector<string> ans;
    
    vector<string> line;
    for(string w : words)
    {
      if((width + line.size() + w.size()) > maxWidth)
      {
        addLine(line, maxWidth, width, false, ans);
        width = 0;
        line.clear();
      }
      
      line.push_back(w);
      
      width += w.size();
    }
    
    if(line.size() > 0)
    {
      addLine(line, maxWidth, width, true, ans);
    }
    
    return ans;
  }
};