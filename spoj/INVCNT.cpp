#include<bits/stdc++.h>
using namespace std;
#define gc getchar
#define sf(x) scanf("%d",&x);
#define sf2(x,y) scanf("%d%d",&x,&y);
#define sfl(x) scanf("%I64d",&x);
#define sfl2(x,y) scanf("%I64d %I64d",&x,&y);
#define pr pair
#define sd second
#define ft first
#define  v vector
class bit{
    private:
        int a[200001];
        int asize;
    public:
        bit(){}
        bit(int n){
            int i;
            asize=n;
            for(i=0;i<=asize;i++)
                a[i]=0;
        }
        void update(int start,int last,int value){
                int index=start;
                while(index<=asize)
                {
                    a[index]+=value;
                    index+=(index&(-index));
                }
                /*index=last+1;
                while(index<=asize)
                {
                    a[index]-=value;
                    index+=(index&(-index));
                }*/
        }
        int query(int index)
        {
            return sum(index);
        }
        int sum(int index)
        {
            int ans=0;
            while(index>0){
                    ans+=a[index];
                index-=(index&(-index));
            }
            return ans;
        }
};
int main()
{
    int i,j,k,t,n;
    long long ans;
    sf(t);
    while(t--)
    {
        int b[200000],c[200000];
        sf(n);
        for(i=0;i<n;i++)
            {sf(b[i]);
            c[i]=b[i];
    }
        sort(b,b+n);
        for(i=0;i<n;i++)
        {
            c[i]=lower_bound(b,b+n,c[i])-b+1;
        }
        bit x(n+1);
        for(i=0,ans=0;i<n;i++)
        {
            ans+=c[i]-x.query(c[i])-1;
            x.update(c[i],c[i],1);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
