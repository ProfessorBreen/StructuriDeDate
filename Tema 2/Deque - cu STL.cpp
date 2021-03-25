	
#include <cstdio>
#include <queue>
using namespace std;
int v[5000005];
typedef pair<int,int> ii;
deque <ii> q;
int main()
{
    freopen("deque.in","r",stdin);
    freopen("deque.out","w",stdout);
    int n,k,i;
    long long s=0;
    scanf("%d%d",&n,&k);
    for(i=1; i<=n; i++)
        scanf("%d",&v[i]);
    for(i=1; i<=n; i++)
    {
        while(!q.empty()&&q.back().first>=v[i])
            q.pop_back();
        q.push_back(ii(v[i],i));
        if(i>=k)
        {
            if(i-q.front().second+1>k)
                q.pop_front();
            s=s+q.front().first;
        }
    }
    printf("%lld",s);
    return 0;
}