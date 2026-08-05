class Solution {
    void dfsSus(unordered_map<int,vector<int>>& graph, int node, vector<int>& vis){
        vis[node] = -1;

        for(auto it : graph[node]){
            if(vis[it] == 0){
                dfsSus(graph, it, vis);
            }
        }
    }

public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& arr) {
        unordered_map<int,vector<int>> graph;

        for(auto &e : arr){
            graph[e[0]].push_back(e[1]);
        }

        vector<int> vis(n,0);

        // Mark suspicious methods
        dfsSus(graph,k,vis);

        // Check dependency from normal -> suspicious
        for(auto &e : arr){
            int u = e[0];
            int v = e[1];

            if(vis[u] == 0 && vis[v] == -1){
                vector<int> ans;
                for(int i=0;i<n;i++){
                    ans.push_back(i);
                }
                return ans;
            }
        }

        // Remove suspicious methods
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(vis[i] == 0){
                ans.push_back(i);
            }
        }

        return ans;
    }
};