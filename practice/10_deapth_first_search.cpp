#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class GraphUtilities_t
{
private:
    static void dfs(vector<bool> &visited, vector<vector<int>> &graph, int32_t node)
    {
        if (visited.size() < node || graph.size() < node || visited[node])
        {
            return;
        }

        printf("\nVisited: %d", node);
        visited[node] = true;
        for (auto n : graph[node])
        {
            dfs(visited, graph, n);
        }
    }

    static void bfs(vector<int32_t> &visited, vector<int32_t> &distance, vector<vector<int32_t>> &graph, int32_t node)
    {
        if (visited.size() < node || distance.size() < node || graph.size() < node)
        {
            return;
        }

        queue<int32_t> nodes;
        nodes.push(node);
        visited[node] = true;
        while (!nodes.empty())
        {
            int32_t node_ = nodes.front();
            nodes.pop();
            for (auto n : graph[node_])
            {
                if (!visited[n])
                {
                    visited[n] = true;
                    distance[n] = distance[node_] + 1;
                    nodes.push(n);
                }
            }

            printf("\nNode[%d] is at distance[%d] from %d", node_, distance[node_], node);
        }
    }

public:
    static int32_t CreateUndirectedGraph(int32_t numOfNodes, vector<vector<int32_t>> &result)
    {
        if (numOfNodes <= 0)
        {
            return -1;
        }

        result.resize(numOfNodes + 1);
        return 0;
    }

    static int32_t AddAdjuscent(int32_t node, int32_t adjuscentNode, vector<vector<int32_t>> &graph)
    {
        if (node <= 0 || adjuscentNode <= 0 || graph.size() < node)
        {
            return -1;
        }

        graph[node].push_back(adjuscentNode);
        return 0;
    }

    static void DepthFirstSearch(vector<vector<int>> &graph)
    {
        int32_t n = graph.size();
        if (n <= 0)
        {
            return;
        }

        vector<bool> visited(n, false);
        dfs(visited, graph, 1);
    }

    static void BreadthFirstSearch(vector<vector<int>> &graph)
    {
        int32_t n = graph.size();
        if (n <= 0)
        {
            return;
        }

        vector<int32_t> visited(n, false);
        vector<int32_t> distance(n, 0);
        bfs(visited, distance, graph, 1);
    }
};

int32_t main()
{
    vector<vector<int>> undirectedGraph;
    if ((GraphUtilities_t::CreateUndirectedGraph(5, undirectedGraph) < 0) || undirectedGraph.size() - 1 != 5)
    {
        return -1;
    }

    /*      Below graph is represented below
            1 ------- 2 ------- 3
             |           |            |
             |           |            |
            4           5 ------- +
    */

    GraphUtilities_t::AddAdjuscent(1, 2, undirectedGraph);
    GraphUtilities_t::AddAdjuscent(1, 4, undirectedGraph);
    GraphUtilities_t::AddAdjuscent(2, 3, undirectedGraph);
    GraphUtilities_t::AddAdjuscent(2, 5, undirectedGraph);
    GraphUtilities_t::AddAdjuscent(3, 2, undirectedGraph);
    GraphUtilities_t::AddAdjuscent(3, 5, undirectedGraph);
    GraphUtilities_t::AddAdjuscent(5, 2, undirectedGraph);
    GraphUtilities_t::AddAdjuscent(5, 3, undirectedGraph);
    GraphUtilities_t::AddAdjuscent(4, 1, undirectedGraph);

    GraphUtilities_t::DepthFirstSearch(undirectedGraph);
    GraphUtilities_t::BreadthFirstSearch(undirectedGraph);
}