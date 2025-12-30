// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {

            if (visited[i]) continue;

            stack<pair<int,int>> st;
            st.push({i, -1});  
            while (!st.empty()) {
                auto [node, parent] = st.top();
                st.pop();
                visited[node] = true;

                for (int nei : adj[node]) {
                    if (!visited[nei]) {
                        st.push({nei, node});
                    }
                    else if (nei != parent) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
 