/****************************************************
Date: April 3rd, 2022
Successful submissions : 2
Time expiration : 1
Memory exhausted : 0
Not Solved : 0
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/weekly-contest-287
****************************************************/

#include<bits/stdc++.h>
using namespace std;

/*
  Q: 2224. Minimum Number of Operations to Convert Time
*/
class Solution1_t
{
public:
  int convertTime(string current, string correct) 
  {
    int ans = 0;
    int deltaHours = ((correct[0]-'0') * 10 + (correct[1]-'0')) - ((current[0]-'0') * 10 + (current[1]-'0'));
    int deltaMins = ((correct[3]-'0') * 10 + (correct[4]-'0')) - ((current[3]-'0') * 10 + (current[4]-'0'));
    
    if(deltaMins < 0)
    {
      deltaHours--;
      deltaMins = 60 + deltaMins;
    }
    
    ans = deltaHours;
    //while(deltaMins > 0)
    {
      if(deltaMins >= 15)
      {
        ans += deltaMins / 15;
        deltaMins %= 15;
      }
      
      if(deltaMins >= 5)
      {
        ans += deltaMins / 5;
        deltaMins %= 5;
      }
      
      ans += deltaMins;
    }
    
    return ans;
  }
};

/*
  Q: 2225. Find Players With Zero or One Losses
*/
class Solution2_t
{
public:
  vector<vector<int>> findWinners(vector<vector<int>>& matches) 
  {
    int winners[100001] = {0};
    int loosers[100001] = {0};
    
    for(vector<int>& m : matches)
    {
      winners[m[0]]++;
      loosers[m[1]]++;
    }
    
    vector<vector<int>> ans(2);
    for(int i = 1; i < 100001; ++i)
    {
      if((winners[i] > 0) && (loosers[i] == 0))
      {
        ans[0].push_back(i);
      }
      
      if(loosers[i] == 1)
      {
        ans[1].push_back(i);
      }
    }
    
    return ans;
  }
};
/*
  Q: 2226. Maximum Candies Allocated to K Children - wrong ans
*/
class Solution3_t
{
public:
  int maximumCandies(vector<int>& candies, long long k) 
  {
    int mini = INT_MAX;
    long long sum = 0; 
    for(int& c : candies)
    {
      sum += c;
      mini = min(mini, c);
    }
    
    long long low = sum / k;
    if(low == 0)
    {
      return 0;
    }
    
    return (low < mini) ? low : mini;
  }
};

/*
  Q: 2227. Encrypt and Decrypt Strings - TLE
*/
class Encrypter 
{
  //TODO: instead of keeping the value_keys and dict,
  // for each entry in dictionary, encrypt and keep the count of encrypted value!!
private:
  unordered_map<char, string> key_values;
  unordered_map< string, vector<string> > values_key;
  unordered_set<string> dict;
  
  vector<string> getAllPossibleStrs(vector<string>& appendWith, vector<string>& ans)
  {
    if(ans.empty())
    {
      return appendWith;
    }
    
    vector<string> retVal;
    for(string& a : ans)
    {
      for(string& aw : appendWith)
      {
        string s = "" + a + aw;
        retVal.push_back(s);
      }
    }
    
    return retVal;
  }
public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) 
    {
      int l = keys.size();
      for(int i = 0; i < l; ++i)
      {
        key_values[keys[i]] = values[i];
        values_key[values[i]].push_back(std::string(1, keys[i]));
      }
      
      for(string& d : dictionary)
      {
        dict.insert(d);
      }
    }
    
    string encrypt(string word1) 
    {
      string ans = "";
      for(char ch : word1)
      {
        ans += key_values[ch];
      }
      
      return ans;
    }
    
    int decrypt(string word2) 
    {
      vector<string> possibleAns;
      int l = word2.size()/2;
      for(int i = 0; i < l; ++i)
      {
        string str = word2.substr(i*2, 2);
        vector<string> matchingKeys = values_key[str];
        
        possibleAns = getAllPossibleStrs(matchingKeys, possibleAns);
        if(possibleAns.empty())
        {
          break;
        }
      }
            
      vector<string> ans;
      for(string& pa : possibleAns)
      {
        if(dict.find(pa) != dict.end())
        {
          ans.push_back(pa);
        }
      }
      
      return ans.size();
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */