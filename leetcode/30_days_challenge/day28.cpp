/****************************************************
Date: April 28th

link: https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/531/week-4/3313/
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

using namespace std;

/*
  Q: First Unique Number

  You have a queue of integers, you need to retrieve the first unique integer in the queue.
  
  Implement the FirstUnique class:
    FirstUnique(int[] nums) Initializes the object with the numbers in the queue.
    int showFirstUnique() returns the value of the first unique integer of the queue, 
                          and returns -1 if there is no such integer.
    void add(int value) insert value to the queue.

  Example 1:
  Input: 
    ["FirstUnique","showFirstUnique","add","showFirstUnique","add","showFirstUnique","add","showFirstUnique"]
    [[[2,3,5]],[],[5],[],[2],[],[3],[]]
  Output: 
    [null,2,null,2,null,3,null,-1]
  Explanation: 
    FirstUnique firstUnique = new FirstUnique([2,3,5]);
    firstUnique.showFirstUnique(); // return 2
    firstUnique.add(5);            // the queue is now [2,3,5,5]
    firstUnique.showFirstUnique(); // return 2
    firstUnique.add(2);            // the queue is now [2,3,5,5,2]
    firstUnique.showFirstUnique(); // return 3
    firstUnique.add(3);            // the queue is now [2,3,5,5,2,3]
    firstUnique.showFirstUnique(); // return -1

  Example 2:
  Input: 
    ["FirstUnique","showFirstUnique","add","add","add","add","add","showFirstUnique"]
    [[[7,7,7,7,7,7]],[],[7],[3],[3],[7],[17],[]]
  Output: 
    [null,-1,null,null,null,null,null,17]
  Explanation: 
    FirstUnique firstUnique = new FirstUnique([7,7,7,7,7,7]);
    firstUnique.showFirstUnique(); // return -1
    firstUnique.add(7);            // the queue is now [7,7,7,7,7,7,7]
    firstUnique.add(3);            // the queue is now [7,7,7,7,7,7,7,3]
    firstUnique.add(3);            // the queue is now [7,7,7,7,7,7,7,3,3]
    firstUnique.add(7);            // the queue is now [7,7,7,7,7,7,7,3,3,7]
    firstUnique.add(17);           // the queue is now [7,7,7,7,7,7,7,3,3,7,17]
    firstUnique.showFirstUnique(); // return 17

  Example 3:
  Input: 
    ["FirstUnique","showFirstUnique","add","showFirstUnique"]
    [[[809]],[],[809],[]]
  Output: 
    [null,809,null,-1]
  Explanation: 
    FirstUnique firstUnique = new FirstUnique([809]);
    firstUnique.showFirstUnique(); // return 809
    firstUnique.add(809);          // the queue is now [809,809]
    firstUnique.showFirstUnique(); // return -1

  Constraints:
  1 <= nums.length <= 10^5
  1 <= nums[i] <= 10^8
  1 <= value <= 10^8
  At most 50000 calls will be made to showFirstUnique and add.
  
  Hide Hint #1  
    Use doubly Linked list with hashmap of pointers to linked list nodes. add unique number to the linked list. 
    When add is called check if the added number is unique then it have to be added to the linked list
    and if it is repeated remove it from the linked list if exists. 
    When showFirstUnique is called retrieve the head of the linked list.
  
  Hide Hint #2  
    Use queue and check that first element of the queue is always unique.
  
  Hide Hint #3  
    Use set or heap to make running time of each function O(logn).
*/

class FirstUnique 
{
private:
  list<int> unique_nums;
  unordered_map<int, pair<int, std::list<int>::iterator>> nums_freq_pos;
  
  void checkAndAddNum(int n)
  {
    if(nums_freq_pos.count(n) == 0)
    {
      unique_nums.push_back(n);
      std::list<int>::iterator it = unique_nums.end();
      --it;
      nums_freq_pos[n] = std::make_pair(1, it);
    }
    else
    {
      nums_freq_pos[n].first++;
      if(nums_freq_pos[n].second != unique_nums.end())
      {
        unique_nums.erase(nums_freq_pos[n].second);
      }
      nums_freq_pos[n].second = unique_nums.end();
    }
  }
  
public:
  FirstUnique(vector<int>& nums) 
  {
    unique_nums.clear();
    nums_freq_pos.clear();
    for(int n : nums)
    {
      checkAndAddNum(n);
    }
  }

  int showFirstUnique() 
  {
    if(unique_nums.empty())
    {
      return -1;
    }
    
    return unique_nums.front();
  }

  void add(int value) 
  {
    checkAndAddNum(value);
  }
};