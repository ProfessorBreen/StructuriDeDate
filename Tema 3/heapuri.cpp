	
#include <fstream>
#include <set>
using namespace std;
ifstream in("heapuri.in");
ofstream out("heapuri.out");
set<int> s;
int elem[200005];
int main()
{
    int n,c,nr,i,ins=0;
    in>>n;
    for(i=1; i<=n; i++)
    {
        in>>c;
        if(c==3)
            out<<*s.begin()<<"\n";
        else
        {
            in>>nr;
            if(c==1)
            {
                elem[++ins]=nr;
                s.insert(nr);
            }
            else
                s.erase(elem[nr]);
        }
    }
    return 0;
}