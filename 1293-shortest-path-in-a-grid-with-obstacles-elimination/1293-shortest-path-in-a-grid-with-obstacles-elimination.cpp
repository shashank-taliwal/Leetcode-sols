class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, INT_MAX));
        queue<vector<int>> q;
        q.push({0, 0, 0});
        visited[0][0] = 0;
        int res = 0;
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto cur = q.front();
                q.pop();
                int x = cur[0];
                int y = cur[1];
                int obs = cur[2];
                if (x == m - 1 && y == n - 1) {
                    return res;
                }
                for (auto dir : dirs) {
                    int nx = x + dir[0];
                    int ny = y + dir[1];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                        continue;
                    }
                    int nobs = obs + grid[nx][ny];
                    if (nobs > k || nobs >= visited[nx][ny]) {
                        continue;
                    }
                    visited[nx][ny] = nobs;
                    q.push({nx, ny, nobs});
                }
            }
            res++;
        }
        return -1;
    }
};   