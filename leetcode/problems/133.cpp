#include<bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution 
{
public:
  Node* cloneGraph(Node* node) 
  {
    if(node == nullptr)
    {
      return nullptr;
    }
    
    unordered_map<int, Node*> valNodeMap;
    unordered_map<int, vector<int>> adjList;
    
    queue<Node*> nodes;
    nodes.push(node);
    
    while(!nodes.empty())
    {
      Node* n = nodes.front();
      nodes.pop();
      
      if(adjList.find(n->val) != adjList.end())
      {
        continue;
      }
      
      valNodeMap[n->val] = new Node(n->val);
      
      for(Node* next : n->neighbors)
      {
        nodes.push(next);
        adjList[n->val].push_back(next->val);
      }
    }
    
    for(auto it = adjList.begin(); it != adjList.end(); ++it)
    {
      Node* n = valNodeMap[it->first];
      for(int v : it->second)
      {
        n->neighbors.push_back(valNodeMap[v]);
      }
    }
    
    return valNodeMap[node->val];
  }
};