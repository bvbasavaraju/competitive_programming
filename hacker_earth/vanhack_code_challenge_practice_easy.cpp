#include <iostream>
#include <vector>
#include <string>

using namespace std;

string decodeString(int numberOfRows, string encodedString)
{
    vector<string> subStrings;
    int lengthOfEachSubStr = encodedString.size() / numberOfRows;

    const char *encodedStringInCStr = encodedString.c_str();
    for (int i = 0; i < numberOfRows; i++)
    {
        string subStr = "";
        subStr.append(encodedStringInCStr, lengthOfEachSubStr);
        subStrings.push_back(subStr);

        encodedStringInCStr += lengthOfEachSubStr;
    }

    int numOfSubStrs = subStrings.size();
    int subStrSizeMin = (subStrings[numOfSubStrs - 1].size() - (numOfSubStrs - 1)); // last substring - initial spaces appended at the beginning of that lst sub string
    string retVal = "";
    for (int i = 0; i < subStrSizeMin; i++)
    {
        for (int j = 0; j < numOfSubStrs; j++)
        {
            string subStr = subStrings[j];

            const char *subStrInCStr = subStr.c_str();
            subStrInCStr += j;

            if (subStrInCStr[i] != '_')
            {
                retVal.append(&subStrInCStr[i], 1);
            }
            else
            {
                retVal.append(" ", 1);
            }
        }
    }

    //Now add the remaining characters from the remaining sub strings
    for (int i = 0; i < (numberOfRows - 1); i++)
    {
        string subStr = subStrings[i];
        if (subStr.size() > subStrSizeMin)
        {
            const char *subStrInCStr = subStr.c_str();
            subStrInCStr += i;

            if (subStrInCStr[subStrSizeMin] != '_')
            {
                retVal.append(&subStrInCStr[subStrSizeMin], 1);
            }
        }
    }
    return retVal;
}

int main(void)
{
    string decodedStr0 = decodeString(3, "mnes__ya_____mi");                                                                                                                                                                                                     //TC0 -> my name is
    string decodedStr1 = decodeString(2, "hlowrd_el_ol");                                                                                                                                                                                                        //TC1 -> hello world
    string decodedStr2 = decodeString(10, "nchjbbxmpkbw________________________________ladodnkameqd__________rrdwbelpcwck__________bzqfecoqohlq__________bosrfdrfqsjt________________________________qkdsaglknmix__________bkxjrglhwgvi__________hyrycxnonbsx"); //TC2 -> n lrbb qbhc arzo kkyh ddqs dxrj owfr sjyb dbef arcb necd ggxx klor llnm apqf khop mcoq nwnk ewhs mgbqwofgr
    string decodedStr3 = decodeString(1, "_");                                                                                                                                                                                                                   //TC3 ->
    return 0;
}