/****************************************************
Date: July 23rd, 2022
Successful submissions : 3
Time expiration : 0
Memory limit exceeded : 0
Not Solved : 0
Wrong Answer/ Partial result / partial solution not submitted : 1

link: https://leetcode.com/contest/biweekly-contest-83
****************************************************/

#include<bits/stdc++.h>
using namespace std;

/*
  Q: 2347. Best Poker Hand
*/
class Solution1_t
{
public:
  string bestHand(vector<int>& ranks, vector<char>& suits) 
  {
    unordered_map<int, int> freq;
    for(int r : ranks)
    {
      freq[r]++;
    }
    
    int count = 1;
    char ch = suits[0];
    for(int i = 1; i < 5; ++i)
    {
      if(ch == suits[i])
      {
        count++;
      }
    }
    
    if(count == 5)
    {
      return "Flush";
    }
    
    int rankCount = 0;
    for(auto it = freq.begin(); it != freq.end(); ++it)
    {
      rankCount = max(rankCount, it->second);
    }
    
    return (rankCount >= 3) ? "Three of a Kind" : ((rankCount >= 2) ? "Pair" : "High Card");
  }
};
/*
  Q: 2348. Number of Zero-Filled Subarrays
*/
class Solution2_t
{
public:
  long long zeroFilledSubarray(vector<int>& nums) 
  {
    long long ans = 0;
    long long count = 0;
    
    int l = nums.size();
    for(int i = 0; i < l; ++i)
    {
      if(nums[i] != 0)
      {
        ans = ans + ((count * (count+1))/2);
        count = 0;
      }
      else
      {
        count++;
      }
    }
    
    if(count > 0)
    {
      ans = ans + ((count * (count+1))/2);
    }
    
    return ans;
  }
};

/*
  Q: 2349. Design a Number Container System
*/
class NumberContainers 
{
private:
  unordered_map<int, int> posNum;
  unordered_map<int, set<int>> numPos;
public:
  NumberContainers() 
  {
  }

  void change(int index, int number) 
  {
    if(posNum.find(index) != posNum.end())
    {
      int num = posNum[index];
      
      auto it = numPos[num].find(index);
      if(it != numPos[num].end())
      {
        numPos[num].erase(it);
      }
      
      if(numPos[num].size() == 0)
      {
        numPos.erase(num);
      }
    }
    
    posNum[index] = number;
    numPos[number].insert(index);
  }

  int find(int number) 
  {
    if(numPos.find(number) == numPos.end())
    {
      return -1;
    }
    
    return *numPos[number].begin();
  }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */

/*
  Q: 2350. Shortest Impossible Sequence of Rolls - solution returns the partial answer - but not submitted, as it is known that it is not the correct solution!!
*/
class Solution4_t
{
public:
  int shortestSequence(vector<int>& rolls, int k) 
  {    
    unordered_map<int, int> freq;
    for(int r : rolls)
    {
      freq[r]++;
    }
    
    int mini = INT_MAX;
    for(int i = 1; i <= k; ++i)
    {
      mini = min(mini, freq[i]);
    }
    
    return mini == k ? k : mini+1;
  }
};