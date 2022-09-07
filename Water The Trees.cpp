// 2022-05-04
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

vi graph[100001];

int main(){
    fastio;
	int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi A(n), B(n);
        for(int i{0}; i < n; ++i){
            cin >> A[i];
        }        
        for(int i{1}; i <= n; ++i) graph[i].clear();
        for(int i{0}; i < n; ++i){
            cin >> B[i];
        }
        int ans{0};
        for(int i{0}; i < n; ++i){
            graph[A[i]].push_back(B[i]);
            graph[B[i]].push_back(A[i]);
        }
        vi ch(n + 1);
        int l{1}, r{n};
        vi select(n + 1);
        for(int i{1}; i <= n; ++i){
            if(ch[i] == 0){
                queue<int> Q;
                Q.push(i);
                ch[i] = 1;
                vi vec;
                while(!Q.empty()){
                    int x{Q.front()};
                    Q.pop();
                    vec.push_back(x);
                    for(auto& k : graph[x]){
                        if(ch[k] == 0){
                            ch[k] = 1;
                            Q.push(k);
                        }
                    }
                }
                bool flag = true;
                if(vec.size() == 1) continue;
                for(int i{0}; i < (int)vec.size(); ++i){
                    if(flag){
                        select[vec[i]] = l;
                        l++;
                        flag = false;
                    }
                    else{
                        select[vec[i]] = r;
                        r--;
                        flag = true;
                    }
                }
                for(int j{0}; j < (int)vec.size() - 1; ++j){
                    ans += abs(select[vec[j + 1]] - select[vec[j]]);
                }
                if(vec.size()){
                    ans += abs(select[vec[0]] - select[vec.back()]);                
                }
            }
        }
        cout << ans << "\n";
    }
}
