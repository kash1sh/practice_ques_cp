
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void io()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

// Find Min/Max
// * Greedy/Brute Force
// * DP
// * BS

const int N = 2e5 + 5;

int n, m;
int tc = 0;
int vis[N], col[N];
vector<int> g[N];
vector<int> ans[2];

void dfs(int u, int c)
{
    if (vis[u] == tc)
        return;
    vis[u] = tc;
    col[u] = c;
    ans[c].push_back(u);
    for (auto &it : g[u])
        dfs(it, c ^ 1);
}

int main()
{
    // IOS;
    io();
    int t;
    cin >> t;
    while (t--)
    {
        tc++;
        ans[0].clear();
        ans[1].clear();
        cin >> n >> m;
        // for (int i = 1; i <= n; i++)
        // g[i].clear();
        memset(vis, 0, sizeof(vis));
        // fill(begin(vis),end(vis),0);
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1, 0);
        if (ans[1].size() < ans[0].size())
            swap(ans[0], ans[1]);
        cout << ans[0].size() << endl;
        for (auto &it : ans[0])
            cout << it << " ";
        cout << endl;
    }
    return 0;
}