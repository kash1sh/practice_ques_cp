
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define vll vector<ll>
#define vpll vector<pair<ll, ll>>
#define fo(i, k, n) for (ll i = k; i < n; i++)
#define fo1(i, k, n) for (ll i = k; i <= n; i++)
#define rr return
#define Endl endl
#define ff first
#define ss second
#define all(X) (X).begin(), (X).end()

#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << endl;
#else
#define debug(x)
#endif
using namespace std;

void io()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("error.txt","w",stderr);
    // freopen("output.txt", "w", stdout);
    // #endif
}

ll mod = 998244353, mxn = 3e5 + 5;
void deb(vector<ll> v)
{
    for (auto t : v)
        cerr << t << " ";
    cerr << "\n";
}
ll mul(ll a, ll b, ll mod)
{
    a %= mod;
    b %= mod;
    a *= b;
    a += mod;
    return a % mod;
}

bool sortbysecdesc(const pair<int, int> &a,
                   const pair<int, int> &b)
{
    return a.second > b.second;
}
bool check_sorted(vll a)
{
    ll n = a.size();
    for (ll i = 1; i < n; i++)
    {
        if (a[i] >= a[i - 1])
            continue;
        return false;
    }
    return true;
}
vll fact(2e5 + 5, 1);
ll binPow(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    ll ret = binPow(a, b / 2);
    if (b % 2 == 0)
        return (ret * ret) % mod;
    return ((ret * ret) % mod * a) % mod;
}
ll inv(ll a)
{
    return (binPow(a, mod - 2) % mod + mod) % mod;
}
ll binom(ll a, ll b)
{
    // before t
    //  for (int i = 1;i<=2e5;i++)fact[i] = (i * fact[i - 1])%mod;
    if (b < 0 or a < 0)
        return 0;
    return (((fact[a] * inv(fact[b])) % mod * inv(fact[a - b])) % mod + mod) % mod;
}
// CONDITION && cout << "YES" || cout << "NO"; cout << '\n';
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
void prime_fact(ll n, vector<ll> &res)
{
    while (n % 2 == 0)
    {
        res.pb(2);
        n = n / 2;
    }

    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            res.pb(i);
            n = n / i;
        }
    }
    if (n > 2)
    {
        res.pb(n);
    }
}
bool valid_coordinate(ll x, ll y, ll n, ll m)
{
    if (x < 0 || y < 0)
        return false;

    else if (x >= n || y >= m)
        return false;

    else
        return true;
}
int sod(int n)
{
    int sum = 0;
    while (n)
    {
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}

bool isPowerOfTwo(ll n)
{
    return n && (!(n & (n - 1)));
}

void solve()
{
    ll n;
    cin >> n;
    vll a(n + 1);
    // ll cnt = 0;
    fo(i, 1, n + 1)
    {
        cin >> a[i];
        // cnt = a[i];
    }
    sort(a.begin() + 1, a.end());
    if (a[n - 1] == a[n])
    {
        cout << fact[n] % mod << endl;
        rr;
    }
    if (a[n] - a[n - 1] > 1)
    {
        cout << 0 << endl;
        rr;
    }
    ll total = fact[n] % mod;
    ll cnt = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (a[i] == a[n] - 1)
            cnt++;
    }
    for (ll i = 1; i <= n; i++)
    {
        if (i - 1 < cnt)
            continue;
        // debug(combi(i - 1, cnt));
        // debug(fact(cnt));
        // debug(fact(n - cnt - 1));
        ll val = (((binom(i - 1, cnt) * fact[cnt]) % mod) * (fact[n - cnt - 1])) % mod;
        total = (total - val) % mod;
        if (total < 0)
            total += mod;
    }
    cout << total << endl;
    rr;
    // for (ll i = 1; i < n; i++)
    // {
    //     if (a[i] == a[0])
    //         cnt++;
    // }
    // if (cnt + 1 == n)
    // {
    //     cout << fact(n) << endl;
    //     rr;
    // }
    // map<ll, ll> m;
    // ll maxa = *max_element(a.begin(), a.end());
    // // for(ll i=0;i<n;i++){

    // // }
    // for (ll i = 0; i < n; i++)
    // {
    //     m[maxa - a[i]]++;
    // }
    // m[0]--;
    // if (m[0] == 0 && m[1] == 0)
    // {
    //     cout << 0 << endl;
    //     rr;
    // }
    // ll total = fact(n);
    // debug(m[0]);
    // total -= fact(n - 1 - m[0]);
    // ll num = 0;
    // for (auto i : m)
    // {
    //     if (i.ff > 1)
    //         num++;
    // }
    // num++;
    // debug(num);
    // for (ll i = 2; i < num + 1; i++)
    //     total -= (fact(n - i) * (num - 1));

    // cout << total << endl;
    // rr;
}
int main()
{
    io();
    // solve();
    // ll t=1;
    for (int i = 1; i <= 2e5; i++)
        fact[i] = (i * fact[i - 1]) % mod;
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    // cout<<setprecision(10)
    return 0;
}