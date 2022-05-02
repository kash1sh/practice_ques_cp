#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, a[600], dp[600][260 * 260], MOD = 1e9 + 7;
int32_t main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        a[i] = i;
    int W = n * (n + 1) / 2;
    if (W % 2)
    {
        cout << 0;
        return 0;
    }
    W /= 2, dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= a[i])
                dp[i][j] += dp[i - 1][j - a[i]], dp[i][j] %= MOD;
        }
    }
    cout << dp[n][W];
}