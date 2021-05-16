#include <fstream>
 
using namespace std;
ifstream cin("baruri.in");
ofstream cout("baruri.out");
int aib[100005], v[100005];
void add(int x, int cantitate, int n)
{
    int i;
    for(i = x; i <= n; i += (i ^ (i - 1) & i))
        aib[i] += cantitate;
}
int compute(int x)
{
    int i, ans = 0;
    for(i = x; i >= 1; i -= (i ^ (i - 1) & i))
        ans += aib[i];
    return ans;
}
int main()
{
    int n, i, t, j, b, d, x, m, a, b1, b2;
    cin >> t;
    for(int l = 1; l <= t; l++){
        cin >> n;
        for(i = 1; i <= n; i++){
            cin >> v[i];
            add(i, v[i], n);
        }
        cin >> m;
        for(i = 1; i <= m; i++){
            cin >> x;
            if(x == 0){
                cin >> b >> d;
                cout << compute(min(b + d, n)) - compute(b) + compute(b - 1) - compute(max(b - d - 1, 0))<< "\n";
            }
            else if(x == 1){
                cin >> a >> b;
                add(b, a, n);
            }
            else if(x == 2){
                cin >> a >> b;
                add(b, -a, n);
            }
            else{
                cin >> a >> b1 >> b2;
                add(b2, a, n);
                add(b1, -a, n);
            }
        }
        for(i = 1; i <= n; i++)
            aib[i] = 0;
    }
    return 0;
}