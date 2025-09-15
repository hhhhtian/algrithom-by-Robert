class Solution {
public:
    // Input：Undirected graph + start node
    // Output： DFS path
    vector<int> dfsIterative(int start, unordered_map<int, vector<int>>& graph) {
        vector<int> path;
        unordered_set<int> visited;
        stack<int> st;

        st.push(start);
        visited.insert(start);

        while (!st.empty()) {
            int node = st.top();
            st.pop();
            path.push_back(node);

            // transverse neighbors of the above node
            for (auto& nei : graph[node]) {
                if (visited.count(nei)) continue;
                visited.insert(nei);
                st.push(nei);
            }
        }
        return path;
    }
};

int main() {
    unordered_map<int, vector<int>> graph;
    graph[0] = {1, 2};
    graph[1] = {0, 3, 4};
    graph[2] = {0};
    graph[3] = {1};
    graph[4] = {1};

    Solution sol;
    vector<int> res = sol.dfsIterative(0, graph);

    cout << "DFS path: ";
    for (int x : res) cout << x << " ";
    cout << endl;

    return 0;
}



