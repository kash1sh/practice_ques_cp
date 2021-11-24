#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FAST1 ios_base::sync_with_stdio(false);
#define FAST2 cin.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FAST1 ios_base::sync_with_stdio(false);
#define FAST2 cin.tie(NULL);

ll power(ll x, ll y, ll mod)
{
    if (y == 0)
        return 1;
    ll val = power(x, y / 2, mod);
    if (y % 2 == 1)
        return (val * val * x) % mod;
    return (val * val) % mod;
}
ll gcd(ll a, ll b)
{
    while (b)
    {
        ll c = b;
        b = a % b;
        a = c;
    }
    return a;
}
void solve()
{
    ll a, b;
    cin >> a >> b;
    if (a == b)
    {
        cout << "0 0 \n";
    }
    else if (a < b)
    {
        ll val = b - a;
        cout << val << " " << min(a % val, val - a % val) << endl;
    }
    else
    {
        ll val = a - b;
        cout << val << " " << min(b % val, val - b % val) << endl;
    }
}

int main()
{
    FAST1;
    FAST2;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}