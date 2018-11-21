#include<bits/stdc++.h>
using namespace std;

#define ft first
#define sd second
#define pb push_back
#define mp make_pair
#define rep(i,n) for(i=0;i<n;i++)
#define pr pair<int,int>
#define pll pair<long long,long long>
#define ll long long
#define v vector
#define all(a) a.begin(),a.end()
#define ina(a,i,n) for(i=0;i<n;i++)cin>>a[i]
#define mmst(a) memset(a,0,sizeof(a))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define MAXN 200050
#define MAXM 18
int stable[MAXN][MAXM];

int nodes[200004]; //assign node name corresponding to dfs traversal number
int occur[100005]; //index of first occurence of a node in nodes during traversal, will be used for querying
int level[200005]; //level of each node corresponding to dfs traversal , sparse table will be built on top of this array

void init_sparse(int a[],int n) {
	int i,j;
	rep(i,n) {
		stable[i][0] = i;
	}
	for(j=1;(1<<j)<=n;j++) {
		for(i=0;i<=n-(1<<j);i++) {
			if(a[stable[i][j-1]] < a[stable[i+(1<<(j-1))][j-1]]) {
				stable[i][j] = stable[i][j-1];
			}
			else 
				stable[i][j] = stable[i+(1<<(j-1))][j-1];
		}
	}
}

int query_sparse(int a[],int nodes[],int l,int r) {
	int col = log(r-l+1)/log(2);
	if(a[stable[l][col]] < a[stable[r-(1<<col)+1][col]]) {
		return nodes[stable[l][col]];
	}
	return nodes[stable[r-(1<<col)+1][col]];
}

v<v<int> > graph(100004);
int vis[100004];

void dfs(int s,int &dtime,int l) {
	nodes[dtime] = s;
	if(!occur[s])
		occur[s] = dtime;
	level[dtime] = l;
	vis[s] = 1;
	for(int i=0;i<graph[s].size();i++) {
		if(vis[graph[s][i]] == 0 ) {
			dtime++;
			dfs(graph[s][i],dtime,l+1);
			dtime++;
			nodes[dtime] = s;
			level[dtime] = l; 
		}
	}
}


int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);   
    #endif
    ios_base::sync_with_stdio(false);
    int i,j,k,n,m,t,l,r,q,x,y;
    cin>>n;
    for(i=2;i<=n;i++) {
    	cin>>x;
    	graph[x].pb(i);
    	graph[i].pb(x);
    }
    int dtime = 0;
    dfs(1,dtime,0);
    init_sparse(level,2*n-1);
    cin>>q;
    while(q--) {
    	cin>>x>>y;
    	if(occur[x] > occur[y])
    		swap(x,y);
    	cout<<query_sparse(level,nodes,occur[x],occur[y])<<endl;
    }

    return 0;
}
