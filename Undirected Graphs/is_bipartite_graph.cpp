class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<int> color;
    bool dfs(int node, int c) {
        color[node] = c;
        for (int nei : graph[node]) {
            if (color[nei] == -1) {
                // 邻居未染色，染成相反颜色
                if (!dfs(nei, 1 - c)) return false;
            } else if (color[nei] == c) {
                // 邻居已染色，且颜色相同 → 不是二分图
                return false;
            }
        }
        return true;
    }

    bool isBipartite(unordered_map<int, vector<int>>& graph) {
        int n = graph.size();
        color.assign(n, -1);  // -1 表示未染色

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {  // 未访问过
                if (!dfs(i, 0)) return false;
            }
        }
        return true;
    }
};
// 判断图是否是二分图（Bipartite Graph）：
// 定义：图的点可以分成两个集合，所有边的两个端点都分属不同集合。
// 等价条件：图中不能有奇数环。

// 方法：DFS 染色法

// 用一个数组 color 保存每个节点的颜色，取值 0 / 1（或 -1 表示未染色）。

// 遍历所有节点（防止图不连通），如果该点未染色，则从它开始 DFS，染成 0。
// 在 DFS 中：
// 如果邻居没染色，染成相反颜色，并继续 DFS；
// 如果邻居已经染色，但颜色和当前点一样 → 说明图不是二分图。

