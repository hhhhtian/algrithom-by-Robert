class Solution {
public:
    int n;
    unordered_map<int, vector<int>> graph;
    unordered_set<int> visited;
    vector<int> compId;
    int cnt;

    void dfs(int node) {
        visited.insert(node);
        compId[node] = cnt;
        for (auto& nei : graph[node]) {
            if (!visited.count(nei)) {
                dfs(nei);
            }
        }
    }

    void CC(int n, unordered_map<int, vector<int>>& graph) {
        this->n = n;
        this->graph = graph;
        compId.assign(n, -1);
        visited.clear();
        cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!visited.count(i)) {
                dfs(i);
                cnt++;
            }
        }
    }

    // Check if two vertices are connected
    bool connected(int v, int w) {
        return compId[v] == compId[w];
    }

    // Return the number of connected components
    int count() {
        return cnt;
    }

    // Return the component identifier for a vertex
    int getId(int v) {  
        return compId[v];
    }
};
