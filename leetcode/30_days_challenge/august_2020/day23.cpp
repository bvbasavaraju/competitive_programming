/****************************************************
Date: July 23rd

link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/552/week-4-august-22nd-august-28th/3434/
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
#include <set>

using namespace std;

class StreamChecker
{
private:
    unordered_set<string> words;
    unordered_set<int> letters;

    string word;

public:
    StreamChecker()
    {
        word = "";
    }

    StreamChecker(vector<string> &ws)
    {
        for (string &w : ws)
        {
            words.insert(w);

            for (char ch : w)
            {
                letters.insert(ch);
            }
        }
    }

    bool query(char l)
    {
        bool letter_found = false;
        if (letters.find(l) != letters.end())
        {
            letter_found = true;
            word += l;
        }
        else
        {
            word = "";
            word += l;
        }

        if (words.find(word) != words.end())
        {
            return true;
        }

        if (!letter_found)
        {
            word = "";
        }

        return false;
    }
};

int main()
{
    {
        vector<string> w = {"ab", "ba", "aaab", "abab", "baa"};
        StreamChecker sc = w;

        sc.query('a');
        sc.query('a');
        sc.query('a');
        sc.query('a');
        sc.query('a');
        sc.query('b');
        sc.query('a');
        sc.query('b');
        sc.query('a');
        sc.query('b');
        sc.query('b');
        sc.query('b');
    }
}