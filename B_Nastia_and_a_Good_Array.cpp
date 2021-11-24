
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fo(i, k, n) for (ll i = k; i < n; i++)
#define fo1(i, k, n) for (ll i = k; i <= n; i++)
// #define fir first
// #define sec second
#define ff first
#define ss second
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
int mod = 1e9 + 7, mxn = 3e5 + 5;

int add(int a, int b, int mod)
{
    a %= mod;
    b %= mod;
    a += b;
    if (a >= mod)
        a -= mod;
    if (a < 0)
    {
        a += mod;
        a %= mod;
    }
    return a;
}

int mul(int a, int b, int mod)
{
    a %= mod;
    b %= mod;
    a *= b;
    a += mod;
    return a % mod;
}
int po(int a, int b, int mod)
{
    if (b == 0)
        return 1;
    if (b % 2 == 0)
        return po(mul(a, a, mod), b / 2, mod);
    return mul(a, po(mul(a, a, mod), (b - 1) / 2, mod), mod);
}

long long power(long long X, long long N)
{
    if (N == 0)
        return 1;
    if (N % 2 == 0)
        return power(X * X, N / 2);
    return X * power(X, N - 1);
}

int fact[200003];
int inv[200003];

void fact0()
{
    int i, j;
    fact[0] = 1;
    for (i = 1; i <= 200000; i++)
    {
        fact[i] = i * fact[i - 1] % mod;
    }
    inv[0] = 1;
    inv[1] = 1;
    int p = mod;
    for (i = 2; i <= 200000; i++)
        inv[i] = (p - (p / i) * inv[p % i] % p) % p;

    for (i = 2; i <= 200000; i++)
    {
        inv[i] *= inv[i - 1];
        inv[i] %= mod;
    }
}
int Comb(int a, int b)
{
    // cout<<a<<" "<<b<<endl;
    int an = fact[a];
    //cout<<an<<endl;
    an *= inv[b];
    an %= mod;
    an *= inv[a - b];
    an %= mod;
    return an;
}

vector<ll> sieveOfEratosthenes(ll N)
{
    bool primes[N + 1];
    memset(primes, true, sizeof(primes));
    vector<ll> arr;

    for (ll i = 2; i * i <= N; i++)
        if (primes[i] == true)
        {
            for (ll j = i * i; j <= N; j += i)
                primes[j] = false;
        }

    for (ll i = 2; i <= N; i++)
        if (primes[i])
            arr.emplace_back(i);

    return arr;
}
#define mod 1000000007
void solve()
{
    ll n;
    cin >> n;

    ll arr[n + 1];
    fo(i, 0, n)
            cin >>
        arr[i];
    vector<pair<ll, ll>> ind;
    // vpll xy;
    vector<pair<ll, ll>> xy;
    for (ll i = 1; i < n; i++)
    {
        ind.pb({i, i + 1});
        xy.pb({min(arr[i], arr[i - 1]), mod});
        i++;
    }
    cout << ind.size() << endl;

    for (ll i = 0; i < ind.size(); i++)
    {
        cout << ind[i].ff << " " << ind[i].ss << " " << xy[i].ff << " " << xy[i].ss << endl;
    }
    return;
    // if (n == 1)
    // {
    //     cout << 0 << endl;
    //     return;
    // }
    // if (n % 2 == 0)
    // {
    //     cout << n / 2 << endl;
    //     // return;
    // }
    // else
    // {
    //     cout << (n / 2) + 1 << endl;
    //     // return;
    // }
    // for (ll i = 0; i < n;)
    // {
    //     cout << i + 1 << " " << i + 2 << " " << mod << " " << min(arr[i], arr[i + 1]) << endl;
    //     i = i + 2;
    //     if (i == n - 1)
    //     {
    //         if (arr[i] > arr[i - 1])
    //             swap(arr[i - 1], arr[i]);
    //         cout << i << " " << i + 1 << " " << min(arr[i], arr[i + 1]) << " " << mod << endl;
    //         return;
    //     }
    //     if (i > n - 1)
    //     {
    //         return;
    //     }
    //     if (arr[i] < arr[i + 1])
    //         swap(arr[i], arr[i + 1]);
    // }
    // ll cnt = 0;
    // vector<ll> ans;
    // for (ll i = 0; i < n - 1; i++)
    // {
    //     if (__gcd(arr[i], arr[i + 1]) == 1)
    //         continue;

    //     if (arr[i] < arr[i + 1])
    //     {
    //         ll mini = arr[i];
    //         arr[i + 1] = upper_bound(prime.begin(), prime.end(), mini) - prime.begin();
    //         cnt++;
    //         ans.pb(i + 1);
    //         ans.pb(i + 2);
    //         ans.pb(mini);
    //         ans.pb(arr[i + 1]);
    //     }
    //     else
    //     {
    //         ll mini = arr[i + 1];
    //         // arr[i] = mini;
    //         arr[i] = upper_bound(prime.begin(), prime.end(), mini) - prime.begin();
    //         cnt++;
    //         ans.pb(i + 1);
    //         ans.pb(i + 2);
    //         ans.pb(mini);
    //         ans.pb(arr[i]);
    //     }
    // }

    // cout << cnt << endl;

    // for (ll i = 0; i < ans.size(); i++)
    // {
    //     if (i != 0 && i % 4 == 0)
    //     {
    //         cout << endl;
    //         continue;
    //     }
    //     // cout << endl;
    //     cout << ans[i] << " ";
    // }
    // cout << endl;
    return;
}
int main()
{
    io();
    ll t;
    cin >> t;
    // vector<ll> prime = sieveOfEratosthenes(100001);
    while (t--)
    {
        solve();
    }
    return 0;
}