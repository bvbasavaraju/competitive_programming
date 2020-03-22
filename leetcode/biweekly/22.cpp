/****************************************************
Date: March 21, 2020
Successful submissions : 2
Time expiration : 
Not Solved : 1
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/biweekly-contest-22
****************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;

/*
  Q: 1385. Find the Distance Value Between Two Arrays - Solved
*/
class Solution1_t
{
public:
  int findTheDistanceValue(vector<int>& a1, vector<int>& a2, int d) 
  {
    int result = 0;
    int la1 = a1.size();
    int la2 = a2.size();
    
    for(int i = 0; i < la1; ++i)
    {
      bool flag = true;
      for(int j = 0; j < la2; ++j)
      {
        if(abs(a1[i] - a2[j]) <= d)
        {
          flag = false;
          break;
        }
      }
      
      if(flag)
      {
        result++;
      }
    }
    
    return result;
  }
};

/*
  Q: 1386. Cinema Seat Allocation - Wrong answer!
*/
class Solution2_t
{  
public:
  int maxNumberOfFamilies(int n, vector<vector<int>>& rs) 
  {
    sort(rs.begin(), rs.end(), [](const vector<int>& r1, const vector<int>& r2) -> bool { return (r1[0] < r2[0]); } );
    
    int result = 0;
    int l = rs.size();
    int r_row = 1;
    int p_r_row = r_row;
    for(int i = 0; i < l; ++i)
    {
      r_row = rs[i][0];
      if(r_row != p_r_row)
      {
        result += 2 * (r_row - r_row);
      }
      
      //Current row num
      vector<int> r_col(10, 0);
      while(r_row == rs[i][0])
      {
        r_col[rs[i][1]] = 1;        
        i++;
      }
      
      int max_pos_count = 0;
      
      if((r_col[5] == 0 && r_col[6] == 0 && r_col[7] == 0 && r_col[8] == 0) && (r_col[1] == 0 && r_col[2] == 0 && r_col[3] == 0 && r_col[4] == 0))
      {
        max_pos_count = 2;
      }
      else if(r_col[5] == 0 && r_col[6] == 0 && r_col[7] == 0 && r_col[8] == 0)
      {
        max_pos_count = 1;
      }
      else if(r_col[1] == 0 && r_col[2] == 0 && r_col[3] == 0 && r_col[4] == 0)
      {
        max_pos_count = 1;
      }
      else if(r_col[3] == 0 && r_col[4] == 0 && r_col[5] == 0 && r_col[6] == 0)
      {
        max_pos_count = 1;
      }
      
      result += max_pos_count;
      
      p_r_row = r_row;
    }
    
    return result;
  }
};

/*
  Q: 1387. Sort Integers by The Power Value - solved
*/
class Solution3_t
{
private:
  vector<int> steps;
  vector< vector<int> > p_map;
  
  void findPowerAndAddToMap(int n)
  {
    int step_count = 0;
    int num = n;
    while(n > 1)
    {
      if(n % 2 == 0)
      {
        n /= 2;
      }
      else
      {
        n = 3*n + 1;
      }
      step_count++;
    }
    
    steps.push_back(step_count);
    p_map.push_back({num, step_count});
  }
  
public:
  int getKth(int lo, int hi, int k) 
  {
    for(int i = lo; i <= hi; ++i)
    {
      findPowerAndAddToMap(i);
    }
    
    sort(p_map.begin(), p_map.end(), [](const vector<int>& s1, const vector<int>& s2) -> bool
                                      {
                                        if(s1[1] == s2[1]) 
                                        {
                                          return (s1[0] < s2[0]);
                                        }

                                        return (s1[1] < s2[1]); 
                                      }
        );
    return p_map[k-1][0];
  }
};

/*
  Q: 1388. Pizza With 3n Slices - Wrong answer
*/
class Solution4_t
{
public:
  int maxSizeSlices(vector<int>& s) 
  {
    const int HEAD_COUNT = 3;
    
    int result = 0;
    for(int j = 0; j < HEAD_COUNT; ++j)
    {
      vector<int> temp = s;
      
      int l = s.size();
      int my_slice_size = 0;
      for(int i = 1; i < l; i = i+HEAD_COUNT)
      {
        int p0 = (i + j) % l;
        int p1 = (p0 + 1) % l;
        int p2 = (p1 + 1) % l;
        
        int p_max = s[p0] > s[p1] ? ((s[p0] > s[p2]) ? p0 : p2) : (s[p1] > s[p2] ? p1 : p2);
        
        int m = p_max;
        int a = (l + (m - 1)) % l;
        int b = (m + 1) % l;
        
        vector<int> s_of_3 = {s[a], s[m], s[b]};
        
        //printf("a = %d, m = %d, b = %d\n", s_of_3[0], s_of_3[1], s_of_3[2]);
        
        my_slice_size += *max_element(s_of_3.begin(), s_of_3.end());
      }
      
      //printf("----------------------------------------\n");
      result = max(result, my_slice_size);
      
      s = temp;
    }
    
    return result;
  }
};

int main()
{
  Solution3_t s3;

  cout << s3.getKth(1, 1000, 777);

  return 0;
}