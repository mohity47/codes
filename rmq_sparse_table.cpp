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
#define MAXN 200000
#define MAXM 20
int stable[MAXN][MAXM];
int a[MAXN];

void init_sparse(int n) {
	int i,j;
	rep(i,n) {
		stable[i][0] = a[i];
	}
	for(j=1;i<log(n);i++) {
		for(i=0;i<=n-(1<<j);i++) {
			stable[i][j] = min(stable[i][j-1],stable[i+(1<<(j-1))][j-1]);
		}	
	}
}

int query_sparse(int l,int r) {
	int col = log(r-l+1);
	return min(stable[l][col],stable[r-(1<<col)+1][col]);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);   
    #endif
    ios_base::sync_with_stdio(false);
    int i,j,k,n,m,t,l,r,q,x,y;
    cin>>n;
    ina(a,i,n);
    init_sparse(n);
    cin>>q;
    while(q--) {
    	cin>>x>>y;
    	cout<<query_sparse(x,y)<<endl;
    }

    return 0;
}