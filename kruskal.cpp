#include<bits/stdc++.h>
using namespace std;
#include <unordered_set>
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
v<pair<int,pr > > edges;
v<pr > graph[100005];
int parent[100005];
int dset[100005];
int find_parent(int u) {
    if(u == parent[u]) {
        return u;
    }
    return parent[u] = find_parent(parent[u]);
}

void union_vert(int u,int v) {
    int pu = find_parent(u);
    int pv = find_parent(v);
    if(dset[pu] > dset[pv]) {
        dset[pu] += dset[pv];
        parent[pv] = pu;
    }
    else {
        dset[pv] += dset[pu];
        parent[pu] =pv ;
    }
} 
v<pair<int,pr > > fedges;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);   
    #endif
    ios_base::sync_with_stdio(false);
    int i,j,x,y,z,n,m,k,c,t;
    cin>>n>>m>>k;
    rep(i,k) {
        cin>>x;
        special.insert(x);
    }
    rep(i,m) {
        cin>>x>>y>>z;
        if(x==y)
            continue;
        edges.pb(mp(z,mp(x,y)));
    }
    for(i=1;i<=n;i++) {
        parent[i] = i;
        dset[i] = 1;
    }
    sort(edges.begin(),edges.end());
    for(i=0;i<edges.size();i++) {
        int u = edges[i].sd.ft;
        int v = edges[i].sd.sd;
        //cout<<u<<" "<<v<<" "<<find_parent(u)<<" "<<find_parent(v)<<endl;
        if(find_parent(u) != find_parent(v)) {
            //cout<<u<<" "<<v<<endl;
            union_vert(u,v);
            fedges.pb(edges[i]);
        }
    }
    for(i=0;i<fedges.size();i++) {
        cout<<fedges[i].ft<<" "<<fedges[i].sd.ft<<" "<<fedges[i].sd.sd<<endl;
    }
    return 0;
}