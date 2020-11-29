/****************************************************
Date: Nov 28th, 2020
Successful submissions : 2
Time expiration : 0
Not Solved : 2
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/biweekly-contest-40
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
#include <string_view>

using namespace std;

/*
    Q: 1668. Maximum Repeating Substring
*/
class Solution_1
{
public:
    int maxRepeating(string sequence, string word)
    {
        int sl = sequence.size();
        int wl = word.size();

        int ans = 0;

        for (int i = 0; i < sl; ++i)
        {
            int ib = i;
            int count = 0;
            for (int j = 0; j < wl;)
            {
                if (sequence[i] != word[j])
                {
                    break;
                }

                i++;
                j++;

                if (j == wl)
                {
                    count++;
                    j = 0;
                }
            }

            i = ib;
            ans = max(ans, count);
        }

        return ans;
    }
};

/*
    Q: 1669. Merge In Between Linked Lists
*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution2_t
{
private:
    ListNode *TraverseTill(ListNode *list, int val_, int get_previous)
    {
        ListNode *prev = NULL;
        while (list != NULL)
        {
            if (list->val == val_)
            {
                break;
            }

            prev = list;
            list = list->next;
        }

        if (get_previous)
        {
            return prev;
        }

        return list->next;
    }

public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *ans = list1;

        ListNode *a_prev = TraverseTill(list1, a, true);
        ListNode *b_next = TraverseTill(a_prev, b, false);

        ListNode *list2_start = list2;
        ListNode *list2_last_node;
        while (list2 != NULL)
        {
            list2_last_node = list2;
            list2 = list2->next;
        }
        list2_last_node->next = b_next;
        list2 = list2_start;

        if (a_prev == NULL)
        {
            ans = list2;
        }
        else
        {
            a_prev->next = list2;
        }

        return ans;
    }
};

/*
    Q: 1670. Design Front Middle Back Queue - wrong. to be solved
*/
class FrontMiddleBackQueue
{
private:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode *prev;
        ListNode() : val(0), next(nullptr), prev(nullptr) {}
        ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
    };

    ListNode *list;

    ListNode *front;
    ListNode *back;
    //ListNodeT* middle;
    //int mid_curr_pos = 0;
    int total_length;

public:
    FrontMiddleBackQueue()
        : list(NULL),
          front(NULL),
          back(NULL),
          total_length(0)
    {
    }

    void pushFront(int val)
    {
        if (total_length == 0)
        {
            front = new ListNode(val);
            back = front;
        }
        else
        {
            ListNode *node = new ListNode(val);
            node->next = front;
            front->prev = node;

            front = node;
        }

        total_length++;
    }

    void pushMiddle(int val)
    {
        if (total_length == 0)
        {
            pushFront(val);
            return;
        }

        ListNode *node = new ListNode(val);

        int nodes_to_skip = total_length / 2;

        ListNode *middle = front;
        int count = total_length % 2 == 0 ? 0 : 1;
        while (count < nodes_to_skip)
        {
            middle = middle->next;
            count++;
        }

        middle->next = node;
        node->prev = middle;

        middle = middle->next;
        node->next = middle;
        if (front == back)
        {
            back = middle;
        }
        total_length++;
    }

    void pushBack(int val)
    {
        if (total_length == 0)
        {
            pushFront(val);
            return;
        }

        ListNode *node = new ListNode(val);
        back->next = node;
        node->prev = back;

        back = node;
        total_length++;
    }

    int popFront()
    {
        if (total_length == 0)
        {
            return -1;
        }

        ListNode *temp = front;

        front = front->next;
        front->prev = NULL;
        temp->next = NULL;

        int ans = temp->val;
        total_length--;
        delete temp;

        return ans;
    }

    int popMiddle()
    {
        if (total_length == 0)
        {
            return -1;
        }

        int nodes_to_skip = total_length / 2;

        ListNode *middle = front;
        int count = total_length % 2 == 0 ? 0 : 1;

        while (count < nodes_to_skip)
        {
            middle = middle->next;
            count++;
        }

        if ((total_length % 2 != 0) && (middle->next != NULL))
        {
            middle = middle->next;
        }

        int ans = middle->val;
        ListNode *temp = middle->prev;
        if (temp != NULL)
        {
            temp->next = middle->next;
        }

        middle->prev = middle->next = NULL;
        delete middle;

        total_length--;
        if (total_length == 0)
        {
            front = back = NULL;
        }
        return ans;
    }

    int popBack()
    {
        if (total_length == 0)
        {
            return -1;
        }

        ListNode *temp = back;
        back = back->prev;
        back->next = NULL;
        temp->prev = NULL;

        int ans = temp->val;
        total_length--;
        delete temp;

        if (total_length == 0)
        {
            front = back = NULL;
        }
        return ans;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */

/*
    Q: 1671. Minimum Number of Removals to Make Mountain Array
*/
class Solution4_t
{
public:
    int minimumMountainRemovals(vector<int> &nums)
    {
    }
};