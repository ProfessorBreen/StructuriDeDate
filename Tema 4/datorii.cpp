#include <cstdio>
#include <algorithm>
using namespace std;

int aib[100005],n;
void update(int poz,int x)
{
    for(; poz<=n; poz+=(poz&(-poz)))
        aib[poz]+=x;
}
void update1(int poz,int x)
{
    for(; poz<=n; poz+=(poz&(-poz)))
        aib[poz]-=x;
}
int query(int poz)
{
    int s=0;
    for(; poz>0; poz-=(poz&(-poz)))
        s+=aib[poz];
    return s;
}
int main()
{
    freopen("datorii.in","r",stdin);
    freopen("datorii.out","w",stdout);
    int m,i,x,a,b;
    scanf("%d%d",&n,&m);
    for(i=1; i<=n; ++i)
    {
        scanf("%d",&x);
        update(i,x);
    }
    for(i=1; i<=m; ++i)
    {
        scanf("%d",&x);
        if(!x)
        {
            scanf("%d%d",&a,&b);
            update1(a,b);
        }
        else
        {
            scanf("%d%d",&a,&b);
            printf("%d\n",query(b)-query(a-1));
        }
    }
    return 0;
}
