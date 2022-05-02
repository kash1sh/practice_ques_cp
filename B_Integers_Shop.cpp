
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define vll vector<ll>
#define vpll vector<pair<ll, ll>>
#define fo(i, k, n) for (ll i = k; i < n; i++)
#define fo1(i, k, n) for (ll i = k; i <= n; i++)
#define rr return
#define ff first
#define ss second
#define llmin LONG_MIN
#define llmax LONG_MAX
#define Yes cout << "Yes\n"
#define No cout << "No\n"
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define yes cout << "yes\n"
#define no cout << "no\n"

#define show(A)           \
    for (auto i : A)      \
        cout << i << " "; \
    cout << '\n';
#define endl "\n"
#define Endl endl
clock_t startTime = clock();
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define all(v) v.begin(), v.end()
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
    cout.tie(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("error.txt","w",stderr);
    // freopen("output.txt", "w", stdout);
    // #endif
}
double PI = 4 * atan(1);
ll mod = 1e9 + 7, mxn = 3e5 + 5;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
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
// int a = count(all(s),'A');
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
vector<int> factors(int n)
{
    vector<int> f;
    for (int x = 2; x * x <= n; x++)
    {
        while (n % x == 0)
        {
            f.push_back(x);
            n /= x;
        }
    }
    if (n > 1)
        f.push_back(n);
    return f;
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

bool prime(ll n)
{
    if (n < 2)
        return false;
    for (ll x = 2; x * x <= n; x++)
    {
        if (n % x == 0)
            return false;
    }
    return true;
}

bool isPowerOfTwo(ll n)
{
    return n && (!(n & (n - 1)));
}
// Find Min/Max
// * Greedy/Brute Force
//* Prefix array of max/min
// * BS
// * DP/KNPS

struct inp
{
    ll lo, hi, c;
    // ll hi;
    // ll c;
};
void solve()
{
    ll n;
    cin >> n;

    // vector<ll, pair<ll, ll>> v;
    vector<inp> v(n);
    for (ll i = 0; i < n; i++)
    {
        ll a, b, cc;
        cin >> a >> b >> cc;
        // pair<ll, ll> p = {b, c};

        // pair<ll, ll> p1 = {a, p};
        // v.pb(p1);
        v[i].lo = a;
        v[i].hi = b;
        v[i].c = cc;
    }
    // for (ll i = 0; i < n; i++)
    // {
    //     cout << v[i].lo << " " << v[i].hi << " " << v[i].c << endl;
    // }
    // vpll sm, la;
    ll mini = LONG_MAX;
    ll maxa = LONG_MIN;
    ll sum = 0;

    ll l = LONG_MAX;
    ll r = LONG_MIN;
    ll cL = LONG_MAX;
    ll cR = LONG_MAX;
    map<pair<ll, ll>, ll> m;
    for (ll i = 0; i < n; i++)
    {
        if (m.find({v[i].lo, v[i].hi}) != m.end())
        {
            m[{v[i].lo, v[i].hi}] = min(v[i].c, m[{v[i].lo, v[i].hi}]);
        }
        else
        {
            m[{v[i].lo, v[i].hi}] = v[i].c;
        }
        if (v[i].lo < l)
        {
            l = v[i].lo;
            cL = v[i].c;
        }
        if (v[i].hi > r)
        {
            r = v[i].hi;
            cR = v[i].c;
        }

        if (v[i].lo == l)
        {
            cL = min(cL, v[i].c);
        }
        if (v[i].hi == r)
        {
            cR = min(cR, v[i].c);
        }

        ll ans = cL + cR;

        if (m.find({l, r}) != m.end())
        {
            ans = min(ans, m[{l, r}]);
        }
        cout << ans << endl;
    }
    rr;
    // for (ll i = 0; i < n; i++)
    // {
    //     // debug(i);
    //     if (i == 0)
    //     {
    //         mini = v[i].lo;
    //         maxa = v[i].hi;
    //         sum = v[i].c;
    //         cout << sum << endl;
    //         continue;
    //     }
    //     if (v[i].lo <= mini)
    //     {
    //         // debug(i);
    //         // debug(maxa);
    //         if (v[i].hi >= maxa)
    //         {
    //             la.pb({v[i].hi, v[i].c});
    //             if (v[i].hi == maxa)
    //             {
    //                 ll ss = 0;
    //                 for (ll j = 0; j < la.size(); j++)
    //                 {
    //                     if (la[j].ff > mini)
    //                     {
    //                         ss += la[j].ss;
    //                     }
    //                 }
    //                 if (v[i].c <= ss)
    //                 {
    //                     la.clear();
    //                     // sm.pb({v[i].h, v[i].c});
    //                     sum -= ss;
    //                     sum += v[i].c;
    //                 }
    //                 cout << sum << endl;
    //                 continue;
    //             }

    //             maxa = v[i].hi;
    //             sum = v[i].c;
    //             cout << sum << endl;
    //             // }
    //             continue;
    //         }
    //         if (v[i].lo < mini)
    //         {
    //             la.pb({v[i].hi, v[i].c});
    //             sum += v[i].c;
    //             cout << sum << endl;
    //             continue;
    //         }
    //         ll ss = 0;
    //         for (ll j = 0; j < la.size(); j++)
    //         {
    //             if (la[j].ff < maxa)
    //             {
    //                 ss += la[j].ss;
    //             }
    //         }
    //         if (v[i].c <= ss)
    //         {
    //             // la.erase();
    //             la.clear();
    //             // sm.pb({v[i].h, v[i].c});
    //             sum -= ss;
    //         }
    //         la.pb({v[i].hi, v[i].c});
    //         if (ss != 0)
    //             sum += v[i].c;
    //         mini = v[i].lo;
    //         cout << sum << endl;
    //     }
    //     if (v[i].hi >= maxa)
    //     {
    //         // debug(i);
    //         // debug(v[i].hi);
    //         // debug(maxa);
    //         // if (v[i].hi > maxa)
    //         // {
    //         debug(i);
    //         debug(v[i].hi);
    //         ll ss = 0;
    //         for (ll j = 0; j < i; j++)
    //         {
    //             if (v[j].lo != mini)
    //             {
    //                 debug(v[j].c);
    //                 ss += v[j].c;
    //             }
    //         }
    //         // debug(ss);
    //         if (v[i].hi > maxa)
    //         {
    //             sum -= ss;
    //             sum += v[i].c;
    //             maxa = v[i].hi;
    //             cout << sum << endl;
    //             continue;
    //         }
    //         if (ss > v[i].c)
    //         {
    //             sum -= ss;
    //             sum += v[i].c;
    //         }
    //         // else
    //         // {
    //         // sum += v[i].c;
    //         // }
    //         maxa = v[i].hi;
    //         cout << sum << endl;
    //         continue;
    //         // }
    //         // ll ss = 0;
    //         // for (ll i = 0; i < sm.size(); i++)
    //         // {
    //         //     cerr << sm[0].ff << " " << sm[0].ss << endl;
    //         // }

    //         // for (ll j = 0; j < sm.size(); j++)
    //         // {
    //         //     if (sm[j].ff > mini)
    //         //     {
    //         //         ss += sm[j].ss;
    //         //     }
    //         // }
    //         // if (v[i].c <= ss)
    //         // {
    //         //     sm.clear();
    //         //     // sm.pb({v[i].h, v[i].c});
    //         //     sum -= ss;
    //         // }
    //         // sm.pb({v[i].lo, v[i].c});
    //         // maxa = max(maxa, v[i].hi);
    //         // if (ss != 0)
    //         //     sum += v[i].c;
    //         // cout << sum << endl;
    //     }
    // }
    // vpll a;
    // ll k = 0, j = 0;
    // sum = v[0].c;
    // for (ll i = 0; i < n; i++)
    // {
    //     if (i == 0)
    //     {
    //         continue;
    //     }

    //     if (v[i].lo < v[k].lo)
    //     {
    //         k = i;
    //     }
    //     if (v[i].hi > v[j].hi)
    //     {
    //         j = i;
    //     }

    //     if (v[i].lo == v[k].lo && v[j].hi >= v[i].hi && v[i].c < v[k].c)
    //     {
    //         k = i;
    //     }
    //     if (v[i].hi == v[j].hi && v[k].lo <= v[i].lo && v[i].c < v[j].c)
    //     {
    //         j = i;
    //     }
    //     if (k == j)
    //     {
    //         sum = v[k].c;
    //     }
    //     else
    //     {
    //         sum = v[k].c + v[j].c;
    //     }
    //     a.pb({k, j});
    // }
    // // cout << "HI";
    // for (ll i = 0; i < n; i++)
    // {
    //     ll a1 = a[i].ff;
    //     ll a2 = a[i].ss;
    //     if (a[i].ff == a[i].ss)
    //     {
    //         cout << v[a1].c << endl;
    //         continue;
    //     }
    //     debug(a[i].ff);
    // cout << v[a[i].ff].lo << endl;
    // if (v[a1].lo == v[a2].lo)
    // {
    //     cout << v[a2].c << endl;
    //     continue;
    // }
    //     if (v[a1].hi == v[a2].hi)
    //     {
    //         cout << v[a1].c << Endl;
    //         continue;
    //     }
    // else
    // {
    // cout/ << v[a1].c + v[a2].c << endl;
    // continue;
    // }
}
// cout << sum << endl;
// rr;
// }
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
    // cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;

    // cout<<fixed<<setprecision(10)<<ans<<endl;

    // cout<<printf("%.8lf", hi)<<endl;
    return 0;
}