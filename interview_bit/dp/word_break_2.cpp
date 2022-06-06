#include<bits/stdc++.h>
using namespace std;

void getAllPossibleCombinations(const string& s, unordered_set<string>& words, int p, string sentence, vector<string>& ans)
{
    if(p == s.size())
    {
        sentence.pop_back();
        ans.push_back(sentence);
        return;
    }

    string word = "";
    for(int i = p; i < s.size(); ++i)
    {
        word += s[i];
        if(words.find(word) != words.end())
        {
            string backup = sentence;
            
            sentence += word + " ";
            getAllPossibleCombinations(s, words, i+1, sentence, ans);

            sentence = backup;
        }
    }
}

vector<string> Solution::wordBreak(string A, vector<string> &B) 
{
    unordered_set<string> words;
    for(string s : B)
    {
        words.insert(s);
    }

    string sentence;
    vector<string> ans;
    getAllPossibleCombinations(A, words, 0, sentence, ans);

    return ans;
}
