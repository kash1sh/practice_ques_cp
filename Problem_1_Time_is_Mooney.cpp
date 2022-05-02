#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

const int mxn = 1e3 + 1;
int n, m, c, M[mxn], ans, dp[1001][mxn];
vector<pair<int, int>> paths;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++)
        cin >> M[i];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        paths.push_back({a, b});
    }
    memset(dp, -1, sizeof(dp));
    dp[0][1] = 0;
    for (int i = 1; i < mxn; i++)
    {
        memset(dp[i], -1, sizeof(dp[i]));
        for (auto j : paths)
        {
            int a = j.first;
            int b = j.second;
            // if (dp[i - 1][a] >= 0)
            dp[i][b] = max(dp[i][b], dp[i - 1][a] + M[b]);
        }
        ans = max(ans, dp[i][1] - c * i * i);
    }
    cout << ans;
}