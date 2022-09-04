/****************************************************
Date: Sept 3rd, 2022
Successful submissions : 3
Successful submissions after timeout : 0
Time expiration : 0
Memory exhausted : 0
Not Solved : 1
Incomplete Solution : 2
Wrong Answer/ Partial result : 1
Solved looking at solutions : 0

link: https://leetcode.com/contest/biweekly-contest-86
****************************************************/

#include<bits/stdc++.h>
using namespace std;

/*
  Q: 2395. Find Subarrays With Equal Sum
*/
class Solution1_t
{
public:
  bool findSubarrays(vector<int>& nums) 
  {
    unordered_map<long long, vector<int>> sumPos;
    
    long long sum = 0;
    int l = nums.size();
    for(int i = 0; i < l; ++i)
    {
      sum += nums[i];
      
      if((i+1) >= 2)
      {
        sumPos[sum].push_back(i+1 - 2);
        if(sumPos[sum].size() >= 2)
        {
          return true;
        }
        
        sum -= nums[i+1 - 2];
      }
    }
    
    return false;
  }
};

/*
  Q: 2396. Strictly Palindromic Number
*/
class Solution2_t
{
private:
  
  bool isPalindrome(const string& toCheck)
  {
    int l = toCheck.size();
    for(int i = 0, j = l-1; i < j; ++i, --j)
    {
      if(toCheck[i] != toCheck[j])
      {
        return false;
      }
    }
    
    return true;
  }
  
  string getStringRepresentation(int n, int b)
  {
    string ans = "";
    while(n > 0)
    {
      ans += ((n % b) + '0');
      n /= b;
    }
    
    return ans;
  }
    
public:
  bool isStrictlyPalindromic(int n) 
  {
    for(int i = 2; i <= n-1; ++i)
    {
      string str = getStringRepresentation(n, i);
      if(!isPalindrome(str))
      {
        return false;
      }
    }
    
    return true;
  }
};

/*
  Q: 2397. Maximum Rows Covered by Columns
*/
class Solution3_t
{
private:
  int getCount(const vector<vector<int>>& mat, unordered_set<int>& cols)
  {
    int count = 0;
    for(const vector<int>& row : mat)
    {
      int l = row.size();
      bool countThisRow = true;
      for(int i = 0; i < l; ++i)
      {
        if(row[i] == 1)
        {
          if(cols.find(i) == cols.end())
          {
            countThisRow = false;
            break;
          }
        }
      }
      
      if(countThisRow)
      {
        count++;
      }
    }
    
    return count;
  }
  
public:
  int maximumRows(vector<vector<int>>& mat, int cols) 
  {
    int r = mat.size();
    int c = mat[0].size();
    
    int ans = 0;
    int val = (1 << c);
    for(int b = 1; b < val; ++b)
    {
      int pos = c-1;
      int count = 0;
      unordered_set<int> colsToBeChecked;
      
      int temp = b;
      while(temp > 0)
      {
        if(temp & 0x01)
        {
          count++;
          colsToBeChecked.insert(pos);
        }
        
        temp >>= 1;
        pos--;
      }
      
      if(count != cols)
      {
        continue;
      }
      
      ans = max(ans, getCount(mat, colsToBeChecked));
    }
    
    return ans;
  }
};

/*
  Q: 2398. Maximum Number of Robots Within Budget
*/
class Solution4_t
{
private:
//   class Compare
//   {
//   public:
//       bool operator() (const pair<int, int>& p1, const pair<int, int>& p2)
//       {
//           return (p1.first >= p2.first);
//       }
//   };
  
//   priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;  // time and position
  priority_queue<pair<int, int>> pq;  // time and position
  
  void removeEntryInPQ(int pos)
  {
    if(pq.top().second == pos)
    {
      pq.pop();
      return;
    }
    
    pair<int, int> pair = pq.top();
    pq.pop();
    
    removeEntryInPQ(pos);
    
    pq.push(pair);
  }
  
public:
  int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) 
  {
    int ans = 0;
    
    int l = chargeTimes.size();
    
    int pos = 0;
    long long sum = 0;
    //long long currentBudget = 0;

    
    for(int i = 0; i < l; ++i)
    {
      pq.push({chargeTimes[i], i});
      
      sum += runningCosts[i];
      
      long long subSum = 0;
      
      //long long currentBudget = pq.top().first + ((i+1 - pos) * sum);
      long long sumLeng = (pq.size() * sum);
      long long currentBudget = pq.top().first + sumLeng;
      
      int count = 1;
      while(currentBudget > budget)
      {
        removeEntryInPQ(pos);
        
        if(pq.empty())
        {
          pos++;
          sum = 0;
          break;
        }
        
        subSum += runningCosts[pos];
        
        long long newSum = sumLeng - (count * subSum);
        
        currentBudget = pq.top().first + newSum;
        
        count++;
        pos++;
        
        if(currentBudget <= budget)
        {
          sum -= subSum;
        }
      }
      
      ans = max(ans, static_cast<int>(pq.size()));
    }
    
    return ans;
  }
};