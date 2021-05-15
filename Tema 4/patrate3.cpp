#include <fstream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
struct PO
{
    int x,y;

    bool operator<(PO other) const
    {
        if(x==other.x)
            return y<other.y;
        return x<other.x;
    }
};

pair<PO,PO> findPoints(PO p1, PO p2)
{
    PO centru = {(p1.x+p2.x)/2,(p1.y+p2.y)/2};
    PO vect = {(p2.y-p1.y)/2,(p1.x-p2.x)/2};

    PO p3 = {centru.x-vect.x, centru.y-vect.y};
    PO p4 = {centru.x+vect.x, centru.y+vect.y};

    return make_pair(p3,p4);
}

vector<PO> v;
map<PO, bool> m;
int main()
{
    ifstream cin("patrate3.in");
    ofstream cout("patrate3.out");
    int n,cnt=0,i,j;
    double x,y;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>x>>y;
        PO temp = {(int)round(x*10000),(int)round(y*10000)};
        v.push_back(temp);
        m.insert(make_pair(temp,true));
    }

    for(i=0; i<n; i++)
        for(j=i+1; j<n; j++)
        {
            auto p = findPoints(v[i],v[j]);
            if(m.find(p.first)!=m.end()&&m.find(p.second)!=m.end())
                cnt++;
        }

    cout<<cnt/2;
    return 0;
}
