//Devendra Uraon
class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        
        int maax=INT_MIN;
        
        for(int i=0;i<sentences.size();i++)
        {  int temp=0;
            for(auto &j:sentences[i])
            {
                if(j==' ') temp++;
            }
            maax=max(maax,++temp);
        }
        
        return maax;
    }
};