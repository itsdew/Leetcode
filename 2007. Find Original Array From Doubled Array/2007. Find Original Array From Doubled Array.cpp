//Author: Devendra Uraon
class Solution {
public:
    int arr[100001];
     vector<int> findOriginalArray(vector<int>& changed) {
        
        vector<int>res;
                
        for (int i = 0; i < changed.size(); i++){
            arr[changed[i]]++;
        }
        
        if (arr[0]){
             if (arr[0] % 2 == 0){
                 while(arr[0] > 0){
                     arr[0] -= 2;
                     res.push_back(0);
                 }
             }else{
                 return res;
             }
         }
         
         for (int i = 1; i <= 50001; i++){
             if (arr[i]){
                 if (arr[i] <= arr[i * 2]){
                     while(arr[i]-- && arr[i * 2]--)
                         res.push_back(i);
                 }else{
                     return vector<int>();
                 }
             }
         }
         return res;
     }
};