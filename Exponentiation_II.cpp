#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define all(a) a.begin(), a.end()

const int maxn = 200010;
const ll MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
ll n, m, a[maxn];
map<int, int> M, N;
string s, ss;
set<int> S;

ll powr(ll a, ll b, ll M)
{
    if (b == 0)
        return 1LL;
    ll c = powr(a, b / 2, M);
    c *= c, c %= M;
    if (b % 2)
        c *= a;
    return c % M;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        ll y = powr(b, c, MOD - 1);
        cout << powr(a, y, MOD) << "\n";
    }
}