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
        void update(int index,int value){
                while(index<=asize)
                {
                    a[index]+=value;
                    index+=(index&(-index));
                }
        }
        int query(int start,int last)
        {
            return sum(last)-sum(start-1);
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
    bit x(5);
    x.update(5,5);
    cout<<x.query(2,5)<<endl;
    x.update(3,4);
    cout<<x.query(1,4)<<endl;
    x.update(2,-2);
    cout<<x.query(3,3)<<endl;
    x.update(1,1);
    cout<<x.query(3,5)<<endl;
    x.update(4,3);
    cout<<x.query(1,5)<<endl;
    return 0;
}
