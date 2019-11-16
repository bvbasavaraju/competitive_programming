/****************************************************
Date: November 16, 2019
Successful submissions : 1
Time expiration :
Not Solved : 2
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/biweekly-contest-13
****************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

/*
    1256. Encode Number
*/

class Solution1_t
{
public:
    string encode(int num)
    {
        int l = 0;
        int n = num;
        while (n > 0)
        {
            n = n >> 1;
            l++;
        }
        l--;

        if (l <= 0)
        {
            if (num == 0)
            {
                return "";
            }
            else
            {
                return "0";
            }
        }
        else if (l == 1)
        {
            if (num == 2)
            {
                return "1";
            }
            else
            {
                return "00";
            }
        }

        int d = num - (1 << l) + 1;
        vector<int> r(l, 0);
        int i = l - 1;
        while (d > 0)
        {
            r[i] = d % 2;
            d = d / 2;
            i--;
            if (i < 0)
            {
                break;
            }
        }

        string retVal = "";
        for (i = 0; i < l; i++)
        {
            retVal += r[i] + '0';
        }
        if (d > 0)
        {
            retVal += '0';
        }

        return retVal;
    }
};

/*
1257. Smallest Common Region
*/

class Solution2_t
{
private:
    struct node
    {
        string val;
        vector<string> adj;

        node()
        {
            val = "";
        }

        void Create(vector<string> &nodeWithEdges)
        {
            int s = nodeWithEdges.size();
            if (s <= 0)
            {
                return;
            }

            //printf("\n%s, - ", nodeWithEdges[0]);
            val.append(nodeWithEdges[0]);
            for (int i = 1; i < s; i++)
            {
                //printf("%s, ", nodeWithEdges[i]);
                adj.push_back(nodeWithEdges[i]);
            }
        }

        string Find(string &val_)
        {
            int s = adj.size();
            for (int i = 0; i < s; i++)
            {
                if (adj[i] == val_)
                {
                    return val;
                }
            }

            return "";
        }

        string Val(void)
        {
            return val;
        }

        vector<string> &Adj(void)
        {
            return adj;
        }

        void print(void)
        {
            printf("\nVal = %s, Adj = ", val.c_str());
            for (int i = 0; i < adj.size(); i++)
            {
                printf("%s - ", adj[i].c_str());
            }
        }
    };

    vector<shared_ptr<node>> graph;

    shared_ptr<node> IsRegion2Present(shared_ptr<node> n, string &r2)
    {
        if (n == nullptr)
        {
            return nullptr;
        }

        if (n->Find(r2).size() > 0)
        {
            return n;
        }

        vector<string> &adj = n->Adj();
        for (int i = 0; i < adj.size(); i++)
        {
            int s = graph.size();
            for (int i = 0; i < s; i++)
            {
                shared_ptr<node> n1 = graph[i];
                if (n1 != nullptr)
                {
                    if (n1->Find(r2).size() > 0)
                    {
                        //printf("\nn->Val() = %s, r2 = %s", n1->Val().c_str(), r2.c_str());
                        string p1 = n1->Val();
                        for (int i = 0; i < s; i++)
                        {
                            shared_ptr<node> retVal = graph[i];
                            if ((retVal != nullptr) && (retVal->Find(p1).size() > 0))
                            {

                                return retVal;
                            }
                        }
                    }
                }
            }
        }

        return nullptr;
    }

    shared_ptr<node> GetParent(string &r1, string &r2)
    {
        int s = graph.size();
        for (int i = 0; i < s; i++)
        {
            shared_ptr<node> n = graph[i];
            if (n == nullptr)
            {
                return nullptr;
            }

            string p1 = n->Find(r1);
            if (p1.size() > 0)
            {
                //n->print();
                if (n->Find(r2).size() > 0)
                {
                    return n;
                }

                n = IsRegion2Present(n, r2);
                if (n != nullptr)
                {
                    return n;
                }
                else
                {
                    return GetParent(p1, r2);
                }
            }
        }

        return nullptr;
    }

public:
    string findSmallestRegion(vector<vector<string>> &regions, string region1, string region2)
    {
        int c = regions.size();
        for (int i = 0; i < c; i++)
        {
            shared_ptr<node> n = std::make_shared<node>();
            if (n == nullptr)
            {
                break;
            }

            n->Create(regions[i]);
            graph.push_back(n);
            //n->print();
        }

        string retVal;
        shared_ptr<node> retValNode = GetParent(region1, region2);
        if (retValNode != nullptr)
        {
            retVal = retValNode->Val();
        }

        return retVal;
    }
};

/*
Q: 1258. Synonymous Sentences
*/

class Solution3_t
{
public:
    vector<string> generateSentences(vector<vector<string>> &synonyms, string text)
    {
    }
};

/*
Q: 1259. Handshakes That Don't Cross
*/

class Solution4_t
{
public:
    int numberOfWays(int num_people)
    {
    }
};