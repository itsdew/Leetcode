//Author: Devendra Uraon 
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
      int row =heights.size(); int col = heights[0].size();
        vector<vector<bool>> pacific(row, vector<bool>(col, false));
		vector<vector<bool>> atlantic(row, vector<bool>(col, false));
        
        for(int i = 0; i <= col; i++){
                dfs(0,i,pacific,INT_MIN,heights);
               dfs(row-1,i,atlantic,INT_MIN,heights);
        }
         for(int j = 0 ; j <= row ; j++){
                dfs(j,0,pacific,INT_MIN,heights);
               dfs(j,col-1,atlantic,INT_MIN,heights);
        }
        vector<vector<int>> ans;
      
         for(int r=0; r < row; r++){
            for(int c = 0; c < col; c++){
          if(pacific[r][c] && atlantic[r][c]){ 
                   ans.push_back({r, c});
                }
            }
        }
        return ans;
    }
    
    void dfs(int r, int c, vector<vector<bool>> &visit, int prev, vector<vector<int>> &heights){
    
if( r<0 || r>=heights.size() || c>=heights[0].size() || c<0 )
           return;
        if(visit[r][c]||  heights[r][c] < prev ) return;
        visit[r][c] = true;
        dfs(r+1,c,visit,heights[r][c],heights);
         dfs(r-1,c,visit,heights[r][c],heights);
         dfs(r,c+1,visit,heights[r][c],heights);
         dfs(r,c-1,visit,heights[r][c],heights);
           
    
        
    }
};
