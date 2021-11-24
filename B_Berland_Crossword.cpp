
// #include <bits/stdc++.h>
// #define ll long long
// #define pb push_back
// #define vll vector<ll>
// #define vpll vector<pair<ll, ll>>
// #define fo(i, k, n) for (ll i = k; i < n; i++)
// #define fo1(i, k, n) for (ll i = k; i <= n; i++)
// #define Endl endl
// #define ff first
// #define ss second

// #define setbits(x) __builtin_popcountll(x)
// #define zrobits(x) __builtin_ctzll(x)
// #ifndef ONLINE_JUDGE
// #define debug(x) cerr << #x << " " << x << endl;
// #else
// #define debug(x)
// #endif
// using namespace std;

// void io()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     // #ifndef ONLINE_JUDGE
//     // freopen("input.txt", "r", stdin);
//     // freopen("error.txt","w",stderr);
//     // freopen("output.txt", "w", stdout);
//     // #endif
// }
// ll mod = 1e9 + 7, mxn = 3e5 + 5;
// ll mul(ll a, ll b, ll mod)
// {
//     a %= mod;
//     b %= mod;
//     a *= b;
//     a += mod;
//     return a % mod;
// }

// bool sortbysecdesc(const pair<int, int> &a,
//                    const pair<int, int> &b)
// {
//     return a.second > b.second;
// }
// bool check_sorted(vll a)
// {
//     ll n = a.size();
//     for (ll i = 1; i < n; i++)
//     {
//         if (a[i] >= a[i - 1])
//             continue;
//         return false;
//     }
//     return true;
// }

// ll po(ll a, ll b, ll mod)
// {
//     if (b == 0)
//         return 1;
//     if (b % 2 == 0)
//         return po(mul(a, a, mod), b / 2, mod);
//     return mul(a, po(mul(a, a, mod), (b - 1) / 2, mod), mod);
// }

// long long power(long long X, long long N)
// {
//     if (N == 0)
//         return 1;
//     if (N % 2 == 0)
//         return power(X * X, N / 2);
//     return X * power(X, N - 1);
// }

// vll fac(200003);
// ll facto(ll n)
// {

//     fac[0] = 1;
//     fac[1] = 1;
//     for (ll i = 2; i <= 200003; i++)
//     {
//         fac[i] = i * fac[i - 1];
//     }
//     return fac[n];
// }
// long combi(ll n, ll k)
// {
//     long long ans = 1;
//     k = k > n - k ? n - k : k;
//     ll j = 1;
//     for (; j <= k; j++, n--)
//     {
//         if (n % j == 0)
//         {
//             ans *= n / j;
//         }
//         else if (ans % j == 0)
//         {
//             ans = ans / j * n;
//         }
//         else
//         {
//             ans = (ans * n) / j;
//         }
//     }
//     return ans;
// }
// // CONDITION && cout << "YES" || cout << "NO"; cout << '\n';
// vector<int> sieveOfEratosthenes(int N)
// {
//     bool primes[N + 1];
//     memset(primes, true, sizeof(primes));
//     vector<int> arr;

//     for (int i = 2; i * i <= N; i++)
//         if (primes[i] == true)
//         {
//             for (int j = i * i; j <= N; j += i)
//                 primes[j] = false;
//         }

//     for (int i = 2; i <= N; i++)
//         if (primes[i])
//             arr.emplace_back(i);

//     return arr;
// }
// void prime_fact(ll n, vector<ll> &res)
// {
//     while (n % 2 == 0)
//     {
//         res.pb(2);
//         n = n / 2;
//     }

//     for (ll i = 3; i <= sqrt(n); i = i + 2)
//     {
//         while (n % i == 0)
//         {
//             res.pb(i);
//             n = n / i;
//         }
//     }
//     if (n > 2)
//     {
//         res.pb(n);
//     }
// }

