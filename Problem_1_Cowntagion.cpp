/*Remember me,
shall you deny,
death will reply*/

#include <iostream>
#include <vector>
#define pb push_back
#define ff first
#define ss second

using namespace std;

typedef long long int ll;

vector<ll> v[100001];
ll res = 0;
vector<bool> vis(100005, false);
ll solve(ll n)
{
    ll num = 0, val = 1;
    while (val <= n)
    {
        val *= 2;
        num++;
    }
    return num;
}

void dfs(ll s)
{
    vis[s] = true;
    if (s == 1)
    {
        res += v[s].size();
        res += solve(v[s].size());
    }
    else
    {
        res += v[s].size() - 1;
        res += solve(v[s].size() - 1);
    }
    // for (ll i = 0; i < v[s].size(); i++)
    for (auto i : v[s])
    {
        // if (v[s][i] == u)
        // continue;
        if (vis[i])
            continue;
        dfs(i);
    }
}

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n;
    cin >> n;
    for (ll i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(1);
    cout << res << endl;
    return 0;
}