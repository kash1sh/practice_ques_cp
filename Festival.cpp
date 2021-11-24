
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
clock_t startTime = clock();
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
double PI = 4 * atan(1);
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

bool sortbysecdesc(const pair<ll, pair<ll, ll>> &a,
                   const pair<ll, pair<ll, ll>> &b)
{
    if (a.ff == b.ff)
    {
        return a.ss.ff < b.ss.ff;
    }
    return a.ff > b.ff;
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
// map<ll, vll> m;
void solve(ll mn)
{
    ll d, n, k;
    cin >> d >> n >> k;
    // vll a(n);
    // vector<pair<ll, pair<ll, ll>>> a(n);
    // vector<pair<ll, pair<ll, ll>>> a(n);
    // vector<vector<ll>> v(n + 1);

    // vector<pair<int, pair<int, int>>> a(n);
    //  l(n), r(n);
    // vll pre(d + 1, 0);
    // vll neg(d + 1, 0);
    // vector<vector<ll>> v(d + 1);
    // vector<vector
    vector<ll> v[d + 1];
    // m.clear();
    for (ll i = 0; i < n; i++)
    {
        ll l, r, val;
        cin >> val >> l >> r;
        for (ll j = l; j <= r; j++)
        {
            v[j].pb(val);
        }
        // cin >> a[i].ff >> a[i].ss.ff >> a[i].ss.ss;
        // l[i]--, r[i]--;
        // a[i].ss.ff--;
        // a[i].ss.ss--;
    }
    int anw = 0;
    for (auto x : v)
    {
        sort(x.begin(), x.end());
        reverse(x.begin(), x.end());
        int summ = 0;
        int p = x.size();

        for (int j = 0; j < k && j < p; j++)
        {
            summ += x[j];
        }
        anw = max(anw, summ);
    }
    cout << "Case #" << mn << ": " << anw << Endl;
    rr;
    // for (auto x : v)
    // {
    // sort()
    // }
    //     sort(a.begin(), a.end(), sortbysecdesc);
    //     for (ll i = 0; i < n; i++)
    //     {
    //         cerr << a[i].ff << " " << a[i].ss.ff << " " << a[i].ss.ss << endl;
    //     }
    //     ll start = a[0].ss.ff;
    //     ll end = a[0].ss.ss;
    //     ll sum = a[0].ff;
    //     ll cnt = k;

    //     for (ll i = 1; i < n; i++)
    //     {
    //         if (cnt > 0)
    //         {
    //             ll ns = a[i].ss.ff;
    //             ll ne = a[i].ss.ss;
    //             if (ns > start && ns < end || (ns < start && ne))
    //                 // if(ns<end){
    //                 sum += a[i].ff;
    //         }
    //         // if(a[i].ss.ss>end || a[i].ss.ff)
    //     }
    // }
    //     a[i].ss = r + 1;
    //     pre[l] += a[i].ff;
    //     // pre[r + 1] -= a[i];
    //     neg[r + 1] -= a[i].ff;
    //     // s.insert(a[i]);
    // }
    // deb(pre);
    // deb(neg);
    // ll cnt = k;
    // ll sum = 0;
    // set<ll> s;
    // for (ll i = 0; i < n; i++)
    // {
    //     if (cnt > 0)
    //     {
    //         if (pre[i] > 0)
    //         {
    //             sum += pre[i];
    //             s.insert(pre[i]);
    //             cnt--;
    //         }
    //         if (neg[i] < 0)
    //         {
    //             auto val = s.find(-neg[i]);
    //             if (val == s.end())
    //                 continue;
    //             sum += neg[i];
    //             cnt++;
    //         }
    //     }
    //     else if (cnt == 0)
    //     {
    //         if (a[i] > 0 && a[i] > *s.begin())
    //         {
    //             sum -= *s.begin();
    //             s.erase(s.begin());
    //             sum += a[i];
    //             s.insert(a[i]);
    //         }
    //     }
    // }
    // cout << sum << endl;
    // rr;
}
int main()
{
    io();
    // solve();
    // ll t=1;
    ll t;
    // cin >> t;
    // while (t--)
    // {
    //     solve();
    // }
    cin >> t;
    ll mn = 1;
    while (t--)
    {

        solve(mn);
        mn++;
    }
    // cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    // cout<<setprecision(10)
    return 0;
}