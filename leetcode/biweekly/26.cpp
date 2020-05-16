/****************************************************
Date: May 16th, 2020
Successful submissions : 3
Time expiration : 1
Not Solved : 0
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/biweekly-contest-26
****************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <limits.h>

using namespace std;

/*
  Q: 1446. Consecutive Characters
*/
class Solution1_t
{
public:
  int maxPower(string s) 
  {
    int ans = 0;
    int power_char = 0;
    int power_char_count = 0;
    
    for(int ch : s)
    {
      if(power_char == ch)
      {
        power_char_count++;
      }
      else
      {
        power_char = ch;
        power_char_count = 1;
      }
      
      ans = max(ans, power_char_count);
    }
    
    return ans;
  }
};

/*
  Q: 1447. Simplified Fractions
*/
class Solution2_t
{
public:
  vector<string> simplifiedFractions(int n) 
  {
    vector<string> ans;
    
    if(n == 1)
    {
      return ans;
    }
    
    unordered_set<double> fractions;
    for(int i = 1; i < n; ++i)
    {
      for(int j = i + 1; j <= n; ++j)
      {
        double frac = static_cast<double>(i) / static_cast<double>(j);
        if(fractions.find(frac) == fractions.end())
        {
          string s = std::to_string(i) + "/" + std::to_string(j);
          ans.push_back(s);
          fractions.insert(frac);
        }
      }
    }
    
    return ans;
  }
};

/*
  Q: 1448. Count Good Nodes in Binary Tree
*/
/**
 * Definition for a binary tree node.
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
  void countIfGood(TreeNode* node, int curr_max, int& count)
  {
    if(node == NULL)
    {
      return;
    }
    
    if(node->val >= curr_max)
    {
      count++;
    }
    
    countIfGood(node->left, max(curr_max, node->val), count);
    countIfGood(node->right, max(curr_max, node->val), count);
  }

public:
  int goodNodes(TreeNode* root) 
  {
    int ans = 0;
    countIfGood(root, INT_MIN, ans);
    return ans;
  }
};

/*
  Q: 1449. Form Largest Integer With Digits That Add up to Target - time limit exceeded!
*/
class Solution4_t
{
private:
  string ans;
  vector<int> costs_in_order;
  unordered_map<int, int> highest_digit_for_given_cost; //first = cost, second = digit

  void isTargetReachable2(int pos, int target, vector< pair<int, int> >& digit_repeat_count, unordered_set<int>& unreachable_target)
  {
    if((target == 0) || (pos >= costs_in_order.size()))
    {
      return;
    }
    
    int repeater = target / costs_in_order[pos];
    if((repeater == 0) || (unreachable_target.find(target) != unreachable_target.end()))
    {
      unreachable_target.insert(target);
      return;
    }
    
    int digit = highest_digit_for_given_cost[costs_in_order[pos]];
    for(int i = repeater; i > 0; --i)
    {
      pair<int, int> pair_ = std::make_pair(digit, i);
      digit_repeat_count.push_back(pair_);
      
      int new_target = target - (costs_in_order[pos] * pair_.second);
      if(new_target == 0)
      {
        updateAnswer(digit_repeat_count);
      }
      else if(new_target < 0)
      {
        unreachable_target.insert(new_target);
      }
      else if(unreachable_target.find(new_target) == unreachable_target.end())
      {
        for(int j = pos + 1; j <= costs_in_order.size(); ++j)
        {
          if(new_target < costs_in_order[pos])
          {
            break;
          }
          unordered_set<int> unreachable_target;
          isTargetReachable2(j, new_target, digit_repeat_count, unreachable_target);
        }
      }

      digit_repeat_count.pop_back();
    }
  }

  void updateAnswer(vector< pair<int, int> > digit_repeat_count)
  {
    string num_in_string = "";
    int l = digit_repeat_count.size();
    
    sort(digit_repeat_count.begin(), digit_repeat_count.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) -> bool { return p1.first > p2.first; });
    for(int i = 0; i < l; i++)
    {
      string s = std::to_string(digit_repeat_count[i].first);

      for(int c = 0; c < digit_repeat_count[i].second; c++)
      {
        num_in_string += s;
      }
    }

    if(ans.size() < num_in_string.size())
    {
      ans = num_in_string;
    }
    else if(ans.size() == num_in_string.size())
    {
      ans = max(ans, num_in_string);
    }
  }
  
public:
  string largestNumber(vector<int>& cost, int target) 
  {
    for(int i = 0; i < 9; ++i)
    {
      highest_digit_for_given_cost[cost[i]] = i + 1;
    }
    
    for(auto p : highest_digit_for_given_cost)
    {
      costs_in_order.push_back(p.first);
    }

    //sort(costs_in_order.begin(), costs_in_order.end());
    sort(costs_in_order.begin(), costs_in_order.end()/*, [](int n1, int n2) -> bool {return n1 > n2;} */);
    
    ans = "0";
    int l = costs_in_order.size();
    for(int i = 0; i < l; ++i)
    {
      vector< pair<int, int> > digit_repeat_count;
      unordered_set<int> unreachable_target;
      isTargetReachable2(i, target, digit_repeat_count, unreachable_target);
    }

    return ans;
  }
};


int main()
{
  // {
  //   Solution4_t s;
  //   vector<int> costs = {4,3,2,5,6,7,2,5,5};
  //   std::cout << s.largestNumber(costs, 9);
  // }
  // {
  //   Solution4_t s;
  //   vector<int> costs = {7,6,5,5,5,6,8,7,8};
  //   std::cout << s.largestNumber(costs, 12);
  // }
  // {
  //   Solution4_t s;
  //   vector<int> costs = {5,4,4,5,5,5,5,5,5};
  //   std::cout << s.largestNumber(costs, 19);
  // }
  // {
  //   Solution4_t s;
  //   vector<int> costs = {5,6,7,3,4,6,7,4,8};
  //   std::cout << s.largestNumber(costs, 29);
  // }
  // {
  //   Solution4_t s;
  //   vector<int> costs = {7,5,7,3,3,4,6,5,4};
  //   std::cout << s.largestNumber(costs, 27);
  // }
  // {
  //   Solution4_t s;
  //   vector<int> costs = {28,38,35,23,37,20,21,27,28};
  //   std::cout << s.largestNumber(costs, 86);
  // }
  // {
  //   Solution4_t s;
  //   vector<int> costs = {29,60,55,90,90,92,61,32,55};
  //   std::cout << s.largestNumber(costs, 602);
  // }
  // {
  //   Solution4_t s;
  //   vector<int> costs = {96,50,39,79,65,64,57,48,95};
  //   std::cout << s.largestNumber(costs, 743);
  // }
  {
    Solution4_t s;
    vector<int> costs = {2,4,2,5,3,2,5,5,4};
    std::cout << s.largestNumber(costs, 739);
  }
}