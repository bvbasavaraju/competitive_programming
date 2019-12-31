/*
    Q: 21. Merge Two Sorted Lists
*/

#include <iostream>
#include <algorithm>
#include <stdint.h>
#include <math.h>
#include <string>
#include <map>
#include <vector>
#include <stack>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        vector<int> v;

        while (l1 != NULL)
        {
            v.push_back(l1->val);
            l1 = l1->next;
        }

        while (l2 != NULL)
        {
            v.push_back(l2->val);
            l2 = l2->next;
        }

        sort(v.begin(), v.end());

        int l = v.size();
        ListNode *retVal = NULL;
        ListNode *p = retVal;
        for (int i = 0; i < l; i++)
        {
            ListNode *n = new ListNode(v[i]);
            if (p == NULL)
            {
                p = n;
                retVal = p;
            }
            else
            {
                p->next = n;
                p = p->next;
            }
        }

        return retVal;
    }
};