#include <fstream>
#include <cmath>
using namespace std;
int v[100005],mat[100005][30];
int main()
{
    ifstream cin("rmq.in");
    ofstream cout("rmq.out");
    int n,m,i,j,x,y;
    cin>>n>>m;
    for(i=0; i<n; i++)
    {
        cin>>v[i];
        mat[i][0]=i;
    }
    for(j=1; (1<<j)<=n; j++)
    {
        for(i=0; (i+(1<<j)-1)<n; i++)
            if(v[mat[i][j-1]]<v[mat[i+(1<<(j-1))][j-1]])
                mat[i][j]=mat[i][j-1];
            else
                mat[i][j]=mat[i+(1<<(j-1))][j-1];
    }

    for(i=1; i<=m; i++)
    {
        cin>>x>>y;
        x--;
        y--;
        j=log2(y-x+1);
        cout<<min(v[mat[x][j]],v[mat[y-(1<<j)+1][j]])<<"\n";
    }
    return 0;
}
