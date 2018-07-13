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

int lps[200005];
void manacher(string text) {
	int n,c=1,r=2,i=0,iMirror;
	n=text.length();
	n=2*n+1;
	lps[0]=0;
	lps[1]=1;
	for (int i=2;i<n; i++) {
        iMirror = 2*c-i;
        lps[i] = 0;
        if( r - i > 0 )
            lps[i] = min(lps[iMirror], r-i);
        while ( ((i + lps[i]) < n && (i - lps[i]) > 0) && ( ((i + lps[i] + 1) % 2 == 0) || (text[(i + lps[i] + 1)/2] == text[(i - lps[i] - 1)/2] ) ) ) {
            lps[i]++;
        }
        if (i + lps[i] > r) {
            c = i;
            r = i + lps[i];
        }
    }
}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

 	int i,j,k,n,t,s,x,y;
 	manacher("aababa");
 	for(i=0;i<11;i++) {
 		cout<<lps[i]<<" ";
 	}
	return 0;
}
