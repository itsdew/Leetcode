// 2022-03-30
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
#define MOD 998244353LL
using namespace std;

int main(){
    fastio;
	int n;
    cin >> n;
    vector<vi> graph(n + 1);
    for(int i{0}; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vi ch(n + 1);
    ch[1] = 1;
    vi seq(n);
    for(int i{0}; i < n; ++i){
        cin >> seq[i];
    }
    if(seq.front() != 1){
        cout << "No";
        return 0;
    }
    queue<int> Q;
    Q.push(1);
    vi par(n + 1);
    par[1] = -1;
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        for(auto& i : graph[x]){
            if(ch[i] == 0){
                ch[i] = 1;
                par[i] = x;
                Q.push(i);
            }
        }
    }
    for(int i{0}; i < n; ++i) ch[i] = 0;
    ch[1] = 1;
    Q.push(1);
    bool flag = true;
    int cur{0};
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        vi vec;
        sort(graph[x].begin(), graph[x].end());
        int k = (int)graph[x].size();
        if(x != 1) k--;
        for(int i{cur + 1}; i < cur + 1 + k && i < n; ++i){
            vec.push_back(seq[i]);
            Q.push(seq[i]);
        }
        if(x != 1) vec.push_back(par[x]);
        cur += k;
        sort(vec.begin(), vec.end());
        for(auto& i : vec) cout << i << " ";
        cout << "\n";
        for(auto& i : graph[x]) cout << i << " ";
        cout << "\n";
        if(vec != graph[x]){
            flag = false;
            break;
        }
    }
    if(flag) cout << "Yes";
    else cout << "No";
}
