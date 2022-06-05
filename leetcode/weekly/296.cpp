/****************************************************
Date: June 5th, 2022
Successful submissions : 3
Time expiration : 1
Memory exhausted : 0
Not Solved : 0
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/weekly-contest-296
****************************************************/

#include <bits/stdc++.h>
using namespace std;

/*
  Q: 2293. Min Max Game
*/
class Solution1_t
{
public:
  int minMaxGame(vector<int>& nums) 
  {
    int l = nums.size();
    
    while(l > 1)
    {
      int i = 0;
      vector<int> newNums(l/2);
      for(int i = 0; i < l/2; ++i)
      {
        if(i % 2 == 0)
        {
          newNums[i] = min(nums[2*i], nums[(2*i) + 1]);
        }
        else
        {
          newNums[i] = max(nums[2*i], nums[(2*i) + 1]);
        }
      }
      
      nums = newNums;
      l = nums.size();
    }
    
    return nums.back();
  }
};

/*
  Q: 2294. Partition Array Such That Maximum Difference Is K
*/
class Solution2_t
{
public:
  int partitionArray(vector<int>& nums, int k) 
  {
    sort(nums.begin(), nums.end());
    
    int ans = 0;
    int l = nums.size();
    int minPos = 0;
    for(int i = 1; i < l; ++i)
    {
      if((nums[i] - nums[minPos]) > k)
      {
        ans++;
        minPos = i;
      }
    }
    
    return ans + 1;
  }
};

/*
  Q: 2295. Replace Elements in an Array
*/
class Solution3_t
{
public:
  vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) 
  {
    int l = nums.size();
    unordered_map<int, int> numPos;
    
    for(int i = 0; i < l; ++i)
    {
      numPos[nums[i]] = i;
    }
    
    for(vector<int> op : operations)
    {
      int numToReplace = op[0];
      int replaceVal = op[1];
      
      int pos = numPos[numToReplace];
      if(pos != -1)
      {
        nums[pos] = replaceVal;
        numPos[replaceVal] = pos;
        numPos[numToReplace] = -1;
      }
    }
    
    return nums;
  }
};

/*
  Q: 2296. Design a Text Editor - TLE. Solution is correct. But the Time limit exceeded.
  I could have used stack<char> for left and right part of the string!!
*/
class TextEditor 
{
private:
  string leftString;
  string rightString;
  
public:
  TextEditor() 
  {
    leftString = "";
    rightString = "";
    
  }

  void addText(string text) 
  {
    leftString += text;
  }

  int deleteText(int k) 
  {
    int deletedCharCount = k;
    
    int l = leftString.size();
    if(l <= k)
    {
      leftString = "";
      deletedCharCount = l; 
    }
    else
    {
      leftString = leftString.substr(0, l-k);
    }
    
    return deletedCharCount;
  }

  string cursorLeft(int k) 
  {
    int l = leftString.size();
    if(l <= k)
    {
      rightString = leftString + rightString;
      leftString = "";
      
      return leftString;
    }
    
    string subStr = leftString.substr(l-k);
    rightString = subStr + rightString;
    leftString = leftString.substr(0, l-k);

    l = leftString.size();
    int returnLength = min(10, l);

    return leftString.substr(l-returnLength);
  }

  string cursorRight(int k) 
  {
    int l = rightString.size();
    if(l <= k)
    {
      leftString += rightString;
      rightString = "";
    }
    else
    {
      leftString += rightString.substr(0, k);
      rightString = rightString.substr(k);
    }
    
    l = leftString.size();
    int returnLength = min(10, l);

    return leftString.substr(l-returnLength);
  }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */