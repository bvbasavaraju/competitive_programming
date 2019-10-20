/****************************************************
Date: September 15, 2019
Successful submissions : 2
Time expiration : 1
Not Solved : 1
****************************************************/

//1.Maximum Number of Balloons
//Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.
//You can use each character in text at most once.Return the maximum number of instances that can be formed.
//Ex: Input: text = "nlaebolko" Output : 1
//Input: text = "loonbalxballpoon" Output : 2

//Note:1 <= text.length <= 10^4
//          text consists of lower case English letters only.class Solution

#include <string>

using namespace std;
class Solution1
{
public:
    int maxNumberOfBalloons(string text)
    {
        const char *textInCStr = text.c_str();
        if ((text.length() <= 0) || (text.length() > 10000) || !textInCStr)
        {
            return 0;
        }

        int bCount = 0;
        int aCount = 0;
        int lCount = 0;
        int oCount = 0;
        int nCount = 0;

        for (int i = 0; i < text.length(); i++)
        {
            switch (textInCStr[i])
            {
            case 'b':
                bCount++;
                break;

            case 'a':
                aCount++;
                break;

            case 'l':
                lCount++;
                break;

            case 'o':
                oCount++;
                break;

            case 'n':
                nCount++;
                break;

            default:
                break;
            }
        }

        if ((bCount == 0) || (aCount == 0) || (lCount == 0) || (oCount == 0) || (nCount == 0))
        {
            return 0;
        }

        int minBetweenLandO = (lCount < oCount) ? lCount : oCount;
        if (minBetweenLandO < 2)
        {
            return 0;
        }

        int minBetweenBAandN = 0;
        if (bCount < aCount)
        {
            minBetweenBAandN = (bCount < nCount) ? bCount : nCount;
        }
        else
        {
            minBetweenBAandN = (aCount < nCount) ? aCount : nCount;
        }
        if (minBetweenBAandN < 1)
        {
            return 0;
        }

        int possibleWordFormCount = (minBetweenLandO / 2);
        return ((possibleWordFormCount < minBetweenBAandN) ? possibleWordFormCount : minBetweenBAandN);
    }
};

// int main()
// {
//   Solution s;
//   int numOfPossibleBalloons = s.maxNumberOfBalloons("nlaebolko");
// }

//2.Reverse Substrings Between Each Pair of Parentheses
//Given a string s that consists of lower case English letters and brackets.
//Reverse the strings in each pair of matching parentheses, starting from the innermost one.
//Your result should not contain any bracket.
//Ex: Input: s = "(abcd)" Output : "dcba"
//      Input: s = "(ed(et(oc))el)" Output : "leetcode"
//      Input: s = "a(bcdefghijkl(mno)p)q"Output : "apmnolkjihgfedcbq"
//Note: 0 <= s.length <= 2000,
//           s only contains lower case English characters and parentheses.
//           It's guaranteed that all parentheses are balanced.

class Solution2
{
private:
    void SwapString(string &str, int pos1, int pos2)
    {
        if ((str.length() < pos1) || (str.length() < pos2))
        {
            return;
        }

        char temp = str.at(pos1);
        str.at(pos1) = str.at(pos2);
        str.at(pos2) = temp;
    }

    int RemoveParenthesesAndReverse(string &s, bool &isSubString)
    {
        int positionOpen = s.find_last_of("(");
        int positionClose = s.find_first_of(")", positionOpen);

        if ((positionOpen < 0) && (positionClose < 0))
        {
            isSubString = false;
            return 0;
        }
        else if (positionOpen < 0)
        {
            if (positionClose > 0)
            {
                s = s.replace(positionClose, 1, "");
            }
            return 0;
        }
        else if (positionClose < 0)
        {
            if (positionOpen)
            {
                s = s.replace(positionOpen, 1, "");
            }
            return 0;
        }

        isSubString = (positionOpen == 0) ? false : true;

        int newStrLength = (positionClose - positionOpen - 1);
        int replaceLength = newStrLength + 2; //2 for each parenthesis;
        string reversedStr = s.substr((positionOpen + 1), newStrLength);
        if (reversedStr.length() < 0)
        {
            return -1;
        }

        if (reversedStr.length() > 0)
        {
            int loopCount = newStrLength / 2;
            int startPos = 0;
            int endPos = reversedStr.length() - 1;
            for (int i = 0; i < loopCount; i++)
            {
                SwapString(reversedStr, startPos++, endPos--);
            }

            //printf("\nResult: %s", reversedStr.c_str());
        }

        s.replace(positionOpen, replaceLength, reversedStr);
        //printf("\nResult: %s", s.c_str());

        return 0;
    }

public:
    string reverseParentheses(string s)
    {
        printf("\nGiven String: %s", s.c_str());
        bool isSubStr = true;
        do
        {
            if (RemoveParenthesesAndReverse(s, isSubStr) < 0)
            {
                break;
            }
        } while (isSubStr);

        printf("\nAfter Reversal: %s", s.c_str());
        return s;
    }
};

