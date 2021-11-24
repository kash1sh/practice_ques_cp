
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

ll mod = 1e9 + 7, mxn = 3e5 + 5;
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

ll po(ll a, ll b, ll mod)
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

vll fac(200003);
ll facto(ll n)
{

    fac[0] = 1;
    fac[1] = 1;
    for (ll i = 2; i <= 200003; i++)
    {
        fac[i] = i * fac[i - 1];
    }
    return fac[n];
}
long combi(ll n, ll k)
{
    long long ans = 1;
    k = k > n - k ? n - k : k;
    ll j = 1;
    for (; j <= k; j++, n--)
    {
        if (n % j == 0)
        {
            ans *= n / j;
        }
        else if (ans % j == 0)
        {
            ans = ans / j * n;
        }
        else
        {
            ans = (ans * n) / j;
        }
    }
    return ans;
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
    string s;
    cin >> s;
    ll n = s.size();
    // vll a;
    // vll b;
    // if (n == 1)
    // {
    //     cout << 0 << endl;
    //     rr;
    // }
    // fo(i, 0, n)
    // {
    //     if (s[i] == '1')
    //         a.pb(i);
    //     else
    //     {
    //         b.pb(i);
    //     }
    // }
    // if (a.size() == 0)
    // {
    //     cout << 0 << Endl;
    //     rr;
    // }
    // if (b.size() == 0)
    // {
    //     cout << 0 << endl;
    //     rr;
    // }
    // // ll i=0,j=n-1;
    // ll first = a[0], cnt = 0;
    // ll back = a[a.size() - 1];
    // for (ll i = 0; i < b.size(); i++)
    // {
    //     if (b[i] > first && b[i] < back)
    //     {
    //         cnt++;
    //         s[b[i]] = '1';
    //     }
    // }
    // // a.clear();
    // // b.clear();
    // // fo(i, 0, n)
    // // {
    // //     if (s[i] == '1')
    // //         a.pb(i);
    // //     else
    // //     {
    // //         b.pb(i);
    // //     }
    // // }
    // first = b[0];
    // back = b[b.size() - 1];
    // for (ll i = 0; i < a.size(); i++)
    // {
    //     if (a[i] > first && a[i] < back)
    //     {
    //         cnt++;
    //     }
    // }
    // cout << cnt << Endl;
    // rr;
    // ll n = s.size();
    vector<ll> one(n), zero(n);
    ll cnt0 = 0, cnt1 = 0;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '0')
            cnt0++;
        else
            cnt1++;
    }
    if (cnt0 == 0)
    {
        cout << 0 << endl;
        rr;
    }
    if (cnt1 == 0)
    {
        cout << 0 << endl;
        rr;
    }
    for (ll i = n - 1; i >= 0; i--)
    {
        zero[i] = (i == n - 1 ? 0 : zero[i + 1]) + (s[i] == '0' ? 1 : 0);
    }
    for (ll i = 0; i < n; i++)
    {
        one[i] = (i == 0 ? 0 : one[i - 1]) + (s[i] == '1' ? 1 : 0);
    }
    ll ans = LONG_MAX;
    for (ll i = 0; i <= n; i++)
    {
        ans = min(ans, (i == 0 ? 0 : one[i - 1]) + (i >= n - 1 ? 0 : zero[i + 1]));
    }
    // return ans;
    // cout << ans << Endl;
    // rr;
    vector<ll> ones(n), zeros(n);
    for (ll i = n - 1; i >= 0; i--)
    {
        ones[i] = (i == n - 1 ? 0 : ones[i + 1]) + (s[i] == '1' ? 1 : 0);
    }
    for (ll i = 0; i < n; i++)
    {
        zeros[i] = (i == 0 ? 0 : zeros[i - 1]) + (s[i] == '0' ? 1 : 0);
    }
    ll anss = LONG_MAX;
    for (ll i = 0; i <= n; i++)
    {
        anss = min(anss, (i == 0 ? 0 : zeros[i - 1]) + (i >= n - 1 ? 0 : ones[i + 1]));
    }
    cout << min(ans, anss) << endl;
    rr;
}
int main()
{
    io();
    // solve();
    // ll t=1;
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    // cout<<setprecision(10)
    return 0;
}