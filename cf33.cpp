ll helper(ll n, vector<ll> a, vector<ll> b)
{
    sort(a.begin(), a.end(), greater<ll>());
    sort(b.begin(), b.end(), greater<ll>());
    vector<ll> pa(n + 1), ppb(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        pa[i] = a[i - 1];
        ppb[i] = b[i - 1];
        pa[i] = pa[i] + pa[i - 1];
        ppb[i] = ppb[i] + ppb[i - 1];
    }
    ll start = 0;
    ll end = 1e9;
    while (start < end)
    {
        ll mid = (start + end) >> 1;
        ll tp = (n + mid) - (n + mid) / 4;
        ll rema = max(tp - mid, 0LL);
        ll remb = min(tp, n);

        ll asc = mid * 100;
        asc = asc + pa[rema];
        ll bsc = ppb[remb];
        if (asc < bsc)
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }
    return start;
}