
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll n;
    cin >> n;

    map<string, ll> m;

    // for (ll i = 0; i < n; i++)
    while (n--)
    {
        string s;
        cin >> s;
        m[s]++;
    }
    cout << m.size() << endl;
    return;
}
int main()
{

    // solve();
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}