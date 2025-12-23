// Course schedule 2

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inde(numCourses);
        for(auto i : prerequisites){
            adj[i[0]].push_back(i[1]);
            inde[i[1]]++;
        }
        queue<int> q;
        vector<int> order;
        for(int i = 0; i < numCourses; i++)
            if(inde[i] == 0) q.push(i);
        int c = 0;

        while(!q.empty()){
            int a = q.front();
            q.pop();
            c++;
            order.push_back(a);
            for(auto j : adj[a])
                if(--inde[j] == 0) q.push(j);
        }
        reverse(order.begin(), order.end());
        if(c == numCourses) return order;
        return {};
    }
};