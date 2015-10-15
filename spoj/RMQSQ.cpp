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
class segtree
{
    private :
    int tree[400000];
    int tsize;
    public:
        segtree(int n)
        {
            tsize=n;
        }
        int create(int a[],int l,int r,int pos)
        {
            if(l==r)
            {
                tree[pos]=a[l];
                return tree[pos];
            }
            int mid=(l+r)/2;
            tree[pos]=min(create(a,l,mid,2*pos+1),create(a,mid+1,r,2*pos+2));
            return tree[pos];
        }
        int query(int l,int r,int ql,int qr,int pos)
        {
            int mid=(l+r)/2;
            if(l>=ql&&r<=qr)
            {
                return tree[pos];
            }
            else if(qr<l||ql>r)
            {
                return INT_MAX;
            }
            else
            {
                return min(query(l,mid,ql,qr,2*pos+1),query(mid+1,r,ql,qr,2*pos+2));
            }
        }
};
int main()
{
    int i,j,k,q,l,r,t,n;
    int a[100001];
    sf(n);
    for(i=0;i<n;i++)
        sf(a[i]);
    segtree x(n);
    x.create(a,0,n-1,0);
    sf(q);
    while(q--)
    {
        sf2(l,r);
        k=x.query(0,n-1,l,r,0);
        printf("%d\n",k);
    }
    return 0;
}