// int main()
// {
//   Solution2 s2;
//   string result = s2.reverseParentheses("(BasavarajuBV)");
//   result = s2.reverseParentheses("(abcd)");
//   result = s2.reverseParentheses("(ed(et(oc))el)");
//   result = s2.reverseParentheses("a(bcdefghijkl(mno)p)q");
//   result = s2.reverseParentheses("vdgzyj()");
//   result = s2.reverseParentheses("ta()usw((((a))))");
//   result = s2.reverseParentheses("f(ul)ao(t(y)qbn)()sj");
//   return 0;
// }

//3. K-Concatenation Maximum Sum
//Given an integer array arr and an integer k, modify the array by repeating it k times
//For example, if arr = [1, 2] and k = 3 then the modified array will be [1, 2, 1, 2, 1, 2].
//Return the maximum sub-array sum in the modified array. Note that the length of the sub-array can be 0 and its sum in that case is 0.
//As the answer can be very large, return the answer modulo 10^9 + 7.
//Ex: Input: arr = [1,2], k = 3 Output : 9
//      Input: arr = [1,-2,1], k = 5 Output : 2
//      Input: arr = [-1,-2], k = 7 Output : 0

//Note: 1 <= arr.length <= 10^5, 1 <= k <= 10 ^ 5, - 10 ^ 4 <= arr[i] <= 10 ^ 4
#include <vector>

class Solution3
{
private:
    int GetMaxOfArraySum(vector<int> &arr)
    {
        long long int retVal = 0;
        int loopCount = arr.size();
        if (!loopCount)
        {
            return 0;
        }

        retVal = (retVal > arr[0]) ? retVal : arr[0];
        for (int i = 1; i < loopCount; i++)
        {
            bool firstLoop = true;
            long long int sum = 0;
            for (int j = i; j >= 0; j--)
            {
                if (firstLoop)
                {
                    if ((retVal + arr[j]) < retVal)
                    {
                        break;
                    }
                    firstLoop = false;
                }
                sum += arr[j];
                retVal = (retVal > sum) ? retVal : sum;
            }
        }

        return retVal;
    }

public:
    int kConcatenationMaxSum(vector<int> &arr, int k)
    {
        const int TEN_POWER_5 = 100000;

        int givenLength = arr.size();
        if ((givenLength < 1) || (givenLength > TEN_POWER_5) || (k < 1) || (k > TEN_POWER_5))
        {
            return 0;
        }

        for (int i = 1; i < k; i++)
        {
            for (int j = 0; j < givenLength; j++)
            {
                arr.push_back(arr.at(j));
            }
        }

        const long int ONE_BILLION_PULS_SEVEN = 1000000007;
        int subArraySum = GetMaxOfArraySum(arr);
        int retVal = subArraySum % (1000000007);
        return retVal;
    }
};

