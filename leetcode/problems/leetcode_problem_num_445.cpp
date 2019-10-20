/*
Add two numbers II:

You are given two non-empty linked lists representing two non-negative integers.
The most significant digit comes first and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Note:
    What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Ex:
    Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 8 -> 0 -> 7
*/

#include <iostream>
#include <stack>
#include <vector>

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
    void ConvertToStack(ListNode *list, stack<int> &result)
    {
        while (list != NULL)
        {
            result.push(list->val);
            list = list->next;
        }
    }

    void AddDigits(int d1, int d2, int carryIn, int &carryOut, int &result)
    {
        int sum = d1 + d2 + carryIn;
        carryOut = sum / 10;
        result = sum % 10;
    }

    ListNode *ConvertToList(stack<int> &data)
    {
        ListNode *front = NULL;
        ListNode *back = NULL;

        while (!data.empty())
        {
            int digit = data.top();
            data.pop();

            ListNode *node = new ListNode(digit);
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
        }

        return front;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        stack<int> num1;
        ConvertToStack(l1, num1);

        stack<int> num2;
        ConvertToStack(l2, num2);

        stack<int> addResult;
        int carryCurrent = 0;
        do
        {
            int d1 = 0;
            if (!num1.empty())
            {
                d1 = num1.top();
                num1.pop();
            }

            int d2 = 0;
            if (!num2.empty())
            {
                d2 = num2.top();
                num2.pop();
            }

            int sum = 0;
            int carryNext = 0;
            AddDigits(d1, d2, carryCurrent, carryNext, sum);

            addResult.push(sum);
            carryCurrent = carryNext;
        } while ((!num1.empty()) || (!num2.empty()));

        if (carryCurrent > 0)
        {
            addResult.push(carryCurrent);
        }

        return ConvertToList(addResult);
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
    vector<int> num1 = {5, 5, 5}; //{7, 2, 4, 3};
    vector<int> num2 = {5, 5, 5}; //{5, 6, 4};

    ListNode *l1 = CreateList(num1);
    ListNode *l2 = CreateList(num2);

    Solution_t s;
    ListNode *sum = s.addTwoNumbers(l1, l2);

    printf("\nAfter Adding two numbers: ");
    PrintListNode(sum);

    return 0;
}