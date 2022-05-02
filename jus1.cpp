#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ll m1, m2, n;

    cin >> m1 >> m2 >> n;
    vector<ll> a(n);
    ll tot = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        tot += a[i];
    }
    sort(a.begin(), a.end(), greater<>());
    vector<ll> pre(n, 0);
    pre[0] = a[0];
    for (ll i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + a[i];
    }
    ll sum = 0;
    if (m1 > m2)
    {
        swap(m1, m2);
    }
    ll ans = LONG_MAX;
    vector<ll> res, re;
    for (ll i = 0; i < n; i++)
    {
        // sum=pre[i];
        sum = pre[i] * m1 + (tot - pre[i]) * m2;
        // ans = min(ans, sum);
        if (sum < ans)
        {
            ans = sum;
            res.push_back(a[i]);
        }
        else
        {
            re.push_back(a[i]);
        }
        sum = 0;
    }
    for (auto i : res)
    {
        cout << i << " ";
    }
    cout << endl;
    for (auto i : re)
    {
        cout << i << " ";
    }
    cout << endl;
    // cout << ans << endl;
    // return 0;

    // cin >> e;
    // for (i = 0; i < e; i++)
    // {
    //     cin >> x >> y >> w;
    //     a[x].push_back({y, w});
    // }
    // cin >> x >> y;
    // dfs(x, y);
    // if (mn == k)
    //     cout << "-1";
    // else
    //     cout << mn;
    return 0;
}