class Solution {
public:
    // Input：Undirected graph + start node
    // Output： DFS path
    unordered_map<int, vector<int>> graph;
    vector<int> path;
    unordered_set<int> visited;
    void dfs(int node){
      visited.insert(node);
      path.push_back(node);
      for(auto& nei: graph[node]){
        if(visited.count(nei)) continue;
        dfs(nei);
      }
    }
    vector<int> dfsGraph(int start, unordered_map<int, vector<int>>& graph) {
      this->graph = graph;
      dfs(start);
      return path;
    }

};
