/****************************************************
Date: July 2nd

link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3409/
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
    Q: Design HashSet

    Design a HashSet without using any built-in hash table libraries.
    
    To be specific, your design should include these functions:
        add(value): Insert a value into the HashSet. 
        contains(value) : Return whether the value exists in the HashSet or not.
        remove(value): Remove a value in the HashSet. If the value does not exist in the HashSet, do nothing.

    Example:
        MyHashSet hashSet = new MyHashSet();
        hashSet.add(1);         
        hashSet.add(2);         
        hashSet.contains(1);    // returns true
        hashSet.contains(3);    // returns false (not found)
        hashSet.add(2);          
        hashSet.contains(2);    // returns true
        hashSet.remove(2);          
        hashSet.contains(2);    // returns false (already removed)

    Note:
        All values will be in the range of [0, 1000000].
        The number of operations will be in the range of [1, 10000].
        Please do not use the built-in HashSet library.
*/

class MyHashSet
{
private:
    vector<int> set;
    int getPos(int key)
    {
        int lo = 0;
        int hi = set.size() - 1;

        int ans = -1;
        while (lo <= hi)
        {
            int m = lo + (hi - lo) / 2;
            if (set[m] == key)
            {
                ans = m;
                break;
            }

            if (set[m] > key)
            {
                ans = m;
                hi = m - 1;
            }
            else
            {
                lo = m + 1;
            }
        }

        return ans;
    }

public:
    /** Initialize your data structure here. */
    MyHashSet()
    {
    }

    void add(int key)
    {
        int p = getPos(key);
        if (p == -1)
        {
            set.push_back(key);
        }
        else if (set[p] != key)
        {
            set.insert(set.begin() + p, key);
        }
    }

    void remove(int key)
    {
        int p = getPos(key);
        if ((p >= 0) && (set[p] == key))
        {
            set.erase(set.begin() + p);
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        int p = getPos(key);
        return ((p >= 0) && (set[p] == key)) ? true : false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */