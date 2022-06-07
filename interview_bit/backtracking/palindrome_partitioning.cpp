#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(const string& str)
{
    int l = 0;
    int r = str.size()-1;
    while(l < r)
    {
        if(str[l] != str[r])
        {
            return false;
        }
        l++;
        r--;
    }

    return true;
}
void getPalindromeSequence(const string& str, int start, int totalLength, vector<string>& subStrings, vector<vector<string>>& allSubStrings)
{
    if(start >= totalLength)
    {
        allSubStrings.push_back(subStrings);
        return;
    }

    for(int length = 1; length <= totalLength-start; ++length)
    {
        string subStr = str.substr(start, length);
        if(isPalindrome(subStr))
        {
            subStrings.push_back(subStr);
            getPalindromeSequence(str, start+length, totalLength, subStrings, allSubStrings);
            subStrings.pop_back();
        }
    }
}

vector<vector<string> > partition(string A) 
{
    vector<string> subStrings;
    vector<vector<string>> allSubStrings;

    getPalindromeSequence(A, 0, A.size(), subStrings, allSubStrings);

    return allSubStrings;
}