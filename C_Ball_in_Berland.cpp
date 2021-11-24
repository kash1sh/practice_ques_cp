
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fo(i, k, n) for (ll i = k; i < n; i++)
#define fo1(i, k, n) for (ll i = k; i <= n; i++)
#define fir first
#define sec second

#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)

using namespace std;

void io()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
}
vector<int> sieveOfEratosthenes(int N)
{
    bool primes[N + 1];
    memset(primes, true, sizeof(primes));
    vector<int> arr;

    for (int i = 2; i * i <= N; i++)
        if (primes[i] == true)
        {
            for (int j = i * i; j <= N; j += i)
                primes[j] = false;
        }

    for (int i = 2; i <= N; i++)
        if (primes[i])
            arr.emplace_back(i);

    return arr;
}
#define mod 1000000007

bool static comp(pair<ll, ll> v1, pair<ll, ll> v2)
{
    return v1.first < v2.first;
}
int main()
{
    io();
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b, k;
        cin >> a >> b >> k;

        ll boys[k];
        ll girls[k];
        ll cnt1[a + 1] = {0};
        ll cnt2[b + 1] = {0};
        for (ll i = 0; i < k; i++)
        {
            ll x;
            cin >> x;
            boys[i] = x;
            cnt1[x]++;
        }

        for (ll i = 0; i < k; i++)
        {
            ll x;

            cin >> x;
            girls[i] = x;

            cnt2[x]++;
        }

        // vector<pair<ll, ll>> v;

        // for (ll i = 0; i < k; i++)
        // {
        //     v[i].first = boys[i];
        //     v[i].second = girls[i];
        // }
        ll ans = 0;
        for (ll i = 0; i < k; i++)
        {
            ll a1 = k - cnt1[boys[i]] - cnt2[girls[i]] + 1;
            ans += a1;
        }

        ans /= 2;
        cout << ans << endl;

        // sort(v.begin(), v.end(), comp);
    }
    return 0;
}