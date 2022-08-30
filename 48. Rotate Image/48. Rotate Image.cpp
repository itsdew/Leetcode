//Author: Devendra Uraon
class Solution {
public:
    void transpose(vector<vector<int>> &mat){
        int m = mat.size();
        
        for(int i = 0; i < m; i++){
            for(int j = i; j < m; j++){
                swap(mat[i][j], mat[j][i]);
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        
        for(auto &i:matrix) reverse(i.begin(), i.end());
    }
};