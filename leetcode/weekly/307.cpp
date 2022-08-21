/****************************************************
Date: August 21st, 2022
Successful submissions : 2
Successful submissions after timeout : 0
Time expiration : 0
Memory exhausted : 0
Not Solved : 0
Incomplete Solution : 2
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/weekly-contest-307
****************************************************/

#include<bits/stdc++.h>
using namespace std;

/*
  Q: 2383. Minimum Hours of Training to Win a Competition
*/
class Solution1_t
{
public:
  int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) 
  {
    int ans = 0;
    
    for(int e : energy)
    {
      while(initialEnergy <= e)
      {
        ans++;
        initialEnergy++;
      }
      
      initialEnergy -= e;
    }
    
    //ans += initialEnergy <= sum ? sum - initialEnergy + 1 : 0;
    
    for(int e : experience)
    {
      while(initialExperience <= e)
      {
        ans++;
        initialExperience++;
      }
      
      initialExperience += e;
    }
    
    return ans;
  }
};

/*
  Q: 2384. Largest Palindromic Number
*/
class Solution2_t
{
public:
  string largestPalindromic(string num) 
  {
    vector<int> freq(10, 0);
    for(char ch : num)
    {
      freq[ch - '0']++;
    }
    
    bool oddFreqFound = false;
    for(int i = 9; i >= 0; --i)
    {
      if(!oddFreqFound)
      {
        if(freq[i] % 2 != 0)
        {
          oddFreqFound = true;
        }
      }
      else
      {
        if(freq[i] % 2 != 0)
        {
          freq[i]--;
        }
      }
    }
    
    string left = "";
    string right = "";
    int middleNumber = 11;
    for(int i = 9; i > 0; --i)
    {
      if(freq[i] % 2 != 0)
      {
        middleNumber = i;
        freq[i]--;
      }
      
      if(freq[i] == 0)
      {
        continue;
      }
      
      int count = freq[i]/2;
      string numS = string(count, i + '0');
      left += numS;
      right = numS + right;
    }

    if(freq[0] % 2 != 0)
    {
      middleNumber = (middleNumber >= 11) ? 0 : middleNumber;
      freq[0]--;
    }
    
    if(freq[0] > 0 && (left.size() > 0) && (right.size() > 0))
    {
      int count = freq[0]/2;
      string numS = string(count, '0');
      left += numS;
      right = numS + right;
    }
    
    string ans = middleNumber >= 11 ? ((left.size() > 0 && right.size() > 0) ? left + right : "0") : (left + string(1, middleNumber + '0') + right);
    return ans;
  }
};

/*
  Q: 2385. Amount of Time for Binary Tree to Be Infected
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

class Solution3_t
{
private:
  void preOrder(TreeNode* node, int start, vector<int>& nodes, int& pos)  
  {
    if(node == nullptr)
    {
      nodes.push_back(-1);
      return;
    }
    
    nodes.push_back(node->val);
    if(node->val == start)
    {
      pos = nodes.size()-1;
    }
    
    preOrder(node->left, start, nodes, pos);
    preOrder(node->right, start, nodes, pos);
  }
public:
  int amountOfTime(TreeNode* root, int start) 
  {
    int pos;
    vector<int> nodes;
    preOrder(root, start, nodes, pos);
   
    int ans = 0;
    int l = nodes.size();
    
    queue<int> infectedPos;
    vector<int> infected(l, 0);
    
    infectedPos.push(pos);
    infected[pos] = true;
    while(!infectedPos.empty())
    {
      int top = infectedPos.front();
            
      int parentPos = (top - 1)/ 2;
      int leftChild = (2 * top)  + 1;
      int rightChild = (2 * top)  + 2;
      
      if(parentPos >= 0 && nodes[parentPos] != -1 && infected[parentPos] != true)
      {
        infectedPos.push(parentPos);
        infected[parentPos] = infected[top] + 1;
        
        ans = max(ans, infected[parentPos]);
      }
      
      if(leftChild < l && nodes[leftChild] != -1 && infected[leftChild] != true)
      {
        infectedPos.push(leftChild);
        infected[leftChild] = infected[top] + 1;
        ans = max(ans, infected[leftChild]);
      }
      
      if(rightChild < l && nodes[rightChild] != -1 && infected[rightChild] != true)
      {
        infectedPos.push(rightChild);
        infected[rightChild] = infected[top] + 1;
        ans = max(ans, infected[rightChild]);
      }
    }
    
    return ans;
    
//     int l = nodes.size();
//     vector<int> infected(l, false);
//     vector<int> infectionTime(l, 0);
    
//     infected[pos] = true;
//     for(int i = pos; i >= 0; --i)
//     {
//       int parentPos = (pos - 1) / 2;
//       if(infected[pos])
//       {
//         infected[parentPos] = true;
//         infectionTime[parentPos] = infectionTime[pos] + 1;
//       }
//     }
  }
};

/*
  Q: 2386. Find the K-Sum of an Array - solution is incomplete
*/
class Solution4_t
{
private:
  void getAllPossible(const vector<int>& nums, int p, long long sum, vector<bool>& done, priority_queue<long long>& pq)
  {
    if(p >= nums.size())
    {
      return;
    }
    
    
    if(done[p])
    {
      return;
    }
    
    pq.push(nums[p]);
    
    long long newSum = sum + nums[p];
    
    pq.push(sum);
    pq.push(newSum);
    
    getAllPossible(nums, p+1, sum, done, pq);
    getAllPossible(nums, p+1, newSum, done, pq);
    
    done[p] = true;
  }
public:
  long long kSum(vector<int>& nums, int k) 
  {
    int l = nums.size();
    vector<bool> done(l, false);
    priority_queue<long long> pq;
    
    getAllPossible(nums, 0, 0, done, pq);
    
    while(pq.size() > 0)
    {
      std::cout << pq.top() << " ";
      pq.pop();
    }
    std::cout << endl;
    
    // int count  = 0;
    // while(count < k && pq.size() > 0)
    // {
    //   count++;
    //   pq.pop();
    // }
    
    return pq.size() > 0 ? pq.top() : 0;
  }
};