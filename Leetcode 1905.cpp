//count sub islands
class Solution {
public:
    int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, 1, -1};
    int r, c;
    bool valid(int i, int j) {
        return i >= 0 && j >= 0 && i < r && j < c; 
    }
    void dfs(int i, int j, vector<vector<int>>& grid2,vector<vector<bool>>& visited, bool& jana,vector<vector<int>>& grid1) {
        visited[i][j] = 1;
        if (grid1[i][j] == 0)
            jana = 0;
        for (int k = 0; k < 4; k++) {
            if (valid(i + row[k], j + col[k]) &&
                !visited[i + row[k]][j + col[k]] &&
                grid2[i + row[k]][j + col[k]] == 1) {
                dfs(i + row[k], j + col[k], grid2, visited, jana, grid1);
            }
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        r = grid1.size(), c = grid1[0].size();
        vector<vector<bool>> visited(r, vector<bool>(c, 0));
        int ans = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (!visited[i][j] && grid2[i][j] == 1) {
                    bool jana = 1;
                    dfs(i, j, grid2, visited, jana, grid1);
                    if (jana)
                        ans++;
                }
            }
        }
        return ans;
    }
};
