#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long sp[100005];
vector<pair<int,int>>v;
int main()
{
    int n,d,x,y,i,j;
    long long mx=0;
    cin>>n>>d;
    for(i=1; i<=n; i++)
    {
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(),v.end());
    sp[0]=v[0].second;
    for(i=1; i<n; i++)
        sp[i]=sp[i-1]+v[i].second;

    i=0;
    for(j=0; j<n; j++)
    {
        if(v[j].first-v[i].first<d)
        {
            if(i>=1)
                mx=max(mx,sp[j]-sp[i-1]);
            else
                mx=max(mx,sp[j]);

            continue;
        }

        i++;
        j--;
    }

    cout<<mx;
    return 0;
}
