#include <bits/stdc++.h>
using namespace std;

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

        for (auto& nei : graph[node]) {
            if (visited.count(nei)) continue;
            st.push(nei);
            visited.insert(nei);
        }
    }

    return path;
}

int main() {
    unordered_map<int, vector<int>> graph;

    // build a undirected graph
    graph[0] = {1, 2};
    graph[1] = {0, 3, 4};
    graph[2] = {0};
    graph[3] = {1};
    graph[4] = {1};

    vector<int> res = dfsIterative(0, graph);

    cout << "DFS path: ";
    for (int x : res) cout << x << " ";
    cout << endl;

    return 0;
}
