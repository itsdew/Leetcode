// 2022-03-26
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
    string str;
    cin >> str;
    vp vec(3);
    vec[0].second = 0;
    vec[1].second = 1;
    vec[2].second = 2;
    for(int i{0}; i < n; ++i){
        vec[str[i] - '0'].first++;
    }
    int k = n / 3;
    sort(vec.begin(), vec.end());
    if(vec[1].first > k){
        int a = vec[1].first - k;
        if(vec[0].second > vec[1].second){
            for(int i{n - 1}, j{0}; i >= 0 && j < a; --i){
                if(str[i] == char('0' + vec[1].second)){
                    str[i] = char('0' + vec[0].second);
                    j++;
                }
            }
        }
        else{
            for(int i{0}, j{0}; i < n && j < a; ++i){
                if(str[i] == char('0' + vec[1].second)){
                    str[i] = char('0' + vec[0].second);
                    j++;
                }
            }
        }
        if(vec[0].second > vec[2].second){
            a = vec[2].first - k;
            for(int i{n - 1}, j{0}; i >= 0 && j < a; --i){
                if(str[i] == char('0' + vec[2].second)){
                    str[i] = char('0' + vec[0].second);
                    j++;
                }
            }
        }
        else{
            for(int i{0}, j{0}; i < n && j < a; ++i){
                if(str[i] == char('0' + vec[2].second)){
                    str[i] = char('0' + vec[0].second);
                    j++;
                }
            }
        }
    }
    else{
        if(vec[2].second == 2){
            if(vec[0].second == 1) swap(vec[0], vec[1]);
            int a = k - vec[0].first;
            for(int i{0}, j{0}; i < n && j < a; ++i){
                if(str[i] == char('0' + vec[2].second)){
                    str[i] = char('0' + vec[0].second);
                    j++;
                }
            }
            a = k - vec[1].first;
            for(int i{0}, j{0}; i < n && j < a; ++i){
                if(str[i] == char('0' + vec[2].second)){
                    str[i] = char('0' + vec[1].second);
                    j++;
                }
            }
        }
        else if(vec[2].second == 1){
            if(vec[0].second == 2) swap(vec[0], vec[1]);
            int a = k - vec[0].first;
            for(int i{0}, j{0}; i < n && j < a; ++i){
                if(str[i] == char('0' + vec[2].second)){
                    str[i] = char('0' + vec[0].second);
                    j++;
                }
            }
            a = k - vec[1].first;
            for(int i{n - 1}, j{0}; i >= 0 && j < a; --i){
                if(str[i] == char('0' + vec[2].second)){
                    str[i] = char('0' + vec[1].second);
                    j++;
                }
            }
        }
        else if(vec[2].second == 0){
            if(vec[0].second == 1) swap(vec[0], vec[1]);
            int a = k - vec[0].first;
            for(int i{n - 1}, j{0}; i >= 0 && j < a; --i){
                if(str[i] == char('0' + vec[2].second)){
                    str[i] = char('0' + vec[0].second);
                    j++;
                }
            }
            a = k - vec[1].first;
            for(int i{n - 1}, j{0}; i >= 0 && j < a; --i){
                if(str[i] == char('0' + vec[2].second)){
                    str[i] = char('0' + vec[1].second);
                    j++;
                }
            }
        }
    }
    cout << str;
}
