// Course schedule 1

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inde(numCourses);
        for(auto i : prerequisites){
            adj[i[0]].push_back(i[1]);
            inde[i[1]]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++)
            if(inde[i] == 0) q.push(i);
        int c = 0;
        while(!q.empty()){
            int a = q.front();
            q.pop();
            c++;
            for(auto j : adj[a])
                if(--inde[j] == 0) q.push(j);
        }
        return c == numCourses;
    }
};