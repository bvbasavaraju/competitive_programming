/****************************************************
Date: August 28th, 2022
Successful submissions : 2
Successful submissions after timeout : 0
Time expiration : 0
Memory exhausted : 0
Not Solved : 1
Incomplete Solution : 2
Wrong Answer/ Partial result : 0
Solved looking at solutions : 1

link: https://leetcode.com/contest/weekly-contest-308
****************************************************/

/*
  Q: 2389. Longest Subsequence With Limited Sum - solved looking at the solution!!
*/
class Solution1_t
{
private:
  
  int getPos(vector<int>& nums, int target)
  {
    int l = 0;
    int h = nums.size() - 1;
    
    int pos = -1;
    while(l <= h)
    {
      int m = l + (h-l)/2;
      
      if(nums[m] <= target)
      {
        pos = m;
        l = m+1;
      }
      else
      {
        h = m-1;
      }
    }
    
    return pos;
  }
  
public:
  vector<int> answerQueries(vector<int>& nums, vector<int>& queries) 
  {
    sort(nums.begin(), nums.end());
    
    int l = nums.size();
    for(int i = 1; i < l; ++i)
    {
      nums[i] += nums[i-1];
    }
    
    vector<int> ans;
    for(int q : queries)
    {
      int p = getPos(nums, q);
      ans.push_back(p+1);
    }
    
    return ans;
  }
};

/*
  Q: 2390. Removing Stars From a String
*/
class Solution2_t
{
public:
  string removeStars(string s) 
  {
    int l = s.size();
    
    string ans = "";
    int count = 0;
    for(int i = l-1; i >= 0; --i)
    {      
      if(s[i] == '*')
      {
        count++;
        continue;
      }
      
      if(count > 0)
      {
        count--;
      }
      else
      {
        ans += s[i];
      }
    }
    
    reverse(ans.begin(), ans.end());
    
    return ans;
  }
};

/*
  Q: 2391. Minimum Amount of Time to Collect Garbage
*/
class Solution3_t
{
public:
  int garbageCollection(vector<string>& garbage, vector<int>& travel) 
  {
    vector<int> freq(26, 0);
    vector<unordered_set<char>> types(garbage.size());
    
    int i = 0;
    for(string g : garbage)
    {
      for(char ch : g)
      {
        freq[ch-'A']++;
        types[i].insert(ch);
      }
      
      i++;
    }
    
    int l = travel.size();
    for(int i = 1; i < l; ++i)
    {
      travel[i] += travel[i-1];
    }
    
    int count = 0;
    string str = "GMP";
    
    int ans = 0;
    l = garbage.size();
    unordered_set<int> found;
    for(int i = l-1; i >= 0; --i)
    {
      for(char t : str)
      {
        if(found.find(t) != found.end())
        {
          continue;
        }
        
        if(types[i].find(t) != types[i].end())
        {
          found.insert(t);
          
          if(i-1 >= 0)
          {
            freq[t-'A'] += travel[i-1];
          }
          
          ans += freq[t - 'A'];
        }
      }
      
      if(found.size() >= 3)
      {
        break;
      }
    }
    
    return ans;
  }
};

/*
  Q: 2392. Build a Matrix With Conditions
*/

class Solution4_t
{
public:
  vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) 
  {
      
  }
};