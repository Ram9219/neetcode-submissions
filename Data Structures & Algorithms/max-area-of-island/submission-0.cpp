class Solution {
   private:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, int &count) {
        vis[row][col] = 1;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};
        int n = grid.size();
        int m = grid[0].size();
        count++;
        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && grid[nrow][ncol] == 1 &&
                !vis[nrow][ncol]) {
                dfs(nrow, ncol, grid, vis, count);
            }
        }
    }

   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    int count = 0;
                    dfs(i, j, grid, vis, count);
                    ans = max(ans, count);
                }
            }
        }
        return ans;
    }
};
