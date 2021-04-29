#include <fstream>
#include <vector>
#pragma GCC optimize ("O3")
using namespace std;
 
const unsigned int hashVal=2017;
vector<unsigned int>lists[hashVal];
 
int contains(int nr,int r)
{
    int n=lists[r].size(),i;
    for(i=0; i<n; i++)
        if(lists[r][i]==nr)
            return i;
    return -1;
}
 
bool contains(int nr)
{
    return contains(nr,nr%hashVal)>=0;
}
 
void add(int nr)
{
    int r=nr%hashVal;
    if(contains(nr,r)==-1)
        lists[r].push_back(nr);
}
 
void del(int nr)
{
    int r=nr%hashVal, poz=contains(nr,r);
    if(poz>=0)
        lists[r].erase(lists[r].begin()+poz);
}
 
int main()
{
    ifstream in("hashuri.in");
    ofstream out("hashuri.out");
    unsigned int n,i,c,nr;
    in>>n;
    for(i=1; i<=n; i++)
    {
        in>>c>>nr;
        if(c==1)
            add(nr);
        else if(c==2)
            del(nr);
        else
            out<<contains(nr)<<"\n";
    }
    return 0;
}