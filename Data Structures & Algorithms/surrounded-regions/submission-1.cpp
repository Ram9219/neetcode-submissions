class Solution {
   private:
    bool isvalid(int n, int m, int nrow, int ncol) {
        return (nrow < n && nrow >= 0 && ncol < m && ncol >= 0);
    }
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};
        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (isvalid(n, m, nrow, ncol) && grid[nrow][ncol] == 'O' && !vis[nrow][ncol]) {
                dfs(nrow, ncol, grid, vis);
            }
        }
    }

   public:
    void solve(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // for surrounded regions
        // first row and last row
        // dfs(row,col,grid,vis)
        for (int i = 0; i < m; i++) {
            if (!vis[0][i] && grid[0][i] == 'O') {
                dfs(0, i, grid, vis);
            }
            if (!vis[n - 1][i] && grid[n - 1][i] == 'O') {
                dfs(n - 1, i, grid, vis);
            }
        }
        // for first col and last col
        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && grid[i][0] == 'O') {
                dfs(i, 0, grid, vis);
            }
            if (!vis[i][m - 1] && grid[i][m - 1] == 'O') {
                dfs(i, m - 1, grid, vis);
            }
        }
        // for entire matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 'O') {
                    grid[i][j] = 'X';
                }
            }
        }
    }
};
