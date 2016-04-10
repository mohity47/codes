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
auto euclidean(int a,int b)
{
    if(a%b==1)
    {
        return mp(1,-a/b);
    }
    pr c;
    c=euclidean(b,a%b);
    return mp(c.sd,c.ft-c.sd*(a/b));
}
int solve(int  a,int b)
{
    int t,ans;
    pr c;
    if(a<b)
        {
            c=euclidean(b,a);
            ans=c.sd;
        }
    else
        {
            c=euclidean(a,b);
            ans=c.ft;
        }
    if(ans<0)
        return ans+b;
    else
        return ans;
}
int main()
{
//    freopen("A-large.in","r",stdin);
//    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(false);
    int a,b;
    cin>>a>>b;
    int ans=solve(a,b);
    cout<<ans<<endl;
    return 0;
}
