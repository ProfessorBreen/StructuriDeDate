#include <fstream>
#include <stack>
using namespace std;
string s;
stack<int>st1,st2;
int main()
{
    ifstream in("queue.in");
    ofstream out("queue.out");
    int n,i;
    in>>n;
    in.get();
    for(i=1; i<=n; i++)
    {
        getline(in,s);
        if(s[1]=='u')
        {
            int m=s.size(),nr=0;
            for(int j=10; j<m; j++)
                if(isdigit(s[j]))
                    nr=nr*10+s[j]-'0';
                else
                    break;
            st1.push(nr);
            out<<i<<": read("<<nr<<") push(1,"<<nr<<")\n";
        }
        else
        {
            out<<i<<": ";
            int tp;
            if(st2.empty())
            {
                while(!st1.empty())
                {
                    tp=st1.top();
                    out<<"pop(1) ";
                    st1.pop();
                    if(!st1.empty())
                    {
                        out<<"push(2,"<<tp<<") ";
                        st2.push(tp);
                    }
                    else
                        out<<"write("<<tp<<")\n";
                }
            }
            else
            {
                out<<"pop(2) "<<"write("<<st2.top()<<")\n";
                st2.pop();
            }
        }
    }
    return 0;
}
