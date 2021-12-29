#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
void setIO()
{
    fast;
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
}
bool is(int mid, vl h)
{
    int n = (int)h.size() - 1;
    vl adds(n + 1);
    for (int i = n; i >= 3; i--)
    {
        if (adds[i] + h[i] < mid)
            return false;
        ll d = min(h[i], (h[i] + adds[i] - mid)) / 3;
        adds[i - 1] += d;
        adds[i - 2] += 2 * d;
    }
    return h[1] + adds[1] >= mid and h[2] + adds[2] >= mid;
}
int main()
{
    setIO();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vl h(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> h[i];
        ll l = 1, r = 1e9, ans = 1;
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            if (is(mid, h))
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        cout << ans << "\n";
    }
    return 0;
}