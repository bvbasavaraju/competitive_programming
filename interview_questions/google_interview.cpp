/*
A[],    {2, 1, 0,0,0,0,0,0, 7, 1}  K

l - k till 0 + k => Max Sum 
10, k = 3
7 to 3
size => k * 2
copying => entries from the ends of the given array
calculate MaxSubArraySum of window size k
*/

#include <iostream>
#include <vector>
#include <stdint.h>

using namespace std;
class Solution_t
{
    int MaxSubArraySum(vector<int> a, int k)
    {
        int al = a.size();

        //Construct the SubArray => O(2*k)
        vector<int> subArray;
        for (int i = al - k; i < al; i++)
        {
            subArray.push_back(a[i]);
        }
        for (int i = 0; i < k; i++)
        {
            subArray.push_back(a[i]);
        }

        //Calculate the MaxSum of SubArray of windows size k => O(k * k + 2k)
        int retVal = INT32_MIN; // minimum int
        int cl = k * 2;
        //SubArray => {0, 7, 1, 2, 1, 0}
        for (int i = 0; i < (cl - (k - 1)); i++)
        {
            int windowSum = 0; //ws
            for (int j = i; j < (i + k); j++)
            {
                windowSum += subArray[i + j];
            }

            retVal = max(windowSum, retVal);
            // it1 => ws = 8, retVal = 8
            // it2 => ws = 10, retVal = 10
            // it3 => ws = 4, retVal = 10
            // it4 => ws = 3, retVal = 10;
        }

        return retVal;
    }
};

/*
Face to Face interview question!
+ Design a system to to flash a driver update for software to specific driver.
    Ex: In a mobile, let say Snapdragon SOC is there, and there is another module from Broadcom.
          Broadcom released an update to its hardware. Now, how do you flash that update in mobile device

+ Applying filter to an image
    Lets say, you have image of 2D matrix, and you have an filter (again 2D matrix), apply this filter to matrix such that

    m[i][j] = (m[i][j] * f[0][0]) + (m[i][j+1] * f[0][1]) + (m[i][j+2] * f[0][2]) + ....... + (m[i+1][j] * f[1][0]) + m[i+1][j+1] * f[1][1] + .......... + (m[i+f_row][j+f_col] * f[f_row][f_col])

+ Given a linked list, and list of pointers. give a solution to check if the pointers are pointing to the nodes in the list.
    Pointers can be in any order.
    Note: My solution was in O(nlogn). but expected was O(n). I got to know after interview got over!! :(

+ Design a class to providing the User access to specific memroy location/buffer.
*/