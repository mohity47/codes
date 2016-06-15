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
#define sf(a) scanf("%d",&a);
#define sf2(a,b) scanf("%d%d",&a,&b);
#define total 400000
#define pie 3.1415926535897932
int suffix_array[100000];
struct node
{
    int first;
    int second;
    int third;
};
struct cmp
{
    bool operator()(node a,node b)
    {
        if(a.ft<b.ft)
            return a.ft<b.ft;
        else if(a.ft==b.ft)
        {
            return a.sd<b.sd;
        }
        else
            return 0;
    }
};
node ranker[100000];
int index_wise_rank[100000];
int new_ranks[100000];
void build_suffix_array(string a)
{
    int n=a.length(),i,j,x;
    //intitialize ranker
    for(i=0;i<n;i++)
    {
        suffix_array[i]=i;
        index_wise_rank[i]=a[i]-'a';
        new_ranks[i]=-1;
    }
    i=0;
    while(i<n)
    {
        for(j=0;j<n;j++)
        {
            ranker[j].ft=new_ranks[j];
            x=suffix_array[j]+i;
            ranker[j].third=suffix_array[j];
            if(x>=n)
                ranker[j].sd=-1;
            else
                ranker[j].sd=index_wise_rank[x];
        }
        sort(ranker,ranker+n,cmp());
        index_wise_rank[ranker[0].third]=0;
        suffix_array[0]=ranker[0].third;
        new_ranks[0]=0;
        x=0;
        for(j=1;j<n;j++)
        {
            if(ranker[j].ft==ranker[j-1].ft&&ranker[j].sd==ranker[j-1].sd)
            {
                new_ranks[j]=x;
            }
            else
                new_ranks[j]=++x;
            index_wise_rank[ranker[j].third]=x;
            suffix_array[j]=ranker[j].third;
        }
        if(i==0)
            i++;
        else
            i*=2;
    }
}
int main()
{
    int i;
    string s;
    cin>>s;
    build_suffix_array(s);
    for(i=0;i<s.length();i++)
    {
        cout<<suffix_array[i]<<" ";
    }
    return 0;
}
