#include <fstream>
#include <unordered_map>
using namespace std;
ifstream cin("pariuri.in");
ofstream cout("pariuri.out");
unordered_map <int, int> mp;
int main() {
    int n ,i ,k, x, y;
    cin >> n;
    for(i = 1; i <= n; i++){
        cin >> k;
        for(int j = 1; j <= k; j++){
            cin >> x >> y;
            mp[x] += y;
        }
    }
    cout << mp.size() << "\n";
    for(auto it = mp.begin(); it != mp.end(); it++)
        cout << it->first << " " << it->second << " ";
    return 0;
}