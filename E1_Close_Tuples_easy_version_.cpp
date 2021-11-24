
// #include <bits/stdc++.h>
// #define ll long long
// #define pb push_back
// #define fo(i, k, n) for (ll i = k; i < n; i++)
// #define fo1(i, k, n) for (ll i = k; i <= n; i++)
// #define fir first
// #define sec second

// #define setbits(x) __builtin_popcountll(x)
// #define zrobits(x) __builtin_ctzll(x)

// using namespace std;

// void io()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     // #ifndef ONLINE_JUDGE
//     // freopen("input.txt", "r", stdin);
//     // freopen("output.txt", "w", stdout);
//     // #endif
// }
// int mod = 1e9 + 7, mxn = 3e5 + 5;

// int add(int a, int b, int mod)
// {
//     a %= mod;
//     b %= mod;
//     a += b;
//     if (a >= mod)
//         a -= mod;
//     if (a < 0)
//     {
//         a += mod;
//         a %= mod;
//     }
//     return a;
// }

// int mul(int a, int b, int mod)
// {
//     a %= mod;
//     b %= mod;
//     a *= b;
//     a += mod;
//     return a % mod;
// }
// int po(int a, int b, int mod)
// {
//     if (b == 0)
//         return 1;
//     if (b % 2 == 0)
//         return po(mul(a, a, mod), b / 2, mod);
//     return mul(a, po(mul(a, a, mod), (b - 1) / 2, mod), mod);
// }

// int fact[200003];
// int inv[200003];

// void fact0()
// {
//     int i, j;
//     fact[0] = 1;
//     for (i = 1; i <= 200000; i++)
//     {
//         fact[i] = i * fact[i - 1] % mod;
//     }
//     inv[0] = 1;
//     inv[1] = 1;
//     int p = mod;
//     for (i = 2; i <= 200000; i++)
//         inv[i] = (p - (p / i) * inv[p % i] % p) % p;

//     for (i = 2; i <= 200000; i++)
//     {
//         inv[i] *= inv[i - 1];
//         inv[i] %= mod;
//     }
// }
// int Comb(int a, int b)
// {
//     // cout<<a<<" "<<b<<endl;
//     int an = fact[a];
//     //cout<<an<<endl;
//     an *= inv[b];
//     an %= mod;
//     an *= inv[a - b];
//     an %= mod;
//     return an;
// }

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
// #define mod 1000000007

// int main()
// {
//     io();
//     ll t;
//     cin >> t;

//     while (t--)
//     {
//         ll n;
//         cin >> n;

//         ll arr[n];
//         fo(i, 0, n)
//                 cin >>
//             arr[i];

//         sort(arr, arr + n);
//         ll count = 0;
//         for (ll i = 0; i < n - 2; i++)
//         {
//             ll mini = arr[i];
//             ll seco = arr[i + 1];
//             if (seco - mini > 2)
//                 continue;
//             ll third = i + 2;

//             if (arr[third] - mini > 2)
//                 continue;
//             count++;
//             while (third < n && arr[third] - mini <= 2)
//             {
//                 ll countThird = upper_bound(arr, arr + n, arr[third]) - arr;
//                 count = count + (countThird - 1 - (i + 2));
//                 third++;
//             }
//         }
//         // if()
//         cout << count << endl;
//     }
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
    ll n;
    cin >> n;
    vll a(n);
    fo(i, 0, n)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll cnt = 0;
    for (ll i = 0; i < n - 1; i++)
    {
        ll val = upper_bound(a.begin(), a.end(), a[i] + 2) - a.begin();
        debug(i);
        // if (a[val - 1] - a[i] < 2)
        // continue;
        ll rem = val - i;
        if (a[val - 1] - a[i] > 2)
            continue;
        // debug(val);
        // ll extra = rem - 2;
        // ll u1 = rem - 2;
        // if (u1 > 0)
        // {
        //     extra = combi(rem, u1);
        // }
        cnt += ((val - i - 2) * (val - i - 1)) / 2;
    }
    cout << cnt << Endl;
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