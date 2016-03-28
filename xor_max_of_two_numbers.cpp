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
    int l=-1;
    int r=-1;
};
node trie[3200000];
int ma,mbit,nt;
void build(int x,int v,int pos)
{
    int bit;
    bit=1&x;
    if(bit==0)
    {
        if(trie[pos].l==-1)
            trie[pos].l=++nt;
        if(v<mbit)
            build(x>>1,v+1,trie[pos].l);
    }
    else
    {
        if(trie[pos].r==-1)
            trie[pos].r=++nt;
        if(v<mbit)
            build(x>>1,v+1,trie[pos].r);
    }
}
int rev(int x)
{
    int j,y=0;
    int bit;
    for(j=0;j<mbit;j++)
    {
        bit=1&(x);
        y=bit|y;
        if(j<mbit-1)
            y<<=1;
        x>>=1;
    }
    return y;
}
void print(int pos,string st,int v)
{
    if(v==mbit)
        {cout<<st<<endl;
        return ;}
    if(trie[pos].l!=-1)
        print(trie[pos].l,st+'0',v+1);
    if(trie[pos].r!=-1)
        print(trie[pos].r,st+'1',v+1);
}
int query(int x,int pos,int v,int ans)
{
    int bit;
    bit=x&1;
    if(bit==0)
    {
        if(trie[pos].r!=-1)
        {
            ans=ans|1;
            if(v==mbit)
                return ans;
            ans=query(x>>1,trie[pos].r,v+1,ans<<1);
        }
        else
        {
            if(v==mbit)
                return ans;
            ans=query(x>>1,trie[pos].l,v+1,ans<<1);
        }
    }
    else
    {
        if(trie[pos].l!=-1)
        {

            ans=ans|1;
            if(v==mbit)
                return ans;
            ans=query(x>>1,trie[pos].l,v+1,ans<<1);
        }
        else
        {
            if(v==mbit)
                return ans;
            ans=query(x>>1,trie[pos].r,v+1,ans<<1);
        }
    }
    return ans;
}
int main()
{
    int i,j,k,n,t,x,y,bit,ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n],b[n];
         ma=0;
         nt=0;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            if(i==0)
                ma=a[i];
            else
                ma=max(a[i],ma);
        }
        x=ma;
        while(x!=0)
        {
            mbit++;
            x=x>>1;
        }
        for(i=0;i<n;i++)
            b[i]=rev(a[i]);
        for(i=0;i<n;i++)
            build(b[i],1,0);
        ans=ma;
        for(i=0;i<n;i++)
        {
            x=query(b[i],0,1,0);
            ans=max(x,ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}
