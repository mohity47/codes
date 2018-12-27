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

v<v<int> > tree(100005);
v<v<pair<int,int> > > segtree(100005);
v<pair<int,int> > common(400005);
int rootNode=0;
bool vis[100005];
int level[100005];
int treeNum[100005];
int sizes[100005];

void update(v<pair<int,int> > &seg, int pos, int l,int r,int ql,int qr,int val) {
    //cout<<pos<<" "<<l<<" "<<r<<" "<<ql<<" "<<qr<<" "<<val<<endl;
    if(ql > qr || qr < l || ql > r) {
        return ;
    }
    else if(ql<=l && r<=qr) {
        seg[pos].sd += val;
    }
    else {
        int mid = (l+r)/2;
        seg[2*pos].sd += seg[pos].sd;
        seg[2*pos+1].sd += seg[pos].sd;
        seg[pos].sd = 0;
        update(seg,2*pos,l,mid,ql,qr,val);
        update(seg,2*pos+1,mid+1,r,ql,qr,val);
    }
}

int query(v<pair<int,int> > &seg, int pos, int l,int r,int node) {
    //cout<<pos<<" "<<l<<" "<<r<<" "<<node<<endl;
    if(l==r) {
        seg[pos].ft += seg[pos].sd;
        seg[pos].sd = 0;
        return seg[pos].ft;
    }
    int mid = (l+r)/2;
    seg[2*pos].sd += seg[pos].sd;
    seg[2*pos+1].sd += seg[pos].sd;
    seg[pos].sd = 0;
    if(node <= mid) 
        return query(seg,2*pos,l,mid,node);
    return query(seg,2*pos+1,mid+1,r,node);
}

int dfs(int s,int l,int num) {
    level[s] = l;
    vis[s] = 1;
    treeNum[s] = num;
    int total=0;
    for(int i=0;i<tree[s].size();i++) {
        if(vis[tree[s][i]]==0) {
            if(s == 1) {
                total = dfs(tree[s][i],l+1,i);
                sizes[i] = total;
            }
            else 
                total = dfs(tree[s][i],l+1,num);
        }
    }
    return 1 + total;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);   
    #endif
    ios_base::sync_with_stdio(false);
    int i,j,k,n,q,m,t,x,y,d,type,node;
    cin>>n>>q;
    rep(i,n-1) {
        cin>>x>>y;
        tree[x].pb(y);
        tree[y].pb(x);
    }


    dfs(1,0,-1);
    for(i=0;i<tree[1].size();i++) {
        for(j=0;j<=4*sizes[i];j++) {
            segtree[i].pb(mp(0,0));
        }
    }

    while(q--) {
        cin>>type>>node;
        if(type ==0 ) {
            cin>>x>>d;
            if(node == 1) {
                rootNode += x;
                update(common,1,1,n,1,min(n,d),x);
            }
            else if(level[node] > d) {
                int last = sizes[treeNum[node]];
                //cout<<"hello "<<node<<" "<<last<<" "<<treeNum[node]<<endl;
                update(segtree[treeNum[node]],1,1,last,max(1,level[node]-d),min(last,level[node] + d),x);
            }
            else {
                rootNode += x;
                update(common,1,1,n,1,min(n,d-level[node]),x);
                int last = sizes[treeNum[node]];
                if(d-level[node] < last) {
                    update(segtree[treeNum[node]],1,1,last,max3(1,level[node]-d,d-level[node]+1),min(last,level[node]+d),x);
                }
            }
        }
        else {
            if(node == 1) {
                cout<<rootNode<<endl;
            }
            else {
                int last = sizes[treeNum[node]];
                cout<<query(segtree[treeNum[node]],1,1,last,level[node])+query(common,1,1,n,level[node])<<endl;
            }
        }
    }
    return 0;
}