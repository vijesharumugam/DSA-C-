// https://www.geeksforgeeks.org/problems/topological-sort/1

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> indegree(V);
        vector<vector<int>> adj(V);
        for(auto i : edges){
            indegree[i[1]]++;
            adj[i[0]].push_back(i[1]);
        }
        vector<int> ans;
        queue<int> q;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int a = q.front();
            q.pop();
            ans.push_back(a);
            for(auto j : adj[a]){
                if(--indegree[j] == 0) q.push(j);
            }
        }
        return ans;
    }
};