#include<bits/stdc++.h>
using namespace std;
#define gc getchar
#define ll long long
#define v vector
#define pr pair<int,int>
#define sd second
#define ft first
#define pb push_back
#defin mp make_pair
int fr()
{
    char ch;
    int t=0,flag=0;
    ch=gc();
    while(ch<33)
        ch=gc();
    if(ch=='-')
        {
            ch=gc();
            flag=1;
        }
    while(ch>33)
    {
        t=t*10+ch-'0';
        ch=gc();
    }
    if(flag)
        return -t;
    else
        return t;
}
int main()
{
    int i,j,k,t,n;

    return 0;
}
