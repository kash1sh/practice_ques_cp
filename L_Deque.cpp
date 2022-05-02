#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pi (3.141592653589)
#define mod 1000000007
#define int long long
#define float double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int32_t main()
{
    fast int t = 1;
    //cin>>t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        rep(i, n) cin >> a[i];
        int dp[n][n];
        for (int l = n - 1; l >= 0; l--)
        {
            for (int h = l; h < n; h++)
            {
                if (l == h)
                    dp[l][h] = a[l];
                else
                {
                    dp[l][h] = max(a[l] - dp[l + 1][h], a[h] - dp[l][h - 1]);
                }
            }
        }
        int total = 0;
        rep(i, n) total += a[i];
        cout << (dp[0][n - 1]) << endl;
    }
    return 0;
}