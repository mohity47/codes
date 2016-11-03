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
#define pie 3.1415926535897932
#define loop(a,b) for(a=0;a<b;a++)

string temp,ans;
v<string> fans;

struct node
{
    int flag=0;
    node* next[26];
};

string a[4];
int vis[4][4];

bool cmp(string a,string b)
{
    return a.length() > b.length();
}

void build(node *root,int x)
{
    int n=ans[x]-97;
    if(root->next[n] == NULL)
    {
        root->next[n]=new node();
    }
    if(x == ans.length()-1)
    {
        root->flag=1;
        return ;
    }
    build(root->next[n],x+1);
}

void msearch(int x,int y,node *root)
{
    ans+=a[x][y];
    if(root->flag==1)
    {
        fans.pb(ans);
    }
    vis[x][y]=1;
    int i,j,tx,ty,n;
    for(i=-1;i<2;i++)
    {
        for(j=-1;j<2;j++)
        {
            if(i==j)
            {
                continue;
            }
            else
            {
                tx=x+i;
                ty=y+j;
                if(vis[tx][ty]==1)
                {
                    continue;
                }
                else
                {
                    int pos=a[tx][ty]-'a';
                    if(root->next[pos])
                    {
                        msearch(tx,ty,root->next[pos]);
                    }
                    else
                    {
                        continue;
                    }
                }
            }
        }
    }
    ans.pop_back();
}
void print(node *root)
{
    if(root->flag==1)
    {
        cout<<ans;
    }
    for(i=0;i<26;i++)
    {
        if(root->next[n])
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int i,j,k,n,m;

//    for(i=0;i<4;i++)
//    {
//        cin>>a[i];
//    }

    string s;
    freopen("dict.txt","r",stdin);
    //freopen("out.txt","w",stdout)
    node *root=new node();

    i=0;
    while(cin>>s)
    {
        ans=s;
        build(root,0);
    }
    print(root);

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(root->next[a[i][j]-'a'])
                msearch(i,j,root);
        }
    }

    sort(fans.begin(),fans.end(),cmp);

    for(i=0;i<fans.size();i++)
    {
        cout<<fans[i]<<endl;
    }

    system("start out.txt");

    return 0;
}
