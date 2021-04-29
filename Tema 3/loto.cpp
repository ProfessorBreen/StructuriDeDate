#include <fstream>
#include <unordered_map>
#pragma optimize GCC("O3")
using namespace std;
ifstream in("loto.in");
ofstream out("loto.out");
unordered_map<int, pair<int, pair<int, int> > > m;
int v[105];
 
int main() {
    int n, s, i, j, k, sum;
    bool ok = 0;
    in >> n >> s;
    for (i = 1; i <= n; i++)
        in >> v[i];
    for (i = 1; i <= n; i++) {
        for (j = i; j <= n; j++) {
            for (k = j; k <= n; k++) {
                sum = v[i] + v[j] + v[k];
                if (sum > s)
                    continue;
                if (2 * sum == s) {
                    out << v[i] << " " << v[j] << " " << v[k] << " " << v[i] << " " << v[j] << " " << v[k];
                    ok = 1;
                    break;
                }
                m[sum] = make_pair(i, make_pair(j, k));
                if (m.find(s - sum) != m.end()) {
                    auto p = m[s - sum];
                    out << v[i] << " " << v[j] << " " << v[k] << " " << v[p.first] << " " << v[p.second.first] << " "
                        << v[p.second.second];
                    ok = 1;
                    break;
                }
            }
            if (ok)
                break;
        }
        if (ok)
            break;
    }
    if (!ok)
        out << -1;
    return 0;
}