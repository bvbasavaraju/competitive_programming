/****************************************************
Date: July 25th, 2021
Successful submissions : 1
Time expiration : 0
Not Solved : 2
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/weekly-contest-252
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
  Q: 1952. Three Divisors
*/
class Solution_1
{
public:
  bool isThree(int n) 
  {
    int divisors = 0;
    
    for(int i = 2; i <= (n/2); ++i)
    {
      if(n % i == 0)
      {
        divisors++;
      }
    }
    
    return (divisors == 1);
  }
};

/*
  Q: 1953. Maximum Number of Weeks for Which You Can Work - wrong answer - partial output
*/
class Solution2_t
{
public:
  long long numberOfWeeks(vector<int>& milestones) 
  {
    int l = milestones.size();
    if(l == 1)
    {
      return 1;
    }
    
    sort(milestones.begin(),milestones.end(), [](const int m1, const int m2) -> bool { return m1 > m2; });
    
    int ans = 0;
    for(int i = 1; i < l; ++i)
    {
      if(milestones[i] == milestones[i-1])
      {
        ans += 2*milestones[i];
        milestones[i] = abs(milestones[i] - milestones[i-1]);
        i++;
      }
      else
      {
        ans += 2 * (min(milestones[i], milestones[i-1]));
        milestones[i] = abs(milestones[i] - milestones[i-1]);
      }
    }
    
    return milestones[l-1] >= 1 ? ans + 1 : ans;
  }
};

/*
  Q: 1954. Minimum Garden Perimeter to Collect Enough Apples
*/
class Solution3_t
{
public:
  long long minimumPerimeter(long long neededApples) 
  {
      
  }
};

/*
  Q: 1955. Count Number of Special Subsequences
*/
class Solution4_t
{
public:
  int countSpecialSubsequences(vector<int>& nums) 
  {
      
  }
};