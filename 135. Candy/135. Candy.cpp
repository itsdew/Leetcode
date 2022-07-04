//Devendra Uraon 
class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum=1, height=0, heightVal=INT_MAX, current=1;
        for(int i=1;i<ratings.size();i++){
            if(ratings[i]>ratings[i-1]){
                current++;
                heightVal=current;
                height=i;
                sum+=current;
            }
            else if(ratings[i]<ratings[i-1]){
                int count=1;
                if((current==1) ? count=i-height+1 : height=i);
                current=1;
                sum+=count;
                if(count==heightVal)
                {
                    heightVal++; sum++;
                }
            }
            else{
                current=1;
                heightVal=INT_MAX;
                height=i;
                sum+=current;
            }
        }
        return sum;
    }
};
