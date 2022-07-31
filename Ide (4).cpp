#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t,n,q,a,b,c,h,p,count,flag=1;
    cin>>t;
    while(t--){
    	a=b=c=h=p=count=0;
    	cin>>n>>q;
    	vector<int> v(n+10);
    	for(int i=0;i<=n;i++){
    		v[i]=0;
    	}
    	vector<vector<pair<int,int>>> m(n+10);
    	for(int i=0;i<q;i++){
    		cin>>a>>b>>c;
    		m[b].push_back({a,c});
    		m[c].push_back({a,b});
    	}
    	/*for(int i=1;i<=n;i++){
    		for(int j=0;j<m[i].size();j++){
    			cout<<m[i][j].first<<','<<m[i][j].second<<"  ";
    		}
    		cout<<'\n';
    	}
    	cout<<'\n';*/
    	a=b=c=p=h=0;
        for(int i=1;i<=n;i++){
        	if(v[i]==0){
        		v[i]=-1;
        		count++;
        		p++;
        		queue<int> q;
        		q.push(i);
        		while(q.empty()==false&&count<n){
        			a=q.front();
        			q.pop();
        			if(v[a]==-1){
        				for(int j=0;j<m[a].size();j++){
        					if(m[a][j].first==1){
        						if(v[m[a][j].second]==-1){
        							flag=0;
        							break;
        						}else if(v[m[a][j].second]==0){
        							q.push(m[a][j].second);
        							count++;
        						    v[m[a][j].second]=1;
        						    h++;
        						}
        					}else{
        						if(v[m[a][j].second]==1){
        							flag=0;
        							break;
        						}else if(v[m[a][j].second]==0){
        							q.push(m[a][j].second);
        							count++;
        						    v[m[a][j].second]=-1;
        						    p++;         							
        						}       						
        					}
        				}
        			}else if(v[a]==1){
        				for(int j=0;j<m[a].size();j++){
        					if(m[a][j].first==1){
        						if(v[m[a][j].second]==1){
        							flag=0;
        							break;
        						}else if(v[m[a][j].second]==0){
        							q.push(m[a][j].second);
        							count++;
        						    v[m[a][j].second]=-1;
        						    p++;        							
        						}
        					}else{
        						if(v[m[a][j].second]==-1){
        							flag=0;
        							break;
        						}else if(v[m[a][j].second]==0){
        							q.push(m[a][j].second);
        							count++;
        							v[m[a][j].second]=1;
        						    h++;
        						}        						
        					}
        				}
        			}
        			if(flag==0){
        				break;
        			}
        		}
        		if(flag==0){
        			break;
        		}else{
        			if(p>h){
        				b+=p;
        			}else{
        				b+=h;
        			}
        		}
        	}
        	p=h=a=c=0;
        }
        if(flag==0){
        	flag=1;
        	cout<<-1<<'\n';
        }else{
        	cout<<b<<'\n';
        }
    }
    return 0;
}