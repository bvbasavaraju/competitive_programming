/*
    Given an encoded string, return its decoded string.The encoding rule is : k[encoded_string], 
    where the encoded_string inside the square brackets is being repeated exactly k times.
    Note that k is guaranteed to be a positive integer.You may assume that the input string is always valid; 
    No extra white spaces, square brackets are well-formed, etc.

    Furthermore, you may assume that the original data does not contain any digits and,
    that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

    Ex:
    s = "3[a]2[bc]", return "aaabcbc".
    s = "3[a2[c]]", return "accaccacc".
    s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

    Approach:
    Use 2 stacks. RepeatCountStack, and SubStringToRepeat
    In the ex: “2[abc]3[cd]ef”, 2 will be moved to RepeatCountStack, 
    as bracket opens, a, b and added to the SubStringToRepeat as a subSting, meaning “abc”. 
    As closing bracket is found repeat subString 2 times in final result. do this till it completes.

    EdgeConditions : 
    + What if number is more than 10
    + what if there are only closing or opening brackets
    + What if repeat count == 0
*/

#include <iostream>
#include <string>
#include <list>
#include <stack>
#include <memory>

using namespace std;
class Solution_t
{
private:
    stack<int> repeatCountList;
    list<shared_ptr<string>> subStringToRepeatList;

    int RepeatString(void)
    {
        if (repeatCountList.empty() || subStringToRepeatList.empty())
        {
            return 0;
        }

        int repeatCount = repeatCountList.top();
        repeatCountList.pop();

        if (repeatCount < 0)
        {
            return -1;
        }

        // if (repeatCount == 0)
        // {
        //     return 0;
        // }

        shared_ptr<string> subString = subStringToRepeatList.back();
        if (subString == nullptr)
        {
            return -1;
        }
        subStringToRepeatList.pop_back();

        shared_ptr<string> s = make_shared<string>("");
        if (s == nullptr)
        {
            return -1;
        }
        for (int i = 0; i < repeatCount; i++)
        {
            s->append(*subString);
        }

        if (subStringToRepeatList.empty())
        {
            subStringToRepeatList.push_back(s);
        }
        else
        {
            shared_ptr<string> subString_ = subStringToRepeatList.back();
            if (subString_ == nullptr)
            {
                return -1;
            }
            subStringToRepeatList.pop_back();

            subString_->append(*s);
            subStringToRepeatList.push_back(subString_);
        }

        return 0;
    }

    void AddLetter(char *letter, bool newEntry)
    {
        shared_ptr<string> letterToAppend = make_shared<string>();
        if (letterToAppend == nullptr)
        {
            return;
        }
        letterToAppend->append(letter, 1);

        if (subStringToRepeatList.empty() || newEntry)
        {
            subStringToRepeatList.push_back(letterToAppend);
            if (repeatCountList.size() != subStringToRepeatList.size())
            {
                repeatCountList.push(0);
            }
        }
        else
        {
            shared_ptr<string> existingStr = subStringToRepeatList.back();
            subStringToRepeatList.pop_back();
            if (existingStr != nullptr)
            {
                existingStr->append(*letterToAppend);
                subStringToRepeatList.push_back(existingStr);
            }
        }
    }

    void OperateOnLetter(char *letter, bool newEntry, bool &previousWasNumber)
    {
        if (!letter)
        {
            return;
        }

        if (*letter >= '0' && *letter <= '9')
        {
            int repeatCount = *letter - '0';
            if (repeatCountList.empty() || newEntry || !previousWasNumber)
            {
                repeatCountList.push(repeatCount);
                // if (repeatCountList.size() != )
            }
            else
            {
                repeatCount += repeatCountList.top();
                repeatCountList.pop();
                repeatCountList.push(repeatCount);
            }

            previousWasNumber = true;
        }
        else
        {
            previousWasNumber = false;
            AddLetter(letter, newEntry);
        }
    }

    int ConstructResultIfRequired(string &result)
    {
        while (!subStringToRepeatList.empty())
        {
            shared_ptr<string> subString = subStringToRepeatList.front();
            subStringToRepeatList.pop_front();

            if ((subString == nullptr) || (subString->empty()))
            {
                return -1;
            }

            result.append(*subString);
        }

        return 0;
    }

public:
    int Encode(const string &input, string &result)
    {
        int inputLength = input.length();
        const char *inputInCStr = input.c_str();
        if ((inputLength <= 0) || !inputInCStr)
        {
            return -1;
        }

        bool newEntry = true;
        bool previousWasNumber = false;
        for (int i = 0; i < inputLength; i++)
        {
            char letter = inputInCStr[i];
            switch (letter)
            {
            case '[':
            {
                shared_ptr<string> subString = make_shared<string>("");
                subStringToRepeatList.push_back(subString);
                newEntry = false;
            }
            break;

            case ']':
                if (RepeatString() < 0)
                {
                    return -1;
                }
                newEntry = true;
                break;

            default:
                OperateOnLetter(&letter, newEntry, previousWasNumber);
                break;
            }
        }

        return ConstructResultIfRequired(result);
    }
};

int main()
{
    Solution_t s;
    {
        string str = "3[a]2[bc]";
        string encodedStr = "";
        s.Encode(str, encodedStr);
        printf("\nGiven String is %s, Encoded string is: %s", str.c_str(), encodedStr.c_str());
    }
    {
        string str = "3[a2[c]]";
        string encodedStr = "";
        s.Encode(str, encodedStr);
        printf("\nGiven String is %s, Encoded string is: %s", str.c_str(), encodedStr.c_str());
    }
    {
        string str = "2[abc]3[cd]ef";
        string encodedStr = "";
        s.Encode(str, encodedStr);
        printf("\nGiven String is %s, Encoded string is: %s", str.c_str(), encodedStr.c_str());
    }

    return 0;
}
