#include <fstream>
#include <stack>
#pragma GCC optimize ("O3")
using namespace std;
stack<pair<char,int>>st;
char rev(char ch)
{
    if(ch=='}')
        return '{';
    if(ch==']')
        return '[';
    return '(';
}
int main()
{
    ifstream in("paranteze.in");
    ofstream out("paranteze.out");
    int n,mx=0;
    char c;
    in>>n;
    for(int i=1; i<=n; i++)
    {
        in>>c;
        if(st.empty()||c=='{'||c=='['||c=='(')
            st.push(make_pair(c,i));
        else if(st.top().first==rev(c))
        {
            st.pop();
            if(!st.empty())
                mx=max(mx,i-st.top().second);
            else
                mx=max(mx,i);
        }
        else
            st.push(make_pair(c,i));
    }
    out<<mx;
    return 0;
}
