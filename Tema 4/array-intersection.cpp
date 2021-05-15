   
#include <bits/stdc++.h>
using namespace std;

vector<int> arrayIntersection(vector<int>& first, vector<int>& second) {
    unordered_map<int, int> mm;
    vector<int> sol;
    int n=first.size(), m=second.size(), i;
    for(i=0;i<n;i++)
        mm[first[i]]++;
        
    for(i=0;i<m;i++)
        if(mm[second[i]])
        {
            mm[second[i]]--;
            sol.push_back(second[i]);
        }
        
    return sol;
}
   
int main() {
    int N1, N2;
    cin >> N1 >> N2;
    vector<int> first, second;
    for (int i = 0; i < N1; ++i) {
        int val;
        cin >> val;
        first.push_back(val);
    }
    for (int i = 0; i < N2; ++i) {
        int val;
        cin >> val;
        second.push_back(val);
    }
    
    vector<int> intersection = arrayIntersection(first, second);
    cout << intersection.size() << "\n";
    for (auto& val : intersection) {
        cout << val << " ";
    }
    return 0;
}
