#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
 
vector<pair<int, int>>val;
priority_queue<int, vector<int>, greater<int>>pq;
 
int main()
{
    ifstream in("timbre.in");
    ofstream out("timbre.out");
    int n,m,k,x,y,i,s=0;
    in>>n>>m>>k;
    for(i=1; i<=m; i++)
    {
        in>>x>>y;
        val.push_back(make_pair(x,y));
    }
    sort(val.begin(),val.end());
    while(n>0)
    {
        while(m>=1&&val[m-1].first>=n)
        {
            pq.push(val[m-1].second);
            m--;
        }
        s+=pq.top();
        pq.pop();
        n-=k;
    }
    out<<s;
}