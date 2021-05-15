#include <fstream>
#include <cmath>
using namespace std;
int n,k,v[100005];

long long adaptHeight(int val)
{
    int i;
    long long curS=0, mn=1e16+5;
    for(i=1; i<=n; i++)
    {
        if(i<=k)
            curS+=fabs(v[i]-val);
        else
        {
            mn=min(mn,curS);
            curS-=fabs(v[i-k]-val);
            curS+=fabs(v[i]-val);
        }
    }
    return min(mn, curS);
}

int main()
{
    ifstream cin("pikachu.in");
    ofstream cout("pikachu.out");
    int i,mx=0;
    cin>>n>>k;
    for(i=1; i<=n; i++)
    {
        cin>>v[i];
        mx=max(mx,v[i]);
    }

    int st=0,dr=mx,med;
    long long bestOption=1e16+5;
    while(st<=dr)
    {
        med=(st+dr)/2;
        long long r1=adaptHeight(med+1), r2=adaptHeight(med-1), r3=adaptHeight(med);
        bestOption=min(bestOption,r1);
        bestOption=min(bestOption,r2);
        bestOption=min(bestOption,r3);
        if(r1>r2)
            dr=med-1;
        else
            st=med+1;
    }
    cout<<bestOption;
    return 0;
}
