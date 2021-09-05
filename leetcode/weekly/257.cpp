/****************************************************
Date: Sept 5, 2021
Successful submissions : 1
Time expiration : 1
Not Solved : 0
Wrong Answer/ Partial result : 2

link: https://leetcode.com/contest/weekly-contest-257
****************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

/*
  Q: 1995. Count Special Quadruplets
*/
class Solution 
{
private:
  
public:
  int countQuadruplets(vector<int>& nums) 
  {
    int ans = 0;
    int l = nums.size();
    for(int i = 0; i < l-3; ++i)
    {
      for(int j = i+1; j < l-2; ++j)
      {
        for(int k = j+1; k < l-1; ++k)
        {
          for(int p = k+1; p < l; ++p)
          {
            if(nums[i] + nums[j] + nums[k] == nums[p])
            {
              ans++;
            }
          }
        }
      }
    }
    
    return ans;
  }
};

/*
  Q: 1996. The Number of Weak Characters in the Game - Wrong answer
*/
class Solution 
{
public:
  int numberOfWeakCharacters(vector<vector<int>>& props) 
  {
    sort(props.begin(), props.end(), [](const vector<int>& p1, const vector<int>& p2) -> bool
         {
            if((p1[0] >= p2[0] && p1[1] >= p2[1]) || (p1[0] >= p2[0]))
            {
              return true;
            }
           
           return false;
         });
    
    int ans = 0;
    int l = props.size();
    
    int p = 0;
    for(int i = 1; i < l;)
    {
      while(props[i][0] > props[p][0] && props[i][1] > props[p][1])
      {
        ans++;
        ++p;
        ++i;
        
        if(p >= l || i >= l)
        {
          break;
        }
      }
      
      p = i;
      ++i;
    }
    
    return ans;
  }
};

/*
  Q: 1997. First Day Where You Have Been in All the Rooms - time limit exceeded
*/
class Solution 
{
public:
  int firstDayBeenInAllRooms(vector<int>& nextVisit) 
  {
    static const int MOD = 1e9 + 7;
    
    long long ans = 0;
    
    int t = nextVisit.size();
    int l = nextVisit.size();

    vector<int> freq(l, 0);
    int room = nextVisit[static_cast<int>(ans)];
    while(l > 0)
    {
      freq[room]++;
      if(freq[room] == 1)
      {
        l--;
        if(l == 0)
        {
          break;
        }
      }
      
      //num of visit check
      if(freq[room] % 2 > 0)
      {
        room = nextVisit[room];
      }
      else
      {
        room = (room + 1) % t;
      }
      
      ans++;
    }
    
    return ans % MOD;
  }
};

/*
  Q: 1998. GCD Sort of an Array - compilation error
*/
class Solution 
{
private:
  unordered_map<vector<int>, int> gcds;
  
  int getGcd(int a, int b)
  {
    if(a == 0)
    {
      return b;
    }
    
    if(b == 0)
    {
      return a;
    }
    
    if(a == b)
    {
      return a;
    }
    
    if(a > b)
    {
      return getGcd(a-b, b);
    }
    
    return getGcd(a, b-a);
  }
  
public:
  bool gcdSort(vector<int>& nums) 
  {
    sort(nums.begin(), nums.end(), [&gcds = gcds, this](const int& a, const int& b) -> bool
         {
           int maxi = max(a,b);
           int mini = min(a,b);
           
           int gcdVal = 1;
           if(gcds.count({maxi, mini}) != 0)
           {
             gcdVal = gcds[{maxi, mini}];
           }
           else
           {
             int gcd_ = this->getGcd(maxi, mini);
             gcds[{maxi, mini}] = gcd_;
             
             gcdVal = gcd_;
           }
           
           return gcdVal > 1;
         });
    
    //Check if sorted!
    int prev = nums[0];
    for(int n : nums)
    {
      if(prev > n)
      {
        return false;
      }
      
      prev = n;
    }
    
    return true;
  }
};