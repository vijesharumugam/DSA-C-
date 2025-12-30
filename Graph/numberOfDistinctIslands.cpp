// https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1

class Solution {
  public:
  
    void dfs(int i, int j, int bi, int bj,
             vector<vector<int>>& grid,
             vector<vector<bool>>& visited,
             vector<pair<int,int>>& shape) {
        
        visited[i][j] = true;
        shape.push_back({i - bi, j - bj});
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<pair<int,int>> dirc = {{0,1},{1,0},{-1,0},{0,-1}};
        
        for (auto& [x, y] : dirc) {
            int ni = i + x;
            int nj = j + y;
            
            if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                grid[ni][nj] == 1 && !visited[ni][nj]) {
                dfs(ni, nj, bi, bj, grid, visited, shape);
            }
        }
    }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        set<vector<pair<int,int>>> st;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    vector<pair<int,int>> shape;
                    dfs(i, j, i, j, grid, visited, shape);
                    st.insert(shape);
                }
            }
        }
        return st.size();
    }
};
