class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, set<int>& s, vector<bool>& visited) {
        if (s.find(node) != s.end())
            return 1;
        if (visited[node])
            return 0;
        visited[node] = 1;
        bool ans = 1;
        for (int i = 0; i < graph[node].size(); i++) {
            ans = ans && dfs(graph[node][i], graph, s, visited);
        }
        if (ans) {
            s.insert(node);
            return 1;
        }
        return 0;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n, 0);
        set<int> s;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, graph, s, visited);
            }
        }
        vector<int> ans;
         for(auto x:s){
            ans.push_back(x);
        }
        return ans;
    }
};
