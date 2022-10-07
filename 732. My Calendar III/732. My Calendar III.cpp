//Author: Devendra Uraon
class MyCalendarThree {
public:
   vector<int> s;
   vector<int> e;
    int maxi = 0;
    
   void check(){
       sort(s.begin(),s.end());
       sort(e.begin(),e.end());
        int i = 0, j = 0, ans = 0;
        while(i<s.size() && j<e.size()){
           if(s[i] < e[j]){
                ans++; i++;
            }
            else{
                ans--; j++;
            }
            maxi = max(maxi, ans);
        }
    }
    
    int book(int start, int end) {
        s.push_back(start);
        e.push_back(end);
        check();
        return maxi;
    }
};
