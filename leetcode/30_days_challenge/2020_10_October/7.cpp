/****************************************************
Date: Oct 7th

link: https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/559/week-1-october-1st-october-7th/3481/
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

using namespace std;

/*
    Q: Rotate List

    Given a linked list, rotate the list to the right by k places, where k is non-negative.

    Example 1:
        Input: 1->2->3->4->5->NULL, k = 2
        Output: 4->5->1->2->3->NULL
        Explanation:
            rotate 1 steps to the right: 5->1->2->3->4->NULL
            rotate 2 steps to the right: 4->5->1->2->3->NULL

    Example 2:
        Input: 0->1->2->NULL, k = 4
        Output: 2->0->1->NULL
        Explanation:
            rotate 1 steps to the right: 2->0->1->NULL
            rotate 2 steps to the right: 1->2->0->NULL
            rotate 3 steps to the right: 0->1->2->NULL
            rotate 4 steps to the right: 2->0->1->NULL
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        vector<ListNode *> nodes;

        ListNode *node = head;
        while (node != NULL)
        {
            nodes.push_back(node);

            node = node->next;
        }

        ListNode *new_head = head;
        int l = nodes.size();
        if ((l > 1) && (k != l))
        {
            if (k > l)
            {
                k = k % l;
            }

            if (k > 0)
            {
                new_head = nodes[l - k];
                ListNode *new_tail = nodes[l - k - 1];
                new_tail->next = NULL;

                nodes[l - 1]->next = nodes[0];
            }
        }

        return new_head;
    }
};