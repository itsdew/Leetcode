//Author: Devendra Uraon
class Solution {
public:
    int largestOverlap(vector<vector<int>>&a, vector<vector<int>>&b) {
        int n = a.size();
        int ans = 0;
        int cur = 0;

        for(int z=0;z<4;z++){
            for(int i=n-1;i>=0;i--){
                for(int j=0;j<n;j++){
                    cur = 0;
                    int tot = (n-i)*(j+1);
                    pair<int,int>ac;
                    pair<int,int>bc;
                    ac.first = i;ac.second = 0;
                    bc.first = 0;bc.second = n-1-j;

                    while(tot--){
                        
                        if(a[ac.first][ac.second]==1 && b[bc.first][bc.second]==1)
                            cur++;
                        ac.second++;
                        bc.second++;
                        if(ac.second==(j+1)){
                            ac.first++;
                            ac.second = 0;
                            bc.first++;
                            bc.second = n-1-j;
                        }
                    }
         
                    ans < cur ? ans = cur : ans = ans;
                }
            }
            if(z%2==0){
                for(int x=0;x<n;x++){
                    int st = 0,ed = n-1;
                    while(st<ed)
                        swap(a[x][st++],a[x][ed--]),swap(b[x][st-1],b[x][ed+1]);
                }
            }else{
                swap(a,b);
            }
        }
        return ans;
    }
};