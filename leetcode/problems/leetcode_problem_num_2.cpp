/*
Add two numbers:

You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Ex:
    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 8
    Explanation: 342 + 465 = 807.
*/

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution_t
{
private:
    void AddDigits(int d1, int d2, int carryIn, int &carryOut, int &result)
    {
        int sum = d1 + d2 + carryIn;
        carryOut = sum / 10;
        result = sum % 10;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *front = NULL;
        ListNode *back = NULL;

        int carryCurrent = 0;
        do
        {
            int d1 = 0;
            if (l1 != NULL)
            {
                d1 = l1->val;
                l1 = l1->next;
            }

            int d2 = 0;
            if (l2 != NULL)
            {
                d2 = l2->val;
                l2 = l2->next;
            }

            int sum = 0;
            int carryNext = 0;
            AddDigits(d1, d2, carryCurrent, carryNext, sum);

            ListNode *node = new ListNode(sum);
            if (node == nullptr)
            {
                return NULL;
            }

            if (front == NULL)
            {
                front = node;
                back = front;
            }
            else
            {
                back->next = node;
                back = back->next;
            }

            carryCurrent = carryNext;
        } while ((l1 != NULL) || (l2 != NULL));

        if (carryCurrent > 0)
        {
            ListNode *node = new ListNode(carryCurrent);
            back->next = node;
        }

        return front;
    }
};

ListNode *CreateList(vector<int> &data)
{
    ListNode *front = nullptr;
    ListNode *back = nullptr;
    for (int digit : data)
    {
        if (front == nullptr)
        {
            front = new ListNode(digit);
            back = front;
        }
        else
        {
            ListNode *node = new ListNode(digit);
            back->next = node;
            back = back->next;
        }
    }

    return front;
}

int PrintListNode(ListNode *data)
{
    while (data != NULL)
    {
        printf("%d,", data->val);
        data = data->next;
    }
}

int main()
{
    vector<int> num1 = {5, 5, 5}; //{2, 4, 3};
    vector<int> num2 = {5, 5, 5}; //{5, 6, 4};

    ListNode *l1 = CreateList(num1);
    ListNode *l2 = CreateList(num2);

    Solution_t s;
    ListNode *sum = s.addTwoNumbers(l1, l2);

    printf("\nAfter Adding two numbers: ");
    PrintListNode(sum);

    return 0;
}