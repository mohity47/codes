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

int a[200000];
v<v<int> > wavelet(400000);
v<v<int> > f(400000);
int nindex;
v<pr> ps(400000);

void build(int c,int low,int high) {
	if(wavelet[c].size() <= 1) {
		return ;
	}
	int mid = (low + high)/2;
	int l=0,i;
	ps[c].ft = nindex;
	ps[c].sd = nindex+1;
	bool flag=0;
	for(i=0;i<wavelet[c].size();i++) {
		if(wavelet[c][i] != wavelet[c][0]) 
			flag=1;
	}
	if(!flag) 
		return;
	for(i=0;i<wavelet[c].size();i++) {
		if(wavelet[c][i] <= mid) {
			wavelet[nindex].pb(wavelet[c][i]);
			f[nindex].pb(0);
			f[c][i] = ++l;
		}
		else {
			wavelet[nindex+1].pb(wavelet[c][i]); 
			f[nindex+1].pb(0);
			f[c][i] = l;
		}
	}
	nindex+=2;
	build(ps[c].ft,low,mid);
	build(ps[c].sd,mid+1,high);
}

int query(int c,int low,int high,int l,int r, int x) {
	//cout<<c<<" "<<low<<" "<<high<<" "<<l<<" "<<r<<endl;
	if(r < l || x < low)
		return 0;
	if(high <= x ) {
		return r-l+1;
	}
	int mid = (low+high)/2;
	int left=0;
	if(l>0) {
		left = f[c][l-1];
	}
	int ql = query(ps[c].ft,low,mid,left,f[c][r]-1,x);
	int qr = query(ps[c].sd,mid+1,high,l-left,r-f[c][r],x);
	return ql + qr;
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
  	int ma =0; 
  	rep(i,n) {
  		ma = max(ma,a[i]);
  		wavelet[0].pb(a[i]);
  		f[0].pb(0);
  	}
  	nindex = 1;
  	build(0,1,ma);
  	cin>>q;
  	while(q--) {
  		cin>>l>>r>>x;
  		cout<<query(0,1,ma,l,r,x)<<endl;
  	}

    return 0;
}