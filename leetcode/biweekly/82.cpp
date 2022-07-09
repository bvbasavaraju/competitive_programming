/****************************************************
Date: June 22th, 2022
Successful submissions : 1
Time expiration : 0
Memory limit exceeded : 0
Not Solved : 3
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/biweekly-contest-82
****************************************************/

#include<bits/stdc++.h>
using namespace std;

/*
  Q: 2331. Evaluate Boolean Binary Tree
*/
struct TreeNode 
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution1_t
{
private:
  bool getAns(TreeNode* node)
  {
    if(node == nullptr)
    {
      return true;
    }
    
    if(node->val == 0 || node->val == 1)
    {
      return node->val == 0 ? false : true;
    }
    
    bool left = getAns(node->left);
    bool right = getAns(node->right);
    
    return node->val == 2 ? (left || right) : (left && right);
  }
public:
  bool evaluateTree(TreeNode* root) 
  {
    return getAns(root);
  }
};

/*
  Q: 2332. The Latest Time to Catch a Bus
*/
class Solution2_t
{
public:
  int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) 
  {
    
  }
};

/*
  Q: 2333. Minimum Sum of Squared Difference
*/
class Solution3_t
{
private:
  long long getMinSum(const vector<int>& n1, const vector<int>& n2, int p1, int p2, int k1, int k2, unordered_map<string, long long>& cache, long long sum)
  {
    if(p1 >= n1.size() || p2 >= n2.size())
    {
      return INT_MAX;
    }
    
    string key = std::to_string(p1) + "_" + std::to_string(p2) + "_" + std::to_string(k1) + "_" + std::to_string(k2);
    if(cache.find(key) != cache.end())
    {
      return cache[key];
    }
    
    long long ans = sum;
    long long ss = ((n1[p1] - n2[p2]) * (n1[p1] - n2[p2]));
    if((k1 > 0) && (k2 > 0))
    {
      ans -= ss;
      long long incBoth = ((n1[p1]+1 - (n2[p2]+1)) * (n1[p1]+1 - (n2[p2]+1)));
      long long decBoth = ((n1[p1]-1 - (n2[p2]-1)) * (n1[p1]-1 - (n2[p2]-1)));
      
      long long ai = getMinSum(n1, n2, p1+1, p2+1, k1-1, k2-1, cache, ans + incBoth);
      long long ad = getMinSum(n1, n2, p1+1, p2+1, k1-1, k2-1, cache, ans + decBoth);
      
      ans = min({ans, ai, ad});
    }
    else if(k1 > 0)
    {
      ans -= ss;
      long long inc = ((n1[p1]+1 - n2[p2]) * (n1[p1]+1 - n2[p2]));
      long long dec = ((n1[p1]-1 - n2[p2]) * (n1[p1]-1 - n2[p2]));
      
      long long ai = min({getMinSum(n1, n2, p1+1, p2, k1-1, k2, cache, ans + inc), getMinSum(n1, n2, p1, p2, k1-1, k2, cache, ans + inc)});
      long long ad = min({getMinSum(n1, n2, p1+1, p2, k1-1, k2, cache, ans + dec), getMinSum(n1, n2, p1, p2, k1-1, k2, cache, ans + dec)});
      
      ans = min({ans, ai, ad});
    }
    else if(k2 > 0)
    {
      ans -= ss;
      long long inc = ((n1[p1] - (n2[p2]+1)) * (n1[p1] - (n2[p2] + 1)));
      long long dec = ((n1[p1] - (n2[p2]-1)) * (n1[p1] - (n2[p2] - 1)));
      
      long long ai = min({getMinSum(n1, n2, p1, p2+1, k1, k2-1, cache, ans + inc), getMinSum(n1, n2, p1, p2, k1, k2-1, cache, ans + inc)});
      long long ad = min({getMinSum(n1, n2, p1, p2+1, k1, k2-1, cache, ans + dec), getMinSum(n1, n2, p1, p2, k1, k2-1, cache, ans + dec)});
      
      ans = min({ans, ai, ad});
    }
    
    cache[key] = min(sum, ans);
    
    return ans;
  }
  
  long long getMinSum(const vector<int> num, int p, int k, vector<vector<long long>>& cache, long long sum)
  {
    if(p >= num.size() || k <= 0)
    {
      return 1e18;
    }
    
    if(cache[p][k] < 1e18)
    {
      return cache[p][k];
    }
    
    int dec = num[p] - 1;
    long long ans = min(sum, sum - (num[p] * num[p]) + (dec * dec));
    
    long long op = min(getMinSum(num, p+1, k-1, cache, ans), getMinSum(num, p, k-1, cache, ans));
    
    ans = min(ans, op);
    
    cache[p][k] = ans;
    return ans;
  }
  
public:
  long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) 
  {
//     long long sum = 0;
//     int l = nums1.size();
    
//     priority_queue<long long> pq;
//     for(int i = 0; i < l; ++i)
//     {
//       long long n = abs(nums1[i] - nums2[i]);
//       pq.push(n);
//       sum += n * n;
//     }
    
//     long long ans = sum;
//     int k = k1 + k2;
//     while(k > 0)
//     {
//       long long t = pq.top();
//       pq.pop();
      
//       long long ns = sum - (t * t);
//       t--;
//       ns += t * t;
      
//       sum = min(sum, ns);
      
//       pq.push(t);
//       ans = min(ans, sum);
      
//       k--;
//     }
    
//     return ans;
      
    long long sum = 0;
    int l = nums1.size();
    
    vector<int> diffs(l);
    for(int i = 0; i < l; ++i)
    {
      diffs[i] = nums1[i] - nums2[i];
      
      sum += diffs[i] * diffs[i];
    }
    
    
    vector<vector<long long>> cache(l, vector<long long>(k1 + k2 + 1, 1e18));
    for(int i = 0; i < l; ++i)
    {
      cache[i][k1+k2] = sum;
    }
    
    long long ans = getMinSum(diffs, 0, k1+k2, cache, sum);
    
    return ans >= 1e18 ? sum : ans;
    
//     for(int i = 0; i < l; ++i)
//     {
//       sum += ((nums1[i] - nums2[i]) * (nums1[i] - nums2[i]));
//     }
    
//     long long ans = sum;
//     unordered_map<string, long long> cache;
//     return getMinSum(nums1, nums2, 0, 0, k1, k2, cache, ans);
  }
};
/*
  Q: 2334. Subarray With Elements Greater Than Varying Threshold
*/
class Solution4_t
{
private:
  int areGreater(vector<int>& nums, int i, int j, int t)
  {
    for(int k = i; k <= j; ++k)
    {
      if(nums[k] <= t)
      {
        return -1;
      }
    }
    
    return (j-i+1);
  }
  
  int getSize(vector<int>& nums, int i, int j, int t, vector<vector<int>>& cache)
  {
    if(i > j)
    {
      return -1;
    }
    
    if(cache[i][j] != -1)
    {
      return cache[i][j];
    }
    
    int count = areGreater(nums, i, j, t/(j-i+1));
    if(count > 0)
    {
      return cache[i][j] = count;
    }

    for(int k = i+1; k <= j; ++k)
    {
      int left = getSize(nums, i, k, t, cache);
      int right = getSize(nums, k, j, t, cache);
      
      cache[i][j] = left != -1 ? left : right;
    }
    
    return cache[i][j];
  }
public:
  int validSubarraySize(vector<int>& nums, int threshold) 
  {
    int l = nums.size();
    vector<vector<int>> cache(l, vector<int>(l, -1));
    return getSize(nums, 0, l-1, threshold, cache);
  }
};