// void solve()
// {
//     int n, u, r, d, l;
//     cin >> n >> u >> r >> d >> l;
//     int u1 = u;
//     int r1 = r;
//     int l1 = l;
//     int d1 = d;
//     if (u == n)
//     {
//         l1--;
//         r1--;
//     }
//     if (d == n)
//     {
//         l1--;
//         r1--;
//     }
//     if (l == n)
//     {
//         d1--;
//         u1--;
//     }
//     if (r == n)
//     {
//         d1--;
//         u1--;
//     }

//     if (u == n - 1)
//     {
//         if (l1 > r1)
//         {
//             l1--;
//         }
//         else
//         {
//             r1--;
//         }
//     }
//     if (d == n - 1)
//     {
//         if (l1 > r1)
//         {
//             l1--;
//         }
//         else
//         {
//             r1--;
//         }
//     }
//     if (l == n - 1)
//     {
//         if (u1 > d1)
//         {
//             u1--;
//         }
//         else
//         {
//             d1--;
//         }
//     }
//     if (r == n - 1)
//     {
//         if (u1 > d1)
//         {
//             u1--;
//         }
//         else
//         {
//             d1--;
//         }
//     }

//     //cout<<u1<<" "<<r1<<" "<<d1<<" "<<l1<<"\n";
//     if (l1 < 0 || u1 < 0 || d1 < 0 || r1 < 0)
//     {
//         cout << "NO" << endl;
//         return;
//     }
//     cout << "YeS" << endl;
//     return;
// }
// int main()
// {
//     io();
//     // solve();
//     // ll t=1;
//     ll t;
//     cin >> t;
//     while (t--)
//     {
//         solve();
//     }

//     // cout<<setprecision(10)
//     return 0;
// }

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
    vpll a, b;

    ll u, r, d, l;
    cin >> u >> r >> d >> l;
    a.pb({u, 0}), a.pb({r, 1}), a.pb({d, 2}), a.pb({l, 3});
    b.pb({u, 0}), b.pb({r, 1}), b.pb({d, 2}), b.pb({l, 3});
    sort(a.begin(), a.end(), greater<>());
    // if(n==2){

    // }
    for (auto i : a)
    {
        cerr << i.ff << " ";
    }
    for (ll i = 0; i < 4; i++)
    {
        ll in = a[i].ss;
        if (b[in].ff <= n - 2)
            continue;
        if (b[in].ff == n)
        {
            debug(i);
            ll ind = a[i].ss;
            debug(ind);
            b[(ind + 1) % 4].ff--;
            if (ind == 0)
            {
                debug(i);
                b[3].ff--;
                if (b[3].ff < 0)
                {
                    cout << "NO" << endl;
                    rr;
                }
            }
            else
            {
                b[ind - 1].ff--;
                if (b[ind - 1].ff < 0)
                {
                    cout << "NO" << endl;
                    rr;
                }
            }

            if (b[(ind + 1) % 4].ff < 0)
            {
                cout << "NO" << endl;
                rr;
            }
        }
        if (b[in].ff == n - 1)
        {

            ll ind = a[i].ss;
            debug(ind);
            ll v1 = b[(ind + 1) % n].ff;
            ll v2 = (ind == 0 ? b[3].ff : b[ind - 1].ff);
            if (v1 >= v2)
            {
                // cout << "HH";
                b[(ind + 1) % n].ff--;
                if (b[(ind + 1) % n].ff < 0)
                {
                    cout << "NO" << endl;
                    rr;
                }
            }
            else
            {
                if (ind == 0)
                {
                    b[3].ff--;
                    if (b[3].ff < 0)
                    {
                        cout << "NO" << endl;
                        rr;
                    }
                }
                else
                {
                    b[ind - 1].ff--;
                    if (b[ind - 1].ff < 0)
                    {
                        cout << "NO" << endl;
                        rr;
                    }
                }
            }
            // if (a[i].ff < 0)
            // {
            //     cout << "NO" << endl;
            //     rr;
            // }
        }
    }
    cout << "YES" << endl;
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
    // cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    // cout<<setprecision(10)
    return 0;
}