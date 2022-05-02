
// #include <bits/stdc++.h>
// #define ll long long
// #define pb push_back
// #define vll vector<ll>
// #define vpll vector<pair<ll, ll>>
// #define fo(i, k, n) for (ll i = k; i < n; i++)
// #define fo1(i, k, n) for (ll i = k; i <= n; i++)
// #define rr return
// #define Endl endl
// #define ff first
// #define ss second
// #define all(X) (X).begin(), (X).end()

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
// void deb(vector<ll> v)
// {
//     for (auto t : v)
//         cerr << t << " ";
//     cerr << "\n";
// }
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

// ll fact(ll n)
// {
//     ll res = 1, i;

//     for (ll i = 2; i <= n; i++)
//     {
//         res = (res * i) % mod;
//     }
//     return res;
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
// bool valid_coordinate(ll x, ll y, ll n, ll m)
// {
//     if (x < 0 || y < 0)
//         return false;

//     else if (x >= n || y >= m)
//         return false;

//     else
//         return true;
// }
// int sod(int n)
// {
//     int sum = 0;
//     while (n)
//     {
//         sum += (n % 10);
//         n /= 10;
//     }
//     return sum;
// }

// bool isPowerOfTwo(ll n)
// {
//     return n && (!(n & (n - 1)));
// }

// void solve()
// {
//     string s, t;
//     cin >> s >> t;
//     ll n = s.size();
//     ll m = t.size();

//     for (ll i = 0; i < n; i++)
//     {
//         // res += s[i];
//         string res;
//         // res += s[i];
//         for (ll j = i; j < n; j++)
//         {
//             res += s[j];
//             string t2 = res;
//             // t2 += s[j];
//             if (t2 == t)
//             {
//                 cout << "YES" << endl;
//                 rr;
//             }
//             for (ll k = j - 1; k >= 0; k--)
//             {
//                 t2 += s[k];
//                 if (t2 == t)
//                 {
//                     cout << "YES" << endl;
//                     rr;
//                 }
//             }
//             if (t2 == t)
//             {
//                 cout << "YES" << endl;
//                 rr;
//             }
//         }
//     }
//     cout << "NO" << Endl;
//     rr;
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
string s, t;
bool solve(string ans, ll i, ll j, ll n, ll m)
{
    // if (i > n || j > m)
    // {
    //     return false;
    // }

    // if (s[i] != t[j])
    // {
    //     solve(ans, i + 1, j, n, m);
    // }
}
void solve()
{

    cin >> s >> t;
    map<ll, ll> m1;
    string ans;
    for (auto i : s)
    {
        m1[i]++;
    }

    for (auto i : t)
    {
        if (m1[i] == 0)
        {
            NO;
            rr;
        }
    }
    if (s == t)
    {
        YES;
        rr;
    }
    string s1 = s;
    reverse(s1.begin(), s1.end());

    if (s.find(t) != std::string::npos)
    {
        YES;
        rr;
        // std::cout << "found!" << '\n';
    }
    if (s1.find(t) != std::string::npos)
    {
        YES;
        rr;
        // std::cout << "found!" << '\n';
    }

    // solve(ans, 0, 0, s.size(), t.size());

    ll i = 0, jj = 0;
    ll n = s.size();
    ll m = t.size();
    // i++;
    if (m == 1)
    {
        YES;
        rr;
    }
    ll j = 0;
    // while (j < m)
    // {
    //     while (s[i] != t[j])
    //     {
    //         i++;
    //     }
    //     if (i == n)
    //     {
    //         NO;
    //         rr;
    //     }
    //     cerr << s[i] << endl;
    //     j++;
    //     while (i < n && s[i] == t[j])
    //     {
    //         i++;
    //         j++;
    //     }
    //     if (j == m)
    //     {
    //         YES;
    //         rr;
    //     }

    //     if (i - 2 >= 0 && t[j] == s[i - 2])
    //     {
    //         i -= 2;
    //     }
    //     while (i >= 0 && j < m && t[j] == s[i])
    //     {
    //         j++;
    //         i--;
    //     }

    //     if (j == m)
    //     {
    //         YES;
    //         rr;
    //     }
    //     if (i == n)
    //     {
    //         NO;
    //         rr;
    //     }
    //     j = 0;
    // }
    // NO;
    // rr;
    // cout << endl;
    // rr;
    ll p = 0;
    for (ll i = 0; i < n; i++)
    {
        // if (s[i] == t[0])
        // {
        for (ll j = i; j < n; j++)
        {
            // ll len = j - i;
            // ll back = m - len;
            // string ans = s.substr(i, j - i + 1);
            // ll back = max(0ll, m - (j - i + 1));
            // string ans2;
            // // cerr << ans << endl;
            // for (ll k = j - 1; back < m && k >= 0; back++, k--)
            // {
            //     ans2 += s[k];
            // }
            string temp;
            temp += s.substr(i, j - i + 1);
            ll curr = j - i + 1;
            ll rem = m - curr;
            for (ll k = j - 1; k >= 0, rem > 0; k--)
            {
                temp += s[k];
                rem--;
            }
            // ll len = max(0ll, m - (j - i + 1));
            // ll idx = max(0ll, j - len);

            // string r = s.substr(idx, j - idx);

            // reverse(all(r));
            // temp += r;
            // cerr << ans2 << endl;
            // if (back < m)
            // {
            //     continue;
            // }
            // reverse(ans2.begin(), ans2.end());
            // ans += ans2;
            // cerr << ans << endl;
            if (temp == t)
            {
                YES;
                rr;
            }
        }
        // }
    }
    NO;
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

    // cout<<fixed<<setprecision(10)<<ans<<endl;

    // cout<<printf("%.8lf", hi)<<endl;
    return 0;
}