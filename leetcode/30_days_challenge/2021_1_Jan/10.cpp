/****************************************************
Date: Jan 10th

link: https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/580/week-2-january-8th-january-14th/3597/
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

class Solution 
{
private:
  int getPos(vector<int>& nums, int num, int& firstPos, int& lastPos)
  {
    firstPos = -1;
    lastPos = -1;
    bool firstPosLocked = false;
    bool lastPosLocked = false;
    
    int retVal = 0;
    
    int l = 0;
    int h = nums.size() - 1;
    do
    {
      while(h >= l)
      {
        int m = l + (h-l)/2;
        
        retVal = m;
        if(nums[m] == num)
        {
          bool restart = true;
          if((firstPos == -1) && (lastPos == -1))
          {
            firstPos = lastPos = m;
            l = m+1;
            h = nums.size() - 1;
          }
          else if(firstPos > m)
          {
            h = m;
            firstPos = m;
            restart = false;
          }
          else if (m > lastPos)
          {
            l = m;
            lastPos = m;
            restart = false;
          }

          if((m == 0) || nums[m-1] < num)
          {
            firstPosLocked = true;
            l = m+1;
            h = nums.size() - 1;
          }
          if((m >= (nums.size() - 1)) || (nums[m+1] > num))
          {
            lastPosLocked = true;
            l = 0;
            h = m-1;
          }

          if(firstPosLocked && lastPosLocked)
          {
            break;
          }

          if(restart)
          {
            break;
          }
          else
          {
            continue;
          }
        }

        if(firstPosLocked && lastPosLocked)
        {
          break;
        }

        if(nums[m] > num)
        {
          h = m - 1;
        }
        else
        {
          l = m + 1;
        }
      }

      if(((!firstPosLocked && !lastPosLocked) && (firstPos == -1) && (lastPos == -1)) || (firstPosLocked && lastPosLocked))
      {
        break;
      }
    } while (true);
    
    return retVal;
  }
  
public:
  int createSortedArray(vector<int>& instructions) 
  {
    int l = instructions.size();
    
    int ans = 0;
    vector<int> nums;
    static const int CONST_MOD = 1e9 + 7;
    for(int i = 0; i < l; ++i)
    {
      int count = nums.size();

      int p = 0;
      if(count > 0)
      {
        int f, s;
        p = getPos(nums, instructions[i], f, s);
        if(f > -1 && s > -1)
        {
          ans += (min(f, count - (s+1))) % CONST_MOD;
        }
        else
        {
          if(instructions[i] > nums[p])
          {
            p++;
            ans += (min(p, count - p)) % CONST_MOD;
          }
          else
          {
            ans += (min(p, count - p)) % CONST_MOD;
          }
        }
      }
      
      ans %= CONST_MOD;
      nums.emplace(nums.begin() + p, instructions[i]);
    }
    
    return ans;
  }
};

int main()
{
  Solution s;
  vector<int> instrcutions = {1,2,1,2,1,2,1,2,1,2,1,2}; // failing for this!!!
  int ans = s.createSortedArray(instrcutions);

  return 0;
}