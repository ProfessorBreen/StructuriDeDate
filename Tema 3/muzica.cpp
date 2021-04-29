#include <fstream>
#include <unordered_set>
#pragma optimize GCC "O3";
using namespace std;
ifstream cin("muzica.in");
ofstream cout("muzica.out");
unordered_set <long long> s(100005);
int main()
{
    long long n, m, i, a, b, c, d, e, x;
    cin >> n >> m;
    cin >> a >> b >> c >> d >> e;
    for(i = 1; i <= n; i++){
        cin >> x;
        s.insert(x);
    }
    int cnt = 0;
    for(i = 1; i <= m; i++){
        auto it = s.find(a);
        if(it != s.end()){
            cnt++;
            s.erase(it);
        }
        long long nr = (1LL * c * b + 1LL * d * a) % e;
        a = b;
        b = nr;
    }
    cout << cnt;
    return 0;