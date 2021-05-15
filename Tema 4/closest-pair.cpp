#include <bits/stdc++.h>
using namespace std;


int closestPair(vector<int>& first, vector<int>& second) {
    sort(second.begin(), second.end());
    int n=first.size(), m=second.size(), i, allMin=1e9+5, mn;
    for(i=0;i<n;i++)
    {
        if(first[i]<second[0])
            mn=second[0]-first[i];
        else if(first[i]>second[m-1])
            mn=first[i]-second[m-1];
        else
        {
            int st=0, dr=m-1, med;
            while(st<=dr){
                med=(st+dr)/2;
                if(second[med] == first[i])
                    return 0;
                if(second[med] > first[i])
                    dr=med-1;
                else
                    st=med+1;
            }
            
            mn=min(fabs(first[i]-second[st]), fabs(first[i]-second[st-1]));
        }
        allMin=min(allMin,mn);
    }
    return allMin;
}

int main() {
    int n; cin >> n;
    vector<int> first, second;
    for (int i = 0; i < n; ++i) {
        int val; cin >> val;
        first.push_back(val);
    }
    for (int i = 0; i < n; ++i) {
        int val; cin >> val;
        second.push_back(val);
    }
    cout << closestPair(first, second) << "\n";
    return 0;
}
