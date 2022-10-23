/****************************************************
Date: Oct 9th, 2022
Successful submissions : 2
Successful submissions after timeout : 0
Time expiration : 1
Memory exhausted : 0
Not Solved : 0
Incomplete Solution : 0
Wrong Answer/ Partial result : 1
Solved looking at solutions : 0

link: https://leetcode.com/contest/weekly-contest-314
****************************************************/

/*
  Q: 2432. The Employee That Worked on the Longest Task
*/
class Solution1_t
{
public:
  int hardestWorker(int n, vector<vector<int>>& logs) 
  {
    //unordered_map<int, priority_queue<int> > tasks;
    
    int l = logs.size();
    int emp = logs[0][0];
    int endTime = logs[0][1];
    
    //tasks[logs[0][0]].push(logs[0][1]);
    
    for(int i = 1; i < l; ++i)
    {
      int timeTaken = logs[i][1] - logs[i-1][1];
      
      if(timeTaken > endTime)
      {
        endTime = timeTaken;
        emp = logs[i][0];
      }
      else if(timeTaken == endTime)
      {
        if(logs[i][0] <= emp)
        {
          endTime = timeTaken;
          emp = logs[i][0];
        }
      }
      //tasks[logs[i][0]].push(logs[i][0])
    }
    
    return emp;
  }
};

/*
  Q: 2433. Find The Original Array of Prefix Xor
*/
class Solution2_t
{
public:
  vector<int> findArray(vector<int>& pref) 
  {
    int l = pref.size();
    
    vector<int> ans(l);
    
    ans[0] = pref[0];
    for(int i = 1; i < l; ++i)
    {
      ans[i] = pref[i-1] ^ pref[i];
    }
    
    return ans;
  }
};

/*
  Q: 2434. Using a Robot to Print the Lexicographically Smallest String - wrong answer
*/
class Solution3_t
{
public:
  string robotWithString(string s) 
  {
    int l = s.size();
    
    vector<priority_queue<int>> pos;
    
    for(int i = 0; i < l; ++i)
    {
      pos[s[i]-'a'].push(i);
    }
    
    string ans = "";
    int prevPosProcessed = -1;
    for(int i = 0; i < 26; ++i)
    {
      if(pos[i].size() <= 0)
      {
        continue;
      }
      
      if(prevPosProcessed >= 0 && prevPosProcessed >= pos[i].top())
      {
        continue;
      }
      
      string subs = "";
      
      if(prevPosProcessed < 0)
      {
        subs = s.substr(0, pos[i].top()+1);
      }
      else
      {
        subs = s.substr(prevPosProcessed, pos[i].top() - prevPosProcessed);
      }
      
      reverse(subs.begin(), subs.end());
      
      ans += subs;
      prevPosProcessed = pos[i].top();
    }
    
    return ans;
  }
};

/*
  Q: 2435. Paths in Matrix Whose Sum Is Divisible by K - time limit exceeded
*/
class Solution4_t
{
public:
  int numberOfPaths(vector<vector<int>>& grid, int k) 
  {
    static const int MOD = 1e9 + 7;
    
    int r = grid.size();
    int c = grid[0].size();
    
    long long ans = 0;
    
    vector< vector< unordered_map<int, long long> > > sum(r, vector<unordered_map<int, long long>>(c));
    for(int i = 0; i < r; ++i)
    {
      for(int j = 0; j < c; ++j)
      {
        if(i == 0 && j == 0)
        {
          sum[i][j][grid[i][j]]++;
          continue;
        }
        
        if(i == 0)
        {
          for(auto it = sum[i][j-1].begin(); it != sum[i][j-1].end(); ++it)
          {
            sum[i][j][grid[i][j] + it->first]++;
          }
          continue;
        }
        
        if(j == 0)
        {
          for(auto it = sum[i-1][j].begin(); it != sum[i-1][j].end(); ++it)
          {
            sum[i][j][grid[i][j] + it->first]++;
          }
          continue;
        }
        
        //to left of cell
        for(auto it = sum[i][j-1].begin(); it != sum[i][j-1].end(); ++it)
        {
          int val = it->first;
          long long freq = it->second;
          
          int sum_ = val + grid[i][j];
          
          freq = (freq + (sum[i][j][sum_] % MOD)) % MOD;
          
          if(i == r-1 && j == c-1)
          {
            if(sum_ % k == 0)
            {
              sum[i][j][sum_] = freq;
            }
          }
          else
          {
            sum[i][j][sum_] = freq;
          }
          // sum[i][j][sum_] = freq;
          
          // if(i == r-1 && j == c-1)
          // {
          //   if(sum_ % k == 0)
          //   {
          //     ans = (ans + freq) % MOD;
          //   }
          // }
        }
        
        //to top of cell
        for(auto it = sum[i-1][j].begin(); it != sum[i-1][j].end(); ++it)
        {
          int val = it->first;
          long long freq = it->second;
          
          int sum_ = val + grid[i][j];
          
          freq = (freq + (sum[i][j][sum_] % MOD)) % MOD;
          
          if(i == r-1 && j == c-1)
          {
            if(sum_ % k == 0)
            {
              sum[i][j][sum_] = freq;
            }
          }
          else
          {
            sum[i][j][sum_] = freq;
          }
          
          //sum[i][j][sum_] = freq;
          
          // if(i == r-1 && j == c-1)
          // {
          //   if(sum_ % k == 0)
          //   {
          //     ans = (ans + freq) % MOD;
          //   }
          // }
        }
      }
    }
    
    // if(k == 1)
    // {
    //   return sum[r-1][c-1].size();
    // }
    
    //long long ans = 0;
    unordered_map<int, long long>& m = sum[r-1][c-1];
    for(auto it = m.begin(); it != m.end(); ++it)
    {
      if(it->first % k == 0)
      {
        ans = (ans + it->second) % MOD;
      }
    }
    
    return static_cast<int>(ans % MOD);
  }
};