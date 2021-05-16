#include <cstdio>
 
using namespace std;
int d[19][250005];
int main()
{
    freopen("stramosi.in","r",stdin);
    freopen("stramosi.out","w",stdout);
    int i,j,n,m,p,q;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)
    scanf("%d",&d[0][i]);
    for(j=1;j<=17;++j)
    for(i=1;i<=n;++i)
    d[j][i]=d[j-1][d[j-1][i]];
    for(i=1;i<=m;++i)
    {
        scanf("%d%d",&q,&p);
        for(j=0;j<=17;++j)
        if(((1<<j)&p)!=0)
        q=d[j][q];
        printf("%d\n",q);
    }
    return 0;
}