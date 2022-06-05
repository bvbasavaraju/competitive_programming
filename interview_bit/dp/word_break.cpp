#include<bits/stdc++.h>
using namespace std;

// struct Trie_t
// {
//     char ch;
//     int wordCount;
//     Trie_t* childs[26] = {nullptr};

//     Trie_t(char ch_) : ch(ch_), wordCount(0) {}
// };

// void addToTrie(const string& s, Trie_t*& root)
// {
//     int l = s.size();
//     Trie_t* t = root;
//     for(int i = 0; i < l; ++i)
//     {
//         int p = s[i]-'a';
//         if(t->childs[p] == nullptr)
//         {
//             t->childs[p] = new Trie_t(s[i]);
//         }
//         t = t->childs[p];
//     }

//     t->wordCount++;
// }

int Solution::wordBreak(string A, vector<string> &B) 
{
    unordered_set<string> words;
    for(string s : B)
    {
        words.insert(s);
    }

    int l = A.size();
    vector<bool> dp(l+1, false);
    dp[0] = true;   //empty string

    for(int i = 1; i <= l; ++i)
    {
        for(int j = i-1; j >= 0; --j)
        {
            string s = A.substr(j, i-j);
            if(words.find(s) != words.end() && dp[j] == true) // NOTE: This is Key!! it should be && operation!!
            {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[l] == true ? 1 : 0;

    //Bellow code gave partial result!!
    // Trie_t* root = new Trie_t(0);
    // for(string& s : B)
    // {
    //     addToTrie(s, root);
    // }

    // Trie_t* t = root;
    // int l = A.size();
    // int prevPos = 0;
    // int sizeCompleted = 0;
    // for(int i = 0; i < l; ++i)
    // {
    //     char ch = A[i];
    //     Trie_t* temp = t->childs[ch-'a'];
    //     if(temp == nullptr || temp->ch != ch)
    //     {
    //         temp = root->childs[ch-'a'];
    //         if(temp == nullptr || temp->ch != ch)
    //         {
    //             return 0;
    //         }
    //     }

    //     if(temp->wordCount > 0)
    //     {
    //         sizeCompleted += (i - prevPos) + 1;
    //         prevPos = i+1;
    //         //temp->wordCount--;
    //         t = root;
    //     }
    //     else
    //     {
    //         t = temp;
    //     }
    // }

    // return sizeCompleted == l ? 1 : 0;
}
