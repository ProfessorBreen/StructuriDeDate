#include <cstdio>
#include <stack>
#include <vector>
using namespace std;
vector<int>v;
stack<int>st;
int main()
{
    freopen("alibaba.in","r",stdin);
    freopen("alibaba.out","w",stdout);
    int n,k,i,x;
    scanf("%d%d",&n,&k);
    for(i=1; i<=n; i++)
    {
        scanf("%1d",&x);
        if(!k)
        {
            printf("%d",x);
            continue;
        }
        if(st.empty())
            st.push(x);
        else
        {
            while(!st.empty()&&x>st.top())
            {
                k--;
                st.pop();
                if(!k)
                {
                    v.push_back(x);
                    while(!st.empty())
                    {
                        v.push_back(st.top());
                        st.pop();
                    }
                    break;
                }
            }
            if(k)
                st.push(x);
            else
            {
                int m=v.size();
                for(int j=m-1; j>=0; j--)
                    printf("%d",v[j]);
            }
        }
    }
    if(!st.empty())
    {
        while(!st.empty())
        {
            v.push_back(st.top());
            st.pop();
        }
        int m=v.size();
        for(int j=m-1; j>=k; j--)
            printf("%d",v[j]);
    }
    return 0;
}
