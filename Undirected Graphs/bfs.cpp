class Solution {
public:
    // Input：Undirected graph + start node
    // Output： DFS path
    vector<int> bfsGraph(int start, unordered_map<int, vector<int>>& graph) {
      vector<int> path;
      unordered_set<int> visited;
      queue<int> que;

      que.push(start);
      visited.insert(start);
      while(!que.empty()){
        int node = que.front();
        que.pop();
        path.push_back(node);
        for(auto& nei: graph[node]){
          if(visited.count(nei)) continue;
          que.push(nei);
          visited.insert(nei);
        }
      }
      return path;
      
    }
};
