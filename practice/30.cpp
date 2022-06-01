#include<bits/stdc++.h>
using namespace std;

class Solution 
{
private:
  void assignNumberForWord(vector<string>& words, unordered_map<string, int>& wordCount, vector<int>& assignedNumbers)
  {
    int number = 1;
    for(string w : words)
    {
      if(wordCount.find(w) == wordCount.end())
      {
        wordCount[w] = number;
        number++;
      }
      
      assignedNumbers[wordCount[w]]++;
    }
  }
  
public:
  vector<int> findSubstring(string s, vector<string>& words) 
  {
    //words are assigned with a number. and frequency of such assigned numbers are calculated
    //map it so that input string can also be converted to array of such number
    int numOfWords = words.size();
    unordered_map<string, int> wordCount;
    vector<int> assignedNumbers(numOfWords + 1, 0);
    assignNumberForWord(words, wordCount, assignedNumbers);
    
    // Array of number series ex: s = abcpqrxyz words = {"abc", "pqr"}, numsArray will have number equivalent of = {{"abc","pqr","xyz"}, {"bcq","qrx"}, {"cpq","rxy"}}
    int wordLength = words.back().size();
    vector<vector<int>> numsArray(wordLength);
    
    for(int i = 0; i < wordLength; ++i)
    {
      int p = i;
      string subStr = s.substr(p, wordLength);
      while(!subStr.empty())
      {
        if(wordCount.find(subStr) != wordCount.end())
        {
          numsArray[i].push_back(wordCount[subStr]);
        }
        else
        {
          numsArray[i].push_back(-1);
        }
        p += wordLength;
        subStr = p+wordLength <= s.size() ? s.substr(p, wordLength) : "";
      }
    }
    
    //Sliding window match for each entry in num array!! 
    //for each entry in num array, calculate the freq for window size and compare with freq calculated above
    vector<int> ans;
    for(int set = 0; set < wordLength; ++set)
    {
      vector<int>& nums = numsArray[set];
      
      bool wordLengthReached = false;
      vector<int> assignedNumbers_(numOfWords + 1, 0);  
      for(int i = 0; i < nums.size(); ++i)
      {
        if(nums[i] >= 0 && nums[i] <= numOfWords)
        {
          assignedNumbers_[nums[i]]++;
        }

        wordLengthReached = i+1 >= numOfWords;  // numOfWords == window size!!
        if(wordLengthReached)
        {
          int pos = (i+1 - numOfWords) * wordLength;

          if((i+1 > numOfWords) && (nums[i-numOfWords] >= 0))
          {
            assignedNumbers_[nums[i-numOfWords]]--;  
          }

          if(assignedNumbers_ == assignedNumbers)
          {
            ans.push_back(pos+set); //which set it belongs to!?
          }
        }
      }
    }
    
    return ans;
  }
};