#include <fstream>

using namespace std;
int v[400005],v1[100005];

void build(int nod,int st,int dr)
{
    if(st==dr)
    {
        v[nod]=v1[st];
        return;
    }
    int med=(st+dr)/2;
    build(2*nod,st,med);
    build(2*nod+1,med+1,dr);
    v[nod]=max(v[2*nod],v[2*nod+1]);
}

int query(int nod,int st,int dr,int a,int b)
{
    if(a>b)
        return 0;
    if(st==a&&dr==b)
        return v[nod];
    int med=(st+dr)/2;
    return max(query(2*nod,st,med,a,min(b,med)),query(2*nod+1,med+1,dr,max(a,med+1),b));
}

void update(int nod,int st,int dr,int poz,int val)
{
    if(st==dr)
    {
        v[nod]=val;
        return;
    }
    int med=(st+dr)/2;
    if(poz<=med)
        update(2*nod,st,med,poz,val);
    else
        update(2*nod+1,med+1,dr,poz,val);
    v[nod]=max(v[2*nod],v[2*nod+1]);
}

int main()
{
    ifstream cin("arbint.in");
    ofstream cout("arbint.out");
    int n,m,i,c,x,y;
    cin>>n>>m;
    for(i=1; i<=n; i++)
        cin>>v1[i];

    build(1,1,n);

    for(i=1; i<=m; i++)
    {
        cin>>c>>x>>y;
        if(c)
            update(1,1,n,x,y);
        else
            cout<<query(1,1,n,x,y)<<"\n";
    }
    return 0;
}
