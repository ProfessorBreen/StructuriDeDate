#include <iostream>
#pragma GCC optimize ("O3")
using namespace std;
bool f[10];
int main()
{
    int n,i;
    char c;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>c;
        if(isdigit(c))
            f[c-'0']=0;
        else
        {
            if(c=='L')
            {
                for(int j=0; j<10; j++)
                    if(!f[j])
                    {
                        f[j]=1;
                        break;
                    }
            }
            else
            {
                for(int j=9; j>=0; j--)
                    if(!f[j])
                    {
                        f[j]=1;
                        break;
                    }
            }
        }
    }
    for(i=0;i<=9;i++)
        cout<<f[i];
    return 0;
}
