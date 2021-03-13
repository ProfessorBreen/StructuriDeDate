#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <chrono>
#include <algorithm>
#pragma GCC optimize ("O3")
using namespace std;
bool test_sort(vector<int>vv)
{
    int i,n=vv.size();
    for(i=1; i<n; i++)
        if(vv[i-1]>vv[i])
            return 0;
    return 1;
}

vector<int> bubble_sort(vector<int>vv)
{
    int n=vv.size(),modif=1,i;
    while(modif)
    {
        modif=0;
        for(i=1; i<n; i++)
            if(vv[i]<vv[i-1])
            {
                swap(vv[i],vv[i-1]);
                modif=1;
            }
    }
    return vv;
}

vector<int> count_sort(vector<int>vv)
{
    map<int,int>m;
    vector<int> newV;
    int n=vv.size(),i,j;
    for(i=0; i<n; i++)
        m[vv[i]]++;
    for(auto it=m.begin(); it!=m.end(); it++)
    {
        int n1=it->second;
        for(j=1; j<=n1; j++)
            newV.push_back(it->first);
    }
    return newV;
}

vector<int> merge_sort(vector<int> vv)
{
    if(vv.size()<=1)
        return vv;
    int n=vv.size()/2;
    vector<int>st(vv.begin(),vv.begin()+n);
    vector<int>dr(vv.begin()+n,vv.end());

    vector<int>resSt=merge_sort(st);
    vector<int>resDr=merge_sort(dr);
    vector<int>res;
    merge(resSt.begin(),resSt.end(),resDr.begin(),resDr.end(),back_inserter(res));
    return res;
}

vector<int> radix_sort(vector<int> vv)
{
    queue<int>buckets[10];
    int n=vv.size(),i,mx=0,j;
    for(i=0; i<n; i++)
        mx=max(mx,vv[i]);
    int nrcif=log10(mx)+1,exp=1;
    for(i=1; i<=nrcif; i++)
    {
        for(j=0; j<n; j++)
            buckets[(vv[j]/exp)%10].push(vv[j]);
        vv.clear();
        for(j=0; j<10; j++)
            while(!buckets[j].empty())
            {
                vv.push_back(buckets[j].front());
                buckets[j].pop();
            }
        exp*=10;
    }
    return vv;
}

vector<int>v,v1;
int main()
{
    ifstream in("test.in");
    ofstream out("test.out");
    int t,n,i,j,x;
    in>>t;
    for(i=1; i<=t; i++)
    {
        out<<"Test "<<i<<"\n";
        v.clear();
        in>>n;
        for(j=1; j<=n; j++)
        {
            in>>x;
            v.push_back(x);
        }

        auto start=chrono::high_resolution_clock::now();
        v1=bubble_sort(v);
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        out<<"Test Bubble Sort\n";
        if(test_sort(v1))
            out<<"Rezultat corect, timp: "<<duration.count()<<"\n\n";
        else
            out<<"Rezultat gresit\n\n";

        v1.clear();
        start=chrono::high_resolution_clock::now();
        v1=count_sort(v);
        stop=chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        out<<"Test Count Sort\n";
        if(test_sort(v1))
            out<<"Rezultat corect, timp: "<<duration.count()<<"\n\n";
        else
            out<<"Rezultat gresit\n\n";

        v1.clear();
        start=chrono::high_resolution_clock::now();
        v1=merge_sort(v);
        stop=chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        out<<"Test Merge Sort\n";
        if(test_sort(v1))
            out<<"Rezultat corect, timp: "<<duration.count()<<"\n\n";
        else
            out<<"Rezultat gresit\n\n";


        v1.clear();
        start=chrono::high_resolution_clock::now();
        v1=radix_sort(v);
        stop=chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        out<<"Test Radix Sort\n";
        if(test_sort(v1))
            out<<"Rezultat corect, timp: "<<duration.count()<<"\n\n";
        else
            out<<"Rezultat gresit\n\n";
    }
    return 0;
}
