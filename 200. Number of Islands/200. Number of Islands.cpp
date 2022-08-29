//Author: Devendra Uraon 
class Solution {
public:
    vector<pair<int,int>> pr = {{1, 0}, {-1, 0}, {0, 1}, {0,-1}};
    void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &vis){
        int m = grid.size();
        int n = grid[0].size();
        
        for(auto it : pr){
            int x = it.first + i;
            int y = it.second + j;
            
            if(x<0 || y<0 || x>=m || y>=n || vis[x][y] || grid[x][y] =='0') continue;
            vis[x][y] = 1;
            dfs(x, y, grid, vis);
        }
    }
    int numIslands(vector<vector<char>> &grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        int numberOfIsland = 0;
        
       vector<vector<int>> vis(m,vector<int>(n,0));
        
        for(int i=0; i<m; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    vis[i][j] = 1;
                    dfs(i, j, grid, vis);
                    numberOfIsland++;
                }
            }
        }
        return numberOfIsland;
    }
};
