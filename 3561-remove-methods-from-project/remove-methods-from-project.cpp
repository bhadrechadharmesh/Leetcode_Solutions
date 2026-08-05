class Solution {
    void dfsSus(unordered_map<int,vector<int>>& graph,int node,vector<int>&vis){
        vis[node] = -1;

        for(auto it:graph[node]){
            if(vis[it]==0){
                dfsSus(graph,it,vis);
            }
        }
    }

    void dfs(unordered_map<int,vector<int>>& graph,int node,vector<int>& vis,bool &isValid){
        if(vis[node]==-1){
            isValid = true;
            return;
        }
        vis[node] = 2;


        for(auto it:graph[node]){
            if(vis[it]!=2){
                dfs(graph,it,vis,isValid);
            }
        }
    }
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& arr) {
        unordered_map<int,vector<int>> graph;

        for(int i=0;i<arr.size();i++){
            graph[arr[i][0]].push_back(arr[i][1]);
        }

        vector<int> vis(n,0);

        dfsSus(graph,k,vis);

        bool isValid = false;
        for(int i=0;i<n;i++){
            if(isValid)break;
            if(vis[i]==0 && !isValid){
                dfs(graph,i,vis,isValid);
            }
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            if(vis[i]==2 || isValid){
                ans.push_back(i);
            }
        }

        return ans;
    }
};