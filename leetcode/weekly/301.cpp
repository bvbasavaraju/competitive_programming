/****************************************************
Date: July 10th, 2022
Successful submissions : 1
Time expiration : 0
Memory exhausted : 0
Not Solved : 3
Wrong Answer/ Partial result : 0

Note: 2 questions solved after contest! after checking other's solutions!!

link: https://leetcode.com/contest/weekly-contest-301
****************************************************/

/*
  Q: 2335. Minimum Amount of Time to Fill Cups - solved after looking into solution!!
*/
class Solution1_t
{
public:
  int fillCups(vector<int>& amount) 
  {
    priority_queue<int> pq;
    for(int a : amount)
    {
      if(a > 0)
      {
        pq.push(a);
      }
    }
    
    int ans = 0;
    while(!pq.empty() && pq.size() > 1)
    {
      int n1 = pq.top();
      pq.pop();
      
      int n2 = pq.top();
      pq.pop();
      
      n1--;
      n2--;
     
      ans++;
      if(n1 > 0)
      {
        pq.push(n1);
      }
      if(n2 > 0)
      {
        pq.push(n2);
      }
    }
    
    if(!pq.empty())
    {
      ans += pq.top();
    }
    
    return ans;
  }
};

/*
  Q: 2336. Smallest Number in Infinite Set
*/
class SmallestInfiniteSet 
{
private:
  int n;
  set<int> nums;
  set<int> removed;
public:
  SmallestInfiniteSet() : n(1)
  {

  }

  int popSmallest() 
  {
    int retVal = n;
    if(nums.empty() || (n < *nums.begin()))
    {
      n++;
    }
    else
    {
      retVal = *nums.begin();
      nums.erase(nums.begin());
    }
    removed.insert(retVal);
    
    return retVal;
  }

  void addBack(int num) 
  {
    if(removed.find(num) == removed.end())
    {
      return;
    }
    
    removed.erase(num);
    nums.insert(num);
  }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

/*
  Q: 2337. Move Pieces to Obtain a String - Sovled after looking into solution!
*/
class Solution 
{
public:
  bool canChange(string start, string target) 
  {
    int l = target.size();
    queue<pair<char, int>> sq;
    queue<pair<char, int>> tq;
    for(int i = 0; i < l; ++i)
    {
      if(start[i] != '_')
      {
        sq.push({start[i], i});
      }
      if(target[i] != '_')
      {
        tq.push({target[i], i});
      }
    }
    
    if(sq.size() != tq.size())
    {
      return false;
    }
    
    while(!sq.empty() && !tq.empty())
    {
      pair<char, int> s = sq.front();
      pair<char, int> t = tq.front();
      
      sq.pop();
      tq.pop();
      
      if(s.first != t.first)
      {
        return false;
      }
      
      if(s.first == 'L' && t.second > s.second)
      {
        return false;
      }
      
      else if(s.first == 'R' && t.second < s.second)
      {
        return false;
      }
    }
    
    return true;
  }
};
public:
  bool canChange(string start, string target) 
  {

  }
};

/*
  Q: 2338. Count the Number of Ideal Arrays - Not complete!
*/
class Solution4_t
{
public:
  int idealArrays(int n, int maxValue) 
  {
    static cosnt int MOD = 1e9 + 7;
    vector<int, int> mulitples(maxValue + 1, 0);
    for(int i = 1; i <= maxValue; ++i)
    {
      multiples[i] = maxValue/i;
    }
    
    vector<int> arr(n, 1);
    for(int i = 2; i <= max; ++i)
    {
      
    }
    
    long long ans = 0;
    for(int n : arr)
    {
      ans += n;
      ans %= MOD;
    }
    
    return static_cast<int>(ans % MOD);
  }
};
