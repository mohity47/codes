#include<bits/stdc++.h>
using namespace std;
class bit{
    private:
        int a[100];
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
                index=last+1;
                while(index<=asize)
                {
                    a[index]-=value;
                    index+=(index&(-index));
                }
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
    bit x(8);
    x.update(1,7,2);
    x.update(4,8,-1);
    x.update(5,7,3);
    x.update(2,6,4);
    x.update(3,5,2);
    x.update(1,1,4);
    x.update(3,6,-3);
    for(int i=0;i<9;i++)
        cout<<x.query(i)<<" ";
    return 0;
}
