#include <cstdio>
 
using namespace std;
int n, aib[30005];
void update(int poz,int x)
{
    for(;poz<=n;poz+=poz&(-poz))
        aib[poz]+=x;
}
int query(int poz)
{
 int s=0;
 for(;poz>=1;poz-=poz&(-poz))
        s+=aib[poz];
 return s;
}
int bs(int val)
{
    int st=0,dr=n,med,rez;
    while(st<dr)
    {
        med=(st+dr)/2;
        rez=query(med);
        if(val<=rez)
            dr=med;
        else
            st=med+1;
    }
    return st;
}
int main()
{
    freopen("order.in","r",stdin);
    freopen("order.out","w",stdout);
    int i,x=2,poz;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        update(i,1);
    for(i=1;i<=n;i++)
    {
        x=(x+i-2)%(n+1-i)+1;
        poz=bs(x);
        update(poz,-1);
        printf("%d ",poz);
    }
    return 0;
}
