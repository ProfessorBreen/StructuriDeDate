#include <fstream>
#include <set>
#include <cmath>
#include <queue>
#include <cstring>
#pragma GCC optimize ("O3")
using namespace std;
set<int>s;
char str[15];

class Compare
{
public:
    bool operator()(pair<int,int> &p1, pair<int,int> &p2)
    {
        return abs(p1.first-p1.second)>abs(p2.first-p2.second);
    }
};

priority_queue<pair<int,int>, vector<pair<int,int>>, Compare>minDif;

int main()
{
    ifstream cin("zeap.in");
    ofstream cout("zeap.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nr;
    while(cin>>str)
    {
        if(str[0]=='M')
        {
            if(s.size()<2)
            {
                cout<<"-1\n";
                continue;
            }
            if(str[1]=='A')
                cout<<*s.rbegin()-*s.begin()<<"\n";
            else
            {
                pair<int,int> p=minDif.top();
                auto setEnd=s.end();
                while(!minDif.empty())
                {
                    if(s.find(p.first)!=setEnd&&s.find(p.second)!=setEnd)
                        break;
                    minDif.pop();
                    p=minDif.top();
                }
                if(minDif.empty())
                    cout<<"-1\n";
                else
                    cout<<abs(p.first-p.second)<<"\n";
            }
        }
        else
        {
            cin>>nr;

            if(str[0]=='I')
            {
                //insert and check neighbours
                auto it=s.find(nr);
                if(it!=s.end())
                    continue;

                s.insert(nr);
                it=s.find(nr);
                if(it!=s.begin())
                {
                    it--;
                    minDif.push(make_pair(nr,*it));
                    it++;
                }

                it++;
                if(it!=s.end())
                    minDif.push(make_pair(nr,*it));
            }
            else if(str[0]=='C')
            {
                auto it=s.find(nr);
                if(it!=s.end())
                    cout<<"1\n";
                else
                    cout<<"0\n";
            }
            else
            {
                //check neighbours and delete
                auto it=s.find(nr);
                if(it!=s.end())
                {
                    auto it1=it;
                    it1--;
                    if(it!=s.begin())
                    {
                        it++;
                        if(it!=s.end())
                            minDif.push(make_pair(*it1,*it));
                        it--;
                    }
                    s.erase(it);
                }
                else
                    cout<<"-1\n";
            }
        }
    }
    return 0;
}
