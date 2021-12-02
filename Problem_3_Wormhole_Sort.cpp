#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pi = pair<ll, ll>;

vector<ll> adj[1000];
vector<pi> coordinates;
bool visited[1000];
ll n;

void DFS(int node)
{
    if (visited[node])
    {
        return;
    }
    visited[node] = true;
    for (int con : adj[node])
    {
        DFS(con);
    }
}

bool works(ll x)
{
    fill(visited, visited + n, false);
    for (int i = 0; i < n; i++)
    {
        adj[i].clear();
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ll xDistance = (coordinates[j].first - coordinates[i].first), yDistance = (coordinates[j].second - coordinates[i].second);
            ll dist = (xDistance) * (xDistance) + (yDistance) * (yDistance);
            if (dist <= x)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    DFS(0);
    for (int j = 0; j < n; j++)
    {
        if (!visited[j])
            return false;
    }
    return true;
}

int main()
{
    // freopen("moocast.in", "r", stdin);
    // freopen("moocast.out", "w", stdout);
    freopen(wormsort.in, "r", stdin);
    freopen(wormsort.in, "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        coordinates.push_back({x, y});
    }
    ll l = 0, r = 1e10, ans = 1e10;
    while (l <= r)
    {
        ll m = l + (r - l) / 2;
        if (works(m))
        {
            ans = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    cout << ans << endl;
}