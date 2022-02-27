/****************************************************
Date: Feb 27th, 2022
Successful submissions : 3
Time expiration : 0
Not Solved : 1
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/weekly-contest-282
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
  Q: 2185. Counting Words With a Given Prefix
*/
class Solution1_t
{
public:
  int prefixCount(vector<string>& words, string pref) 
  {
    int ans = 0;
    for(string w : words)
    {
      string p = w.substr(0, pref.size());
      if(p == pref)
      {
        ans++;
      }
    }
    
    return ans;
  }
};

/*
  Q: 2186. Minimum Number of Steps to Make Two Strings Anagram II
*/
class Solution2_t
{
public:
  int minSteps(string s, string t) 
  {
    vector<int> freq(26, 0);
    
    for(auto ch : s)
    {
      freq[ch-'a']++;
    }
    
    for(auto ch : t)
    {
      freq[ch-'a']--;
    }
    
    int ans = 0;
    for(int i = 0; i < 26; ++i)
    {
      ans += abs(freq[i]);
    }
    
    return ans;
  }
};

/*
  Q: 2187. Minimum Time to Complete Trips
*/
class Solution3_t
{
private:
  long long getTripsForGivenTime(vector<int>& time, long long timeTaken)
  {
    long long retVal = 0;
    
    for(long long t : time)
    {
      retVal += (timeTaken / t);
    }
    
    return retVal;
  }
    
public:
  long long minimumTime(vector<int>& time, int totalTrips) 
  {
    long long s = 1;
    long long e = s << 1;
    
    //First calculate the range of time!
    while(s <= e)
    {
      long long timeTaken = s + (e-s)/2;
      long long trips = getTripsForGivenTime(time, timeTaken);
      
      if(trips < static_cast<long long>(totalTrips))
      {
        s = timeTaken;
        e <<= 1;
      }
      else
      {
        break;
      }
    }
    
    //In that range find the min time required to complet total trips
    long long ans = 0;
    long long prevDelta = 1e14;
    while(s <= e)
    {
      long long timeTaken = s + (e-s)/2;
      long long trips = getTripsForGivenTime(time, timeTaken);
      
      if(trips < static_cast<long long>(totalTrips))
      {
        s = timeTaken + 1;
      }
      else
      {
        long long delta = trips - static_cast<long long>(totalTrips);
        if(delta <= prevDelta)
        {
          ans = timeTaken;
          prevDelta = delta;
        }
        
        e = timeTaken - 1;
      }
    }

    return ans;
  }
};

/*
  Q: 2188. Minimum Time to Finish the Race
*/
class Solution 
{
public:
  int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) 
  {
      
  }
};