int main()
{
    Solution3 s3;
    //vector<int> arr = {95, 20, 249, 94, 186, -174, -31, 24, -279, -97, 98, -263, -284, -257, -168, -240, -172, 80, -87, -169, -86, 206, 202, 67, -114, -48, -274, 11, 276, -191, -82, 285, -168, 124, 57, 73, 229, 213, 235, -95, 195, -30, 284, 282, -4, 208, -166, -57, -201, 93, -196, 64, 180, -261, 199, 2, -230, -292, -133, -150, -47, -15, -168, -65, -194, 229, -202, 40, -55, 84, 8, -185, -194, 115, 200, 229, -157, 116, 56, 136, -299, 237, 104, 155, 236, 130, 86, -131, -168, -164, 294, -253, -56, 152, -126, -273, -259, 218, 52, 261, -171, -159, 266, 36, -103, -33, 106, -246, -60, 215, -181, -4, 139, 3, 32, -296, -62, 180, -244, -290, 48, 119, -290, 34, -14, -144, 174, 64, 247, 276, -55, -271, -56, -19, 31, 9, 86, 73, 235, 268, 25, 72, 297, -39, 114, -107, 65, -182, 82, 204, 193, 246, 100, -170, 37, 100, -119, -17, -85, 80, 55, 230, -71, 270, -78, 258, -85, 213, 133, 279, -288, -144, -130, -260, -250, 119, -200, 232, 186, -63, -122, 78, -109, -272, -196, -268, -124, 169, -293, 180, -176, -111, 40, -83, -224, -71, -233, -143, 110, -175, -268, 25, 231, 40, -130, -296, -286, 175, -122, -61, -54, -275, -139, 199, -132, -129, -80, -291, 257, -283, -193, -206, -4, 89, 150, 171, 79, 190, -235, -64, 165, 29, 124, -69, -262, -72, -19, -184, 186, 121, -49, 218, -66, -206, -160, -252, -148, -212, -100, 49, -217, -149, -6, -158, 178, -209, -252, 263, -181, -187, -281, -138, 182, -1, -256, -163, -17, 72, 30, 145, -62, -189, -81, 40, -144, 21, 257, 275, -140, 164, 109, 215, -296, 13, 58, -37, -290, 194, 23, -72, -185, 173, -73, -292, 62, -51, -125, 39, -163, -273};
    //printf("\nResult: %d", s3.kConcatenationMaxSum(arr, 129));

    //vector<int> arr = {1, -2, 1 };
    //printf("\nResult: %d", s3.kConcatenationMaxSum(arr, 5));

    //vector<int> arr = {1, 2};
    //printf("\nResult: %d", s3.kConcatenationMaxSum(arr, 3));

    vector<int> arr = {-220, -304, 161, -154, -414, 180, -98, -245, 314, 452, 92, 175, -64, -442, 185, -429, 263, -178, -240, -48, 461, -389, -6, 394, 245, 85, -399, -358, 499, 434, -260, -414, -218, -115, -180, -149, -41, -135, -209, -326, 446, -325, 259, -265, -281, 369, -423, 404, 336, -190, 70, 102, -141, 149, -166, -407, 486, 284, -22, 217, -418, 450, 0, -9, 87, 276, 57, -22, 484, 326, -161, 16, 352, 391, 321, -85, 272, 231, -191, -53, 154, -87, -172, 87, 181, -316, -427, 345, 49, -114, 311, -483, 77, 30, 48, -381, 338, 24, 270, 476, -136, -220, -361, -466, 73, 55, 206, -232, -332, 431, 354, 259, -191, -244, -376, -52, -213, 225, 31, 351, -153, -281, -221, 232, -461, 323, 296, -182, -275, -489, -487, 429, 480, 336, 127, -8, -494, 256, -446, -300, 260, -312, -127, 3, -161, 322, 352, -14, -73, -262, -177, -457, 208, -80, 180, 381, 485, 362, 85, -285, -466, 153, -323, -22, -431, -461, 471, -178, 337, -331, -422, 499, -433, -215, -389, -108, -423, -448, 116, -386, -258, 67, -336, 142, -122, 265, -353, 110, -84, -145, 261, 145, 364, 105, -463, -341, -375, 172, -227, -238, 254, 429, -110, 239, -163, 265, 437, -170, 215, -47, 331, 461, -407, -252, -424, 382, 216, -15, 490, -127, -217, -370, 143, 266, -216, -323, 223, 341, -236, -111, 25, 359, 25, -145, 12, 105, -331, 450, -101, 144, 431, 398, -418, 493, 1, 247, -430, -195, 376, -463, -121, 454, -93, -156, 437, -236, 292, -11, 347, 368, -180, 500, 342, 437, 375, 218, 421, 101, 484, -267, 264, -423, 121, 63, 123, -309, -442, 177, -442, 236, 384, 30, 239, -202, 278, -225, 323, 394, -143, -129, 274, 443, -211, 324, 493, -167, -64, -14, -278, -496, -154, 72, -157, 281, -377, 472, -298, 116, 259, 296, -472, 322, 500, 195, -274, 114, 324, 75, -10, -180, 417, -95, -112, 88, 51, 11, -337, 467, 104, -145, -202, -269, -387, -179, -462, -361, -308, 77, -348, 113, 369, 430, -349, -382, -391, 128, 358, 141, -244, 297, 469, 334, 423, -157, -184, 123, -171, 341, -480, -143, 161, 258, 442, 267, 478, -373, 230, -280, 403, 180, 353, -398, -269, -127, 206, 127, -366, 311, 390, 252, 461, -415, -167, -255, -92, -105, 158, -118, -357, -321, -273, -92, -117, -433, 263, 377, -59, 276, 452, -204, 497, 100, -306, 343, 15, 474, 184, 28, 15, -95, -490, -191, 490, 137, -316, -480, 37, 424, 82, -415, 311, 214, 22, 437, -128, -142, 213, -244, -287, -499, -73, -234, 49, 461, -149, -38, -254, -111, -474, -8, -7, -434, 434, -364, -106, 344, -195, -329, -4, -324, -273, -317, -326, 50, 182, 47, 132, -267, 391, -130, 469, -371, -440, 399, 246, 234, -304, -489, 224, 459, 310, -47, -15, -480, -490, 114, 426, 292, -391, 291, 138, 130, 261, 411, -197, 217, 285, -498, -165, -436, 213, -155, -236, -190, 263, 489, -119, -24, 100, 10};
    printf("\nResult: %d", s3.kConcatenationMaxSum(arr, 223));

    return 0;
}

// 4: Critical Connections in a Network - Need to Complete!!
//There are n servers numbered from 0 to n-1 connected by undirected server-to-server connections forming a network where connections[i] = [a, b] represents a connection between servers a and b. Any server can reach any other server directly or indirectly through the network.
//A critical connection is a connection that, if removed, will make some server unable to reach some other server.
//Return all critical connections in the network in any order.
//Ex: Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]; Output : [[ 1, 3 ]]; Explanation : [[ 3, 1 ]] is also accepted.