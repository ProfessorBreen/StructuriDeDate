#include <fstream>
#include <queue>
#pragma optimize GCC ("O3")
using namespace std;
priority_queue<int, vector<int>, greater<int> > pq;
priority_queue<pair<int, int>, vector< pair <int, int> >, greater< pair <int, int> > > pq1;
int main()
{
    ifstream in("proc2.in");
    ofstream out("proc2.out");
    int n,m,i,j,x,y;
    in>>n>>m;
    int mn=min(m,n);
    for(i=1; i<=mn; i++)
        pq.push(i);
    for(j=1; j<=m; j++)
    {
        in>>x>>y;
        while(pq1.size())
        {
            auto p=pq1.top();
            if(p.first>x)
                break;
 
            pq.push(p.second);
            pq1.pop();
        }
        out<<pq.top()<<"\n";
 
        pq1.push(make_pair(x+y, pq.top()));
        pq.pop();
    }
    return 0;
}