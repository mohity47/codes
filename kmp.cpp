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

int lps[100004];

void lps_builder(string s) {
    lps[0] = 0;
    for(int i=1;i<s.length();i++) {
        int j=i-1;
        while( lps[j]!=0 && s[lps[j]] != s[i]) {
            j = lps[j]-1;
        }
        lps[i] = (s[lps[j]] == s[i]) ? lps[j] + 1 : 0;
    }
}



int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);   
    #endif
    ios_base::sync_with_stdio(false);
    int i,j,k,n,m,t,l,r,q,x;

    string s;
    cin>>s;
    lps_builder(s);
    rep(i,s.length()) {
        cout<<lps[i]<<" ";
    }
    cout<<endl;
    return 0;
}