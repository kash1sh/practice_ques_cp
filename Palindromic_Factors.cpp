
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
// #define all(X) (X).begin(), (X).end()
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
bool isPalindrome(string s)
{
    ll n = s.size();
    if (s.size() == 1)
        return true;
    for (ll i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - i - 1])
            return false;
    }
    return true;
}
void prime_fact(ll n, vector<ll> &res)
{
    // vector<int> v;
    for (int i = 1; i <= sqrt(n); i++)
    {
        bool f = true, f1 = true;
        if (isPalindrome(to_string(i)))
        {
            f = false;
            // continue;
        }
        if (isPalindrome(to_string(n / i)))
        {
            f1 = false;
            // continue;
        }
        // if (f)
        //     continue;
        if (n % i == 0 && (n / i == i) && !f)
        {
            res.pb(i);
            continue;
        }
        // debug(i);
        if (n % i == 0)
        {

            if (f1 == false && f == false)
            {
                res.pb(i);
                res.pb(n / i);
            }
            else if (f1 == false)
            {
                res.pb(i);
            }
            else if (f == false)
            {
                res.pb(n / i);
            }
        }
    }
    // bool f = true;
    // while (n % 2 == 0)
    // {
    //     f = false;
    //     // res.pb(2);

    //     n = n / 2;
    // }
    // if (!f)
    // {
    //     res.pb(2);
    // }

    // for (ll i = 3; i <= sqrt(n); i = i + 2)
    // {
    //     f = true;
    //     if (isPalindrome(to_string(i)))
    //     {
    //         // res.pb(i);
    //         // f = false;
    //         f = false;
    //     }
    //     if (!f)
    //     {
    //         while (n % i == 0)
    //         {
    //             // res.pb(i);
    //             // f = false;
    //             n = n / i;
    //         }
    //         res.pb(i);
    //     }
    // }
    // if (n > 2 && isPalindrome(to_string(n)))
    // {
    //     res.pb(n);
    // }
    // deb(res);
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
// Find Min/Max
// * Greedy/Brute Force
// * DP
// * BS

void solve(ll mn)
{
    // ll n, d, c, m;
    // cin >> n >> d >> c >> m;
    ll n;
    cin >> n;
    // set<ll>s;
    vector<ll> res;
    prime_fact(n, res);
    // if (isPalindrome(to_string(n)))
    // {
    //     // cout << n << endl;
    //     // return;
    //     cout << "Case #" << mn << ": "
    //          << res.size() << Endl;
    //     rr;
    // }
    cout << "Case #" << mn << ": "
         << res.size() << Endl;
    // cout << res.size() << Endl;
    rr;
    // string s;
    // cin >> s;

    // ll cd = 0, cc = 0;
    // for (ll i = 0; i < n; i++)
    // {
    //     if (s[i] == 'D')
    //         cd++;
    //     else
    //         cc++;
    // }
    // if (cd > d)
    // {
    //     // cout<<
    //     cout << "Case #" << mn << ": "
    //          << "NO" << Endl;
    //     rr;
    // }
    // ll f = c;
    // ll corr = cd;
    // for (ll i = 0; i < n; i++)
    // {
    //     if (s[i] == 'D')
    //     {
    //         f += m;
    //         corr--;
    //     }
    //     else if (s[i] == 'C')
    //     {
    //         f--;
    //     }
    //     if (f < 0 && corr > 0)
    //     {

    //         cout << "Case #" << mn << ": "
    //              << "NO" << Endl;
    //         rr;
    //     }
    // }
    // cout << "Case #" << mn << ": "
    //      << "YES" << Endl;
    // rr;
}
int main()
{
    io();
    // solve();
    // ll t=1;
    ll t;
    ll mn = 1;
    cin >> t;
    while (t--)
    {
        solve(mn);
        mn++;
    }
    // cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    // cout<<fixed<<setprecision(10)<<ans<<endl;
    // cout<<printf("%.8lf", hi)<<endl;
    return 0;
}