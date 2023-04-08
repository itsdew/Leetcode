//Author: Devendra Uraon
class Solution {
public:
    int dfs(int row,int col,vector<vector<int>>&grid,vector<pair<int,int>>&directions,
    vector<vector<bool>>&visited){
        if(row<0 || col<0 || row==grid.size() || col==grid[0].size())return -1;
        if(grid[row][col]==0 || visited[row][col])return 0;
        visited[row][col]=true;
        int prev=0;
        for(auto [new_row,new_col]:directions){
            int ans=dfs(row+new_row,col+new_col,grid,directions,visited);
            (prev==-1 || ans==-1)?prev=-1:prev+=ans;
        }
        return prev==-1?prev:grid[row][col]+prev;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<pair<int,int>>directions{{0,-1},{0,1},{1,0},{-1,0}};
        vector<vector<bool>>visited(n,vector<bool>(grid[0].size(),false));
        int res=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<grid[0].size();col++){
                if(grid[row][col]==1 && !visited[row][col]){
                    int ans=dfs(row,col,grid,directions,visited);
                    res+=ans==-1?0:ans;
                }
            }
        }
        return res;
    }
};