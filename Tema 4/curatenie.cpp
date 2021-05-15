#include <fstream>
#include <unordered_map>
using namespace std;

int inOrder[500005], preOrder[500005], index, nodSt[500005], nodDr[500005];
unordered_map<int,int>m;

int buildTree(int st, int dr)
{
    if(st>dr)
        return 0;

    int newNode=preOrder[index], inIndex=m[newNode];
    index++;
    nodSt[newNode]=buildTree(st,inIndex-1);
    nodDr[newNode]=buildTree(inIndex+1,dr);

    return newNode;
}

int main()
{
    ifstream cin("curatenie.in");
    ofstream cout("curatenie.out");
    int n,i;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>inOrder[i];
        m[inOrder[i]]=i;
    }
    for(i=0; i<n; i++)
        cin>>preOrder[i];

    buildTree(0,n-1);

    for(i=1; i<=n; i++)
        cout<<nodSt[i]<<" "<<nodDr[i]<<"\n";
    return 0;
}
