/****************************************************
Date: Oct 3rd, 2020
Successful submissions : 1
Time expiration : 0
Not Solved : 2
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/biweekly-contest-36
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
#include <string_view>

using namespace std;

/*
    Q: 1603. Design Parking System
*/
class ParkingSystem
{
private:
    int b;
    int m;
    int s;

public:
    ParkingSystem(int big, int medium, int small)
        : b(big), m(medium), s(small)
    {
    }

    bool addCar(int carType)
    {
        bool ans = false;
        switch (carType)
        {
        case 1:
            if (b > 0)
            {
                b--;
                ans = true;
            }
            break;

        case 2:
            if (m > 0)
            {
                m--;
                ans = true;
            }
            break;

        case 3:
            if (s > 0)
            {
                s--;
                ans = true;
            }
            break;
        }

        return ans;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */

/*
    Q: 1604. Alert Using Same Key-Card Three or More Times in a One Hour Period 
    - simply complicated. It could have been solved with simple hashing approach!!
*/
class Solution2_t
{
private:
    class MyComporator_t
    {
    public:
        bool operator()(const string &s1, const string &s2)
        {
            return s1 > s2;
        }
    };

    priority_queue<string, vector<string>, MyComporator_t> names;

    unordered_set<string> names_;

    void convertTimeToPair(const string &time_s, pair<int, int> &time)
    {
        int h = stoi(time_s.substr(0, 2));
        int m = stoi(time_s.substr(3, 2));
        time.first = h;
        time.second = m;
    }

    bool usedWithinHour(const pair<int, int> &new_time, const pair<int, int> &old_time)
    {
        int diff = new_time.first - old_time.first;
        if ((diff < 0) || (diff > 1))
        {
            return false;
        }

        int m_diff = new_time.second - old_time.second;
        if ((diff == 1) && (m_diff > 0))
        {
            return false;
        }

        return true;
    }

public:
    vector<string> alertNames(vector<string> &keyName, vector<string> &keyTime)
    {
        int l = keyName.size();

        unordered_map<string, vector<vector<pair<int, int>>>> stats;
        for (int i = 0; i < l; ++i)
        {
            pair<int, int> t;
            convertTimeToPair(keyTime[i], t);

            string &name = keyName[i];
            if (names_.find(name) != names_.end())
            {
                continue;
            }

            if (stats.count(name) > 0)
            {
                vector<vector<pair<int, int>>> &data = stats[name];

                data[t.first].push_back(t);
                if (data[t.first].size() >= 3)
                {
                    names.push(name);
                    names_.insert(name);
                }

                if (t.second == 0)
                {
                    if (data[t.first - 1].size() >= 2)
                    {
                        names.push(name);
                        names_.insert(name);
                    }
                }
            }
            else
            {
                vector<vector<pair<int, int>>> data(24);
                data[t.first].push_back(t);

                stats[name] = data;
            }
        }

        vector<string> ans;
        while (names.size() > 0)
        {
            ans.push_back(names.top());
            names.pop();
        }

        return ans;

        /*int l = keyName.size();
    
    unordered_map<string, vector<pair<int, int>> > stats;
    for(int i = 0; i < l; ++i)
    {
      pair<int, int> t;
      convertTimeToPair(keyTime[i], t);
      
      string& name = keyName[i];
      if(names_.find(name) != names_.end())
      {
        continue;
      }
      
      if(stats.count(name) > 0)
      {
        vector<pair<int, int>>& time = stats[name];
        
        pair<int, int> old_time = time.back();
        while(!usedWithinHour(t, old_time))
        {
          time.pop_back();
          if(time.size() == 0)
          {
            break;
          }
          
          old_time = time.back();
        }
        
        stats[name].insert(time.begin(), t);
        if(time.size() >= 3)
        {
          names.push(name);
          names_.insert(name);
        }
      }
      else
      {
        stats[name].push_back(t);
      }
    }
    
    vector<string> ans;
    while(names.size() > 0)
    {
      ans.push_back(names.top());
      names.pop();
    }
    
    return ans;*/
    }
};

/*
    Q: 1605. Find Valid Matrix Given Row and Column Sums
*/
class Solution3_t
{
public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum)
    {
    }
};

/*
    Q: 1606. Find Servers That Handled Most Number of Requests
*/
class Solution4_t
{
public:
    vector<int> busiestServers(int k, vector<int> &arrival, vector<int> &load)
    {
    }
};