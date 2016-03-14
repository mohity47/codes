#include<bits/stdc++.h>
using namespace std;
#define gc getchar
#define ll long long
#define v vector
#define pr pair<int,int>
#define sd second
#define ft first
#define pb push_back
#define mp make_pair
struct node
{
    int x;
    int y;
    int i1;
    int i2;
};
struct cmp1
{
    bool operator()(node a,node b)
    {
        if(a.x==b.x)
            return a.y>b.y;
        else
            return a.x>b.x;
    }
};
struct cmp2
{
    bool operator()(node a,node b)
    {
        if(a.y==b.y)
            {
                if(a.x==b.x)
                    return a.i2<b.i2;
                else
                    return a.x<b.x;
            }
        else
            return a.y<b.y;
    }
};
int fans[300000];
node data[300000];
int tree[1250000];
int duplicate[300000];
class seg
{
    public:
    int update(int pos,int l,int r,int x)
    {
        if(x<l||x>r)
            return tree[pos];
        if(l==r)
            return tree[pos]=1;
        int mid=(l+r)/2;
        int left;
        int right;
        left=update(2*pos+1,l,mid,x);
        right=update(2*pos+2,mid+1,r,x);
        tree[pos]=left+right;
        return tree[pos];
    }
    int query(int pos,int l,int r,int ql,int qr)
    {
        if(ql<=l&&qr>=r)
            return tree[pos];
        else if(l>qr||r<ql)
            return 0;
        else
        {
            int mid=(l+r)/2;
            int le=query(2*pos+1,l,mid,ql,qr);
            int ri=query(2*pos+2,mid+1,r,ql,qr);
            return le+ri;
        }
    }
};
int main()
{
    ios::sync_with_stdio(false);
    int i,j,k,n,x,y;
    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>x;
        cin>>y;
        data[i].x=x;
        data[i].y=y;
        data[i].i1=i;
    }

    sort(data,data+n,cmp1());
    for(i=0;i<n;i++)
        data[i].i2=i;
    sort(data,data+n,cmp2());

    seg a;
    for(i=0;i<n;i++)
    {
        fans[data[i].i1]=a.query(0,0,n-1,data[i].i2+1,n-1);
        a.update(0,0,n-1,data[i].i2);
    }

    for(i=0;i<n;i++)
        cout<<fans[i]<<endl;

    return 0;
}
