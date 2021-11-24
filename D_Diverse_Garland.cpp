
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

ll fact(ll n)
{
    ll res = 1, i;

    for (ll i = 2; i <= n; i++)
    {
        res = (res * i) % mod;
    }
    return res;
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

ll dp[200005];
// string a;
vector<char> a;
ll help(string s, ll n, ll i)
{
    if (i >= n)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    ll ans = 0;
    if (s[i] == 'R' && (i + 1 < n && s[i + 1] == 'R'))
    {
        // ans=min()
        s[i + 1] = 'G';
        ll a1 = help(s, n, i + 1);
        s[i + 1] = 'B';
        ll a2 = help(s, n, i + 1);
        if (a1 < a2)
        {
            ans = a1;
            a[i + 1] = 'G';
        }
        else
        {
            ans = a2;
            a[i + 1] = 'B';
        }
        ans = 1 + min(a1, a2);
    }
    else if (s[i] == 'B' && (i + 1 < n && s[i + 1] == 'B'))
    {
        // ans=min()
        s[i + 1] = 'G';
        ll a1 = help(s, n, i + 1);
        s[i + 1] = 'R';
        ll a2 = help(s, n, i + 1);
        if (a1 < a2)
        {
            ans = a1;
            a[i + 1] = 'G';
        }
        else
        {
            ans = a2;
            a[i + 1] = 'R';
        }
        ans = 1 + min(a1, a2);
    }
    else if (s[i] == 'G' && (i + 1 < n && s[i + 1] == 'G'))
    {
        // ans=min()
        s[i + 1] = 'B';
        ll a1 = help(s, n, i + 1);
        s[i + 1] = 'R';
        ll a2 = help(s, n, i + 1);
        if (a1 < a2)
        {
            ans = a1;
            a[i + 1] = 'B';
        }
        else
        {
            ans = a2;
            a[i + 1] = 'R';
        }
        ans = 1 + min(a1, a2);
    }
    else
    {
        ans = help(s, n, i + 1);
    }
    return dp[i] = ans;
}
void solve()
{
    ll n;
    cin >> n;
    string s;
    a.resize(n);
    for (ll i = 0; i < n; i++)
    {
        a[i] = 0;
    }
    // a.clear();
    cin >> s;
    // ll r = 0;
    // string t = "RGB";
    // for (ll i = 1; i < n; i++)
    //     if (s[i] == s[i - 1])
    //     {
    //         r++;
    //         for (ll j = 0; j < 3; j++)
    //             if (t[j] != s[i - 1] && t[j] != s[i + 1])
    //                 s[i] = t[j];
    //     }
    // cout << r << endl
    //      << s;
    // rr;
    ll cnt = 0;
    for (ll i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
        {
            cnt++;
            debug(i);
            debug(s[i]);
            if (s[i - 1] == 'R')
            {
                if (i == n - 1)
                {
                    s[i] = 'G';
                    continue;
                }
                if (i + 1 < n && s[i + 1] == 'R')
                {
                    s[i] = 'G';
                }
                if (i + 1 < n && s[i + 1] == 'B')
                {
                    s[i] = 'G';
                }
                else if (i + 1 < n && s[i + 1] == 'G')
                {
                    s[i] = 'B';
                }
            }
            else if (s[i - 1] == 'G')
            {
                if (i == n - 1)
                {
                    s[i] = 'B';
                    continue;
                }
                if (i + 1 < n && s[i + 1] == 'G')
                {
                    s[i] = 'B';
                }
                if (i + 1 < n && s[i + 1] == 'B')
                {
                    s[i] = 'R';
                }
                else if (i + 1 < n && s[i + 1] == 'R')
                {
                    s[i] = 'B';
                }
            }
            if (s[i - 1] == 'B')
            {
                if (i == n - 1)
                {
                    s[i] = 'R';
                    continue;
                }
                if (i + 1 < n && s[i + 1] == 'B')
                {
                    s[i] = 'R';
                }
                if (i + 1 < n && s[i + 1] == 'R')
                {
                    s[i] = 'G';
                }
                else if (i + 1 < n && s[i + 1] == 'G')
                {
                    s[i] = 'R';
                }
            }
        }
    }
    cout << cnt << endl
         << s << endl;
    rr;
    // ll cnt = 0;
    // bool f = true;
    // for (ll i = 0; i < n - 1; i++)
    // {
    //     if (s[i] == s[i + 1])
    //         f = false;
    // }
    // if (f)
    // {
    //     cout << 0 << endl;
    //     cout << s << endl;
    //     rr;
    // }
    // cout << help(s, n, 0) << endl;
    // for (ll i = 0; i < n; i++)
    // {
    //     if (a[i] != 0)
    //     {
    //         s[i] = a[i];
    //     }
    // }
    // cout << s << endl;
    // rr;
}
int main()
{
    io();
    // solve();
    ll t = 1;
    // ll t;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    // cout<<setprecision(10)
    return 0;
}