//Question: https://codeforces.com/contest/1102/problem/D
//Author: Devendra Uraon
#include <bits/stdc++.h>
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define forloop for(int i = 0; i < n; ++i)
#define input cin >>
#define print cout <<
#define MAX 2147000000
#define MOD 998244353LL
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n; input n;
    string str; input str;
    vp vec(3);
    vec[0].second = 0;
    vec[1].second = 1;
    vec[2].second = 2;
    forloop vec[str[i] - '0'].first++;
    int k = n / 3;
    sort(vec.begin(), vec.end());
    if(vec[1].first > k){
        int a = vec[1].first - k;
        if(vec[0].second > vec[1].second){
            for(int i{n - 1}, j = 0; i >= 0 && j < a; --i){
                if(str[i] == char('0' + vec[1].second)){
                    str[i] = char('0' + vec[0].second);
                    j++;
                }
            }
        }
        else{
            for(int i = 0, j = 0; i < n && j < a; ++i){
                if(str[i] == char('0' + vec[1].second)){
                    str[i] = char('0' + vec[0].second);
                    j++;
                }
            }
        }
        a = vec[2].first - k;
        if(vec[0].second > vec[2].second){
            for(int i = n - 1, j = 0; i >= 0 && j < a; --i){
                if(str[i] == char('0' + vec[2].second)){
                    str[i] = char('0' + vec[0].second);
                    j++;
                }
            }
        }
        else{
            for(int i = 0, j = 0; i < n && j < a; ++i){
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
            for(int i = 0, j = 0; i < n && j < a; ++i){
                if(str[i] == char('0' + vec[2].second)){
                    str[i] = char('0' + vec[0].second);
                    j++;
                }
            }
            a = k - vec[1].first;
            for(int i = 0, j = 0; i < n && j < a; ++i){
                if(str[i] == char('0' + vec[2].second)){
                    str[i] = char('0' + vec[1].second);
                    j++;
                }
            }
        }
        else if(vec[2].second == 1){
            if(vec[0].second == 2) swap(vec[0], vec[1]);
            int a = k - vec[0].first;
            for(int i = 0, j = 0; i < n && j < a; ++i){
                if(str[i] == char('0' + vec[2].second)){
                    str[i] = char('0' + vec[0].second);
                    j++;
                }
            }
            a = k - vec[1].first;
            for(int i = n - 1, j = 0; i >= 0 && j < a; --i){
                if(str[i] == char('0' + vec[2].second)){
                    str[i] = char('0' + vec[1].second);
                    j++;
                }
            }
        }
        else if(vec[2].second == 0){
            if(vec[0].second == 1) swap(vec[0], vec[1]);
            int a = k - vec[0].first;
            for(int i = n - 1, j = 0; i >= 0 && j < a; --i){
                if(str[i] == char('0' + vec[2].second)){
                    str[i] = char('0' + vec[0].second);
                    j++;
                }
            }
            a = k - vec[1].first;
            for(int i = n - 1, j = 0; i >= 0 && j < a; --i){
                if(str[i] == char('0' + vec[2].second)){
                    str[i] = char('0' + vec[1].second);
                    j++;
                }
            }
        }
    }
    print str;
}
