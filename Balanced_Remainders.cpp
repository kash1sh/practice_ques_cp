
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fo(i, n) for (ll i = 0; i < n; i++)
#define fo1(i, n) for (ll i = 1; i <= n; i++)
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

int main()
{
    io();

    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        ll c0 = 0, c1 = 0, c2 = 0;
        fo(i, n)
        {
            ll x;
            cin >> x;
            if (x % 3 == 0)
                c0++;
            else if (x % 3 == 1)
                c1++;
            else
                c2++;
        }

        ll ans = n / 3;
        ll cnt = 0;

        fo(i, 3)
        {
            if (c0 == c1 && c1 == c2)
                break;
            if (c0 > ans)
            {
                ll diff = c0 - ans;
                c0 = c0 - diff;
                c1 = c1 + diff;
                cnt += diff;
            }
            if (c1 > ans)
            {
                ll diff = c1 - ans;
                c1 = c1 - diff;
                c2 = c2 + diff;
                cnt += diff;
            }
            if (c2 > ans)
            {
                ll diff = c2 - ans;
                c2 = c2 - diff;
                c0 = c0 + diff;
                cnt += diff;
            }
        }

        cout << cnt << endl;
    }
    return 0;
}