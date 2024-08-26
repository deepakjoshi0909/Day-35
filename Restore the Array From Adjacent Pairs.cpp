class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adj;
        unordered_set<int> vis;
        vector<int> ans;

        for(auto& pair : adjacentPairs) {
            adj[pair[0]].push_back(pair[1]);
            adj[pair[1]].push_back(pair[0]);
        }

        int st = 0;
        for(auto& [key, value] : adj) {
            if(value.size() == 1) {
                st = key;
                break;
            }
        }

        dfs(st, adj, vis, ans);
        return ans;
    }

private:
    void dfs(int node, unordered_map<int, vector<int>>& adj, unordered_set<int>& vis, vector<int>& ans) {
        vis.insert(node);
        ans.push_back(node);

        for(int it : adj[node]) {
            if(vis.find(it) == vis.end()) {
                dfs(it, adj, vis, ans);
            }
        }
    }
};
