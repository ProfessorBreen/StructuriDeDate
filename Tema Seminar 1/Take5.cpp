#include <cstdio>
#include <thread>
#include <algorithm>
#include <map>
#include <vector>
#pragma GCC optimize ("O3")
using namespace std;
int v[1005],n,s,nrPairs=0;
map<int,vector<pair<int,int>>>m;
void cnt(int a,int b)
{
    int sum, temp=0;
    for(int i=a; i<b; ++i)
    {
        int x=v[i];
        for(int j=i+1; j<n; ++j)
        {
            int y=v[j];
            for(int k=j+1; k<n; ++k)
            {
                sum=x+y+v[k];
                sum=s-sum;
                if(sum<0)
                    break;
                int z=m[sum].size();
                for(int l=z-1; l>=0; --l)
                {
                    pair<int,int>p=m[sum][l];
                    if(p.first>k&&p.second>k)
                        ++temp;
                }
            }
        }
    }
    nrPairs+=temp;
}
int main()
{
    freopen("take5.in","r",stdin);
    freopen("take5.out","w",stdout);
    int x;
    scanf("%d%d",&n,&s);
    for(int i=n-1; i>=0; --i)
    {
        scanf("%d",&x);
        v[i]=x;
    }
    sort(v,v+n);
    for(int i=n-1; i>=1; --i)
    {
        int y=v[i];
        for(int j=i-1; j>=0; --j)
            if(y+v[j]<=s)
                m[y+v[j]].push_back(make_pair(i,j));
    }
    int y=n>>2;
    x=y;
    thread t1(cnt,0,x);
    thread t2(cnt,x,x+y);
    x+=y;
    thread t3(cnt,x,x+y);
    x+=y;
    thread t4(cnt,x,n);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    printf("%d",nrPairs);
    return 0;
}
