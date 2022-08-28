//Author: Devendra Uraon
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
       int i, j, k, l, p, q, n = mat.size(), m = mat[0].size();
    for(i = 0; i < n; i++){
        vector<int> a;
        for(j = i, k = 0; j < n && k < m; j++, k++)
            a.push_back(mat[j][k]);
        sort(a.begin(), a.end());
        for(j = i, k = 0; j < n && k < m; j++, k++)
            mat[j][k] = a[k];
    }
    for(i = 0; i < m; i++){
        vector<int> a;
        for(j = i, k = 0; j < m && k < n; j++, k++)
            a.push_back(mat[k][j]);
        sort(a.begin(), a.end());
        for(j = i, k = 0; j < m && k < n; j++, k++)
            mat[k][j] = a[k];
    }
    return mat; 
    }
};