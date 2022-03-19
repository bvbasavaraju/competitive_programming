/****************************************************
Date: March 19, 2022
Successful submissions : 1
Time expiration : 0
Not Solved : 1
Wrong Answer/ Partial result : 2

link: https://leetcode.com/contest/biweekly-contest-74
****************************************************/

#include<bits/stdc++.h>

using namespace std;

/*
  Q: 2206. Divide Array Into Equal Pairs
*/
class Solution1_t
{
public:
  bool divideArray(vector<int>& nums) 
  {
    unordered_map<int, int> freq;
    for(int& n : nums)
    {
      freq[n]++;
    }
    
    for(auto it = freq.begin(); it != freq.end(); ++it)
    {
      if(it->second % 2 != 0)
      {
        return false;
      }
    }
    
    return true;
  }
};

/*
  Q: 2207. Maximize Number of Subsequences in a String
*/
class Solution2_t
{
public:
  long long maximumSubsequenceCount(string text, string pattern) 
  {
    long long ans = 0;
    int p0Count = 0;
    int p1Count = 0;
    for(char ch : text)
    {
      if(ch == pattern[1])
      {
        ans += p0Count;
        p1Count++;
      }
      
      if(ch == pattern[0])
      {
        p0Count++;
      }
    }
    
    return ans + max(p0Count, p1Count);
  }
};

/*
  Q: 2208. Minimum Operations to Halve Array Sum
*/
class Solution3_t
{
public:
  int halveArray(vector<int>& nums) 
  {
    double sum = 0;
    priority_queue<double> pq;
    for(int& n : nums)
    {
      sum += n;
      pq.push(n * 1.0);
    }
    
    int ans = 0;
    double rSum = sum;
    while(rSum > sum/2.0)
    {
      ans++;
      
      double t = pq.top();
      pq.pop();
      
      rSum -= t;
      rSum += (t / 2.0);
      if((t / 2.0) > 0)
      {
        pq.push(t / 2.0);
      }
      
      //std::cout << pq.top() << " " << rSum << " " << std::endl;
    }
    
    return ans;
  }
};

/*
  Q: 2209. Minimum White Tiles After Covering With Carpets - not solved!! yet to complete!
*/
class Solution4_t
{
public:
  int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) 
  {
    int l = floor.size();
    if(l <= numCarpets * carpetLen)
    {
      return 0;
    }
    
    int count = 0;
    unordered_map<int, int> freq;
    for(int i = 0; i < l; ++i)
    {
      if(floor[i] == '1')
      {
        count++;
        if(count == carpetLen)
        {
          freq[carpetLen]++;
          count = 0;
        }
      }
      else
      {
        freq[carpetLen]++;
        count = 0;
      }
    }
    
    for(int i = carpetLen; i > 0; --i)
    {
      int c = freq[i];
      
      if(c < numCarpets)
      {
        freq[i] -= numCarpets;
      }
    }
  }
};