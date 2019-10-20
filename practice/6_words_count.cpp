#include <iostream>
#include <string>
#include <map>
#include <memory>

using namespace std;
class Solution_t
{
private:
    struct LetterCount_t
    {
        char givenLetter;
        int minRequiredToFormWord;
        int countInGivenString;
    };

    int ConstructLetterCountMap(string word, map<char, shared_ptr<LetterCount_t>> &letterCountMap)
    {
        const char *wordInCStr = word.c_str();
        if ((word.size() <= 0) || !wordInCStr)
        {
            return -1;
        }

        map<char, shared_ptr<LetterCount_t>>::iterator it;
        for (int i = 0; i < word.length(); i++)
        {
            char letter = wordInCStr[i];
            it = letterCountMap.find(letter);
            if (it != letterCountMap.end() && (it->second != nullptr))
            {
                it->second->minRequiredToFormWord++;
            }
            else
            {
                shared_ptr<LetterCount_t> letterCount = std::make_shared<LetterCount_t>();
                if (letterCount == nullptr)
                {
                    return -1;
                }
                letterCount->givenLetter = letter;
                letterCount->minRequiredToFormWord++;
                letterCountMap.insert(std::pair<char, shared_ptr<LetterCount_t>>(letter, letterCount));
            }
        }

        return 0;
    }

    int CalculateTotalWordsFormationCount(map<char, shared_ptr<LetterCount_t>> &letterCountMap, int &result)
    {
        result = 0;
        map<char, shared_ptr<LetterCount_t>>::iterator it;
        for (it = letterCountMap.begin(); it != letterCountMap.end(); it++)
        {
            if (it->second == nullptr)
            {
                return -1;
            }

            if (it->second->minRequiredToFormWord <= 0)
            {
                return -1;
            }

            if (it->second->countInGivenString <= 0)
            {
                result = 0;
                break;
            }

            int wordsCount = it->second->countInGivenString / it->second->minRequiredToFormWord;
            if (result == 0)
            {
                result = wordsCount;
            }
            else
            {
                result = (result < wordsCount) ? result : wordsCount;
            }
        }

        return 0;
    }

public:
    int WordCount(string &word, string &inputStr, int &result)
    {
        result = 0;
        const char *inputInCStr = inputStr.c_str();
        int length = inputStr.length();
        if (!inputInCStr || (length <= 0) || (word.length() <= 0))
        {
            return -1;
        }

        map<char, shared_ptr<LetterCount_t>> letterCountMap;
        if (ConstructLetterCountMap(word, letterCountMap) < 0)
        {
            return -1;
        }

        map<char, shared_ptr<LetterCount_t>>::iterator it;
        for (int i = 0; i < length; i++)
        {
            char letter = inputInCStr[i];
            it = letterCountMap.find(letter);
            if (it != letterCountMap.end())
            {
                if (it->second == nullptr)
                {
                    return -1;
                }
                it->second->countInGivenString++;
            }
        }

        return CalculateTotalWordsFormationCount(letterCountMap, result);
    }
};

int main()
{
    string word = "balloon";
    //string input = "balloonballoonballoonballoon";
    string input = "asdfbasdfalsdfasdfosdfasfdosadfasdnl";

    Solution_t solution;
    int totalNumWordsCanBeFormed = 0;
    solution.WordCount(word, input, totalNumWordsCanBeFormed);

    printf("Total words that can be formed is: %d", totalNumWordsCanBeFormed);

    return 0;
}